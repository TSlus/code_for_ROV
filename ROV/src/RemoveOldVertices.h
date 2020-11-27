#pragma once

#include "MeshEx.h"
#include<list>
//#include <stdarg.h>

///算法设计思路：
///1.将网格顶点（在Mesh中读入MeshEx中） //在mex文件中写
///2.利用本类RemoveOldVertices（参考MeshEx_retriangulate中函数的方法）实现移除顶点的过程。


/// 算法实现思路
/// 1.函数RemoveOldVertices作用相当于RetileSurfsce，主要实现remove的过程还是在Mesh_retiangulate中进行
/// 2.定义一个MeshEx，初始化后，直接应用MeshEx_retriangulate中的代码。
/// 3.输出网格
/// 
/// 
/// \brief performs retiling like proposed in Turk'92
///
class RemoveOldVertices
{
public:
	typedef std::vector<std::pair<math::Vec3f, MeshEx::Triangle*> > ConstrainedVertexSet;
	//RemoveOldVertices() { };//构造函数和解析函数需要在cpp文件中详细描述                                                                                         // constructor
	~RemoveOldVertices() {}; // destructor
	void removeFunc(MeshEx* _mesh); // performs the algorithm on the given mesh with a set of contrained vertices
	//bool removeVertexIsPermited(MeshEx::Vertex* v); // 判断顶点是否可以被移除


private:
	MeshEx* mesh_ROV;

};

