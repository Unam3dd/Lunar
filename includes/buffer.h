#ifndef BUFFER_H
#define BUFFER_H

/////////////////////////////////
//
//			INCLUDES
//
/////////////////////////////////

#include <string.h>
#include <stdint.h>

/////////////////////////////////
//
//			BUFFER_SIZE
//
/////////////////////////////////

#ifndef BUFFER_SIZE 
#define BUFFER_SIZE 0x1000
#endif

/////////////////////////////////
//
//			TYPEDEF
//
/////////////////////////////////

typedef struct buffer_t	buffer_t;

/////////////////////////////////
//
//			STRUCT
//
/////////////////////////////////

struct buffer_t
{
	char 	_buf[BUFFER_SIZE];
	union {
		const char		*buf;
		const uint8_t	*bufu8;
	};
	size_t		size;
	size_t		index;
};

void set_buffer(buffer_t *buf, const char *data);
void unset_buffer(buffer_t *buf);

#endif
