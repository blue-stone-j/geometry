cmake_minimum_required(VERSION 3.16.3)
project(geometry)

set(CMAKE_BUILD_TYPE "Release")
add_compile_options(-std=c++17)
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -pthread")


# pkg-config 是一个在 UNIX-like 系统中广泛使用的计算机工具，它帮助在编译阶段自动从已安装的库中获取关于编译器和链接器选项的信息。
# 这个工具设计用于通过一个中心化的方式管理软件库的元数据，如版本、描述、编译器和链接器的标志等。
find_package(PkgConfig)

# 1. 查询库信息：使用 pkg-config 来获取 jsoncpp 库的信息，包括编译标志（CFLAGS）、链接标志（LIBS）等。
# 2. 设置变量：根据查询到的信息，CMake 会设置一系列变量，这些变量使用 JSONCPP 作为前缀。例如，JSONCPP_INCLUDE_DIRS、JSONCPP_LIBRARY_DIRS 和 JSONCPP_LIBRARIES。
# pkg_check_modules(JSONCPP jsoncpp)

enable_testing()

set(modules_directory ${CMAKE_CURRENT_SOURCE_DIR}/modules)

include_directories(
  ${modules_directory}
)

function(get_functions module_directory function_names function_files)

    set(function_names_local "")
    set(function_files_local "")
    file(GLOB functions RELATIVE "${module_directory}" "${module_directory}/*")
    set(function_directories "")
    foreach(function ${functions})
        if(IS_DIRECTORY "${module_directory}/${function}" AND 
           NOT function STREQUAL "test" AND 
           NOT function STREQUAL "common" AND 
           NOT function STREQUAL "docs")
            list(APPEND function_names_local "${function}")
            file(GLOB_RECURSE temp_cpp_files "${module_directory}/${function}/*.cpp")
            list(APPEND function_files_local ${temp_cpp_files})
        endif()
    endforeach()
    # PARENT_SCOPE: sets a variable in the parent scope (i.e., the scope of the caller of the current function or macro), not the current one.
    set(function_names ${function_names_local} PARENT_SCOPE)
    set(function_files ${function_files_local} PARENT_SCOPE)

endfunction()

function(compile_module module_name module_include module_lib)

    set(function_names "")
    set(function_files "")
    get_functions(${modules_directory}/${module_name} function_names function_files)

    add_library(${module_name} SHARED ${function_files})
    target_link_libraries(${module_name} ${module_lib})
    target_include_directories(${module_name} PUBLIC ./include  ${module_include})
    install(TARGETS ${module_name} DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/)


    if(BUILD_TEST)
        foreach(function_name ${function_names})
            message(STATUS "${modules_directory}/${module_name}/${function_name}")
            file(GLOB_RECURSE function_cpp_files "${modules_directory}/${module_name}/${function_name}/*.cpp")
            add_executable(${module_name}_${function_name}_test
                           ${modules_directory}/${module_name}/test/${function_name}_test.cpp 
                           ${function_cpp_files})
            target_link_libraries(${module_name}_${function_name}_test ${module_lib} gtest gtest_main)
            target_include_directories(${module_name}_${function_name}_test PUBLIC ./include ${module_include})
            # Register test
            add_test(NAME ${function_name}Test COMMAND ${module_name}_${function_name}_test)
        endforeach()
    endif()

endfunction()

file(GLOB sub_elements RELATIVE "${modules_directory}" "${modules_directory}/*")
set(module_directories "")
foreach(sub_element ${sub_elements})
    if(IS_DIRECTORY "${modules_directory}/${sub_element}" AND EXISTS "${modules_directory}/${sub_element}/CMakeLists.txt")        
        list(APPEND module_directories "${modules_directory}/${sub_element}")
        add_subdirectory("${modules_directory}/${sub_element}")
    endif()
endforeach()