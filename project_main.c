/**
 * @file main.c
 * @author 314695 V Sai Sumanth
 * @brief  Seat Heating Application.when both seat and heat button are ON then we are going to read the analog value from the sensor.Then we are Converting Analog value to Digital value.Then generating PWM wave form with their respective duty cycle.And displaying the respective temperature.
 * @version 0.1
 * @date 2021-07-24
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "Activity4.h"
/**
 * @brief Main function where the code execution starts
 * @note when both seat and heat button are ON then we are going to read the analog value from the sensor.
 * @note Then we are Converting Analog value to Digital value.
 * @note Then generating PWM wave form with their respective duty cycle.And displaying the respective temperature.
 * @return int Return 0 if the program completes successfully
 */
int main(void)
{
    /* Initialize Peripherals */
    peripheral_init();
    peripheral_init_ADC();
    peripheral_init_pwm();
    peripheral_init_usart(Baudrate);
    uint16_t digital_temp_value=0;
    while(1)
    {
        if(SeatButton_ON) //Checking Seat Button is ON or OFF.
        {
            if(HeaterButton_ON)  //Checking Heater Button is ON or OFF.
            {                     //If both are ON  then enter into this if loop.
                change_led_state(LED_ON);
                digital_temp_value=ReadADC(channel); //Analog to Digital Conversion.
                generate_pwm(digital_temp_value);  //Generating the respective PWM wave form.
                uart_transmit(digital_temp_value);    //Transmiting the Temperature value using UART protocol.
                delay(LED_ON_TIME);
            }
            else
            {
                change_led_state(LED_OFF);
                delay(LED_OFF_TIME);
            }
        }
        else
        {
            change_led_state(LED_OFF);
            delay(LED_OFF_TIME);
        }
    }
    return 0;
}
