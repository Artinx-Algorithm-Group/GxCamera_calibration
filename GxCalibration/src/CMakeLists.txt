cmake_minimum_required(VERSION 3.0.0)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/exe)

include_directories(../inc)
include_directories(../inc/camera_inc)

add_executable(main1_initboard main1_initboard.cpp)
target_link_libraries(main1_initboard ${OpenCV_LIBS})


add_executable(main2_takeImgs main2_takeImgs.cpp GxCamera.cpp)
target_link_libraries(main2_takeImgs libgxiapi.so)  ## /usr/lib/libgxiapi.so
target_link_libraries(main2_takeImgs ${OpenCV_LIBS})


add_executable(main3_calibration main3_calibration.cpp)
target_link_libraries(main3_calibration ${OpenCV_LIBS})

