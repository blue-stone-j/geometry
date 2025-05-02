
#include <Eigen/Dense>

#include "circle_hull/circle_hull.h"

CircleHull::CircleHull() :
  circle_()
{
}

bool CircleHull::isInside(const Circle &c, const PointT &p)
{
  return (p - c.center).squaredNorm() <= c.radius * c.radius;
}

Circle CircleHull::circleFromTwoPoints(const PointT &p1, const PointT &p2)
{
  PointT center = (p1 + p2) / 2.0;
  double radius = (p1 - p2).norm() / 2.0;
  return Circle(center, radius);
}

Circle CircleHull::circleFromThreePoints(const PointT &p1, const PointT &p2, const PointT &p3)
{
  PointT d1 = p2 - p1, d2 = p3 - p1;
  Eigen::Matrix2d A;
  A << d1.x(), d1.y(), d2.x(), d2.y();

  PointT b = PointT(d1.squaredNorm(), d2.squaredNorm()) / 2.0;

  if (std::abs(A.determinant()) < 1e-9)
  {
    // Points are collinear; return a degenerate circle
    PointT center = (p1 + p3) / 2.0;
    double radius = (p1 - p3).norm() / 2.0;
    return Circle(center, radius);
  }

  PointT centerOffset = A.inverse() * b;
  PointT center       = p1 + centerOffset;
  double radius       = (center - p1).norm();
  return Circle(center, radius);
}

Circle CircleHull::welzlRecursive(std::vector<PointT> &P, std::vector<PointT> R, int n)
{
  if (n == 0 || R.size() == 3)
  {
    if (R.size() == 0)
    {
      return Circle();
    }
    if (R.size() == 1)
    {
      return Circle(R[0], 0);
    }
    if (R.size() == 2)
    {
      return circleFromTwoPoints(R[0], R[1]);
    }

    return circleFromThreePoints(R[0], R[1], R[2]);
  }

  PointT p = P[n - 1];
  Circle d = welzlRecursive(P, R, n - 1);

  if (isInside(d, p))
  {
    return d;
  }

  R.push_back(p);
  return welzlRecursive(P, R, n - 1);
}

Circle CircleHull::findMinimumEnclosingCircle()
{
  // Compute centroid
  Eigen::Vector2d centroid(0, 0);
  for (const auto &p : points_)
  {
    centroid += p;
  }
  centroid /= points_.size();

  std::sort(points_.begin(), points_.end(), [&](const Eigen::Vector2d &a, const Eigen::Vector2d &b) {
    return (a - centroid).squaredNorm() > (b - centroid).squaredNorm();
  });

  return welzlRecursive(points_, {}, points_.size());
}

bool CircleHull::processPoints(const std::vector<PointT> &points)
{
  // Check if the input points are empty
  if (points.size() == 0)
  {
    return false;
  }

  points_ = points;

  circle_ = findMinimumEnclosingCircle();

  return true;
}

Circle CircleHull::getCircleHull() const
{
  return circle_;
}