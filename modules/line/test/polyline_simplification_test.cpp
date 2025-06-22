

#include <gtest/gtest.h>

#include "line/polyline_simplification/polyline_simplification.h"


TEST(Test, test1)
{
  // std::vector<Point3D> points;
  int mode = 1;

  PolylineSimplification *ps;
  switch (mode)
  {
    case 0:
      ps = new RadialDistance();
      break;
    case 1:
      ps = new PerpendicularDistance();
      break;
    case 2:
      ps = new DouglasPeucker();
      break;
    default:
      ps = new RadialDistance();
      break;
  }

  ps->readPoly("../assets/polyline_simplification/poly.json");

  ps->simplifyBase();

  ps->writePoly("../assets/polyline_simplification/ps.json");
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}