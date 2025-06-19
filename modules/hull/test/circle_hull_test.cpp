
#include <iostream>

#include "hull/circle_hull/circle_hull.h"

int main(int argc, char const *argv[])
{
  CircleHull circle_hull;
  std::vector<PointT> points = {
      {1.0, 0.0}, // Point A
      {0, 1},     // Point B
      {0, -1},    // Point C
      {1, -1},    // Point C
      {5, 9}};

  circle_hull.processPoints(points);

  auto circle = circle_hull.getCircleHull();
  std::cout << circle.center << std::endl;
  std::cout << circle.radius << std::endl;

  return 0;
}