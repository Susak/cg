cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(convex-hull-example)

add_executable(graham_hull graham_hull.cpp)

add_executable(andrew_hull andrew_hull.cpp)
add_executable(quick_hull quick_hull.cpp)
target_link_libraries(quick_hull visualization ${GMP_LIBRARIES})
target_link_libraries(graham_hull visualization ${GMP_LIBRARIES})
target_link_libraries(andrew_hull visualization ${GMP_LIBRARIES})

