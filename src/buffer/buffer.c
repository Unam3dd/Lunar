#include "lunar.h"

/////////////////////////////////
//
//			INCLUDES
//
/////////////////////////////////

#include <string.h>
#include <stddef.h>

void	set_buffer(buffer_t *buf, const char *data)
{
	size_t	len = 0;

	if (!buf || !data)
		return ;
	len = strlen(data);
	memcpy(buf->_buf, data, len);
	buf->bufu8 = (const uint8_t *)buf->_buf;
	buf->buf = buf->_buf;
	buf->index = 0;
	buf->size = len;
}

void	unset_buffer(buffer_t *buf)
{
	if (!buf)
		return ;
	memset(buf->_buf, 0, sizeof(buf->_buf));
	buf->bufu8 = NULL;
	buf->buf = NULL;
}
