//#include <iostream>
//#include <fstream>
//#include <string>
//
//#include "ObjIO.h"
//#include "Mesh.h"
//#include "MeshEx.h"
//#include "RemoveOldVertices.h"
//#include<ctime>
//
//int main(int argc, char** argv)
//{
//	dk::Mesh* m = dk::io::importFromObjFile("C:/Users/Husen_Li/Desktop/code/code_for_ROV/projects/myobjm2.obj");
//
//	// generate winged edge datastructure
//	MeshEx* mx = new MeshEx(m);
//
//	delete m;
//
//	std::cout << "read obj successfully." << std::endl;
//
//	std::vector<int>         CSV_idx;//不能移除的点
//
//	std::ifstream myfile3("C:/Users/Husen_Li/Desktop/code/code_for_ROV/projects/CSP_idx.txt");
//	if (!myfile3.is_open())
//	{
//		std::cout << "can not open this file2" << std::endl;
//		return 0;
//	}
//
//	while (myfile3)
//	{
//		float ctemp0;
//		myfile3 >> ctemp0;
//		int ctemp = (int)ctemp0;
//		CSV_idx.push_back(ctemp);
//	}
//	myfile3.close();
//
//
//	//std::cout << "顶点个数 = " << mx->m_vertices.size() << std::endl;
//	//std::cout << "面个数 = " << mx->m_triangles.size() << std::endl;
//
//	// load mesh
//	clock_t startTime, endTime;
//	startTime = clock();//计时开始
//
//	RemoveOldVertices rov;
//	rov.removeFunc(mx, CSV_idx);
//
//	endTime = clock();//计时结束
//	std::cout << "The run time is: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << std::endl;
//
//	m = mx->getMesh();
//	dk::io::exportToObjFile(m, "bustedRE.obj");
//
//	delete mx;
//
//	std::cout << "ROV完成。" << std::endl;
//
//	return 0;
//}


//标准无错做法
#include <iostream>

#include "ObjIO.h"
#include "Mesh.h"
#include "MeshEx.h"
//#include "RetileSurface.h"
#include "RemoveOldVertices.h"
#include<ctime>


Mesh* creatMesh(std::vector<math::Vec3f> _mvertices, std::vector<int> _mindicees)
{
	return new Mesh(_mvertices, _mindicees);
}

int main(int argc, char ** argv)
{
	// load mesh

	dk::Mesh *m = dk::io::importFromObjFile( "C:/Users/Husen_Li/Desktop/code/code_for_ROV/projects/myobjm2.obj" );

	/***************************************/
	/// 将顶点，面索引读进来，
	/// 然后用一个数组存，mex
	/// 重新写一个函数读一遍
	/// 程序仍然可以运行，就可。
	std::vector<math::Vec3f> mvertices;//这里的mvertices，mindicees从mex文件输入，11.28pm
	std::vector<int>         mindicees;

	mvertices = m->tempvertices;
	mindicees = m->tempindicees;

	std::cout << "mvertices.size()=" << mvertices.size() << std::endl;
	std::cout << "mindicees.size()=" << mindicees.size() << std::endl;

	dk::Mesh* m2 = creatMesh(mvertices, mindicees);

	/****************************************/


	// generate winged edge datastructure
	MeshEx *mx = new MeshEx(m2);

	delete m;
	delete m2;

	std:: cout<< "read obj successfully." << std::endl;

	//std::cout << "顶点个数 = " << mx->m_vertices.size() << std::endl;
	//std::cout << "面个数 = " << mx->m_triangles.size() << std::endl;

	clock_t startTime, endTime;
	startTime = clock();//计时开始

	RemoveOldVertices rov;
	rov.removeFunc(mx);

	endTime = clock();//计时结束
	std::cout << "The run time is: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << std::endl;

	m2 = mx->getMesh();
	dk::io::exportToObjFile( m2, "bustedRE.obj" );

	delete m2;
	delete mx;

	std::cout << "ROV完成。" << std::endl;




	return 0;
}


