cmake_minimum_required(VERSION 2.8)
project(exponentiator)
enable_testing()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror -Wpedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra -Wswitch-default")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wunused -Wuninitialized")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wshadow -Wcast-align -Wparentheses")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

include(${CMAKE_CURRENT_LIST_DIR}/cmake/gtest.cmake)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

find_package(GMP REQUIRED)

# Executable build
add_executable(expo main.cpp exponentiator.cpp reverse.cpp)
target_link_libraries(expo ${GMP_LIBRARY})

# Test builds
add_executable(exponentiator_suite exponentiator.cpp exponentiator_tests.cpp reverse.cpp)
target_link_libraries(exponentiator_suite ${GTEST_BOTH_LIBRARIES} ${GMP_LIBRARY})
add_test(NAME exponentiator_suite COMMAND exponentiator_suite)

add_executable(reverse_suite reverse_tests.cpp reverse.cpp)
target_link_libraries(reverse_suite ${GTEST_BOTH_LIBRARIES})
add_test(NAME reverse_suite COMMAND reverse_suite)
