/**
  * This file is part of cg3lib: https://github.com/cg3hci/cg3lib
  * This Source Code Form is subject to the terms of the GNU GPL 3.0
  *
  * @author Alessandro Muntoni (muntoni.alessandro@gmail.com)
  */
#ifndef CG3_SEGMENT2D_H
#define CG3_SEGMENT2D_H

#include "../segment.h"

namespace cg3 {

template <class T>
using Segment2D = Segment<Point2D<T>>;

typedef Segment2D<double> Segment2Dd;

typedef Segment2D<double> Segment2Di;


}
#endif // CG3_SEGMENT2D_H
