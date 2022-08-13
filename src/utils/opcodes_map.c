#include "lunar.h"

/////////////////////////////////
//
//		OPCODES MAP x86
//
/////////////////////////////////

/*
struct opcodes_t
{
	mnemonic_t	*mnemonic[4];	// Array pointer to mnemonic table string, 4 if has fews mnemonic
	uint8_t		len;			// Len of mnemonics instruction
	uint8_t		p_twobyte;		// Two byte prefix
	uint16_t	po;				// Primary opcodes
	uint8_t		so;				// Secondary opcodes
	uint8_t		o;				// Opcodes fields
	uint32_t	op;				// 4 bytes of operands
};
*/

const opcodes_t	opcodes32[] = {
	{ { &mnemonics[MNEMO_ADD], NULL, NULL, NULL }, 0x2, 0x00, 0x00, NO_SO, MODRM, (((RM | 8) << 8) | (REG | 8))},
	{ { &mnemonics[MNEMO_ADD], NULL, NULL, NULL }, 0x2, 0x00, 0x01, NO_SO, MODRM, (((RM | 16 | 32) << 8 | (REG | 16 | 32)))},
	{ { NULL, NULL, NULL, NULL }, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }
};

/////////////////////////////////
//
//		OPCODES MAP X64
//
/////////////////////////////////

const opcodes_t opcodes64[] = {
	{ { &mnemonics[MNEMO_ADD], NULL, NULL, NULL }, 0x2, 0x00, 0x00, NO_SO, MODRM, (((RM | 8) << 8) | (REG | 8))},
	{ { &mnemonics[MNEMO_ADD], NULL, NULL, NULL }, 0x2, 0x00, 0x01, NO_SO, MODRM, (((RM | 16 | 32) << 8 | (REG | 16 | 32)))},
	{ { NULL, NULL, NULL, NULL }, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }
};
