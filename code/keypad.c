/*
 * keypad.c
 *
 *  Created on: Mar 11, 2020
 *      Author: Asmaa Hashim
 */



#include "keypad.h"

static const unint8 keypad[ROW_NUM][COLUM_NUM]={ {7 , 8 , 9 , '/' },
		                                         {4 , 5 , 6 , '*' },
	                                             {1 , 2 , 3 , '-' },
	                                             {'c', 0 ,'=','+' },
                                               };

void keypad_init(void)
{
	KEY_DDR = 0x0f;

    KEY_PORT = 0xff;
}

unint8 key_pressed()
{
	unint8 i , j ;

while(1)
{
		for(i=0 ; i < ROW_NUM ; i++)
		{
			KEY_PORT &=~(1u << i);
            _delay_ms(1);
			for(j=0 ; j < COLUM_NUM  ; j++)
			{
				if(!READ_BIT(KEY_PIN , j+4))
				{
					while(!READ_BIT(KEY_PIN , j+4));

					return keypad[i][j];
				}
			}

			KEY_PORT |=(1u << i);

		}
	}}
