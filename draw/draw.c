#include <stdbool.h>

#include "em_chip.h"
#include "em_cmu.h"
#include "em_lcd.h"

enum {LED_PORT = gpioPortH};

enum {
	LED0R_PIN = 10,
	LED0G_PIN = 11,
	LED0B_PIN = 12
};

int
main(void)
{
	LCD_Init_TypeDef lcd_init = LCD_INIT_DEFAULT;

	CHIP_Init();

	CMU_ClockEnable(cmuClock_GPIO, true);
	GPIO_PinModeSet(LED_PORT, LED0R_PIN, gpioModePushPull , 0);
	//configure
	GPIO_PinOutClear(LED_PORT, LED0R_PIN);

	CMU_ClockEnable(cmuClock_LCD, true);
	LCD_Init(&lcd_init);
	LCD_Enable(true);
	LCD_BlankEnable(true);

	for (;;)
		;
}
