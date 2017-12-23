#include <stdbool.h>

#include "dmd.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "glib.h"

enum {LED_PORT = gpioPortH};

enum {
	LED0R_PIN = 10,
	LED0G_PIN = 11,
	LED0B_PIN = 12
};

void
redLedOn(void)
{
	CMU_ClockEnable(cmuClock_GPIO, true);
	GPIO_PinModeSet(LED_PORT, LED0R_PIN, gpioModePushPull , 0);
	GPIO_PinOutClear(LED_PORT, LED0R_PIN);
}

void
initDisplay(GLIB_Context_t *glib_context)
{
	EMU_DCDCInit_TypeDef dcdc_init = EMU_DCDCINIT_DEFAULT;
	CMU_HFXOInit_TypeDef hfxo_init = CMU_HFXOINIT_DEFAULT;

	EMU_DCDCInit(&dcdc_init);
	CMU_HFXOInit(&hfxo_init);
	DMD_init(0);
	GLIB_contextInit(glib_context);
}

int
main(void)
{
	GLIB_Context_t glib_context;
	int i;
	int j;
	int width;
	int height;

	CHIP_Init();
	redLedOn();
	initDisplay(&glib_context); /* TODO rename */

	glib_context.backgroundColor = Black;
	glib_context.foregroundColor = White;
	GLIB_clear(&glib_context);
	/*
	for (i = 0; i < 64; i++) {
		for (j = 0; j < 64; j++) {
			GLIB_drawPixel(&glib_context, i, j);
		}
	}
	*/
	width = glib_context.pDisplayGeometry->xSize;
	height = glib_context.pDisplayGeometry->ySize;
	GLIB_drawCircle(&glib_context, width / 2, height / 2, 4);
	DMD_updateDisplay();

	for (;;)
		;
}
