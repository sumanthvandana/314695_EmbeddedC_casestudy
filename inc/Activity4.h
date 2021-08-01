#ifndef ACTIVITY4_H_INCLUDED
#define ACTIVITY4_H_INCLUDED
/**
 * @file Activity4.h
 * @author 314695 V Sai Sumanth
 * @brief To transmit the temperature value by using UART Protocol.
 * @version 0.1
 * @date 2021-04-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "Activity3.h"
#define Baudrate (103)
/**
 * @brief To initialize the UART serial communication.
 * 
 */
void peripheral_init_usart(uint16_t );
/**
 * @brief To write characters to send it to other UART port
 * 
 */
void usartWriteChar(char );
/**
 * @brief To provide the respective temperature value.
 * 
 */
void uart_transmit(uint16_t );


#endif // ACTIVITY4_H_INCLUDED
