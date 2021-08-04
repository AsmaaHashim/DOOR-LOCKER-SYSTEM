/*
 * main.c
 *
 *  Created on: Mar 12, 2020
 *      Author: Asmaa Hashim
 */


#include"DOOR_LOCK.h"

unint8 mode ;
int main(void)
{
	door_lock_init();
	while(1)
	{
		if(!SYSTEM_STATE())
		{
		    LCD_displayStringOnRowColum(0 , 0 , "+ NEW PASSWARD MODE");
		    LCD_displayStringOnRowColum(1 , 0 , "- OLD PASSWARD MODE");
            mode=check_mode();
            if(mode == '-')
            {
            	do
            	{
            	LCD_clear_screen();
    		    LCD_displayStringOnRowColum(0 , 0 , "ENTER THE PASSWARD");
    		    scan_password();
            	}while(!check_password());

            }
            else if('+')
            {
                do
                {
            	LCD_clear_screen();
    		    LCD_displayStringOnRowColum(0 , 0 , "ENTER THE OLD PASSWARD");
    		    scan_password();
            	}while(!check_password());
    		    LCD_displayStringOnRowColum(0 , 0 , "ENTER THE NEW PASSWARD");
    		    scan_new_password();
            }
            open_the_door();
            while(!CHECK_DOOR_STATE());
            close_the_door();

		}
	}
	return 0;
}
