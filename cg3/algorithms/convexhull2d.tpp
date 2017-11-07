#include "convexhull2d.h"

#include <vector>
#include <set>
#include <list>

#include "cg3/geometry/2d/point2d.h"

#include "cg3/geometry/geometryutils.h"

namespace cg3 {

/* ----- FUNCTION DECLARATION ----- */

template <class T, class Container>
inline bool grahamScanStep(
        Container& container,
        typename Container::iterator& it1);

template <class T, class Container>
inline void grahamScanOnContainer(Container& list);



/* ----- IMPLEMENTATION OF GRAHAM SCAN ----- */

/**
 * @brief Get the convex hull using Graham scan algorithm
 * @param[in] points Points of the shape
 * @param[out] convexHullPoints Points of the convex hull
 */
template <class T = double, class InputContainer, class OutputContainer>
void convexHull2D(const InputContainer& points, OutputContainer& convexHull) {

    //If there aren't more than 3 points, return the input points
    if (points.size() <= 3) {
        std::vector<Point2D<T>> sortedPoints(points.begin(), points.end());
        std::sort(sortedPoints.begin(), sortedPoints.end());

        convexHull = OutputContainer(sortedPoints.begin(), sortedPoints.end());
    }
    else {
        //Initialize upper convex hull
        std::list<Point2D<T>> upperConvexHull(points.begin(), points.end());
        upperConvexHull.sort();

        //Initialize lower convex hull, copying the upper
        std::list<Point2D<T>> lowerConvexHull(upperConvexHull.begin(), upperConvexHull.end());

        //Reverse the lower convex hull to get the opposite of the initialize upper
        std::reverse(lowerConvexHull.begin(), lowerConvexHull.end());

        //Graham scan on upper and lower convex hull
        grahamScanOnContainer<T>(lowerConvexHull);
        grahamScanOnContainer<T>(upperConvexHull);

        //Delete endpoints from lower convex hull
        lowerConvexHull.pop_back();
        lowerConvexHull.pop_front();

        //Concatenate upper and lower convex hull in the output list
        upperConvexHull.splice(upperConvexHull.end(), lowerConvexHull);

        convexHull = OutputContainer(upperConvexHull.begin(), upperConvexHull.end());
    }
}



/* ----- FUNCTIONS FOR GRAHAM SCAN ----- */

/**
 * @brief Step of the Graham scan
 * Erase a point (the predecessor of the iterator) if it stays
 * at the right of the two neighbor points
 *
 * @param[out] container Current iterating container
 * @param[out] it Iterator to be processed
 * @return True if a point has been erased, false otherwise
 */
template <class T, class Container>
inline bool grahamScanStep(
        Container& container,
        typename Container::iterator& it1)
{
    typename Container::iterator it2 = it1;
    it2--;
    if (it2 == container.begin())
        return false;

    typename Container::iterator it3 = it2;
    it3--;

    const Segment<Point2D<T>> seg(*it1, *it2);
    const Point2D<T>& point = *it3;

    if (cg3::isPointAtRight(seg, point)) {
        container.erase(it2);
        return true;
    }

    return false;
}

/**
 * @brief Graham scan on a list of points (upper or lower)
 *
 * @param[out] container Container that contains the points
 */
template <class T, class Container>
inline void grahamScanOnContainer(Container& container) {
    for (typename Container::iterator it = container.begin(); it != container.end(); it++) {
        bool done = false;
        while (it != container.begin() && !done) {
            done = !grahamScanStep<T>(container, it);
        }
    }
}






}