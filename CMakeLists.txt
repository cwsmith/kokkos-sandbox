cmake_minimum_required(VERSION 3.1)
project(scalarToArray CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(${KOKKOS_PATH} ${CMAKE_BINARY_DIR}/kokkos)

message("CMAKE_CXX_COMPILER_ID ${CMAKE_CXX_COMPILER_ID}")
#the XL compiler does not support standard detection
if( CMAKE_CXX_COMPILER_ID STREQUAL "XL" )
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

message(STATUS "CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS}")

include_directories(${Kokkos_INCLUDE_DIRS_RET})
if(KOKKOS_ENABLE_CUDA)
  set(scalarToArray_tgt scalarToArray.gpu)
  add_definitions(-DGPU=1)
else()
  set(scalarToArray_tgt scalarToArray.host)
endif()
add_executable(${scalarToArray_tgt} scalarToArray.cpp)
set_property(TARGET ${scalarToArray_tgt} PROPERTY CXX_STANDARD_REQUIRED 11)
target_link_libraries(${scalarToArray_tgt} kokkos)
