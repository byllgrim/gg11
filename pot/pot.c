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
measurePot()
{
	ADC_InitSingle_TypeDef single_init = {0}; /* TODO */
	uint32_t data = 0;

	//single_init.reference = VREF?
	//single_init.acqTime = ADC_ACQTIME?
	//single_init.resolution = ADC_RESOLUTION?
	//single_init.rep = true?
	//single_init.posSel = adcPosSelAPORT2XCH27?
	//single_init.negSel = adcNegSelVSS?
	ADC_InitSingle(ADC0, &single_init);

	ADC_Start(ADC0, adcStartSingle);
	/* TODO check data valid? adc->STATUS? */
	data = ADC_DataSingleGet(ADC0);
	return data;
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

	//adc_init.timebase = ADC_TimebaseCalc(0);
	//adc_init.prescale = ADC_PrescaleCalc(?, 0);
	//adc_init.warmUpMode = adcWarmupKeepADCWarm;
	ADC_Init(ADC0, &adc_init);
}

int
main(void)
{
	CHIP_Init();
	initLeds();
	initAdc();

	//measurePot();

	for (;;)
		;
}
