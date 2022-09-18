# hello_realsense
sandbox for developing apps with Intel's realsense SDK

A bit of a hack at the moment but you can replace the `/home/mark/Dev/tools/librealsense_install` line in CMakeLists with the location for realsense on other machines.

I built the shared library version of realsense on an Ubuntu 20 machine
```
cmake ..  -DCMAKE_BUILD_TYPE=Release  -DBUILD_SHARED_LIBS=1 -DBUILD_WITH_OPENMP=1 -DBUILD_CV_EXAMPLES=1 -DBUILD_PCL_EXAMPLES=1 
          -DBUILD_PC_STITCHING=1 -DBUILD_PYTHON_BINDINGS=0 -DCMAKE_INSTALL_PREFIX:PATH=/home/mark/Dev/tools/librealsense_install
```
I found that trying to use ninja rather than Make for the generator fell down at build time for target libcurl

I link to OpenCV but it's a placeholder that may go away.  It's not needed by the three current executables
- `hello_realsense` (very basic can I build and use the SDK, copied from rs examples)
- `hello_capture` (nice GL rendering of depth and RGB. also copied from rs examples)
- `frame_rate` (actually frame time, never divide in a loop)
