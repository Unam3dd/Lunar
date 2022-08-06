
//////////////////////////////////
//
//	  X86 (32bits)
//	  Mnemonic Instruction
//
//////////////////////////////////

#include "lunar.h"

//////////////////////////////////
//
//	List of [x86] Instructions only
//
//////////////////////////////////


const mnemonic_t mnemonics32[] = {
	
	//////////////////////////////////
	//
	//	x86 Mnemonic Instructions
	//
	//////////////////////////////////
	
	{"ADD",   3},
	{"PUSH",  4},
	{"POP",   3},
	{"OR",    2},
	{"ADC",   3},
	{"SBB",   3},
	{"AND",   3},
	{"DAA",   3},
	{"SUB",   3},
	{"DAS",   3},
	{"XOR",   3},
	{"AAA",   3},
	{"CMP",   3},
	{"AAS",   3},
	{"INC",   3},
	{"DEC",   3},
	{"PUSHA", 5},
	{"PUSHAD",6},
	{"POPA",  4},
	{"POPAD", 5},
	{"BOUND", 5},
	{"ARPL",  4},
	{"IMUL",  4},
	{"INS",   3},
	{"INSB",  4},
	{"INSW",  4},
	{"INSD",  4},
	{"OUTS",  4},
	{"OUTSB", 5},
	{"OUTSW", 5},
	{"OUTSD", 5},
	{"JO",    2},
	{"JNO",   3},
	{"JB",    2},
	{"JNAE",  4},
	{"JC",    2},
	{"JNB",   3},
	{"JAE",   3},
	{"JNC",   3},
	{"JZ",    2},
	{"JE",    2},
	{"JNZ",   3},
	{"JNE",   3},
	{"JBE",   3},
	{"JNA",   3},
	{"JNBE",  4},
	{"JA",    2},
	{"JS",    2},
	{"JNS",   3},
	{"JP",    2},
	{"JPE",   3},
	{"JNP",   3},
	{"JPO",   3},
	{"JL",    2},
	{"JNGE",  4},
	{"JNL",   3},
	{"JGE",   3},
	{"JLE",   3},
	{"JNG",   3},
	{"JNLE",  4},
	{"JG",    2},
	{"TEST",  4},
	{"XCHG",  4},
	{"MOV",   3},
	{"LEA",   3},
	{"NOP",   3},
	{"PAUSE", 5},
	{"CBW",   3},
	{"CWDE",  4},
	{"CWD",   3},
	{"CDQ",   3},
	{"CALLF", 5},
	{"FWAIT", 5},
	{"WAIT",  4},
	{"PUSHF", 5},
	{"PUSHFD",6},
	{"POPF",  4},
	{"POPFD", 5},
	{"SAHF",  4},
	{"LAHF",  4},
	{"MOVS",  4},
	{"MOVSB", 5},
	{"MOVSW", 5},
	{"MOVSD", 5},
	{"CMPS",  4},
	{"CMPSB", 5},
	{"CMPSW", 5},
	{"CMPSD", 5},
	{"STOS",  4},
	{"STOSB", 5},
	{"STOSW", 5},
	{"STOSD", 5},
	{"LODS",  4},
	{"LODSB", 5},
	{"LODSW", 5},
	{"LODSD", 5},
	{"SCAS",  4},
	{"SCASB", 5},
	{"SCASW", 5},
	{"SCASD", 5},
	{"ROL",   3},
	{"ROR",   3},
	{"RCL",   3},
	{"RCR",   3},
	{"SHL",   3},
	{"SAL",   3},
	{"SHR",   3},
	{"SAR",   3},
	{"RETN",  4},
	{"LES",   3},
	{"LDS",   3},
	{"ENTER", 5},
	{"LEAVE", 5},
	{"RETF",  4},
	{"INT",   3},
	{"INTO",  4},
	{"IRET",  4},
	{"IRETD", 5},
	{"AAM",   3},
	{"AMX",   3},
	{"AAD",   3},
	{"ADX",   3},
	{"SALC",  4},
	{"SETALC",6},
	{"XLAT",  4},
	{"XLATB", 5},
	{"FADD",  4},
	{"FMUL",  4},
	{"FCOM",  4},
	{"FCOMP", 5},
	{"FSUB",  4},
	{"FSUBR", 5},
	{"FDIV",  4},
	{"FDIVR", 5},
	{"FLD",   3},
	{"FXCH",  4},
	{"FST",   3},
	{"FNOP",  4},
	{"FSTP",  4},
	{"FSTP1", 5},
	{"FLDENV",6},
	{"FCHS",  4},
	{"FABS",  4},
	{"FTST",  4},
	{"FXAM",  4},
	{"FLDCW", 5},
	{"FLD1",  4},
	{"FLD2T", 5},
	{"FLD2E", 5},
	{"FLDPI", 5},
	{"FLDG2", 5},
	{"FLDN2", 5},
	{"FLDZ",  4},
	{"FNSTENV",7},
	{"FSTENV", 6},
	{"F2XM1",  5},
	{"FYL2X",  5},
	{"FPTAN",  5},
	{"FPATAN", 6},
	{"FXTRACT",7},
	{"FPREM1", 6},
	{"FDECSTP",7},
	{"FINCSTP",7},
	{"FNSTCW",6},
	{"FSTCW", 5},
	{"FPREM", 5},
	{"FYL2XP1",7},
	{"FSQRT", 5},
	{"FSINCOS",7},
	{"FRNDINT",7},
	{"FSCALE", 6},
	{"FSIN",   4},
	{"FCOS",   4},
	{"FIADD",  5},
	{"FCMOVB", 6},
	{"FIMUL",  5},
	{"FCMOVE", 6},
	{"FICOM",  5},
	{"FCMOVBE",7},
	{"FICOMP", 6},
	{"FCMOVU", 6},
	{"FISUB",  5},
	{"FISUBR", 6},
	{"FUCOMPP",7},
	{"FIDIV",  5},
	{"FIDIVR", 6},
	{"FILD",   4},
	{"FCMOVNB",7},
	{"FISTTP", 6},
	{"FCMOVNE",7},
	{"FIST",   4},
	{"FCMOVNBE",8},
	{"FISTP",  5},
	{"FCMOVNU",7},
	{"FNENI",  5},
	{"FNDISI", 6},
	{"FNCLEX", 6},
	{"FCLEX",  5},
	{"FNINIT", 6},
	{"FINIT",  5},
	{"FNSETPM",7},
	{"FLD",    3},
	{"FUCOMI", 6},
	{"FCOMI",  5},
	{"FSTP",   4},
	{"FADD",   4},
	{"FMUL",   4},
	{"FCOM",   4},
	{"FCOM2",  5},
	{"FCOMP",  5},
	{"FCOMP3", 6},
	{"FSUB",   4},
	{"FSUBR",  5},
	{"FDIV",   4},
	{"FDIVR",  5},
	{"FFREE",  5},
	{"FISTTP", 6},
	{"FXCH4",  5},
	{"FRSTOR", 6},
	{"FUCOM",  5},
	{"FUCOMP", 6},
	{"FNSAVE", 6},
	{"FSAVE",  5},
	{"FNSTW",  5},
	{"FSTSW",  5},
	{"FADDP",  5},
	{"FMULP",  5},
	{"FCOMP5", 6},
	{"FCOMPP", 6},
	{"FSUBRP", 6},
	{"FSUBP",  5},
	{"FDIVRP", 6},
	{"FDIVP",  5},
	{"FFREEP", 6},
	{"FXCH7",  5},
	{"FSTP8",  5},
	{"FSTP9",  5},
	{"FBLD",   4},
	{"FNSTSW", 6},
	{"FSTSW",  5},
	{"FUCOMIP",7},
	{"FBSTP",  5},
	{"FCOMIP", 6},
	{"LOOPNZ", 6},
	{"LOOPNE", 6},
	{"LOOPZ",  5},
	{"LOOPE",  5},
	{"LOOP",   4},
	{"JCXZ",   4},
	{"JECXZ",  5},
	{"IN",     2},
	{"OUT",    3},
	{"CALL",   4},
	{"JMP",    3},
	{"JMPF",   4},
	{"INT1",   4},
	{"ICEBP",  5},
	{"REPNZ",  5},
	{"REPNE",  5},
	{"REP",    3},
	{"HLT",    3},
	{"CMC",    3},
	{"NOT",    3},
	{"NEG",    3},
	{"MUL",    3},
	{"DIV",    3},
	{"IDIV",   4},
	{"CLC",    3},
	{"STC",    3},
	{"CLI",    3},
	{"STI",    3},
	{"CLD",    3},
	{"STD",    3},
	{"SLDT",   4},
	{"STR",    3},
	{"LLDT",   4},
	{"LTR",    3},
	{"VERR",   4},
	{"VERW",   4},
	{"SGDT",   4},
	{"VMCALL", 6},
	{"VMLAUNCH",8},
	{"VMRESUME",8},
	{"VMXOFF",  6},
	{"SIDT",    4},
	{"MONITOR", 7},
	{"MWAIT",   5},
	{"LGDT",    4},
	{"XGETBV",  6},
	{"XSETBV",  6},
	{"LIDT",    4},
	{"SMSW",    4},
	{"LMSW",    4},
	{"INVLPG",  6},
	{"RDTSCP",  6},
	{"LAR",     3},
	{"LSL",     3},
	{"CLTS",    4},
	{"INVD",    4},
	{"WBINVD",  6},
	{"UD2",     3},
	{"MOVUPS",  6},
	{"MOVSS",   5},
	{"MOVUPD",  6},
	{"MOVSD",   5},
	{"MOVHLPS", 7},
	{"MOVLPS",  6},
	{"MOVLPD",  6},
	{"MOVDDUP", 7},
	{"MOVSLDUP",8},
	{"MOVLPS",  6},
	{"MOVLPD",  6},
	{"UNPCKLPS",8},
	{"UNPCKLPD",8},
	{"UNPCKHPS",8},
	{"UNPCKHPD",8},
	{"MOVHPS",  6},
	{"MOVHPD",  6},
	{"PREFETCHNTA", 11},
	{"PREFETCHT0", 10},
	{"PREFETCHT1", 10},
	{"PREFETCHT2", 10},
	{"HINT_NOP", 8},
	{"MOVAPS",   6},
	{"MOVAPD",   6},
	{"CVTPI2PS", 8},
	{"CVTSI2SS", 8},
	{"CVTPI2PD", 8},
	{"CVTSI2SD", 8},
	{"MOVNTPS",  7},
	{"MOVNTPD",  7},
	{"CVTTPS2PI",9},
	{"CVTTSS2SI",9},
	{"CVTTPD2PI",9},
	{"CVTTSD2SI",9},
	{"UCOMISS",  6},
	{"UCOMISD",  6},
	{"WRMSR",    5},
	{"RDTSC",    5},
	{"RDMSR",    5},
	{"RDPMC",    5},
	{"SYSENTER", 8},
	{"SYSEXIT",  7},
	{"GETSEC",   6},
	{"PSHUFB",   6},
	{"PHADDW",   6},
	{"PHADDD",   6},
	{"PHADDSW",  7},
	{"PMADDUBSW",9},
	{"PHSUBW",   6},
	{"PHSUBD",   6},
	{"PSIGNB",   6},
	{"PSIGNW",   6},
	{"PSIGND",   6},
	{"PMULHRSW", 8},
	{"PBLENDVB", 8},
	{"BLENDVPS", 8},
	{"BLENDVPD", 8},
	{"PTEST",    5},
	{"PABSB",    5},
	{"PABSW",    5},
	{"PABSD",    5},
	{"PMOVSXBW", 8},
	{"PMOVSXBD", 8},
	{"PMOVSXBQ", 8},
	{"PMOVSXWD", 8},
	{"PMOVSXWQ", 8},
	{"PMOVSXDQ", 8},
	{"PMULDQ",   6},
	{"PCMPEQQ",  7},
	{"MOVNTDQA", 8},
	{"PACKUSDW", 8},
	{"PMOVZXBW", 8},
	{"PMOVZXBD", 8},
	{"PMOVZXBQ", 8},
	{"PMOVZXWD", 8},
	{"PMOVZXWQ", 8},
	{"PMOVZXDQ", 8},
	{"PCMPGTQ",  7},
	{"PMINSB",   6},
	{"PMINSD",   6},
	{"PMINUW",   6},
	{"PMINUD",   6},
	{"PMAXSB",   6},
	{"PMAXSD",   6},
	{"PMAXUW",   6},
	{"PMAXUD",   6},
	{"PMULLD",   6},
	{"PHMINPOSUW",10},
	{"INVEPT", 6},
	{"INVVPID",7},
	{"MOVBE",  5},
	{"CRC32",  5},
	{"ROUNDPS",7},
	{"ROUNDPD",7},
	{"ROUNDSS",7},
	{"ROUNDSD",7},
	{"BLENDPS",7},
	{"BLENDPD",7},
	{"PBLENDW",7},
	{"PALIGNR",7},
	{"PEXTRB", 6},
	{"PEXTRW", 6},
	{"PEXTRD", 6},
	{"PEXTRQ", 6},
	{"EXTRACTPS",9},
	{"PINSRB", 6},
	{"INSERTPS",8},
	{"PINSRD", 6},
	{"PINSRQ", 6},
	{"DPPS",   4},
	{"DPPD",   4},
	{"MPSADBW",7},
	{"PCMPESTRM",9},
	{"PCMPESTRI",9},
	{"PCMPISTRM",9},
	{"PCMPISTRI",9},
	{"CMOVO",    5},
	{"CMOVNO",   6},
	{"CMOVB",    5},
	{"CMOVNAE",  7},
	{"CMOVC",    5},
	{"CMOVNB",   6},
	{"CMOVAE",   6},
	{"CMOVNC",   6},
	{"CMOVZ",    5},
	{"CMOVE",    5},
	{"CMOVNZ",   6},
	{"CMOVNE",   6},
	{"CMOVNBE",  7},
	{"CMOVA",    5},
	{"CMOVNA",   5},
	{"CMOVBE",   6},
	{"CMOVS",    5},
	{"CMOVNS",   6},
	{"CMOVP",    5},
	{"CMOVPE",   6},
	{"CMOVNP",   6},
	{"CMOVPO",   6},
	{"CMOVL",    5},
	{"CMOVNGE",  7},
	{"CMOVNL",   6},
	{"CMOVGE",   6},
	{"CMOVLE",   6},
	{"CMOVNG",   6},
	{"CMOVNLE",  7},
	{"CMOVG",    5},
	{"MOVMSKPS", 8},
	{"MOVMSKPD", 8},
	{"SQRTPS",   6},
	{"SQRTSS",   6},
	{"SQRTPD",   6},
	{"SQRTSD",   6},
	{"RSQRTPS",  7},
	{"RSQRTSS",  7},
	{"RCPPS",    5},
	{"RCPSS",    5},
	{"ANDPS",    5},
	{"ANDPD",    5},
	{"ANDNPS",   6},
	{"ANDNPD",   6},
	{"ORPS",     4},
	{"ORPD",     4},
	{"XORPS",    5},
	{"XORPD",    5},
	{"ADDPS",    5},
	{"ADDSS",    5},
	{"ADDPD",    5},
	{"ADDSD",    5},
	{"MULPS",    5},
	{"MULSS",    5},
	{"MULPD",    5},
	{"MULSD",    5},
	{"CVTPS2PD", 8},
	{"CVTPD2PS", 8},
	{"CVTSS2SD", 8},
	{"CVTSD2SS", 8},
	{"CVTDQ2PS", 8},
	{"CVTPS2DQ", 8},
	{"CVTTPS2DQ",8},
	{"SUBPS",    5},
	{"SUBSS",    5},
	{"SUBPD",    5},
	{"SUBSD",    5},
	{"MINPS",    5},
	{"MINSS",    5},
	{"MINPD",    5},
	{"MINSD",    5},
	{"DIVPS",    5},
	{"DIVSS",    5},
	{"DIVPD",    5},
	{"DIVSD",    5},
	{"MAXPS",    5},
	{"MAXSS",    5},
	{"MAXPD",    5},
	{"MAXSD",    5},
	{"PUNPCKLBW",9},
	{"PUNPCKLBW",9},
	{"PUNPCKLWD",9},
	{"PUNPCKLWD",9},
	{"PUNPCKLDQ",9},
	{"PUNPCKLDQ",9},
	{"PACKSSWB", 8},
	{"PACKSSWB", 8},
	{"PCMPGTB",  7},
	{"PCMPGTW",  7},
	{"PCMPGTD",  7},
	{"PACKUSWB", 8},
	{"PUNPCKHBW",9},
	{"PUNPCKHWD",9},
	{"PUNPCKHDQ",9},
	{"PACKSSDW", 9},
	{"PUNPCKLQDQ",9},
	{"PUNPCKHQDQ",9},
	{"MOVD", 	  4},
	{"MOVQ",      4},
	{"MOVDQA",    6},
	{"MOVDQU",    6},
	{"PSHUFW",    6},
	{"PSHUFLW",   7},
	{"PSHUFHW",   7},
	{"PSHUFD",    6},
	{"PSRLW",     5},
	{"PSRAW",     5},
	{"PSLLW",     5},
	{"PSRLD",     5},
	{"PSRAD",     5},
	{"PSLLD",     5},
	{"PSRLQ",     5},
	{"PSRLDQ",    6},
	{"PSLLQ",     5},
	{"PSLLDQ",    6},
	{"PCMPEQB",   7},
	{"PCMPEQW",   7},
	{"PCMPEQD",   7},
	{"EMMS",      4},
	{"VMREAD",    6},
	{"VMWRITE",   7},
	{"HADDPD",    6},
	{"HADDPS",    6},
	{"HSUBPD",    6},
	{"HSUBPS",    6},
	{"MOVD",      4},
	{"MOVQ",      4},
	{"MOVDQA",    6},
	{"MOVDQU",    6},
	{"SETO",      4},
	{"SETNO",     5},
	{"SETB",      4},
	{"SETNAE",    6},
	{"SETC",      4},
	{"SETNB",     5},
	{"SETAE",     5},
	{"SETNC",     5},
	{"SETZ",      4},
	{"SETE",      4},
	{"SETNZ",     5},
	{"SETNE",     5},
	{"SETBE",     5},
	{"SETNA",     5},
	{"SETNBE",    6},
	{"SETA",      4},
	{"SETS",      4},
	{"SETNS",     5},
	{"SETP",      4},
	{"SETPE",     5},
	{"SETNP",     5},
	{"SETPO",     5},
	{"SETL",      4},
	{"SETNGE",    6},
	{"SETNL",     5},
	{"SETGE",     5},
	{"SETLE",     5},
	{"SETNG",     5},
	{"SETNLE",    6},
	{"SETG",      4},
	{"CPUID",     5},
	{"BT",        2},
	{"SHLD",      4},
	{"RSM",       3},
	{"BTS",       3},
	{"SHRD",      4},
	{"FXSAVE",    6},
	{"FXRSTOR",   7},
	{"LDMXCSR",   7},
	{"STMXCSR",   7},
	{"XSAVE",     5},
	{"LFENCE",    6},
	{"XRSTOR",    6},
	{"MFENCE",    6},
	{"SFENCE",    6},
	{"CLFLUSH",   7},
	{"CMPXCHG",   7},
	{"LSS",       3},
	{"BTR",       3},
	{"LFS",       3},
	{"LGS",       3},
	{"MOVZX",     5},
	{"POPCNT",    6},
	{"UD",        2},
	{"BTR",       3},
	{"BTC",       3},
	{"BSF",       3},
	{"BSR",       3},
	{"MOVSX",     5},
	{"XADD",      4},
	{"CMPPS",     5},
	{"CMPSS",     5},
	{"CMPPD",     5},
	{"CMPSD",     5},
	{"MOVNTI",    6},
	{"PINSRW",    6},
	{"PEXTRW",    6},
	{"SHUFPS",    6},
	{"SHUFPD",    6},
	{"CMPXCHG8B", 9},
	{"VMPTRLD",   7}, 
	{"VMCLEAR",   7},
	{"VMXON",     5},
	{"VMPTRST",   7},
	{"BSWAP",     5},
	{"ADDSUBPD",  8},
	{"ADDSUBPS",  8},
	{"PSRLW",     5},
	{"PSRLD",     5},
	{"PSRLQ",     5},
	{"PADDQ",     5},
	{"PMULLW",    6},
	{"MOVQ2DQ",   7},
	{"MOVDQ2Q",   7},
	{"PMOVMSKB",  8},
	{"PSUBUSB",   7},
	{"PSUBUSW",   7},
	{"PMINUB",    6},
	{"PAND",      4},
	{"PADDUSB",   6},
	{"PADDUSW",   6},
	{"PMAXUB",    5},
	{"PANDN",     5},
	{"PAVGB",     5},
	{"PSRAW",     5},
	{"PSRAD",     5},
	{"PAVGW",     5},
	{"PMULHUW",   7},
	{"PMULHW",    6},
	{"CVTPD2DQ",  8},
	{"CVTTPD2DQ", 9},
	{"CVTDQ2PD",  8},
	{"MOVNTQ",    6},
	{"MOVNTDQ",   7},
	{"PSUBSB",    6},
	{"PSUBSW",    6},
	{"PMINSW",    6},
	{"POR",       3},
	{"PADDSB",    6},
	{"PADDSW",    6},
	{"PMAXSW",    6},
	{"PXOR",      4},
	{"LDDQU",     5},
	{"PSLLW",     5},
	{"PSLLD",     5},
	{"PSLLQ",     5},
	{"PMULUDQ",   7},
	{"PMADDWD",   7},
	{"PSADBW",    6},
	{"MASKMOVQ",  8},
	{"MASKMOVDQU",10},
	{"PSUBB",     5},
	{"PSUBW",     5},
	{"PSUBD",     5},
	{"PSUBQ",     5},
	{"PADDB",     5},
	{"PADDW",     5},
	{"PADDD" ,    5},
	{NULL, 0},

	//////////////////////////////////
	//
	//  x64 Mnemonic Instruction
	//
	//////////////////////////////////

	{ "REX",      3},
	{ "REX.B",    5},
	{ "REX.X",    5},
	{ "REX.XB",   6},
	{ "REX.R",    5},
	{ "REX.RB",   6},
	{ "REX.RX",   6},
	{ "REX.RXB",  7},
	{ "REX.W",    5},
	{ "REX.WB",   6},
	{ "REX.WX",   6},
	{ "REX.WXB",  7},
	{ "REX.WR",   6},
	{ "REX.WRB",  7},
	{ "REX.WRX",  7},
	{ "REX.WRXB", 8},
	{ "MOVSXD",   6},
	{ "FS",       2},
	{ "GS",       2},
	{ "CDQE",     4},
	{ "CQO",      3},
	{ "PUSHFQ",   6},
	{ "POPFQ",    5},
	{ "MOVSQ",    5},
	{ "CMPSQ",    5},
	{ "STOSQ",    5},
	{ "LODSQ",    5},
	{ "SCASQ",    5},
	{ "IRETQ",    5},
	{ "SYSCALL",  7},
	{ "SYSRET",   6},
	{ "MOVSHDUP", 8},
	{ NULL,   0}
};
