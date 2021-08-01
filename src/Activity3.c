/**
 * @file Activity3.c
 * @author 314695 Vandana Sai Sumanth
 * @brief Having the functions required for the PWM wave generation.
 * @version 0.1
 * @date 2021-07-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Activity3.h"
/**
 * @brief To initialize the PWM peripherals.
 * 
 */
void peripheral_init_pwm()
{
    TCCR1A |=(1<<COM1A1) |(1<<WGM11) |(1<<WGM10);
    TCCR1B |=(1<<WGM12) | (1<<CS12);
    DDRB |=(1<<PB1);
}
/**
 * @brief To Generate the PWM wave form.
 * 
 */
void generate_pwm(uint16_t digital_temp_value)
{
    if(digital_temp_value<= (0b11001000))
    {
        OCR1A= 205;     /* To generate PWM wave form with 20% duty cycle */
        _delay_ms(200);

    }
    else if(digital_temp_value>=(0b11001001) && digital_temp_value<=(0b111110100))
    {
        OCR1A= 410;    /* To generate PWM wave form with 40% duty cycle */
        _delay_ms(200);

    }
    else if(digital_temp_value>=(0b111110101) && digital_temp_value<=(0b1010111100))
    {
        OCR1A= 710;   /* To generate PWM wave form with 70% duty cycle */
        _delay_ms(200);

    }
    else
    {
        OCR1A= 970;   /* To generate PWM wave form with 95% duty cycle */
        _delay_ms(200);
    }
}