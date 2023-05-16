cmake_minimum_required(VERSION 3.15)
project ( Filters )
find_package ( OpenCV REQUIRED )
add_executable ( Filters filters.cpp )
target_link_libraries ( Filters ${OpenCV_LIBS} )

