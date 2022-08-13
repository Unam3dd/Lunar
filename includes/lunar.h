#ifndef LUNAR_H
#define LUNAR_H

//////////////////////////////////
//
//			INCLUDES
//
//////////////////////////////////

#include <stddef.h>
#include <stdint.h>

/////////////////////////////////
//
//			BUFFER
//
/////////////////////////////////

#include "buffer.h"

/////////////////////////////////
//
//			ERROR
//
/////////////////////////////////

#include "lunar_error.h"

//////////////////////////////////
//
//			DEFINES
//
//////////////////////////////////

#define MAX_OPCODES_LENGTH 0xF
#define GET_VALUE_FIELD(value) ( ((value << 2) & 0xFF ) >> 5 & 0xF)
#define INVALID_REGISTER NULL
#define REGISTER_ARRAY_SIZE 0x10

//////////////////////////////////
//
//			TYPEDEFS	
//
//////////////////////////////////

typedef struct 	registers_t		registers_t;
typedef struct 	opcodes_t		opcodes_t;
typedef struct 	mnemonic_t		mnemonic_t;
typedef struct 	rex_t			rex_t;
typedef struct 	mod_rm_t		mod_rm_t;
typedef struct	prefix_t		prefix_t;
typedef struct 	sib_t    		sib_t;
typedef struct 	inst_t 			inst_t;
typedef struct 	fmt_t  			fmt_t;
typedef enum	prefix_idx_t	prefix_idx_t;
typedef enum	flags_idx_t		flags_idx_t;
typedef enum	mnemo_idx_t		mnemo_idx_t;
typedef enum	reg_idx_t		reg_idx_t;
typedef enum	arch_mode_t		arch_mode_t;

/////////////////////////////////
//
//		MNEMONIC TABLE
//
/////////////////////////////////

struct mnemonic_t
{
	const char 	*str;	// Pointer in .rodata section to mnemonic instruction
	size_t		len;	// Len of string
};

/////////////////////////////////
//
//	 	REGISTER TABLES
//
/////////////////////////////////

struct registers_t
{
	const char	*r8[2];	// Two 8 bits registers Example : AH | AL
	const char	*r16;	// 16 bits registers	Example : AX
	const char	*r32;	// 32 bits registers	Example : (Extended + AX) EAX
	const char	*r64;	// 64 bits registers	Example : (Rex Prefix + AX) RAX
	const char	*r80;	// 80 bits registers is extension to floating point stack registers : ST0
	const char	*mmx;	// 128 bits registers with first SSE Extensions
	const char	*xmm;	// 128 bits registers with new SSE Extensions
	const char	*ymm;	// 256 bits registers with AVX Extensions
	const char	*sreg;	// Segment Register like : CS, SS, etc....
	const char	*cr;	// Control register Example : CR0
	const char	*dr;	// Debug register Example : DR0
	// New Zmm 512 registers comming soon with AVX2 support
};

/////////////////////////////////
//
//		OPCODES TABLES
//
/////////////////////////////////


struct opcodes_t
{
	const mnemonic_t	*mnemonic[4];	// Array pointer to mnemonic table string, 4 if has fews mnemonic
	uint8_t				len;			// Len of mnemonics instruction
	uint8_t				p_twobyte;		// Two byte prefix
	uint16_t			po;				// Primary opcodes
	uint8_t				so;				// Secondary opcodes
	uint8_t				o;				// Opcodes fields
	uint32_t			op;				// 4 bytes of operands
};

//////////////////////////////////
//
//			ENUM
//
//////////////////////////////////

#include "lunar_enum.h"

//////////////////////////////////
//
//			TABLES
//
//////////////////////////////////

extern const mnemonic_t mnemonics[];	// Mnemonics instruction table
extern const registers_t regs[];		// Registers table
extern const opcodes_t opcodes32[];		// Opcodes x86 Map
extern const opcodes_t opcodes64[];		// Opcodes x64 Map

//////////////////////////////////
//
//			MOD R/M
//
//////////////////////////////////

