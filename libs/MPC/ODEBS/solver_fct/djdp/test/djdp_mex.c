#include "mex.h"
#include "matrix.h"
#include "djdp_cmp.h"
#include <stdio.h>
                
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{   
    /* H,h,Gamma,g,lb,ub,alpha,alpha_min,alpha_max,z_0 */
    double* H = (double *)mxGetPr(prhs[0]);
    double* h = (double *)mxGetPr(prhs[1]);
    double* Gamma = (double *)mxGetPr(prhs[2]);
    double* g = (double *)mxGetPr(prhs[3]);
    double* lb = (double *)mxGetPr(prhs[4]);
    double* ub = (double *)mxGetPr(prhs[5]);
    double* alpha = (double *)mxGetPr(prhs[6]);
    double* alpha_min = (double *)mxGetPr(prhs[7]);
    double* alpha_max = (double *)mxGetPr(prhs[8]);
    double* z = (double *)mxGetPr(prhs[9]);
    double* der;
    mwSize* S1;
    
    S1 = (mwSize*)mxGetDimensions(prhs[2]);
    
    size_H = S1[1];
    size_A = S1[0];

    plhs[0] = mxCreateDoubleMatrix(size_H,1,mxREAL);
    der = mxGetPr(plhs[0]);
    
    djdp_cmp(H,h,Gamma,g,lb,ub,alpha,alpha_min,alpha_max,z,der);
}