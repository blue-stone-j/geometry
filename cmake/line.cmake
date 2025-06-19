

add_executable(perpendicular_bisector ${module_dir}/line/test/perpendicular_bisector_test.cpp ${module_dir}/line/perpendicular_bisector/perpendicular_bisector.cpp)
target_include_directories(perpendicular_bisector PUBLIC ${module_dir}/line/perpendicular_bisector)

