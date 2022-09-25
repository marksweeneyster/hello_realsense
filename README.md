# hello_realsense
sandbox for developing apps with Intel's realsense SDK

## The RealSense build
I built the shared library version of realsense on an Ubuntu 20 machine
```
cmake ..  -DCMAKE_BUILD_TYPE=Release  -DBUILD_SHARED_LIBS=1 -DBUILD_WITH_OPENMP=1 -DBUILD_CV_EXAMPLES=1 -DBUILD_PCL_EXAMPLES=1 
          -DBUILD_PC_STITCHING=1 -DBUILD_PYTHON_BINDINGS=0 -DCMAKE_INSTALL_PREFIX:PATH=/home/mark/Dev/tools/librealsense_install
```
I found that trying to use ninja rather than Make for the generator fell down at build time for target libcurl

### dependencies 
```
> ldd librealsense2.so
        linux-vdso.so.1 (0x00007ffd1a15e000)
        libudev.so.1 => /lib/x86_64-linux-gnu/libudev.so.1 (0x00007f70d534f000)
        libusb-1.0.so.0 => /lib/x86_64-linux-gnu/libusb-1.0.so.0 (0x00007f70d5333000)
        libstdc++.so.6 => /lib/x86_64-linux-gnu/libstdc++.so.6 (0x00007f70d5151000)
        libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007f70d5002000)
        libgomp.so.1 => /lib/x86_64-linux-gnu/libgomp.so.1 (0x00007f70d4fc0000)
        libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x00007f70d4fa5000)
        libpthread.so.0 => /lib/x86_64-linux-gnu/libpthread.so.0 (0x00007f70d4f80000)
        libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f70d4d8e000)
        /lib64/ld-linux-x86-64.so.2 (0x00007f70d6803000)
        libdl.so.2 => /lib/x86_64-linux-gnu/libdl.so.2 (0x00007f70d4d88000)
```

## This project
To build targets in this project add the location of the RealSense install to the cmake command
```
cmake .. -DREALSENSE_DIR=/home/foobar/realsense_install
```
Where in this case `realsense_install` contains the `bin`, `lib`, and `include` folders for RealSense.

Executables built by this project:
- `hello_realsense` (very basic can I build and use the SDK, copied from rs examples)
- `capture` (nice rendering of depth and RGB. also copied from rs examples)
- `frame_time` (just print out the time to get frames)
