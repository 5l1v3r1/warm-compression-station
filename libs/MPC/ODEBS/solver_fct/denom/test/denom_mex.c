#include "mex.h"
#include "matrix.h"
#include "denom_cmp.h"
#include <stdio.h>
                            
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{   /*H,Gamma,g,lb,ub,alpha,alpha_min,alpha_max,dt,z_0*/
    double* H = (double *)mxGetPr(prhs[0]);
    double* Gamma = (double *)mxGetPr(prhs[1]);
    double* g = (double *)mxGetPr(prhs[2]);
    double* lb = (double *)mxGetPr(prhs[3]);
    double* ub = (double *)mxGetPr(prhs[4]);
    double* alpha = (double *)mxGetPr(prhs[5]);
    double* alpha_min = (double *)mxGetPr(prhs[6]);
    double* alpha_max = (double *)mxGetPr(prhs[7]);
    double dt = *mxGetPr(prhs[8]);
    double* z = (double *)mxGetPr(prhs[9]);
    double* den;
	mwSize* S1;
    
    S1 = (mwSize*)mxGetDimensions(prhs[1]);

	size_H = S1[1];
    size_A = S1[0];

    plhs[0] = mxCreateDoubleMatrix(size_H,size_H,mxREAL);
    den = mxGetPr(plhs[0]);
    
    denom_cmp(H,Gamma,g,lb,ub,alpha,alpha_min,alpha_max,dt,z,den);      
  
}