cmake_minimum_required(VERSION 3.16)
project(hello_realsense)

set(CMAKE_CXX_STANDARD 17)

message(STATUS "RealSense dir: ${REALSENSE_DIR}")
message(STATUS "OpenCV dir: ${OCV_DIR}")

#############

add_executable(frame_time src/frame_time.cpp)

target_include_directories(frame_time PUBLIC
        ${REALSENSE_DIR}/include
        )
target_link_directories(frame_time PUBLIC
        ${REALSENSE_DIR}/lib
        )
target_link_options(frame_time PUBLIC
         -Wl,-rpath=${REALSENSE_DIR}/lib)
target_link_libraries(frame_time PUBLIC realsense2)

#############

add_executable(hello_realsense src/hello_realsense.cpp)

target_include_directories(hello_realsense PUBLIC
        ${REALSENSE_DIR}/include
        )
target_link_directories(hello_realsense PUBLIC
        ${REALSENSE_DIR}/lib
        )
target_link_options(hello_realsense PUBLIC
        -Wl,-rpath=${REALSENSE_DIR}/lib )
target_link_libraries(hello_realsense PUBLIC realsense2)

#############

add_executable(capture src/capture.cpp)

target_include_directories(capture PUBLIC
        ${REALSENSE_DIR}/include
        rs_utilities
        )
target_link_directories(capture PUBLIC
        ${REALSENSE_DIR}/lib
        ${OCV_DIR}/lib
        )
target_link_options(capture PUBLIC
        -Wl,-rpath=${REALSENSE_DIR}/lib
        )
target_link_libraries(capture PUBLIC
        realsense2
        glfw GL GLU
        )
