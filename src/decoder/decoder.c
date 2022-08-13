#include "lunar.h"

int	lunar_decoder_init(inst_t *inst, int arch)
{
	if (!inst || (arch != ARCH_MODE_X64 && arch != ARCH_MODE_X86))
		return (ERROR_BAD_ARCH);
	inst->arch = arch;

	if (arch == ARCH_MODE_X64) {
		inst->prefix_arr[0] = PREFIX_GROUP1;
		inst->prefix_arr[1] = PREFIX_GROUP2;
		inst->prefix_arr[2] = PREFIX_GROUP3;
		inst->prefix_arr[3] = PREFIX_GROUP4;
		inst->prefix_arr[4] = PREFIX_REX;
	}

	if (arch == ARCH_MODE_X86) {
		inst->prefix_arr[0] = PREFIX_GROUP1;
		inst->prefix_arr[1] = PREFIX_GROUP2;
		inst->prefix_arr[2] = PREFIX_GROUP3;
		inst->prefix_arr[3] = PREFIX_GROUP4;
	}

	return (0);
}
