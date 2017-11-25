/*
 * This file is part of cg3lib: https://github.com/cg3hci/cg3lib
 * @author    Stefano Nuvoli (stefano.nuvoli@gmail.com)
 */

#ifndef CG3_CGAL_CONVEXHULL2D_H
#define CG3_CGAL_CONVEXHULL2D_H


#include <vector>

#include "cg3/geometry/2d/point2d.h"

#include "cg3/meshes/dcel/dcel.h"



namespace cg3 {
namespace cgal {

template <class T = double, class InputContainer, class OutputContainer>
void getConvexHull2D(
        const InputContainer& points,
        OutputContainer& convexHull);

}
}


#include "cgal_convexhull2d.tpp"

#endif // CG3_CGAL_CONVEXHULL2D_H