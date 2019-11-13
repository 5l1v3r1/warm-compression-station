#include "mex.h"
#include "matrix.h"
#include "solve_pb_mpc_c.h"
#include <math.h>

#define Newton 1
#define __lambda 0.585786437626905
#define __delta 1
#define __a 1.0       
#define __b 1.207106781186548
#define __c 0.207106781186548
#define __d 0.292893218813453
#define __e -0.040440114519881
#define __f 1.707106781186548
#define __g 4.121320343559642
#define __l 2.414213562373095

#define REL_TOL 100
#define ABS_TOL 1

						     /*H,h,Gamma,g,lb,ub,alpha,alpha_min,alpha_max,dt,z_0*/
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    double* H = (double *)mxGetPr(prhs[0]);
    double* h = (double *)mxGetPr(prhs[1]);
    double* Gamma = (double *)mxGetPr(prhs[2]);
    double* g = (double *)mxGetPr(prhs[3]);
    double* lb = (double *)mxGetPr(prhs[4]);
    double* ub = (double *)mxGetPr(prhs[5]);
    double* alpha = (double *)mxGetPr(prhs[6]);
    double* alpha_min = (double *)mxGetPr(prhs[7]);
    double* alpha_max = (double *)mxGetPr(prhs[8]);
    double* st = (double *)mxGetPr(prhs[9]);
	double* t0 = (double *)mxGetPr(prhs[10]);
    double* z = (double *)mxGetPr(prhs[11]);
    double z_copy[SIZE_H_MAX];

    mwSize* S1;
    double *zpu;
    double *lambda;
    double *iter;
	double *norm;
    
    S1 = (mwSize*)mxGetDimensions(prhs[2]);

    size_H = 9;
    size_A = 64;

	memcpy(z_copy,z,size_H*sizeof(double));
    
    plhs[0] = mxCreateDoubleMatrix(size_H,1,mxREAL);
    zpu = mxGetPr(plhs[0]);
    plhs[1] = mxCreateDoubleMatrix(1,1,mxREAL);
    iter = mxGetPr(plhs[1]);
    plhs[2] = mxCreateDoubleMatrix(size_A,1,mxREAL);
    lambda = mxGetPr(plhs[2]);
	plhs[3] = mxCreateDoubleMatrix(1,1,mxREAL);
    norm = mxGetPr(plhs[3]);
    
    solve_pb_mpc_fct(H,h,Gamma,g,lb,ub,alpha,alpha_min,alpha_max,(int)*st,z_copy,zpu,iter,lambda,norm);
}

