#include <iostream>
#include "Gaz.h"


extern "C" {
#include <math.h>
#include "mex.h"
}

extern "C" {
  void mexFunction( int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
    {
	 static double data[50000][3][42], *outputData, *outputInt, *VALU1, *VALU2;
     static double *temp;
     static int IDID, JOUT, JUNITS, JPRECS, i,J1, J2, iter=0;
	 mwSize *S1, *S2;
     he g;
      
      /* Check for proper number of arguments */
      
      if (nrhs != 7) {
        mexErrMsgTxt("EXAMPLE requires seven input arguments.");
      } else if (nlhs > 1) {
        mexErrMsgTxt("EXAMPLE requires one output argument only.");
      } 
      
      
      /*Get input values*/
	  temp = mxGetPr(prhs[0]);
	  JOUT = (int) *temp;
	  temp = mxGetPr(prhs[1]);
	  J1 = (int) *temp;
	  temp = mxGetPr(prhs[3]);
	  J2 = (int) *temp;
	  temp = mxGetPr(prhs[6]);
	  JUNITS = (int) *temp;
	  temp = mxGetPr(prhs[5]);
	  JPRECS = (int) *temp;
	  VALU1 = mxGetPr(prhs[2]);
	  S1 = (mwSize*)mxGetDimensions(prhs[2]);
	  VALU2 = mxGetPr(prhs[4]);
	  S2 = (mwSize*)mxGetDimensions(prhs[4]);
	  
	  for(iter=0 ; iter<max(S1[0],S1[1]); iter++)
	  {
      g.calc(IDID,(const int) JOUT,(const int) J1,(const long double) VALU1[iter],(const int) J2,(const long double) VALU2[iter],JPRECS,JUNITS);
		  
		    /*Populate the output arrays */
		  for (int ii = 0; ii <42;ii++)
		  {
      		data[iter][0][ii]=g.prpdbl[ii];
      		data[iter][1][ii]=g.prpdbl[ii+42];
      		data[iter][2][ii]=g.prpdbl[ii+84];
		  }
	  }

	  		  /* Create the output arrays */
        plhs[0] = mxCreateDoubleMatrix(42,3*iter,mxREAL);
        outputData = mxGetPr(plhs[0]);
      
      memcpy(outputData, data , iter * 42 * 3 * sizeof(double));
      
      return;
    }
}    