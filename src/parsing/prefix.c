#include "lunar.h"

/////////////////////////////////
//
//			INCLUDES
//
/////////////////////////////////

#include <string.h>
#include <stdio.h>

/////////////////////////////////
//
//		PARSING PREFIX
//
/////////////////////////////////

int	parse_prefix(inst_t *inst)
{	
	unsigned int	prefix_data = 0;
	size_t	prfx_len = 0, len = 0;
	int 	cnt = 0, i = 0, j = 0, x = 0;

	if (!inst)
		return (ERROR_PREFIX_DECODING);
	prfx_len = strspn(inst->buf.buf, PREFIX_STRING);

	// Instruction must be have max 4 bytes of prefix, more is considered the
	// behavior is undefined
	if (prfx_len > 4)
		return (ERROR_PREFIX_DECODING);

	// check duplicate prefix group if the instruction contains two or more prefixes of the same group, the instruction has an undefined behavior and is considered as an error.
	
	for (i = 0; i < (int)(sizeof(inst->prefix_arr) / sizeof(char *)); i++) {
		len = strlen(inst->prefix_arr[i]);
		for (x = 0; x < (int)prfx_len; x++)
		{
			cnt = 0;
			for (j = 0; j < (int)len; j++) {
				if (memchr(inst->buf._buf, inst->prefix_arr[i][j], prfx_len)) {
					cnt++;
					inst->nprfx++;
				}
				if (cnt >= 2) {
					return (ERROR_PREFIX_DECODING);
				}
			}
		}
	}

	// Parse value prefix

	prefix_data = *(unsigned int *)inst->buf._buf;

	if (!inst->nprfx)
		return (0);
	return (0);
}
