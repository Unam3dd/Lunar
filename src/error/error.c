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
	{ DURING_ENCODING_MSG, DURING_ENCODING_ERR},
	{ BAD_ARCHITECTURE_MSG, BAD_ARCHITECTURE_ERR},
	{ NULL, 0 }
};

int	lunar_strerror(int code)
{
	for (int i = 0; lerror[i].msg; i++)
		if (code == lerror[i].status)
			return (printf("[-] Error (%d) : %s\n", lerror[i].status, lerror[i].msg), 1);
	return (0); 
}
