#include <stdbool.h>

#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_lcd.h"

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
clearScreen(void)
{
	LCD_Init_TypeDef lcd_init = LCD_INIT_DEFAULT;
	EMU_DCDCInit_TypeDef dcdc_init = EMU_DCDCINIT_DEFAULT;
	CMU_HFXOInit_TypeDef hfxo_init = CMU_HFXOINIT_DEFAULT;

	EMU_DCDCInit(&dcdc_init);
	CMU_HFXOInit(&hfxo_init); /* TODO not needed? */
	CMU_ClockEnable(cmuClock_LCD, true);

	LCD_Init(&lcd_init);
	LCD_Enable(true);
	LCD_BlankEnable(true);
}

int
main(void)
{
	CHIP_Init();
	redLedOn();
	clearScreen();

	for (;;)
		;
}
