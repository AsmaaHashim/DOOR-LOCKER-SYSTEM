/*
 * DOOR_LOCK.h
 *
 *  Created on: Mar 11, 2020
 *      Author: Asmaa Hashim
 */

#ifndef DOOR_LOCK_H_
#define DOOR_LOCK_H_

/*****************************************INCLUDES FILE**********************************/
#include "lcd.h"
#include "keypad.h"
#include "eeprom.h"

/****************************************MACROS*****************************************/
#define SIZE_OF_PASSWARD   5

#define BASE_ADDRESS       0x0311

#define INIT_PASSWARD      0x01

#define NEW_PASSWORD_MODE  '+'

#define OLD_PASSWORD_MODE  '-'

#define CHECK_DOOR_STATE() READ_BIT(PINC , PC2)

#define SYSTEM_STATE()     READ_BIT(PINC , PC3)


/***************************************FUNCTIONS PROTOTYPE***************************/
void door_lock_init(void);
void scan_password(void);
void scan_new_password(void);
unint8 check_password(void);
void open_the_door(void);
void close_the_door(void);
unint8 check_mode(void);

#endif /* DOOR_LOCK_H_ */
