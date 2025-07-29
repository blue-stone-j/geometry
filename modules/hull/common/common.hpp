
#ifndef GEOMETRY_HULL_COMMON_HPP
#define GEOMETRY_HULL_COMMON_HPP

// Cross product to determine orientation
static int cross(const Point2D<float> &O, const Point2D<float> &A, const Point2D<float> &B)
{
  return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

#endif