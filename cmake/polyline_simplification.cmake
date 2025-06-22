add_executable(polyline_simplification ${module_dir}/line/test/polyline_simplification_test.cpp ${module_dir}/line/polyline_simplification/polyline_simplification.cpp)
target_include_directories(polyline_simplification PUBLIC ${JSONCPP_INCLUDE_DIRS} ${module_dir}/polyline_simplification)
target_link_libraries(polyline_simplification ${JSONCPP_LIBRARIES})
target_link_libraries(polyline_simplification GTest::GTest GTest::Main)