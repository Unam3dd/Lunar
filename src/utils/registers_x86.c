#include "lunar.h"

//////////////////////////////////
//
//		X86 REGISTER TABLE
//
//////////////////////////////////

const registers_t regs[] = {
	
	//////////////////////////////////
	//
	//	   [X86/x64] Registers
	//
	//////////////////////////////////

	{ { "AL", NULL }, "AX", "EAX", "RAX", "ST0", "MMX0", "XMM0", "YMM0", "ES", "CR0", "DR0" },
	{ { "CL", NULL }, "CX", "ECX", "RCX", "ST1", "MMX1", "XMM1", "YMM1", "CS", "CR1", "DR1" },
	{ { "DL", NULL }, "DX", "EDX", "RDX", "ST2", "MMX2", "XMM2", "YMM2", "SS", "CR2", "DR2" },
	{ { "BL", NULL }, "BX", "EBX", "RBX", "ST3", "MMX3", "XMM3", "YMM3", "DS", "CR3", "DR3" },
	{ { "AH", "SPL"}, "SP", "ESP", "RSP", "ST4", "MMX4", "XMM4", "YMM4", "FS", "CR4", "DR4" },
	{ { "CH", "BPL"}, "BP", "EBP", "RBP", "ST5", "MMX5", "XMM5", "YMM5", "GS", "CR5", "DR5" },
	{ { "DH", "SIL"}, "SI", "ESI", "RSI", "ST6", "MMX6", "XMM6", "YMM6", NULL, "CR6", "DR6" },
	{ { "BH", "DIL"}, "DI", "EDI", "RDI", "ST7", "MMX7", "XMM7", "YMM7", NULL, "CR7", "DR7" },

	//////////////////////////////////
	//
	//	[x86/x64] Extented Registers
	//
	//////////////////////////////////
	

	{ { "R8L", NULL}, "R8W", "R8D", "R8", NULL, "MMX0", "XMM8", "YMM8", "ES", "CR8", "DR8"},
	{ { "R9L", NULL}, "R9W", "R9D", "R9", NULL, "MMX1", "XMM9", "YMM9", "CS", "CR9", "DR9"},
	{ { "R10L", NULL}, "R10W", "R10D", "R10", NULL, "MMX2", "XMM10", "YMM10", "SS", "CR10", "DR10" },
	{ { "R11L", NULL}, "R11W", "R11D", "R11", NULL, "MMX3", "XMM11", "YMM11", "DS", "CR11", "DR11" },
	{ { "R12L", NULL}, "R12W", "R12D", "R12", NULL, "MMX4", "XMM12", "YMM12", "FS", "CR12", "DR12" },
	{ { "R13L", NULL}, "R13W", "R13D", "R13", NULL, "MMX5", "XMM13", "YMM13", "GS", "CR13", "DR13" },
	{ { "R14L", NULL}, "R14W", "R14D", "R14", NULL, "MMX6", "XMM14", "YMM14", NULL, "CR14", "DR14" },
	{ { "R15L", NULL}, "R15W", "R15D", "R15", NULL, "MMX7", "XMM15", "YMM15", NULL, "CR15", "DR15" },
	{ {NULL, NULL}, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}
};
