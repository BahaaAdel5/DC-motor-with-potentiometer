/*
 * timer0.c
 *
 *  Created on: Nov 6, 2020
 *      Author: BAHAA
 */

#include "timer0.h"
//#include <math.h>

void timer0_init(uint16 duty){
	TCNT0 = 0;
	//OCR0 = duty;
	//OCR0 = (uint8)((duty*255)/1023);
	OCR0 = (duty*0.25);
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
	DDRB |= (1<<3) | (1<<1) | (1<<2);

}


