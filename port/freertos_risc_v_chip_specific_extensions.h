#ifndef __FREERTOS_RISC_V_CHIP_SPECIFIC_EXTENSIONS_H__
#define __FREERTOS_RISC_V_CHIP_SPECIFIC_EXTENSIONS_H__

#define portasmHAS_SIFIVE_CLINT 1
#define portasmHAS_MTIME 1
#define portasmADDITIONAL_CONTEXT_SIZE 32
#define portasmHANDLE_INTERRUPT external_interrupt_handler

.macro portasmSAVE_ADDITIONAL_REGISTERS
	addi    sp,  sp, -(portasmADDITIONAL_CONTEXT_SIZE * portWORD_SIZE)

	fsd     f0,   1 * portWORD_SIZE(sp)
	fsd     f1,   2 * portWORD_SIZE(sp)
	fsd     f2,   3 * portWORD_SIZE(sp)
	fsd     f3,   4 * portWORD_SIZE(sp)
	fsd     f4,   5 * portWORD_SIZE(sp)
	fsd     f5,   6 * portWORD_SIZE(sp)
	fsd     f6,   7 * portWORD_SIZE(sp)
	fsd     f7,   8 * portWORD_SIZE(sp)
	fsd     f8,   9 * portWORD_SIZE(sp)
	fsd     f9,  10 * portWORD_SIZE(sp)
	fsd     f10, 11 * portWORD_SIZE(sp)
	fsd     f11, 12 * portWORD_SIZE(sp)
	fsd     f12, 13 * portWORD_SIZE(sp)
	fsd     f13, 14 * portWORD_SIZE(sp)
	fsd     f14, 15 * portWORD_SIZE(sp)
	fsd     f15, 16 * portWORD_SIZE(sp)
	fsd     f16, 17 * portWORD_SIZE(sp)
	fsd     f17, 18 * portWORD_SIZE(sp)
	fsd     f18, 19 * portWORD_SIZE(sp)
	fsd     f19, 20 * portWORD_SIZE(sp)
	fsd     f20, 21 * portWORD_SIZE(sp)
	fsd     f21, 22 * portWORD_SIZE(sp)
	fsd     f22, 23 * portWORD_SIZE(sp)
	fsd     f23, 24 * portWORD_SIZE(sp)
	fsd     f24, 25 * portWORD_SIZE(sp)
	fsd     f25, 26 * portWORD_SIZE(sp)
	fsd     f26, 27 * portWORD_SIZE(sp)
	fsd     f27, 28 * portWORD_SIZE(sp)
	fsd     f28, 29 * portWORD_SIZE(sp)
	fsd     f29, 30 * portWORD_SIZE(sp)
	fsd     f30, 31 * portWORD_SIZE(sp)
	fsd     f31, 32 * portWORD_SIZE(sp)
.endm

.macro portasmRESTORE_ADDITIONAL_REGISTERS
	fld     f0,   1 * portWORD_SIZE(sp)
	fld     f1,   2 * portWORD_SIZE(sp)
	fld     f2,   3 * portWORD_SIZE(sp)
	fld     f3,   4 * portWORD_SIZE(sp)
	fld     f4,   5 * portWORD_SIZE(sp)
	fld     f5,   6 * portWORD_SIZE(sp)
	fld     f6,   7 * portWORD_SIZE(sp)
	fld     f7,   8 * portWORD_SIZE(sp)
	fld     f8,   9 * portWORD_SIZE(sp)
	fld     f9,  10 * portWORD_SIZE(sp)
	fld     f10, 11 * portWORD_SIZE(sp)
	fld     f11, 12 * portWORD_SIZE(sp)
	fld     f12, 13 * portWORD_SIZE(sp)
	fld     f13, 14 * portWORD_SIZE(sp)
	fld     f14, 15 * portWORD_SIZE(sp)
	fld     f15, 16 * portWORD_SIZE(sp)
	fld     f16, 17 * portWORD_SIZE(sp)
	fld     f17, 18 * portWORD_SIZE(sp)
	fld     f18, 19 * portWORD_SIZE(sp)
	fld     f19, 20 * portWORD_SIZE(sp)
	fld     f20, 21 * portWORD_SIZE(sp)
	fld     f21, 22 * portWORD_SIZE(sp)
	fld     f22, 23 * portWORD_SIZE(sp)
	fld     f23, 24 * portWORD_SIZE(sp)
	fld     f24, 25 * portWORD_SIZE(sp)
	fld     f25, 26 * portWORD_SIZE(sp)
	fld     f26, 27 * portWORD_SIZE(sp)
	fld     f27, 28 * portWORD_SIZE(sp)
	fld     f28, 29 * portWORD_SIZE(sp)
	fld     f29, 30 * portWORD_SIZE(sp)
	fld     f30, 31 * portWORD_SIZE(sp)
	fld     f31, 32 * portWORD_SIZE(sp)

	addi    sp, sp, (portasmADDITIONAL_CONTEXT_SIZE * portWORD_SIZE )
.endm
#endif
