cmake_minimum_required(VERSION 3.10)
project(operators)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(operators Sobel_Operator.cpp)
target_link_libraries(operators ${OpenCV_LIBS})

