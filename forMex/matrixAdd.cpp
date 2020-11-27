# include "mex.h"
void mexArrayAdd(const int Row,const int Col,const double *A,const double *B,double *C){
    int i,j;
    for(i=0;i<Row;i++){
        for(j=0;j<Col;j++){
            //注意数据的表达方式, C语言是按行存储A[i*Col+j]，matlab是按列存储 A[i+j*Row]
            C[i+j*Row] = A[i+j*Row] + B[i+j*Row]; 
        }
    }
}
 
void mexFunction(int nlhs,mxArray *plhs[],int nrhs,const mxArray *prhs[]){
    double *A,*B,*C;
    int RowA,ColA,RowB,ColB;
    if(nlhs != 1){
       mexErrMsgTxt("One output required.");
    }
    else if(nrhs > 2){
        mexErrMsgTxt("Two input required.");
    }
    if( !mxIsDouble(prhs[0]) || !mxIsDouble(prhs[1]) || mxIsComplex(prhs[0]) || mxIsComplex(prhs[1]) ){
        mexErrMsgTxt("Input Array must be double.");
    }
    //获得矩阵的行数
    RowA = mxGetM(prhs[0]);
    //获得矩阵的列数
    ColA = mxGetN(prhs[0]);
    RowB = mxGetM(prhs[1]);
    ColB=  mxGetN(prhs[1]);
    //判断行列是否相等
    if(RowA != RowB || ColA != ColB){
        mexErrMsgTxt("Rows and Cols must be same.");
    }
    //获取指向输入参数的指针
    A = mxGetPr(prhs[0]);
    B = mxGetPr(prhs[1]);
    //生成输出参量的mxArray
    plhs[0] = mxCreateDoubleMatrix(RowA,ColB,mxREAL);
    //获取指向输出参数的指针
    C= mxGetPr(plhs[0]);
    mexArrayAdd(RowA, ColA, A, B, C);
}