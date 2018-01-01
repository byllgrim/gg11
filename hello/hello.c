#include <stdio.h>

#include "em_chip.h"
#include "em_device.h"
#include "retargetserial.h"

int
main(void)
{
	CHIP_Init();
	RETARGET_SerialInit();
	RETARGET_SerialCrLf(1);

	printf("Hello, World!\n");

	for (;;)
		;
}
