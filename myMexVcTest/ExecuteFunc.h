#pragma once
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/Polygon_mesh_processing/self_intersections.h>
#include <fstream>
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Surface_mesh<K::Point_3>             Mesh;
typedef boost::graph_traits<Mesh>::face_descriptor face_descriptor;
namespace PMP = CGAL::Polygon_mesh_processing;

class ExecuteFunc
{
public:
	void myExcute();
};

void ExecuteFunc::myExcute()
{
	const char* filename = "C:/Library/CGAL/examples/Polygon_mesh_processing/data/pig.off";
	std::cout << "reading..." << std::endl;

	// 样例路径在你安装的cgal的examples文件夹下面
	std::ifstream input(filename);
	Mesh mesh;

	if (!input || !(input >> mesh) || !CGAL::is_triangle_mesh(mesh))
	{
		std::cerr << "Not a valid input file." << std::endl;
	}

	bool intersecting = PMP::does_self_intersect(mesh,
		PMP::parameters::vertex_point_map(get(CGAL::vertex_point, mesh)));
	std::cout
		<< (intersecting ? "There are self-intersections." : "There is no self-intersection.")
		<< std::endl;
	std::vector<std::pair<face_descriptor, face_descriptor> > intersected_tris;
	PMP::self_intersections(mesh, std::back_inserter(intersected_tris));
	std::cout << intersected_tris.size() << " pairs of triangles intersect." << std::endl;

	std::cout << "successful." << std::endl;
}

