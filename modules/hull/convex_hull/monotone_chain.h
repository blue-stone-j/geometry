
#ifndef MONOTONE_CHAIN_H
#define MONOTONE_CHAIN_H

#include <vector>
#include "common/point_definition.h"
#include "hull/common/common.hpp"

class MonotoneChain
{
 public:
  static std::vector<Point2D<float>> convex_hull(std::vector<Point2D<float>> &points);
};


#endif // MONOTONE_CHAIN_H