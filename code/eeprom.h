/*
 * eeprom.h
 *
 *  Created on: Mar 11, 2020
 *      Author: Asmaa Hashim
 */

#ifndef EEPROM_H_
#define EEPROM_H_



#include "data_types.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define ERROR 0
#define SUCCESS 1

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void  EEPROM_init(void);
unint8 EEPROM_writeByte(unint16 u16addr,unint8 u8data);
unint8 EEPROM_readByte(unint16 u16addr,unint8 *u8data);

#endif /* EEPROM_H_ */
