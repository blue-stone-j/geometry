
#include "hull/convex_hull/monotone_chain.h"
#include <algorithm>



// Compute the convex hull using Andrew's monotone chain
std::vector<Point2D<float>> convexHull(std::vector<Point2D<float>> points)
{
  int n = points.size();
  if (n < 3)
  {
    return points;
  }

  std::sort(points.begin(), points.end());

  std::vector<Point2D<float>> hull;

  // Build the lower hull
  for (const auto &p : points)
  {
    while (hull.size() >= 2 && cross(hull[hull.size() - 2], hull.back(), p) <= 0)
      hull.pop_back();
    hull.push_back(p);
  }

  // Build the upper hull
  size_t lowerSize = hull.size();
  for (int i = n - 2; i >= 0; i--)
  {
    while (hull.size() > lowerSize && cross(hull[hull.size() - 2], hull.back(), points[i]) <= 0)
      hull.pop_back();
    hull.push_back(points[i]);
  }

  hull.pop_back(); // Remove duplicate last point
  return hull;
}