
add_executable(circle_hull src/circle_hull/circle_hull.cpp test/circle_hull/circle_hull_test.cpp)
target_include_directories(circle_hull PUBLIC ${EIGEN3_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/include)