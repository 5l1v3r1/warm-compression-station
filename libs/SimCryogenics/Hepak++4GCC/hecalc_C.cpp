#include <iostream>
#include "Gaz.h"
#include <math.h>
#include "mex.h"

int isSingleton(double L, double C)
{
    return (L==1 && C==1);
}

int isMatrix(double L, double C)
{
    return (L>1 && C>1);
}
int isVector(double L, double C) // -1 if lign, 1 if collumn, 0 if matrix 
{
    return ( (L!=1 && C==1)*1 + (L==1 && C!=1)*-1 );
}

int isVectorSame(double V1_l, double V1_c, double V2_l, double V2_c)
{
    return isVector(V2_l,V2_c) && isVector(V1_l,V1_c) && (V1_c==V2_c) && (V1_l==V2_l);
}     

int isVectorDirectionDiff(double V1_l, double V1_c, double V2_l, double V2_c)
{
    return isVector(V2_l,V2_c) && isVector(V1_l,V1_c) && (isVector(V1_l,V1_c) != isVector(V2_l,V2_c));
}    

void mexFunction( int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    int IDID, JOUT, JUNITS, JPRECS, i, j, J1, J2, off, Index, Jtemp;
    int vs, sv, vv_same, vv_diff, ss;
    int V1_l,V1_c,V1_size,V2_size,V2_l,V2_c,V3_l,V3_c,iter;
    
    double *VALU1, *VALU2, *VALUtemp, *data;
    mwSize *S1, *S2;
    he g;

    if (nrhs != 8) 
    {
        mexErrMsgTxt("Hecalc needs 8 input arguments to work");
    } 
    if (nlhs != 1) 
    {
        mexErrMsgTxt("Hecalc provides only one output arguments");
    } 
  
    /*Get input values*/
    JOUT = (int) *mxGetPr(prhs[0]);
    J1 = (int) *mxGetPr(prhs[1]);
    J2 = (int) *mxGetPr(prhs[3]);
    JUNITS = (int) *mxGetPr(prhs[6]);
    JPRECS = (int) *mxGetPr(prhs[5]);
    
    VALU1 = mxGetPr(prhs[2]);
    S1 = (mwSize*)mxGetDimensions(prhs[2]);
    VALU2 = mxGetPr(prhs[4]);
    S2 = (mwSize*)mxGetDimensions(prhs[4]);
    
    Index = (int) *mxGetPr(prhs[7]);
 
    off = 0;
    if (J1==13 || J2==13)
    {
        off = 1;
    }
    
	if (J1==14 || J2==14)
    {
        off = 2;
    }
    
    V1_l = S1[0]; V1_c = S1[1]; V2_l = S2[0]; V2_c = S2[1];

    if ( isMatrix(V1_l,V1_c) || isMatrix(V2_l,V2_c) ) 
    {
        mexErrMsgTxt("Does not suport matrix inputs: check help");
    }

    // vector of same dimensions
    vv_same = isVectorSame(V1_l,V1_c,V2_l,V2_c); 
    // vectors of differents dimensions
    vv_diff = isVectorDirectionDiff(V1_l,V1_c,V2_l,V2_c);
    // singleton vector
    sv = isSingleton(V1_l, V1_c) && isVector(V2_l, V2_c); 
    // vector singleton
    vs = isVector(V1_l, V1_c) && isSingleton(V2_l, V2_c); 
    // input are both singleton
    ss = isSingleton(V1_l, V1_c) && isSingleton(V2_l, V2_c);

    if ( !ss && !vv_same && (isVector(V1_l,V1_c) == isVector(V2_l,V2_c)) ) 
    {
        mexErrMsgTxt("Vector of different dimensions must be line/collon or colum/line: check help");
    } 
    
    // if input are vector of same size
    if (vv_same)
    {
        plhs[0] = mxCreateDoubleMatrix(V1_l,V1_c,mxREAL);
        data = mxGetPr(plhs[0]);
        for(i=0 ; i<max(V1_l,V1_c); i++)
        {
            g.calc(IDID,JOUT,J1,VALU1[i],J2,VALU2[i],JPRECS,JUNITS);
            data[i]=g.prpdbl[Index+42*off];
        }
    }
    
    // if input is singleton vector or vector singleton or both singleton 
    if (sv || vs || ss)
    {
        if (sv || ss)
        {
            V3_l = V2_l;  V3_c = V2_c;
        }        
        
        if (vs)
        {
            VALUtemp = VALU1; VALU1 = VALU2; VALU2 = VALUtemp;
            Jtemp = J1; J1 = J2; J2 = Jtemp;
            V3_l = V1_l;  V3_c = V1_c;
        }
        
        iter = max(V3_l,V3_c);
        
        plhs[0] = mxCreateDoubleMatrix(V3_l,V3_c,mxREAL);
        data = mxGetPr(plhs[0]);
        for(i=0 ; i<iter; i++)
        {
            g.calc(IDID,JOUT,J1,*VALU1,J2,VALU2[i],JPRECS,JUNITS);
            data[i]=g.prpdbl[Index+42*off];
        }
    }
    
    // if input is vectors of differents dimensions
    if (vv_diff)
    {
        if (isVector(V1_l,V1_c)==1) // -1 line +1 collum
        {
            V1_size = V1_l;
            V2_size = V2_c;
        }
        else
        {
            V1_size = V2_l;
            V2_size = V1_c;
            
            VALUtemp = VALU1; VALU1 = VALU2; VALU2 = VALUtemp;
            Jtemp = J1; J1 = J2; J2 = Jtemp;
        }

        plhs[0] = mxCreateDoubleMatrix(V1_size,V2_size,mxREAL);
        data = mxGetPr(plhs[0]);
        for(i=0 ; i<V1_size; i++)
        {
            for(j=0; j<V2_size; j++)
            {
                g.calc(IDID,JOUT,J1,VALU1[i],J2,VALU2[j],JPRECS,JUNITS);
                data[i+V1_size*j]=g.prpdbl[Index+42*off];
            }
        }
    }  
}
 