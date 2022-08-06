#ifndef LUNAR_H
#define LUNAR_H

//////////////////////////////////
//
//			INCLUDES
//
//////////////////////////////////

#include <stddef.h>
#include <stdint.h>

//////////////////////////////////
//
//			DEFINES
//
//////////////////////////////////

#define GET_VALUE_FIELD(value) ( ((value << 2) & 0xFF ) >> 5 & 0xF)

#define INVALID_REGISTER NULL

//////////////////////////////////
//
//			TYPEDEFS	
//
//////////////////////////////////

typedef struct register_t	register_t;
typedef struct opcodes_t	opcodes_t;
typedef struct mnemonic_t	mnemonic_t;
typedef struct rex_prfx_t	rex_prfx_t;
typedef struct mod_rm_t		mod_rm_t;
typedef struct sib_t    	sib_t;
typedef struct inst_t 		inst_t;
typedef struct fmt_t  		fmt_t;
typedef enum   mnemo_idx_t 	mnemo_idx_t;
typedef enum   arch_mode_t	arch_mode_t;

/////////////////////////////////
//
//		MNEMONIC TABLE
//
/////////////////////////////////

struct mnemonic_t
{
	char 	*str;
	size_t	len;
};

/////////////////////////////////
//
//	 	REGISTER TABLES
//
/////////////////////////////////

struct register_t
{
	char	*r8;
	char	*r16;
	char	*r32;
	char	*r64;
	char	*mm;
	char	*xmm;
	char	*sreg;
	char	*cr;
	char	*dr;
};

/////////////////////////////////
//
//		OPCODES TABLES
//
/////////////////////////////////


struct opcodes_t
{
	mnemonic_t	*mnemonic[4];
	uint8_t		len;
	uint8_t		p_rex;
	uint8_t		p_rep;
	uint8_t		p_lock;
	uint8_t		p_seg;
	uint8_t		p_66;
	uint8_t		p_67;
	uint8_t		p_twobyte;
	uint8_t		po;
	uint8_t		so;
	uint8_t		o;
	uint8_t		x;
	uint8_t		op1;
	uint8_t		op2;
	uint8_t		op3;
	uint8_t		op4;
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

extern const mnemonic_t mnemonics32[];
extern const mnemonic_t mnemonics64[];
extern const register_t regs[];
extern const opcodes_t opcodes32[];
extern const opcodes_t opcodes64[];

//////////////////////////////////
//
//			PREFIX
//
//////////////////////////////////

//////////////////////////////////
//
//			MOD R/M
//
//////////////////////////////////

struct mod_rm_t
{
	uint8_t	rm  : 3;
	uint8_t	reg : 3;
	uint8_t	mod : 2;
};

//////////////////////////////////
//
//			SIB
//
//////////////////////////////////

struct sib_t
{
	uint8_t	base	: 3;
	uint8_t index	: 3;
	uint8_t scale 	: 2;
};

/////////////////////////////////
//
//			INSTRUCTION
//
/////////////////////////////////

struct inst_t
{
};

/////////////////////////////////
//
//			Formatter
//
/////////////////////////////////

struct fmt_t
{
};

#endif