struct mod_rm_t
{
	/*
	 *   7                           0
		+---+---+---+---+---+---+---+---+
		|  mod  |    reg    |     rm    |
		+---+---+---+---+---+---+---+---+
	 	
		Field 		Length 	Description
		
		MODRM.mod 	2 bits 	In general, when this field is b11, then register-direct addressing mode is used; otherwise register-indirect addressing mode is used.

		MODRM.reg 	3 bits 	This field can have one of two values:

	A 3-bit opcode extension, which is used by some instructions but has no further meaning other than distinguishing the instruction from other instructions.
    A 3-bit register reference, which can be used as the source or the destination of an instruction (depending on the instruction). The referenced register depends on the operand-size of the instruction and the instruction itself. See Registers for the values to use for each of the registers. The REX.R, VEX.~R or XOP.~R field can extend this field with 1 most-significant bit to 4 bits total. 

		MODRM.rm 	3 bits 	Specifies a direct or indirect register operand, optionally with a displacement. The REX.B, VEX.~B or XOP.~B field can extend this field with 1 most-significant bit to 4 bits total.
	 */

	uint8_t	rm  : 3;	// Register/Memory
	uint8_t	reg : 3;	// Register
	uint8_t	mod : 2;	// determined by D bit (SRC -> DST | DST -> SRC)(before last one bits in first opcode)
};

//////////////////////////////////
//
//			SIB
//
//////////////////////////////////

struct sib_t
{
	/*
	 *   7                           0
		+---+---+---+---+---+---+---+---+
		| scale |   index   |    base   |
		+---+---+---+---+---+---+---+---+

		Field 		Length 	Description
		SIB.scale 	2 bits 	This field indicates the scaling factor of SIB.index, where s (as used in the tables) equals 2SIB.scale.
							SIB.scale 	factor s
								b00 		1
								b01 		2
								b10 		4
								b11 		8
		SIB.index 	3 bits 	The index register to use. See Registers for the values to use for each of the registers. The REX.X, VEX.~X or XOP.~X field can extend this field with 1 most-significant bit to 4 bits total.
SIB.base 	3 bits 	The base register to use. See Registers for the values to use for each of the registers. The REX.B, VEX.~B or XOP.~B field can extend this field with 1 most-significant bit to 4 bits total.
	 */
	uint8_t	base	: 3; // Base
	uint8_t index	: 3; // Index
	uint8_t scale 	: 2; // Scale
};

/////////////////////////////////
//
//			PREFIX
//
/////////////////////////////////

#define PREFIX_STRING "\xF0""\xF2""\xF3""\x2E""\x36""\x3E""\x26""\x64""\x65""\x2E""\x3E""\x66""\x67""\x40""\x41""\x42""\x43""\x44""\x45""\x46""\x47""\x48""\x49""\x4A""\x4B""\x4C""\x4D""\x4E""\x4F"

#define PREFIX_GROUP1 "\xF0""\xF2""\xF3"
#define PREFIX_GROUP2 "\x2E""\x36""\x3E""\x26""\x64""\x65""\x2E""\x3E"
#define PREFIX_GROUP3 "\x66"
#define PREFIX_GROUP4 "\x67"
#define PREFIX_REX "\x40""\x41""\x42""\x43""\x44""\x45""\x46""\x47""\x48""\x49""\x4A""\x4B""\x4C""\x4D""\x4E""\x4F"

struct prefix_t
{
	// Prefix Group 1
	
	uint8_t		p_lock; // with lock prefix certain rmw instruction are executed atomically
	/*
	 * The repeat prefixes cause string handling instructions to be repeated.

		The REP prefix will repeat the associated instruction up to CX times, decreasing CX with every repetition. It can be used with the INS, LODS, MOVS, OUTS and STOS instructions.

	REPE and REPZ are synonyms and repeat the instruction until CX reaches 0 or when ZF is set to 0. It can be used with the CMPS, CMPSB, CMPSD, CMPSW, SCAS, SCASB, SCASD and SCASW instructions.

	REPNE and REPNZ also are synonyms and repeat the instruction until CX reaches 0 or when ZF is set to 1. It can be used with the CMPS, CMPSB, CMPSD, CMPSW, SCAS, SCASB, SCASD and SCASW instructions
	*/
	uint8_t		p_rep;

