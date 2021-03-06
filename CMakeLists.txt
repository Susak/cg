cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(cg-library)

SET(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMake/Modules)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wall")

if(CMAKE_C_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_D MATCHES "Clang")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif()

ADD_DEFINITIONS(-pthread)
SET(CMAKE_SHARED_LINKER_FLAGS "-pthread ${CMAKE_SHARED_LINKER_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS "-pthread ${CMAKE_EXE_LINKER_FLAGS}")
SET(CMAKE_SHARED_LINKER_FLAGS "-U_undefined -undefined dynamic_lookup ${CMAKE_SHARED_LINKER_FLAGS}")

find_package(OpenGL REQUIRED)
find_package(GMP REQUIRED)

find_package(Qt4 COMPONENTS QtOpenGL QtCore QtGui REQUIRED)
include(${QT_USE_FILE})

find_package(Boost REQUIRED)

include_directories(include ${Boost_INCLUDE_DIR} ${GMP_INCLUDE_DIR})

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(examples)
