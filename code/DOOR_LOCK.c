/*
 * DOOR_LOCK.c
 *
 *  Created on: Mar 11, 2020
 *      Author: Asmaa Hashim
 */

#include"DOOR_LOCK.h"

/*************************************Global variables************************************/

static unint8 Password_buffer[SIZE_OF_PASSWARD ];

static unint8 Correct_Password_buffer[SIZE_OF_PASSWARD ];

/******************************static function***************************************************/

static void store_init_password(void)
{
	unint8 i , val;
	EEPROM_readByte(0x0000, &val);  /* Read 0x0F from the external EEPROM */
	_delay_ms(10);
	if(val != 0xAA)
	{
		EEPROM_writeByte(0x0000, 0xAA);
		_delay_ms(10);
		for(i=0 ; i< SIZE_OF_PASSWARD ; i++)
		{
			EEPROM_writeByte((BASE_ADDRESS + i),  INIT_PASSWARD);
			_delay_ms(10);
		}
	}
}
static void Copy_correct_password(void)
{
	unint8 i , val;

	for(i=0 ; i< SIZE_OF_PASSWARD ; i++)
	{
		EEPROM_readByte((BASE_ADDRESS + i), &val);
	    _delay_ms(10);
	    Correct_Password_buffer[i]=val;
	}
}

/*******************************global functions implementation**********************************/

void door_lock_init(void)
{
	EEPROM_init();
	keypad_init();
    LCD_init();
    SET_BIT(DDRB , PB4);
    SET_BIT(DDRB , PB5);
    CLEAR_BIT(DDRC , PC2);
    CLEAR_BIT(DDRC , PC3);
    SET_BIT(PORTC , PC2);
    SET_BIT(PORTC , PC3);
    store_init_password();
    Copy_correct_password();
}

void scan_password(void)
{
	unint8 digit , i;

	for(i=0 ; i<SIZE_OF_PASSWARD ;i++)
	{
		digit=key_pressed();

	    LCD_displayStringOnRowColum(1 , i , "*");

	    Password_buffer[i]=digit;
	}
}

unint8 check_password(void)
{
	unint8 i;

	for(i=0 ; i<SIZE_OF_PASSWARD ;i++)
	{
		if( Password_buffer[i] !=Correct_Password_buffer[i])  return 0;
	}

	return 1;
}

unint8 check_mode(void)
{
	unint8 return_val;

	return_val = key_pressed();

	return return_val;
}

void open_the_door(void)
{
	LCD_clear_screen();

    LCD_displayStringOnRowColum(0 , 0 , "DOOR IS OPENED");

    SET_BIT(PORTB , PB4);

    CLEAR_BIT(PORTB , PB5);

}

void close_the_door(void)
{
	LCD_clear_screen();
    SET_BIT(PORTB , PB4);
    SET_BIT(PORTB , PB5);

}

void scan_new_password(void)
{
	unint8 digit , i;

	LCD_displayStringOnRowColum(1 , 0 , "                                   ");

	for(i=0 ; i<SIZE_OF_PASSWARD ;i++)
	{
		digit=key_pressed();

		LCD_displayStringOnRowColum(1 , i , "*");

		Password_buffer[i]=digit;

	    EEPROM_writeByte((BASE_ADDRESS + i), digit);

		_delay_ms(10);

		Correct_Password_buffer[i]=digit;
	}
}











