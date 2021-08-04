/*
 * lcd.h
 *
 *  Created on: Mar 11, 2020
 *      Author: Asmaa Hashim
 */

#ifndef LCD_H_
#define LCD_H_


#include <avr/io.h>

#include "std_macros.h"

#define DATA_BITS_MODE 8


#if (DATA_BITS_MODE == 4)

#define UPPER_PORT_BINS

#endif


/** LCD HW_BINS ***/

#define RS PB0

#define E  PB2

#define RW PB1

#define  LCD_CTRL_PORT_DIR  DDRB

#define LCD_CTRL_PORT       PORTB

#define LCD_DATA_PORT       PORTA

#define LCD_DIR_PORT     DDRA

/** LCD_COMMANDS **/

#define CLEAR_COMMAND  0X01

#define TWO_LINE_LCD_4BITS_MODE 0X28

#define TWO_LINE_LCD_8BITS_MODE 0X38

#define  CURSOR_ON 0X0E

#define CURSOR_OFF 0X0C

#define SET_CURSOR_LOCATION  0X80

#define SET_CGRAM_ADDRESS  0X40

#define RETURN_HOME  0X02

/**LCD FUNCTION PROTOTYPE***/

void LCD_init(void);

void LCD_sendCommand(unint8 commond);

void LCD_displayCharacter(unint8 ch);

void LCD_displayString(const unint8 *str);

void LCD_clear_screen(void);

void LCD_goToRowColum(unint8 row , unint8 colum);

void LCD_displayStringOnRowColum(unint8 row , unint8 colum , const unint8 *str);

void LCD_intgerToString(int data);

void LCD_store_pattren(unint8 *pattren , unint8 indix);



#endif /* LCD_H_ */
