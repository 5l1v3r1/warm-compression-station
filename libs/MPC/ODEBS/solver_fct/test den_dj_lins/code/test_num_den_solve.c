#include "mex.h"
#include "matrix.h"
#include "denom_cmp.h"
#include "djdp_cmp.h"
#include "lins_perso_cmp.h"

#include <stdio.h>
                            
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{   
        /*H,h,Gamma,g,lb,ub,alpha,alpha_min,alpha_max,dt,z_0*/
    double* H = (double *)mxGetPr(prhs[0]);
    double* h = (double *)mxGetPr(prhs[1]);
    double* Gamma = (double *)mxGetPr(prhs[2]);
    double* g = (double *)mxGetPr(prhs[3]);
    double* lb = (double *)mxGetPr(prhs[4]);
    double* ub = (double *)mxGetPr(prhs[5]);
    double* alpha = (double *)mxGetPr(prhs[6]);
    double* alpha_min = (double *)mxGetPr(prhs[7]);
    double* alpha_max = (double *)mxGetPr(prhs[8]);
    double dt = *mxGetPr(prhs[9]);
    double* z = (double *)mxGetPr(prhs[10]);
    mwSize* S1;
    
    double der[SIZE_H_MAX];
    double den[SIZE_H_MAX*SIZE_H_MAX];
    double *delta;
    
    S1 = (mwSize*)mxGetDimensions(prhs[2]);

    size_H = S1[1];
    size_A = S1[0];
    
    plhs[0] = mxCreateDoubleMatrix(size_H,1,mxREAL);
    delta = mxGetPr(plhs[0]);

    djdp_cmp(H,h,Gamma,g,lb,ub,alpha,alpha_min,alpha_max,z,der);
    denom_cmp(H,Gamma,g,lb,ub,alpha,alpha_min,alpha_max,dt,z,den);    
    lins_perso_cmp(den,der,delta);      

}

