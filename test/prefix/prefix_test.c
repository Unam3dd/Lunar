#include "lunar.h"
#include <stdio.h>

int main(int ac, char **av)
{
	inst_t	inst;
	int		err = 0;

	char buf[] = { 0x48, 0xB8, 0x1, 0x00, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
	
	set_buffer(&inst.buf, buf);
	lunar_decoder_init(&inst, ARCH_MODE_X64);

	if ((err = parse_prefix(&inst)))
			return (lunar_strerror(err), 1);
	printf("[+] Decoding performed !\n");
	return (0);
}
