#include "lunar.h"
#include <stdio.h>

int main(int ac, char **av)
{
	inst_t	inst;
	int		err = 0;

	char buf[] = { 0x48, 0xF3, 0xF2, 0xB8, 0x1, 0x00, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
	
	lunar_decoder_init(&inst, ARCH_MODE_X64, buf);

	if ((err = parse_prefix(&inst)))
			return (lunar_strerror(err), 1);
	printf("REX prefix is present : %x\n", inst.p.p_rex);
	printf("Number of prefix found ! : %d\n", inst.nprfx);
	printf("[+] Decoding performed !\n");
	return (0);
}
