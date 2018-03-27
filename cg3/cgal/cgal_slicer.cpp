/*
 * This file is part of cg3lib: https://github.com/cg3hci/cg3lib
 * This Source Code Form is subject to the terms of the GNU GPL 3.0
 *
 * @author Alessandro Muntoni (muntoni.alessandro@gmail.com)
 */

#include "cgal_slicer.h"

namespace cg3 {

std::vector<std::vector<Pointd>> cgal::slicer::getPolylines(
        const std::string& inputOffFile,
        const Vec3& norm,
        double d)
{
    std::ifstream input(inputOffFile.c_str());
    Mesh mesh;
    if (!input || !(input >> mesh) || mesh.is_empty()) {
        std::cerr << "Not a valid off file." << std::endl;
        exit(1);
    }
    //std::vector< std::vector<Pointd> > result;
    //result = getPolylines2(mesh, norm, d);
    return getPolylines(mesh, norm, d);
}


std::vector<std::vector<Pointd>> cgal::slicer::getPolylines(
        const Mesh &mesh,
        const Vec3& norm,
        double d)
{

    // Slicer constructor from the mesh
    //CGAL::Polygon_mesh_slicer<Mesh, K> slicer(mesh);
    Polylines polylines;
    AABB_tree tree(edges(mesh).first, edges(mesh).second, mesh);
    //qDebug() << tree.size();
    CGAL::Polygon_mesh_slicer<Mesh, K> slicer_aabb(mesh, tree);
    slicer_aabb(K::Plane_3(norm.x(), norm.y(), norm.z(), d), std::back_inserter(polylines));
    std::vector< std::vector<Pointd> > result;
    for (std::vector<K::Point_3> singlePolyline : polylines){
        std::vector<Pointd> v;
        for (K::Point_3 point : singlePolyline){
            Pointd pres(point.x(), point.y(), point.z());
            v.push_back(pres);
        }
        result.push_back(v);
    }
    //qDebug() << result.size() << "result size";
    return result;
}

#ifdef CG3_DCEL_DEFINED
std::vector<std::vector<Pointd> > cgal::slicer::getPolylines(
        const Dcel &mesh,
        const Plane &p)
{
    return getPolylines(mesh, p.getNormal(), p.getD());
}

std::vector<std::vector<Pointd> > cgal::slicer::getPolylines(
        const Dcel &mesh,
        const Vec3 &norm,
        double d)
{
    Mesh m = cgal::surfaceMesh::getSurfaceMeshFromDcel(mesh);
    return getPolylines(m, norm, d);
}
#endif

}
