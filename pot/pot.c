#include <stdbool.h>

#include "em_adc.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_gpio.h"

enum {
	LEDPORT = gpioPortH,
	REDPIN = 10,
	GREENPIN = 11
};

uint32_t
measurePot(ADC_TypeDef *adc)
{
	ADC_InitSingle_TypeDef single_init = {0}; /* TODO */
	ADC_Start_TypeDef adc_start = {0}; /* TODO */
	uint32_t data = 0;

	ADC_InitSingle(adc, &single_init);
	ADC_Start(adc, adc_start);
	/* TODO check data valid? */
	data = ADC_DataSingleGet(adc);
	return data;
}

void
greenLedOn(void)
{
	GPIO_PinOutSet(LEDPORT, REDPIN);
	GPIO_PinOutClear(LEDPORT, GREENPIN); /* active low */
}

void
initLeds(void)
{
	CMU_ClockEnable(cmuClock_GPIO, true);
	GPIO_PinModeSet(LEDPORT, REDPIN, gpioModePushPull, 1);
	GPIO_PinModeSet(LEDPORT, GREENPIN, gpioModePushPull, 1);
	greenLedOn();
}

int
main(void)
{
	ADC_Init_TypeDef adc_init = ADC_INIT_DEFAULT;
	ADC_TypeDef adc = {0};

	CHIP_Init();
	/* TODO enable clocks: HFPERCLK? */
	//ADC_Init(&adc, &adc_init);
	initLeds();

	//measurePot(&adc);

	for (;;)
		;
}
