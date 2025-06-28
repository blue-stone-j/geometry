

add_executable(perpendicular_bisector ${module_dir}/line/test/perpendicular_bisector_test.cpp ${module_dir}/line/perpendicular_bisector/perpendicular_bisector.cpp)
target_include_directories(perpendicular_bisector PUBLIC ${module_dir}/line/perpendicular_bisector)
target_link_libraries(perpendicular_bisector GTest::GTest GTest::Main)

add_executable(polyline_simplification ${module_dir}/line/test/polyline_simplification_test.cpp ${module_dir}/line/polyline_simplification/polyline_simplification.cpp)
target_include_directories(polyline_simplification PUBLIC ${JSONCPP_INCLUDE_DIRS} ${module_dir}/polyline_simplification)
target_link_libraries(polyline_simplification ${JSONCPP_LIBRARIES} GTest::GTest GTest::Main)