void solve_pb_mpc_fct(  double* H,
                        double* h,
                        double* Gamma, 
                        double* g,
                        double* lb,
                        double* ub,
                        double* alpha,
                        double* alpha_min,
                        double* alpha_max,
                        int st, 
                        double* z,
                        double* zpu,
                        double* iter,
                        double* lambda,
						double* norm)
{
	double zpl[SIZE_H_MAX], num_pl[SIZE_H_MAX], num_pu[SIZE_H_MAX];
	double den_pl[SIZE_H_MAX*SIZE_H_MAX], den_pu[SIZE_H_MAX*SIZE_H_MAX];
	double delta_zpu[SIZE_H_MAX], delta_zpl[SIZE_H_MAX];
    
	double LTE, EEE, SSS, r, nG;
	
	double Gpu[SIZE_H_MAX], Gpl[SIZE_H_MAX], G[SIZE_H_MAX];
	double inter1[SIZE_A_MAX], inter2[SIZE_A_MAX];
	double dt = .001, dt_new;
    
	int n=0, s=0, i; /*les classiques*/ 
    
    djdp_cmp(H, h, Gamma, g, lb, ub, alpha, alpha_min, alpha_max, z, G);

    *norm = 1.0;
	while( s<st && *norm>1e-6) /* st fois */
    {
		s=s+1;
		/*memcpy(inter2, inter1, SIZE_A*sizeof(double));*/
		memcpy(zpl, z, size_H*sizeof(double)); memcpy(Gpl, G, size_H*sizeof(double));
        denom_cmp(H, Gamma, g, lb, ub, alpha, alpha_min, alpha_max, dt, zpl, den_pl);
		for(i=0; i<Newton; i++)
		{
			num_pl_fct(zpl,z,Gpl,dt,G,num_pl);
			lins_perso_cmp(den_pl, num_pl, delta_zpl);
			saut(zpl,delta_zpl);
            djdp_cmp(H, h, Gamma, g, lb, ub, alpha, alpha_min, alpha_max, zpl, Gpl);
		}

		/* calcul de Gpu */
		memcpy(zpu, zpl, size_H*sizeof(double)); memcpy(Gpu, Gpl, size_H*sizeof(double));
        denom_cmp(H, Gamma, g, lb, ub, alpha, alpha_min, alpha_max, dt, zpu, den_pu);
		for(i=0; i<Newton; i++)
		{
			num_pu_fct(zpu, zpl, z, Gpu, dt, num_pu);
			lins_perso_cmp(den_pu, num_pu, delta_zpu);
			saut(zpu,delta_zpu);
            djdp_cmp(H, h, Gamma, g, lb, ub, alpha, alpha_min, alpha_max, zpu, Gpu);
		}

		/*serie->les_J[n] = infos->J;
		serie->les_nG[n] = infos->norme;*/

		for(i=0, SSS=0; i<size_H; i++)
		{
				LTE = 2.0*__e*dt* ( __f*G[i] - __g*Gpl[i] + __l*Gpu[i] );
				EEE = REL_TOL*fabs(G[i]) + ABS_TOL;
				SSS += (LTE*LTE)/(EEE*EEE);
		}
		r = sqrt(SSS/size_H);

		/*for(i=0; i<size_H; i++)	{ serie->les_p[i+n*size_H] = ppu[i]; }*/

		if (r < 2 )
		{
			dt_new = dt/pow(r,0.3333);
			dt = min(dt_new, 10*dt);
			memcpy(z, zpu, size_H*sizeof(double)); memcpy(G, Gpu, size_H*sizeof(double));
		}
		else
		{
			//h = h/4;
			dt = dt*0.5;
			/*memcpy(inter1, inter2, (size_A+2*size_H)*sizeof(double));*/
		}
        
        nG = 0;
        for(i=0; i<size_H; i++)
            nG  += G[i]*G[i];
        
        *norm = sqrt(nG);
	}
    //csrt_cmp(H, h, Gamma, g, lb, ub, alpha, alpha_min, alpha_max, z, lambda);
    *iter = s;
}

void num_pu_fct(double *ppu, double *ppl, double *p, double *Gpu, double h, double *num_pu)
{
	int i;
	for(i=0; i<size_H; i++)
	{
		num_pu[i] = -(__a*ppu[i]-__b*ppl[i]+__c*p[i]) + __d*h*Gpu[i];
	}
}

void num_pl_fct(double *ppl, double *p, double *Gpl, double h, double *G, double *num_pl)
{
	int i;
	for(i=0; i<size_H; i++)
	{
		num_pl[i] = -(ppl[i]-p[i]) + __lambda*h/2*(Gpl[i]+G[i]);
	}
}

void saut(double *pp, double *delta_pp)
{
	int i;
	for(i=0; i<size_H; i++)
	{
		pp[i] = pp[i] + __delta*delta_pp[i];
	}
}

void denom_cmp( double* H,
	            double* Gamma, 
			    double* g, 
			    double* lb, 
			    double* ub,
			    double* alpha,
			    double* alpha_min,
			    double* alpha_max,
			    double dt, 
			    double* z,
			    double* den)
{
  int ind[SIZE_A_MAX];
  double cstp[SIZE_A_MAX];
  double cst[SIZE_A_MAX];
  int i;
  int k;
  int j;
  double a;
  double hmm[SIZE_H_MAX];
  double u0;
  double b_u0;
  int l;

  memset(&den[0], 0, size_H*size_H * sizeof(double));
  a = dt * __lambda / 2.0;

  k = csrt_cmp(H, Gamma, g, lb, ub, alpha, alpha_min, alpha_max, z, cstp, ind);
  
  for (i = 0; i < k; i++) {
      cstp[i] = a * 6.0 * alpha[ind[i]] * cstp[i];
  }

  for (i = 0; i < size_H; i++) {
    u0 = z[i] - ub[i];
    if (u0 >= 0.0) {
    } else {
      u0 = 0.0;
    }

    b_u0 = lb[i] - z[i];
    if (b_u0 >= 0.0) {
    } else {
      b_u0 = 0.0;
    }

    hmm[i] = a * (alpha_max[i] * 6.0 *u0 + alpha_min[i] * 6.0 *b_u0);
  }

  for (i = 0; i < size_H; i++) {
    for (l = 0; l <= i; l++) {
      den[l + size_H * i] = a * H[i + size_H * l];
      for (j = 0; j < k; j++) {
        den[l + size_H * i] += Gamma[(ind[j] + size_A * l) ] * cstp[j] * Gamma[(ind[j] + size_A * i) ];
      }
    }

    den[i + size_H * i] = (den[i + size_H * i] + hmm[i]) + 1.0;
  }
}

