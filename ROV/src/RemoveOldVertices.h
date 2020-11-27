#pragma once

#include "MeshEx.h"
#include<list>
//#include <stdarg.h>

///�㷨���˼·��
///1.�����񶥵㣨��Mesh�ж���MeshEx�У� //��mex�ļ���д
///2.���ñ���RemoveOldVertices���ο�MeshEx_retriangulate�к����ķ�����ʵ���Ƴ�����Ĺ��̡�


/// �㷨ʵ��˼·
/// 1.����RemoveOldVertices�����൱��RetileSurfsce����Ҫʵ��remove�Ĺ��̻�����Mesh_retiangulate�н���
/// 2.����һ��MeshEx����ʼ����ֱ��Ӧ��MeshEx_retriangulate�еĴ��롣
/// 3.�������
/// 
/// 
/// \brief performs retiling like proposed in Turk'92
///
class RemoveOldVertices
{
public:
	typedef std::vector<std::pair<math::Vec3f, MeshEx::Triangle*> > ConstrainedVertexSet;
	//RemoveOldVertices() { };//���캯���ͽ���������Ҫ��cpp�ļ�����ϸ����                                                                                         // constructor
	~RemoveOldVertices() {}; // destructor
	void removeFunc(MeshEx* _mesh); // performs the algorithm on the given mesh with a set of contrained vertices
	//bool removeVertexIsPermited(MeshEx::Vertex* v); // �ж϶����Ƿ���Ա��Ƴ�


private:
	MeshEx* mesh_ROV;

};

