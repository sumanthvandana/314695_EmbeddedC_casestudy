/**
 * @file Activity4.c
 * @author 314695 V Sai Sumanth
 * @brief Having Functions required by uART Serial Communication
 * @version 0.1
 * @date 2021-07-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "Activity4.h"
/**
 * @brief To initialize the UART serial communication.
 * 
 */
void peripheral_init_usart(uint16_t ubrr_value)
{
    UBRR0L=ubrr_value;
    UBRR0H=(ubrr_value>>8)&0x00ff;
    UCSR0C=(1<<UMSEL00) |(1<<UCSZ01) |(1<<UCSZ00);
    UCSR0B=(1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);

}
/**
 * @brief To write characters to send it to other UART port
 * 
 */
void usartWriteChar(char data)
{
    while(!(UCSR0A &(1<<UDRE0)));
    UDR0=data;

}
/**
 * @brief To provide the respective temperature value.
 * 
 */
void uart_transmit(uint16_t digital_temp_value)
{
    if(digital_temp_value<= (0b11001000))
    {
        usartWriteChar('2');
        usartWriteChar('0');
        usartWriteChar('C');
        usartWriteChar(' ');

    }

    else if(digital_temp_value>=(0b11001001) && digital_temp_value<=(0b111110100))
    {
        usartWriteChar('2');
        usartWriteChar('5');
        usartWriteChar('C');
        usartWriteChar(' ');

    }
    else if(digital_temp_value>=(0b111110101) && digital_temp_value <=(0b1010111100))
    {
        usartWriteChar('2');
        usartWriteChar('9');
        usartWriteChar('C');
        usartWriteChar(' ');
    }
    else
    {
        usartWriteChar('3');
        usartWriteChar('3');
        usartWriteChar('C');
        usartWriteChar(' ');
    }
}
