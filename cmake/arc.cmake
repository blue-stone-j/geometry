
set(arc_dir ${CMAKE_CURRENT_SOURCE_DIR}/modules/arc)

add_executable(min_arc ${arc_dir}/test/min_arc_test.cpp ${arc_dir}/min_arc/min_arc.cpp)
target_include_directories(min_arc PUBLIC ${arc_dir}/min_arc)
target_link_libraries(min_arc GTest::GTest GTest::Main)

add_executable(midpoint_angle ${arc_dir}/test/midpoint_angle_test.cpp ${arc_dir}/midpoint_angle/midpoint_angle.cpp)
target_include_directories(midpoint_angle PUBLIC ${arc_dir}/midpoint_angle)
target_link_libraries(midpoint_angle GTest::GTest GTest::Main)

# if(BUILD_TEST)
#   add_executable(cylinder_node test/cylinder_node.cpp src/cylinder.cpp)
#   target_link_libraries(cylinder_node ${PCL_LIBRARIES})
# endif()