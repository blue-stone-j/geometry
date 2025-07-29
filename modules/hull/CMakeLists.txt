

# add_executable(circle_hull ${module_dir}/hull/circle_hull/circle_hull.cpp ${module_dir}/hull/test/circle_hull_test.cpp)
# target_include_directories(circle_hull PUBLIC ${EIGEN3_INCLUDE_DIR} ${module_dir}/hull/circle_hull)
# target_link_libraries(circle_hull GTest::GTest GTest::Main)

# add_executable(convex_hull2d ${module_dir}/hull/convex_hull/convex_hull2d.cpp ${module_dir}/hull/test/convex_hull2d_test.cpp)
# target_include_directories(convex_hull2d PUBLIC ${EIGEN3_INCLUDE_DIR} ${module_dir}/hull/convex_hull)
# target_link_libraries(convex_hull2d GTest::GTest GTest::Main)

set(module_name hull)
find_package(Eigen3 REQUIRED)
pkg_check_modules(JSONCPP jsoncpp)
find_package(PCL REQUIRED)
set(hull_include ${EIGEN3_INCLUDE_DIRS} ${PCL_INCLUDE_DIRS})
set(hull_lib ${PCL_LIBRARIES})

compile_module(${module_name} "${hull_include}" "${hull_lib}")