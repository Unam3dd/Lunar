#include "lunar.h"
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	if (ac < 2 || atoi(av[1]) > 0xF)
		return (1);
	printf("%s\n", regs[atoi(av[1])].r32);
	return (0);
}
