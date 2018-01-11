#include <stdbool.h>
#include <stdio.h>

#include "em_device.h" /* include before other emlib headers */

#include "em_adc.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "retargetserial.h"

enum {
	LEDPORT = gpioPortH,
	REDPIN = 10,
	GREENPIN = 11
};

uint32_t
measurePot()
{
	ADC_InitSingle_TypeDef single_init = ADC_INITSINGLE_DEFAULT;

	/*
	 TODO
	.reference?
	.rep?
	*/
	single_init.posSel = adcPosSelAPORT0XCH1; /* pin PC1 */
	single_init.negSel = adcNegSelVSS;

	ADC_InitSingle(ADC0, &single_init);
	ADC_Start(ADC0, adcStartSingle);

	/* TODO check data valid? adc->STATUS? */
	return ADC_DataSingleGet(ADC0);
}

void
greenLedOn(void)
{
	GPIO_PinOutSet(LEDPORT, REDPIN);
	GPIO_PinOutClear(LEDPORT, GREENPIN); /* active low */
}

void
redLedOn(void)
{
	GPIO_PinOutSet(LEDPORT, GREENPIN);
	GPIO_PinOutClear(LEDPORT, REDPIN); /* active low */
}

void
initLeds(void)
{
	CMU_ClockEnable(cmuClock_GPIO, true);
	GPIO_PinModeSet(LEDPORT, REDPIN, gpioModePushPull, 1);
	GPIO_PinModeSet(LEDPORT, GREENPIN, gpioModePushPull, 1);
	greenLedOn();
}

void
initAdc(void)
{
	ADC_Init_TypeDef adc_init = ADC_INIT_DEFAULT;

	CMU_ClockEnable(cmuClock_ADC0, true);
	CMU_ClockEnable(cmuClock_HFPER, true); /* TODO necessary? */

	adc_init.warmUpMode = adcWarmupKeepADCWarm;
	ADC_Init(ADC0, &adc_init);
}

void
initVcom()
{
	RETARGET_SerialInit();
	RETARGET_SerialCrLf(1);

	printf("VCOM enabled\n");
}

int
main(void)
{
	CHIP_Init();
	initLeds();
	initAdc();
	initVcom();

	printf("adc: %lu\n", measurePot());

	for (;;)
		;
}
