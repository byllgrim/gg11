#include <stdbool.h>
#include <stdio.h>

#include "em_device.h" /* include before other emlib headers */

#include "em_chip.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "retargetserial.h"

enum {PORT = gpioPortA};
enum {PIN = 14};

void
vcomInit(void)
{
	RETARGET_SerialInit();
	RETARGET_SerialCrLf(1);
	printf("VCOM enabled\n");
}

void
pinInit(void)
{
	CMU_ClockEnable(cmuClock_GPIO, true);
	GPIO_PinModeSet(PORT, PIN, gpioModeInput, 0); /* TODO 1? */
	printf("pin inited\n"); /* TODO shut up */
}

int
main(void)
{
	CHIP_Init();
	vcomInit();
	pinInit();

	printf("pin = %d\n", GPIO_PinInGet(PORT, PIN));

	for (;;)
		;
}
