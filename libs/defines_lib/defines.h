#ifndef _DEFINES_H_
#define _DEFINES_H_

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>

#include "USART0.h"

#define RELAYS_AMOUNT 16

#define INPUT       0
#define OUTPUT      1
#define pin_mode(ddr, pin, state) *(ddr) = state ? *(ddr)|(1<<pin) : *(ddr)&(~(1<<pin))

#define HIGH    1
#define LOW     0
#define digital_write(port, pin, val) *(port) = val ? *(port)|(1<<pin) : *(port)&(~(1<<pin))

#define ACTIVE_STATE LOW

struct relay_t {
    volatile uint8_t *ddr;
    volatile uint8_t *port;
    volatile uint8_t pin;
};

uint8_t *get_ddr(uint8_t relay_num);
uint8_t *get_port(uint8_t relay_num);
uint8_t get_pin(uint8_t relay_num);


#endif /* _DEFINES_H_ */