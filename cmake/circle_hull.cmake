
add_executable(circle_hull ${module_dir}/hull/circle_hull/circle_hull.cpp ${module_dir}/hull/test/circle_hull_test.cpp)
target_include_directories(circle_hull PUBLIC ${EIGEN3_INCLUDE_DIR} ${module_dir}/hull/circle_hull)