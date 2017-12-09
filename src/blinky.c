#include "bsp.h"

/*
TODO from example blink.c
#include <stdint.h>
#include <stdbool.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "bsp.h"
#include "bsp_trace.h"
*/

int
main(void)
{
	/* TODO CHIP_Init(); */
	BSP_LedsInit();

	/* TODO BSP_LedSet(0); */

	for (;;)
		;
}
