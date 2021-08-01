/**
 * @file Activity2.c
 * @author 314695 V Sai Sumanth
 * @brief Having Functions required for performing Analog to Digital Conversion.
 * @version 0.1
 * @date 2021-07-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "Activity2.h"
/**
 * @brief To initialize the ADC peripherals
 * 
 */
void peripheral_init_ADC()
{
    ADMUX=(1<<REFS0);   //for Aref=Avcc
    ADCSRA=(1<<ADEN)| (7<<ADPS0);

}
/**
 * @brief Analog to digital Conversion
 * 
 * @param[in] ch It will tell the software that for which channel the sensor is physically connected.
 * 
 * @return Return Digital value for the analog value read by the sensor. 
 */
uint16_t ReadADC(uint8_t ch)
{
    //Select ADC Channel ch must be 0-7
    ADMUX &=0xf8;
    ch&=0b00000111;
    ADMUX|=ch;
    //Start single conversion
    ADCSRA |=(1<<ADSC);
    //Wait for conversion to complete
    while(!(ADCSRA&(1<<ADIF)));
    //Clear ADIF by writing one to it
    ADCSRA|=(1<<ADIF);
    return (ADC);

}
