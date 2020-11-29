#include "pch.h"
#include "mex.h"
#include "myAdd.h"
#include<iostream>

void mexFunction(int nlhs, mxArray* plhs[], int nrhs, const mxArray* prhs[])
{
    printf("Hello World\n");
    myAdd myadd;
    double *sum;
    
    //mexPrintf("Hello World\n");
    
    plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
    sum = mxGetPr(plhs[0]);

    *sum = myadd.addFunc(2.0, 0.03);

    std::cout << "mysum = " << *sum << std::endl;

    std::cout << "iam1128" << std::endl;

}