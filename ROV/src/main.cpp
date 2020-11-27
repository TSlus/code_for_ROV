#include <iostream>

#include "ObjIO.h"
#include "Mesh.h"
#include "MeshEx.h"
//#include "RetileSurface.h"
#include "RemoveOldVertices.h"


int main(int argc, char ** argv)
{
	// load mesh
	dk::Mesh *m = dk::io::importFromObjFile( "busted.obj" );

	// generate winged edge datastructure
	MeshEx *mx = new MeshEx(m);

	delete m;

	std:: cout<< "read obj successfully" << std::endl;

	//std::cout << "顶点个数 = " << mx->m_vertices.size() << std::endl;
	//std::cout << "面个数 = " << mx->m_triangles.size() << std::endl;

	RemoveOldVertices rov;
	rov.removeFunc(mx);

	m = mx->getMesh();
	dk::io::exportToObjFile( m, "bustedRE.obj" );

	delete m;
	delete mx;

	return 0;
}
