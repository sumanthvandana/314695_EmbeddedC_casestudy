#ifndef ACTIVITY2_H_INCLUDED
#define ACTIVITY2_H_INCLUDED
/**
 * @file Activity2.h
 * @author 314695 Vandana Sai Sumanth
 * @brief Analog to digital Conversion
 * @version 0.1
 * @date 2021-07-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "Activity1.h"
#define channel (0)
/**
 * @brief To initialize the ADC peripherals
 * 
 */
void peripheral_init_ADC();
/**
 * @brief Analog to digital Conversion
 * 
 * @param[in] ch It will tell the software that for which channel the sensor is physically connected.
 * 
 * @return Return Digital value for the analog value read by the sensor. 
 */
uint16_t ReadADC(uint8_t );

#endif // ACTIVITY2_H_INCLUDED