#include "bsp.h"
#include "em_chip.h"
#include "em_device.h"

int
main(void)
{
	CHIP_Init();
	BSP_LedsInit();

	BSP_LedSet(0);
	BSP_LedToggle(1);

	for (;;)
		;
}
