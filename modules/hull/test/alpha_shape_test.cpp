

#include <gtest/gtest.h>

#include "alpha_shape.h"

TEST(Test, test1)
{
  AlphaShape alpha_shape;
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}