cmake_minimum_required(VERSION 3.7)

# Also suppresses "-rdynamic" compiler and linker flag.
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM Generic)

if(NOT DEFINED KENDRYTE_TOOLCHAIN)
	set(KENDRYTE_TOOLCHAIN /opt/kendryte-toolchain)
endif()
set(CMAKE_C_COMPILER ${KENDRYTE_TOOLCHAIN}/bin/riscv64-unknown-elf-gcc)
set(CMAKE_CXX_COMPILER ${KENDRYTE_TOOLCHAIN}/bin/riscv64-unknown-elf-g++)
set(CMAKE_LINKER ${KENDRYTE_TOOLCHAIN}/bin/riscv64-unknown-elf-ld)
set(CMAKE_OBJCOPY ${KENDRYTE_TOOLCHAIN}/bin/riscv64-unknown-elf-objcopy)
set(CMAKE_OBJDUMP ${KENDRYTE_TOOLCHAIN}/bin/riscv64-unknown-elf-objdump)

set(CMAKE_C_FLAGS_INIT
	"-mcmodel=medany -mabi=lp64f -march=rv64imafc -fno-common -ffunction-sections -fdata-sections -fstrict-volatile-bitfields -fno-zero-initialized-in-bss -ffast-math -fno-math-errno -fsingle-precision-constant"
)
set(CMAKE_CXX_FLAGS_INIT ${CMAKE_C_FLAGS_INIT})
set(CMAKE_EXE_LINKER_FLAGS_INIT
	"-nostartfiles -static -Wl,--gc-sections -Wl,-static -Wl,-EL -Wl,--no-relax"
)
#set(CMAKE_STATIC_LINKER_FLAGS_INIT ${CMAKE_EXE_LINKER_FLAGS_INIT})

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
