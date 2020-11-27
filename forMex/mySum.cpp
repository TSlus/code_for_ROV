#include "mex.h"
#include<iostream>

/* 入口函数 */
void mexFunction( int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[])
{
    double multiplier1, multiplier2;      
    double *outMatrix;
    
    multiplier1 = mxGetScalar(prhs[0]);   
    multiplier2 = mxGetScalar(prhs[1]);
    
    plhs[0] = mxCreateDoubleMatrix(1,1,mxREAL);
    outMatrix = mxGetPr(plhs[0]); //指针初始化

    *outMatrix = (100*multiplier1 + multiplier2)*100;

    std::cout<<"mySum = "<< *outMatrix << std::endl;
}
