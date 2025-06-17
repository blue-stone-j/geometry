#ifndef POINT_DEFINITION_H
#define POINT_DEFINITION_H


template <typename T>
struct Point2D
{
  T x = 0;
  T y = 0;
  bool operator<(const Point2D &point) const
  {
    return x < point.x || (x == point.x && y < point.y);
  }
};

#endif