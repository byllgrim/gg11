#include "em_adc.h"
#include "em_chip.h"

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

int
main(void)
{
	ADC_Init_TypeDef adc_init = ADC_INIT_DEFAULT;
	ADC_TypeDef adc = {0};

	CHIP_Init();
	/* TODO enable clocks: HFPERCLK? */
	ADC_Init(&adc, &adc_init);

	measurePot(&adc);

	for (;;)
		;
}
