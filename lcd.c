/*
 * lcd.c
 *
 *  Created on: Nov 5, 2020
 *      Author: BAHAA
 */

#include "lcd.h"

void LCD_init(){
	DDRC = 0xFF;
	DDRD |= (1<<4) | (1<<5) | (1<<6);
	LCD_sendCommand(0x01);
	LCD_sendCommand(0x0C);
	LCD_sendCommand(0x38);

}
void LCD_sendCommand(uint8 command){
	CLEAR_BIT(PORTD,4);
	CLEAR_BIT(PORTD,5);
	_delay_ms(1);
	SET_BIT(PORTD,6);
	_delay_ms(1);
	PORTC = command;
	_delay_ms(1);
	CLEAR_BIT(PORTD,6);
	_delay_ms(1);

}

void LCD_displayCharacter(uint8 data){
	SET_BIT(PORTD,4);
	CLEAR_BIT(PORTD,5);
	_delay_ms(1);
	SET_BIT(PORTD,6);
	_delay_ms(1);
	PORTC = data;
	_delay_ms(1);
	CLEAR_BIT(PORTD,6);
	_delay_ms(1);

}

void LCD_displayString(const char *str){
	for(uint8 i=0; str[i]!='\0'; i++){
		LCD_displayCharacter(str[i]);
	}
}

void LCD_goToRowColumn(uint8 row, uint8 col){
	uint8 address;
	switch(row){
		case 0: address = col;
				break;
		case 1: address = col+0x40;
				break;
		case 2:	address = col+0x10;
				break;
		case 3: address = col+0x50;
				break;
	}
	LCD_sendCommand(address | 0x80);
}

void LCD_displayStringRowColumn(uint8 row, uint8 col, const char *str){
	LCD_goToRowColumn(row, col);
	LCD_displayString(str);
}
void LCD_integerToString(uint16 num){
	char arr[16];
	itoa(num,arr,10);
	LCD_displayString(arr);
}

void LCD_clearScreen(){
	LCD_sendCommand(0x01);
}
