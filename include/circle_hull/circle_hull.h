#ifndef CIRCLE_HULL_H
#define CIRCLE_HULL_H


#include <Eigen/Core>

#include <cstdlib>
#include <vector>

using PointT = Eigen::Vector2d;

struct Circle
{
  PointT center;
  float radius;

  Circle() :
    center(PointT(0, 0)), radius(0) {}
  Circle(const PointT &c, double r) :
    center(c), radius(r) {}
};

class CircleHull
{
 public:
  CircleHull();
  bool processPoints(const std::vector<PointT> &points);

  Circle getCircleHull() const;

 private:
  std::vector<PointT> points_;
  Circle circle_;

  // check if a point is inside or on the circle
  bool isInside(const Circle &c, const PointT &p);

  // Compute circle from 2 points
  Circle circleFromTwoPoints(const PointT &p1, const PointT &p2);

  // Compute circle from 3 points using circum center formula
  Circle circleFromThreePoints(const PointT &p1, const PointT &p2, const PointT &p3);

  // Recursive function for Welzl's Algorithm
  Circle welzlRecursive(std::vector<PointT> &P, std::vector<PointT> R, int n);

  // Entry function for computing the Minimum Enclosing Circle
  Circle findMinimumEnclosingCircle();
};



#endif