#include "lunar.h"

/////////////////////////////////
//
//			INCLUDES
//
/////////////////////////////////

#include <stdio.h>
#include <string.h>

/////////////////////////////////
//
//		PARSING PREFIX
//
/////////////////////////////////

int	parse_prefix(inst_t *inst)
{	
	unsigned int	prefix_data = 0;
	size_t	prfx_len = 0, len = 0;
	int 	cnt = 0, i = 0, j = 0;

	if (!inst)
		return (ERROR_PREFIX_DECODING);
	prfx_len = strspn(inst->buf.buf, PREFIX_STRING);

	// Instruction must be have max 4 bytes of prefix, more is considered the
	// behavior is undefined
	if (prfx_len > 4)
		return (ERROR_PREFIX_DECODING);

	// check duplicate prefix group if the instruction contains two or more prefixes of the same group, the instruction has an undefined behavior and is considered as an error.
	
	for (i = 0; i < (int)(sizeof(inst->prefix_arr) / sizeof(char *)); i++) {
		len = strlen((const char *)inst->prefix_arr[i]);
		cnt = 0;
		for (j = 0; j < (int)len; j++) {
			if (memchr(inst->buf._buf, inst->prefix_arr[i][j], prfx_len)) {
				cnt++;
				inst->nprfx++;
			}

			if (cnt >= 2)
				return (ERROR_PREFIX_DECODING);
		}
	}

	// Parse value prefix

	prefix_data = *(unsigned int *)inst->buf._buf;

	if (!inst->nprfx)
		return (0);
	for (i = 0; i < inst->nprfx; i++)
		prefix_check_data(&inst->p, ((prefix_data >> (i * 8)) & 0xFF));
	inst->buf.index += inst->nprfx;
	return (0);
}

void	prefix_check_data(prefix_t *p, unsigned char data)
{
	if (!p->p_lock && data == PREFIX_LOCK) {
		p->p_lock = data;
		return ;
	}

	if (!p->p_rep && ( data == 0xF2 || data == 0xF3 )) {
		p->p_rep = data;
		return ;
	}

	if (!p->p_66 && (data == PREFIX_OP_SIZE_OVERRIDE)) {
		p->p_66 = data;
		return ;
	}

	if (!p->p_67 && (data == PREFIX_ADDR_SIZE_OVERRIDE)) {
		p->p_67 = data;
		return ;
	}

	if (!p->p_seg && (data == 0x2E || data == 0x36 || data == 0x3E || data == 0x26 || data == 0x64 || data == 0x65)) {
		p->p_seg = data;
		return ;
	}

	if (!p->p_rex && (data >= 0x40 && data <= 0x4F)) {
		p->p_rex = data;
		return ;
	}
}