	// Prefix Group 2
	uint8_t		p_seg; // Segment overrides are used with instruction that ref non stack memory

	/*
	 							CS.d 	REX.W 	Prefix Operand size 	Address size
	Real mode /				:
	Virtual 8086 mode 			
								N/A 	N/A 	No 		16-bit 				16-bit
								N/A 	N/A 	Yes 	32-bit 				32-bit
	Protected mode /
	Long compatibility mode :	
								0 		N/A 	No 		16-bit 				16-bit
								0 		N/A 	Yes 	32-bit 				32-bit
								1 		N/A 	No 		32-bit 				32-bit
								1 		N/A 	Yes 	16-bit 				16-bit
	Long 64-bit mode 	 	:
								Ignored  0 		No 		32-bit 				64-bit
								Ignored  0 		Yes 	16-bit 				32-bit
								Ignored  1 		No 		64-bit  			64-bit
								Ignored  1 		Yes 	64-bit 				32-bit
	*/

	// Prefix Group 3
	uint8_t		p_66; // Operands size prefix

	// Prefix Group 4
	uint8_t		p_67; // Address size prefix
	
	// Prefix Rex (only for long mode)
	uint8_t		p_rex; // Rex prefix for long mode instruction see REX Sections below

	// Twobyte prefix
	uint8_t		p_twobyte; // Two byte prefix
};

/////////////////////////////////
//
//	REX Prefix (only long mode)
//
/////////////////////////////////

/*
A REX prefix must be encoded when:

    using 64-bit operand size and the instruction does not default to 64-bit operand size; or
    using one of the extended registers (R8 to R15, XMM8 to XMM15, YMM8 to YMM15, CR8 to CR15 and DR8 to DR15); or
    using one of the uniform byte registers SPL, BPL, SIL or DIL. 

A REX prefix must not be encoded when:

    using one of the high byte registers AH, CH, BH or DH. 

In all other cases, the REX prefix is ignored. 
The use of multiple REX prefixes is undefined, although processors seem to use only the last REX prefix.

Instructions that default to 64-bit operand size in long mode are:
CALL (near) 	ENTER 		Jcc
JrCXZ 			JMP (near) 	LEAVE
LGDT 			LIDT 		LLDT
LOOP 			LOOPcc 		LTR
MOV CR(n) 		MOV DR(n) 	POP reg/mem
POP reg 		POP FS 		POP GS
POPFQ 			PUSH imm8 	PUSH imm32
PUSH reg/mem 	PUSH reg 	PUSH FS
PUSH GS 		PUSHFQ 		RET (near) 
*/

struct rex_t
{
	uint8_t	b		: 1; // this value is an extension of MODRM.rm
	uint8_t	x		: 1; // this value is an extension of SIB.index
	uint8_t	r		: 1; // this value is an extension of MODRM.reg
	uint8_t	w		: 1; // When 1, a 64 bit operand size is used
	uint8_t	pattern	: 4; // Fixed bit pattern
};

/////////////////////////////////
//
//			INSTRUCTION
//
/////////////////////////////////

struct inst_t
{
	buffer_t	buf;
	prefix_t	p;
	char		*prefix_arr[5];
	int			arch;
	int			nprfx;
};

/////////////////////////////////
//
//			Formatter
//
/////////////////////////////////

struct fmt_t
{
	buffer_t	buf;
	int			syntax;
};

/////////////////////////////////
//
//			DECODER
//
/////////////////////////////////

int	lunar_decoder_init(inst_t *inst, int arch);

/////////////////////////////////
//
//			Parsing
//
/////////////////////////////////

// prefix.c

int	parse_prefix(inst_t *inst);

#endif
