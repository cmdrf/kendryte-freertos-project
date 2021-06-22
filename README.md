# kendryte-freertos-project
Example project combining the Kendryte standalone SDK with an official FreeRTOS release.

An official FreeRTOS SDK for the K210 exists, but it is now deprecated. It's also rather
weird in some aspects. This project allows you to use the Kendryte K210 RISC-V processor
with the official FreeRTOS kernel and the still (somewhat) maintained standalone Kendryte
SDK.

Most of the CMake configuration in the SDK is replaced with more canonical ways of doing
things, e.g. the use of a toolchain file. This causes less issues e.g. with IDE
integration. A miniumum CMake version of 3.12 is required now.

## Building

After cloning the repository, make sure you have initialized and updated the submodules,
too, like so:
```
$ git submodule init
$ git submodule update
```

Create a build directory and run CMake and make:
```
$ mkdir build
$ cd build
$ cmake -DKENDRYTE_TOOLCHAIN=/absolute/path/to/kendryte/toolchain ..
$ make
```

Specifying `KENDRYTE_TOOLCHAIN` can be omitted if it is installed in the default location
`/opt/kendryte-toolchain`. The path must point to the toolchain directory, not the `bin`
directory inside it (as the Kendryte SDK requires).

At the time of this writing, after running `make`, a compiler error will occur in
`FreeRTOS-Kernel/portable/GCC/RISC-V/portmacro.h:85`. Simply commenting out the `#error`
line will solve this.

## Using for Your Own Projects

Copy the contents of or fork this repository. Place your source files into the `src`
directory and add the file names to `CMakeLists.txt` (where `src/main.c` already is).

## Known Issues

- The `#error` in `portmacro.h` described above.
- Saving and restoring floating point registers on context switches is untested.
- Current `develop` branch of the SDK does not work with this (it didn't even work on its
  own last time I tried).
- `configTICK_RATE_HZ` must be set higher by a factor 50 than you want it to be.
- `printf` and other APIs relying on syscall don't work after the scheduler has started. 
  This is due to the FreeRTOS trap handler intercepting the interrupts.
- Inter-processor interrupts probably won't work for the same reason.
