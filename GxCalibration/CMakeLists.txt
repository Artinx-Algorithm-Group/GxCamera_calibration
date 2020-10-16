cmake_minimum_required(VERSION 3.0.0)

project(cmake_proj_template)


# set(PROJECT_BINARY_DIR ./build)

set(OpenCV_DIR set(OpenCV_DIR ~/opencv4/opencv-4.4.0/build))
find_package(OpenCV 4 REQUIRED)


add_subdirectory(src)

include_directories(OpenCV_INCLUDE_DIRS)
include_directories(./inc)
include_directories(./inc/camera_inc)

# link_libraries(libgxiapi.so)


