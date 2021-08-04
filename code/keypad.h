/*
 * keypad.h
 *
 *  Created on: Mar 11, 2020
 *      Author: Asmaa Hashim
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include<avr/io.h>
#include<util/delay.h>

#include"data_types.h"

#include "std_macros.h"

#define KEY_DDR  DDRD

#define KEY_PORT PORTD

#define KEY_PIN  PIND

#define ROW_NUM  4

#define COLUM_NUM 4

void keypad_init(void);

unint8 key_pressed();

#endif /* KEYPAD_H_ */
