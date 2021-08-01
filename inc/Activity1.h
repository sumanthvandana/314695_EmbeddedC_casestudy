#ifndef ACTIVITY1_H_INCLUDED
#define ACTIVITY1_H_INCLUDED
/**
 * @file Activity1.h
 * @author 314695 V Sai Sumanth
 * @brief  To Blink an LED when both seat button and heater button are ON.
 * @version 0.1
 * @date 2021-07-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * Macro Definitions
 */
#define LED_ON 	(1)			/**< LED state HIGH */
#define LED_OFF	(0)			/**< LED state LOW */

#define LED_ON_TIME     (300)  /**< LED ON time in milli seconds  */
#define LED_OFF_TIME    (300)   /**< LED OFF time in milli seconds */

#define F_CPU 16000000UL 	/**< Clock Frequency of MCU is 16 MHz */

#define HeaterButton_ON !(PIND &(1<<PD0))
#define SeatButton_ON !(PIND &(1<<PD1))

/**
 * Include files
 */
#include <avr/io.h>
#include <util/delay.h>


/**
 * Function Definitions
 */


/**
 * @brief To configure the peripherals like heater button ,Seat button as Inputs and Led as output.
 * 
 */
void peripheral_init();
/**
 * @brief Change the state of the LED Pin according to the value of state
 *
 * @param state Pin level to which the LED Pin should be set
 */
void change_led_state(uint8_t );
/**
 * @brief Function to generate delay in micro seconds
 * 
 * @param[in] delay_time Delay in Micro seconds
 * 
 */
void delay(uint32_t );

#endif // ACTIVITY1_H_INCLUDED