int csrt_cmp(  double* H,
               double* Gamma,
               double* g, 
               double* lb,
               double* ub,
               double* alpha,
               double* alpha_min,
               double* alpha_max,
               double* z,
			   double* cstp,
			   int* ind)
{
  double cst[SIZE_A_MAX];
  int i,j,k;

  k = 0;
  for (i = 0; i < size_A; i++) {
    ind[i] = 0;
    cst[i] = -g[i];
    for (j = 0; j < size_H; j++) {
      cst[i] += Gamma[i + size_A * j] * z[j];
    }
	if (cst[i] > 0.0) {
		cstp[k] = cst[i];
		ind[k] = (int16_T)(i);
		k++;
	}
  }
  return k;
}

void djdp_cmp( double* H,
               double* h, 
               double* Gamma,
               double* g, 
               double* lb,
               double* ub,
               double* alpha,
               double* alpha_min,
               double* alpha_max,
               double* z,
               double* der)
{
  int ind[SIZE_A_MAX];
  double cstp[SIZE_A_MAX];
  int i, j, k;
  double b_u0;
  double u0;

  k = csrt_cmp(H, Gamma, g, lb, ub, alpha, alpha_min, alpha_max, z, cstp, ind);
  
  for (i = 0; i < k; i++) {
      cstp[i] = 3.0 * cstp[i]* cstp[i] * alpha[ind[i]];
    }

  for (i = 0; i < size_H; i++) {
    der[i] = h[i];
    for (j = 0; j < size_H; j++) {
      der[i] += H[i + size_H * j] * z[j];
    }
  }

  for (i = 0; i < size_H; i++) {
    for (j = 0; j < k; j++) {
      der[i] += Gamma[(ind[j] + size_A * i)] * cstp[j];
    }

    u0 = z[i] - ub[i];
    if (u0 >= 0.0) {
    } else {
      u0 = 0.0;
    }

    b_u0 = lb[i] - z[i];
    if (b_u0 >= 0.0) {
    } else {
      b_u0 = 0.0;
    }

    der[i] = (der[i] + 3.0 * alpha_max[i] * u0 * u0) - alpha_min[i] * 3.0 * b_u0 * b_u0;
  }

  for (i = 0; i < size_H; i++) {
    der[i] = -der[i];
  }
}

void lins_perso_cmp(const real_T A[SIZE_H_MAX*SIZE_H_MAX],
	                const real_T B[SIZE_H_MAX],
					real_T p[SIZE_H_MAX])
{
  real_T C[SIZE_H_MAX*SIZE_H_MAX];
  real_T y[SIZE_H_MAX];
  int32_T i;
  real_T temp;
  int32_T k;
  int32_T j;
  int32_T b_j;
  memset(&C[0], 0, size_H*size_H * sizeof(real_T));
  for (i = 0; i < size_H; i++) {
    y[i] = 0.0;
    p[i] = 0.0;
  }

  /*  cholesky */
  for (i = 0; i < size_H; i++) {
    temp = 0.0;
    for (k = 0; k <= i; k++) {
      temp -= C[k + size_H * i] * C[k + size_H * i];
    }

    C[i + size_H * i] = sqrt(A[i + size_H * i] + temp);
    for (j = 0; j <= size_H - 2 - i; j++) {
      b_j = (i + j) + 1;
      temp = 0.0;
      for (k = 0; k <= i; k++) {
        temp -= C[k + size_H * i] * C[k + size_H * b_j];
      }

      C[i + size_H * b_j] = (A[i + size_H * b_j] + temp) / C[i + size_H * i];
    }
  }

  /*  up and down */
  for (i = 0; i < size_H; i++) {
    temp = B[i];
    for (j = 0; j <= i; j++) {
      temp -= C[j + size_H * i] * y[j];
    }

    y[i] = temp / C[i + size_H * i];
  }

  for (i = size_H-1; i >=0 ; i--) {
    temp = y[i];
    for (j = size_H-1; j>=i+1 ; j--) {
      temp -= C[size_H*j+i] * p[j];
    }

    p[i] = temp / C[size_H * i+i];
  }

}