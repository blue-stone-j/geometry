
#include <cmath>
#include <iostream>

#include <gtest/gtest.h>

#include "arc/midpoint_angle/midpoint_angle.h"

TEST(Test, test1)
{
  double midAngle;

  // two angles
  double theta1 = -M_PI + 0.2;
  double theta2 = M_PI - 0.1;
  midAngle      = calculateMidpointAngle(theta1, theta2);
  std::cout << "Midpoint Angle: " << midAngle << " radians" << std::endl;

  // many angles
  std::vector<double> angles;
  angles.push_back(theta1);
  angles.push_back(theta2);
  midAngle = calculateAverageAngle(angles);
  std::cout << "Midpoint Angle: " << midAngle << " radians" << std::endl;

  // EXPECT_NEAR(midAngle, 0.0, 1e-6);
}
int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}