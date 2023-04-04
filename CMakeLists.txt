cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(ColorPointCloudViewer)

find_package(PCL 1.2 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})


add_executable(pcdVisualizer main.cpp)

target_link_libraries(pcdVisualizer ${PCL_LIBRARIES})
