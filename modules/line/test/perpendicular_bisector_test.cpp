

#include <gtest/gtest.h>

#include "line/perpendicular_bisector/perpendicular_bisector.h"

TEST(Test, test1)
{
  Point A = {1, 5};
  Point B = {3, 4};
  findPerpendicularBisector(A, B);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}