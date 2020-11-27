#include "RemoveOldVertices.h"

void RemoveOldVertices::removeFunc(MeshEx* _mesh)
{
	mesh_ROV = _mesh;

	// 1.store current mesh vertices
	std::vector<MeshEx::Vertex*>  oldVertices;
	for (size_t i = 0; i < mesh_ROV->m_vertices.size(); ++i)
		oldVertices.push_back(mesh_ROV->m_vertices[i]);


	// 2.remove old vertices
	printf("retriangulating...\n");

	//�Ƴ������а�����ȥ����������й���
	//1.�ж�
	//2.�Ƴ������򣬳�Ϊ�����㣬�Ƴ���
	//3.ͨ��̰�������������µ�������
	// 11.26��

	std::vector<MeshEx::Vertex*> retainedVertices; // vertices which could not be removed
	for (size_t i = 0; i < 2; ++i)
	{
		bool removed = mesh_ROV->removeVertexAndReTriangulateNeighbourhood(oldVertices[i]);

		// if vertex could not be removed
		if (!removed)
			// try again later...
			retainedVertices.push_back(oldVertices[i]);
	}

	//����û��ɾ���ĵ㣬����5��ɾ��
	//����5�ε��������ģ�
	{
		int count = 0; // this variable counts the number of tries

		// as long as there are any retained vertices and
		// we have not hit the maximum trial count yet:
		while (!retainedVertices.empty() && (count < 5))
		{
			// get the first entry
			std::vector<MeshEx::Vertex*>::iterator it = retainedVertices.begin();

			// as long as we have not reached the list of all retained vertices...
			while (it != retainedVertices.end())
			{
				// try to remove the current vertex
				if (mesh_ROV->removeVertexAndReTriangulateNeighbourhood(*it))
					// if it was successfull, then remove the vertex
					// from the list of retained vertices
					retainedVertices.erase(it); // it now points to the next element within the vector
				else
					// vertex could not be removed -> go ahead
					++it;
			};

			++count;
		};
	}

	printf("done (%i vertices retained from removal)\n", retainedVertices.size());

}