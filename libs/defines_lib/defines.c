#include "defines.h"

void pin_mode(char ddr, uint8_t pin, bool state)
{
    switch (ddr) {
        case 'B':
            DDRB = state ? DDRB|(1<<pin) : DDRB&(~(1<<pin));
            break;

        case 'C':
            DDRC = state ? DDRC|(1<<pin) : DDRC&(~(1<<pin));
            break;
        
        case 'D':
            DDRD = state ? DDRD|(1<<pin) : DDRD&(~(1<<pin));
            break;
        
        default:
            break;
    }
}

void digital_write(char port, uint8_t pin, bool state)
{
    switch (port) {
        case 'B':
            PORTB = state ? PORTB|(1<<pin) : PORTB&(~(1<<pin));
            break;

        case 'C':
            PORTC = state ? PORTC|(1<<pin) : PORTC&(~(1<<pin));
            break;
        
        case 'D':
            PORTD = state ? PORTD|(1<<pin) : PORTD&(~(1<<pin));
            break;
        
        default:
            break;
        }
}
