/*
 * project.c
 *
 *  Created on: Nov 5, 2020
 *      Author: BAHAA
 */

#include "lcd.h"
#include "adc.h"
#include "timer0.h"

int main(){
	uint16 result, temp=0;
	//timer0_init(64);
	//timer0_init(128);
	LCD_init();
	ADC_init();
	LCD_clearScreen();
	LCD_displayStringRowColumn(0, 2, "Value = ");
	PORTB |= (1<<1);
	DDRD &= ~(1<<7);

	//_delay_ms(5000);
	//timer0_init(128);
	while(1){
		result = ADC_readChannel(0);
		if(temp != result){
			if(result<=999 && temp>=1000){
				LCD_clearScreen();
				LCD_displayStringRowColumn(0, 2, "Value = ");
			}
			LCD_goToRowColumn(0, 10);
			LCD_integerToString(result);
			temp = result;

			timer0_init(result);
			//timer0_init(128.28282938);
		}
		if(PIND & (1<<7)){
			_delay_ms(30);
			if(PIND & (1<<7)){
				PORTB ^= (1<<1);
				PORTB ^= (1<<2);
			}while(PIND & (1<<7));

		}

	}
}

