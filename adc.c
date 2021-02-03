/*
 * adc.c
 *
 *  Created on: Nov 5, 2020
 *      Author: BAHAA
 */

#include "adc.h"

void ADC_init(void)
{

	ADMUX = 0;
	ADCSRA = (1<<ADEN) | (1<<ADPS1) | (1<<ADPS0);
}

uint16 ADC_readChannel(uint8 channel_num)
{
	channel_num &= 0x07; /* channel number must be from 0 --> 7 */
	ADMUX &= 0xE0; /* clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = ADMUX | channel_num; /* choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA,ADSC); /* start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* wait for conversion to complete ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* clear ADIF by write '1' to it :) */
	return ADC; /* return the data register */
}


