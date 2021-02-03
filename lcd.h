/*
 * lcd.h
 *
 *  Created on: Nov 5, 2020
 *      Author: BAHAA
 */

#ifndef LCD_H_
#define LCD_H_

#include "common_macros.h"
#include "std_types.h"
#include "micro_config.h"

void LCD_init();
void LCD_sendCommand(uint8 command);
void LCD_displayCharacter(uint8 data);
void LCD_displayString(const char *str);
void LCD_goToRowColumn(uint8 row, uint8 col);
void LCD_displayStringRowColumn(uint8 row, uint8 col, const char *str);
void LCD_integerToString(uint16 num);
void LCD_clearScreen();


#endif /* LCD_H_ */
