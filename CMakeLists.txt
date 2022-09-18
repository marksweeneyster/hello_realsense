cmake_minimum_required(VERSION 3.16)
project(hello_realsense)

set(CMAKE_CXX_STANDARD 17)

set(REALSENSE_DIR /home/mark/Dev/tools/librealsense_install)
set(OCV_DIR /home/mark/Dev/tools/opencv_install)

find_package(PkgConfig)

pkg_check_modules(RS2 REQUIRED realsense2)
pkg_check_modules(RS2GL REQUIRED realsense2-gl)

add_executable(frame_rate frame_rate.cpp)

target_include_directories(frame_rate PUBLIC ${RS2_INCLUDE_DIRS})
target_link_directories(frame_rate PUBLIC
        ${REALSENSE_DIR}/lib
        ${OCV_DIR}/lib
        )
target_link_options(frame_rate PUBLIC
         -Wl,-rpath=${REALSENSE_DIR}/lib -Wl,-rpath=${OCV_DIR}/lib)
target_link_libraries(frame_rate realsense2)

#############

add_executable(hello_realsense main.cpp)

target_include_directories(hello_realsense PUBLIC ${RS2_INCLUDE_DIRS})
target_link_directories(hello_realsense PUBLIC
        ${REALSENSE_DIR}/lib
        ${OCV_DIR}/lib
        )

target_link_options(hello_realsense PUBLIC
        -Wl,-rpath=${REALSENSE_DIR}/lib -Wl,-rpath=${OCV_DIR}/lib)
target_link_libraries(hello_realsense PUBLIC realsense2)

#############

add_executable(hello_capture capture.cpp)

target_include_directories(hello_capture PUBLIC
        ${RS2_INCLUDE_DIRS}
        rs_utilities
        )
target_link_directories(hello_capture PUBLIC
        ${REALSENSE_DIR}/lib
        ${OCV_DIR}/lib
        )

target_link_options(hello_capture PUBLIC
        -Wl,-rpath=${REALSENSE_DIR}/lib -Wl,-rpath=${OCV_DIR}/lib)
target_link_libraries(hello_capture PUBLIC
        realsense2
        realsense2-gl
        glfw GL GLU
        )