//读取txt不可行
//#include <iostream>
//
//#include "ObjIO.h"
//#include "Mesh.h"
//#include "MeshEx.h"
////#include "RetileSurface.h"
//#include "RemoveOldVertices.h"
//#include<ctime>
//
//#include <fstream>
//#include <string>
//using namespace std;
//
//Mesh* creatMesh(std::vector<math::Vec3f> _mvertices, std::vector<int> _mindicees)
//{
//	return new Mesh(_mvertices, _mindicees);
//}
//
//int main(int argc, char** argv)
//{
//
//
//	//dk::Mesh* m = dk::io::importFromObjFile("busted.obj");
//
//	/***************************************/
//	/// 将顶点，面索引读进来，
//	/// 然后用一个数组存，mex
//	/// 重新写一个函数读一遍
//	/// 程序仍然可以运行，就可。
//	std::vector<math::Vec3f> mvertices;//这里的mvertices，mindicees从mex文件输入，11.28pm
//	std::vector<int>         mindicees;
//	std::vector<int>         CSV_idx;
//
//	{
//		//1.
//		ifstream myfile1("C:/Users/Husen_Li/Desktop/code/code_for_ROV/projects/vertices_Mutual.txt");
//		if (!myfile1.is_open())
//		{
//			cout << "can not open this file1" << endl;
//			return 0;
//		}
//
//		while (myfile1)
//		{
//			math::Vec3f vtemp;
//			myfile1 >> vtemp.x;
//			myfile1 >> vtemp.y;
//			myfile1 >> vtemp.z;
//			mvertices.push_back(vtemp);
//		}
//		myfile1.close();
//
//		//2.
//		ifstream myfile2("C:/Users/Husen_Li/Desktop/code/code_for_ROV/projects/faces_Mutual.txt");
//		if (!myfile2.is_open())
//		{
//			cout << "can not open this file2" << endl;
//			return 0;
//		}
//
//		while (myfile2)
//		{
//			float ftemp0;
//			myfile2 >> ftemp0;
//			int ftemp = (int)ftemp0;
//			mindicees.push_back(ftemp);
//		}
//		myfile2.close();
//
//		//3.
//		ifstream myfile3("C:/Users/Husen_Li/Desktop/code/code_for_ROV/projects/CSP_idx.txt");
//		if (!myfile3.is_open())
//		{
//			cout << "can not open this file2" << endl;
//			return 0;
//		}
//
//		while (myfile3)
//		{
//			float ctemp0;
//			myfile3 >> ctemp0;
//			int ctemp = (int)ctemp0;
//			CSV_idx.push_back(ctemp);
//		}
//		myfile3.close();
//	}
//
//	mvertices.pop_back();
//	mindicees.pop_back();
//	CSV_idx.pop_back();
//
//	cout << "顶点个数:" << mvertices.size() << endl;
//	cout << "3面个数:" << mindicees.size() << endl;
//	cout << "CSV个数:" << CSV_idx.size() << endl;
//
//	//for (int i = 0; i < 9; i++)
//	//{
//	//	cout << "mvertices[" << i << "] =" << "x="<<mvertices[i].x<< "\t y="<< mvertices[i].y<< "\t z=" << mvertices[i].z << endl;
//	//	cout << "mindicees[" << i << "] =" << mindicees[i] << endl;
//	//	cout << "CSV_idx[" << i << "] =" << CSV_idx[i] << endl;
//	//}
//
//	//for (int i = mvertices.size() - 9; i < mvertices.size(); i++)
//	//{
//	//	cout << "mvertices[" << i << "] =" << "x=" << mvertices[i].x << "\t y=" << mvertices[i].y << "\t z=" << mvertices[i].z << endl;
//	//}
//	//for (int i = mindicees.size() - 9; i < mindicees.size(); i++)
//	//{
//	//	cout << "mindicees[" << i << "] =" << mindicees[i] << endl;
//	//}
//	//for (int i = CSV_idx.size() - 9; i < CSV_idx.size(); i++)
//	//{
//	//	cout << "CSV_idx[" << i << "] =" << CSV_idx[i] << endl;
//	//}
//
//	dk::Mesh* m2 = creatMesh(mvertices, mindicees);
//
//	// generate winged edge datastructure
//	MeshEx* mx = new MeshEx(m2);
//
//	//delete m2;
//	delete m2;
//
//	std::cout << "read obj successfully." << std::endl;
//
//	// load mesh
//	clock_t startTime, endTime;
//	startTime = clock();//计时开始
//
//	RemoveOldVertices rov;
//	rov.removeFunc(mx, CSV_idx);
//
//	std::cout << "ROV完成。" << std::endl;
//	endTime = clock();//计时结束
//	std::cout << "The run time is: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << std::endl;
//
//	//m = mx->getMesh();
//	dk::io::exportToObjFile(m2, "bustedRE.obj");
//
//	//delete m;
//	delete mx;
//
//
//
//
//
//	return 0;
//}

