#include "pch.h"
#include "mex.h"
#include "myAdd.h"
#include"ExecuteFunc.h"
#include<iostream>

#include <time.h>

//#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
//#include <CGAL/Surface_mesh.h>
//#include <CGAL/Polygon_mesh_processing/self_intersections.h>
//#include <fstream>
//typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
//typedef CGAL::Surface_mesh<K::Point_3>             Mesh;
//typedef boost::graph_traits<Mesh>::face_descriptor face_descriptor;
//namespace PMP = CGAL::Polygon_mesh_processing;


void mexFunction(int nlhs, mxArray* plhs[], int nrhs, const mxArray* prhs[])
{
    printf("Hello World\n");
    myAdd myadd;
    double *sum;
    
    //mexPrintf("Hello World\n");
    
    plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);

    sum = mxGetPr(plhs[0]);
    double a = mxGetScalar(prhs[0]);
    double b = mxGetScalar(prhs[1]);

    *sum = myadd.addFunc(a, b);
    //double dd = myadd.addFunc(a, b);

    //std::cout << "mysum = " << *sum << std::endl;

    //std::cout << "1616" <<std::endl;

	time_t timep;
	time(&timep); //获取time_t类型的当前时间
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));
	std::cout << tmp << std::endl;
	/*****************************/

	ExecuteFunc myex;
	myex.myExcute();


}