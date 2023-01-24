#include "defines.h"

uint8_t *get_ddr(uint8_t relay_num)
{
    if (relay_num >= 0 && relay_num <= 5 )
        return (uint8_t*)&DDRD;
    else if (relay_num >= 6 && relay_num <= 11 )
        return (uint8_t*)&DDRB;
    else if (relay_num >= 12 && relay_num <= 15 )
        return (uint8_t*)&DDRC;
    else
        return NULL;
}

uint8_t *get_port(uint8_t relay_num)
{
    if (relay_num >= 0 && relay_num <= 5 )
        return (uint8_t*)&PORTD;
    else if (relay_num >= 6 && relay_num <= 11 )
        return (uint8_t*)&PORTB;
    else if (relay_num >= 12 && relay_num <= 15 )
        return (uint8_t*)&PORTC;
    else
        return NULL;
}

uint8_t get_pin(uint8_t relay_num)
{
    if (relay_num >= 0 && relay_num <= 5 )
        return relay_num + 2;
    else if (relay_num >= 6 && relay_num <= 11 )
        return relay_num - 6;
    else if (relay_num >= 12 && relay_num <= 15 )
        return relay_num - 12;
    else
        return -1;
}