#ifndef _DEFINES_H_
#define _DEFINES_H_

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "USART0.h"

#define RELAYS_AMOUNT 16

#define INPUT       0
#define OUTPUT      1

#define HIGH    true
#define LOW     false

#define ACTIVE_STATE LOW

void pin_mode(char ddr, uint8_t pin, bool state);
void digital_write(char port, uint8_t pin, bool state);


#endif /* _DEFINES_H_ */