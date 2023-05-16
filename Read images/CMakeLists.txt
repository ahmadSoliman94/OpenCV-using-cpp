cmake_minimum_required(VERSION 3.10)
project(read_Img)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(read_Img read_Img.cpp)
target_link_libraries(read_Img ${OpenCV_LIBS})

