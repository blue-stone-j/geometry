

# add_executable(alpha_shape ${module_dir}/hull/test/alpha_shape_test.cpp ${module_dir}/hull/alpha_shape/alpha_shape.cpp)
# target_include_directories(alpha_shape PUBLIC ${module_dir}/hull/alpha_shape)
# target_link_libraries(alpha_shape GTest::GTest GTest::Main)

set(module_name arc)
find_package(Eigen3 REQUIRED)
find_package(PCL REQUIRED)
set(arc_include ${EIGEN3_INCLUDE_DIRS} ${PCL_INCLUDE_DIRS})
set(arc_lib ${PCL_LIBRARIES})

compile_module(${module_name} "${arc_include}" "${arc_lib}")