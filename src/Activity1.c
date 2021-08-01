/**
 * @file Activity1.c
 * @author 314695 Vandana Sai Sumanth
 * @brief Having the functions required for the led ON when both Seat button and Heater button are ON.
 * @version 0.1
 * @date 2021-07-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "Activity1.h"
/**
 * @brief To configure the peripherals like heater button ,Seat button as Inputs and Led as output.
 * 
 */
void peripheral_init()
{
    DDRB |=(1<<PB0);    /* Configure LED Pin as output*/
    DDRD &=~(1<<PD0);
    DDRD &=~(1<<PD1);
    PORTD |=(1<<PD0);
    PORTD |=(1<<PD1);
    
}
/**
 * @brief Change the state of the LED Pin according to the value of state
 *
 * @param state Pin level to which the LED Pin should be set
 */
void change_led_state(uint8_t state)
{
	PORTB = (state << PB0);
}
/**
 * @brief Function to generate delay in micro seconds
 * 
 * @param[in] delay_time Delay in Micro seconds
 * 
 */
void delay(uint32_t delay_time)
{
    uint32_t units = 0;
	for (units = 0; units <= delay_time; units++)
	{
		_delay_ms(1);
	}
}
