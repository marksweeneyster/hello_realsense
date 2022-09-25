//
// Created by mark on 9/18/22.
//
#include <iostream>
#include <chrono>
#include <librealsense2/rs.hpp>

[[noreturn]]
int main() {
    std::cout << "Time for frame (\u03BCs)\n===================\n";

    using Clock = std::chrono::steady_clock;
    using std::chrono::time_point;
    using std::chrono::duration_cast;
    using std::chrono::milliseconds;
    using namespace std::literals::chrono_literals;

    std::string time_units = "\u03BCs";

    // Create a Pipeline - this serves as a top-level API for streaming and processing frames
    rs2::pipeline p;

    // Configure and start the pipeline
    p.start();

    while (true)
    {
        time_point<Clock> start = Clock::now();
        // Block program until frames arrive
        rs2::frameset frames = p.wait_for_frames();
        time_point<Clock> stop = Clock::now();
        auto diff = duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << '\t' << diff.count() << time_units << " \n";
    }
}
