/*
 * mini_proj3.c
 * By: Amr Mohamed Yousef
 * Diploma Number: 83
 * Facebook Name: Amr Mohamed
 * ======================================================================================================================================
 */

#include "std_types.h"
#include "adc.h"
#include "lcd.h"
#include "motor.h"
#include "lm35_sensor.h"
int main(void)
{
	uint8 temp;
	const ADC_ConfigType s_adcConfig = {INTERNAL,PS8};
	LCD_init(); /* initialize LCD driver */
	ADC_init(&s_adcConfig); /* initialize ADC driver */
	DcMotor_Init(); /* initialize DC Motor */
	LCD_moveCursor(0,3);
	LCD_displayString("FAN STATUS");
	LCD_moveCursor(1,3);
	LCD_displayString("Temp =    C");
	while(1)
	{
		temp = LM35_getTemperature();
		if(temp >= 120)
		{
			LCD_moveCursor(0,3);
			LCD_displayString("FAN is ON ");
			LCD_moveCursor(1,10);
			LCD_intgerToString(temp);
			DcMotor_Rotate(CW,100);
		}
		else if(temp >= 90)
		{
			LCD_moveCursor(0,3);
			LCD_displayString("FAN is ON ");
			LCD_moveCursor(1,10);
			if(temp >= 100)
			{
				LCD_intgerToString(temp);
			}
			else
			{
				LCD_intgerToString(temp);
				LCD_displayCharacter(' ');
			}
			DcMotor_Rotate(CW,75);
		}
		else if(temp >= 60)
		{
			LCD_moveCursor(0,3);
			LCD_displayString("FAN is ON ");
			LCD_moveCursor(1,10);
			LCD_intgerToString(temp);
			DcMotor_Rotate(CW,50);
		}
		else if(temp >= 30)
		{
			LCD_moveCursor(0,3);
			LCD_displayString("FAN is ON ");
			LCD_moveCursor(1,10);
			LCD_intgerToString(temp);
			DcMotor_Rotate(CW,25);
		}
		else
		{
			LCD_moveCursor(0,3);
			LCD_displayString("FAN is OFF");
			LCD_moveCursor(1,10);
			if(temp >= 10)
			{
				LCD_intgerToString(temp);
			}
			else
			{
				LCD_intgerToString(temp);
				LCD_displayCharacter(' ');
			}
			DcMotor_Rotate(stop,0);
		}

	}
}
