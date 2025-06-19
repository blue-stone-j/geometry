

add_executable(alpha_shape ${module_dir}/hull/test/alpha_shape_test.cpp ${module_dir}/hull/alpha_shape/alpha_shape.cpp)
target_include_directories(alpha_shape PUBLIC ${module_dir}/hull/alpha_shape)