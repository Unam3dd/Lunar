#include "lunar_error.h"

/////////////////////////////////
//
//			INCLUDES
//
/////////////////////////////////

#include <stddef.h>
#include <stdio.h>

/////////////////////////////////
//
//			ERROR TABLE
//
/////////////////////////////////

const lunar_error_t	lerror[] = {
	{ ERROR_PREFIX_DECODING_MSG, ERROR_PREFIX_DECODING_CODE},
	{ ERROR_BAD_ARCH_MSG, ERROR_BAD_ARCH_CODE},
	{ NULL, 0 }
};

void	lunar_strerror(int code)
{
	for (int i = 0; lerror[i].msg; i++)
		if (code == lerror[i].status)
			return (printf("[-] Error (%d) : %s\n", lerror[i].status, lerror[i].msg), 1);
}
