#include "mex.h"
#include "matrix.h"
#include "lins_perso_cmp.h"
#include <stdio.h>
                            
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{   
    double* H = (double *)mxGetPr(prhs[0]);
    double* h = (double *)mxGetPr(prhs[1]);
    double* delta;
	mwSize* S1;

	S1 = (mwSize*)mxGetDimensions(prhs[0]);

	size_H = S1[0];

    plhs[0] = mxCreateDoubleMatrix(size_H,1,mxREAL);
    delta = mxGetPr(plhs[0]);
    
    lins_perso_cmp(H,h,delta);      
  
}