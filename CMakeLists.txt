# Minimum cmake version requiered
cmake_minimum_required(VERSION 3.18.4)

# Project name
project(Cpp-Buffer)

# Variables
set (cpp_buffer_VERSION_MAJOR 1)
set (cpp_buffer_VERSION_MINOR 0)

# Generate config.h file
configure_file (${PROJECT_SOURCE_DIR}/config.h.in ${PROJECT_SOURCE_DIR}/config.h)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in ${PROJECT_SOURCE_DIR}/googletest/googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/googletest/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/googletest/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${PROJECT_SOURCE_DIR}/googletest/googletest-src
                 ${PROJECT_SOURCE_DIR}/googletest/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()

add_subdirectory (${PROJECT_SOURCE_DIR}/modules/functions)
add_subdirectory (${PROJECT_SOURCE_DIR}/modules/Data)

# Executable file generation
add_executable(cpp-buffer main.cpp)
target_link_libraries(cpp-buffer FunctionsLib DataLib)
add_executable(test test.cpp)
target_link_libraries(test gtest_main FunctionsLib DataLib)
