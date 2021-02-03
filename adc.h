/*
 * adc.h
 *
 *  Created on: Nov 5, 2020
 *      Author: BAHAA
 */

#ifndef ADC_H_
#define ADC_H_

#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"


void ADC_init(void);


uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
