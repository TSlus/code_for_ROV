#include "pch.h"
#include<iostream>


void ROV()
{
	//输入9个变量，输出三个变量
	/*
	function [vertices_Mutual, faces_Mutual, n_rem] = RemovingOldVertices_cpp2(...
    mymesh, vertices_cand, faces_Mutual, CSP_idx)
	*/
	//mesh.
	double vertices, norm_face; //矩阵形式，norm_face：面--法向量。
	//double sa，si; //网格面积，每个小三角形面积。

	int np, nf;
	int faces; //矩阵形式
	int hedge_face; //稀疏矩阵，半边--面
	//其他输入量
	double vertices_cand; // 插入点坐标
	int faces_Mutual;//每个面连接关系
	int CSP_idx;//固定的点，这里可以换成 (1:np-CSP_idx);

	//输出
	double vertices_Mutual; //生成的网格顶点
	//int faces_Mutual; //生成的面
	int n_rem; //原网格留下来的点


	/*************
	1.将网格信息读入网格类中，理清网格类的运作方式
	2.RemoveOldVertices在c++中的实现流程；
	(1)寻找点P的邻域点
	(2)判断邻域点是否能投影,邻域边之间没有交集（test1）
	(3)在投影平面上寻找 critical edge，
		如果在多边形内部存在 critical edge，这个点就不能去掉（test2）
	(4)去除原始顶点后，将多边形重新三角化，做collapse（可能会出现奇异情况）
	(5)更新面和顶点信息
	(6)循环
	***************/

	//在做写cpp之前需要解决一个大问题：之前的奇异情况 findNearPs失效怎么处理。





	//return 0;
}
