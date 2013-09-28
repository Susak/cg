cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(convex-hull-example)
add_executable (douglas_peucker, douglas_peucker.cpp)

target_link_libraries(douglas_peucker, visualization ${GMP_LIBRARIES})
