#include "defines.h"

int main(void)
{
    USART0_init();

    struct relay_t relay_list[RELAYS_AMOUNT];

    for (uint8_t i = 0; i < RELAYS_AMOUNT; i++) {
        relay_list[i].ddr = get_ddr(i);
        relay_list[i].port = get_port(i);
        relay_list[i].pin = get_pin(i);

        _delay_ms(10);

        pin_mode(relay_list[i].ddr, relay_list[i].pin, OUTPUT);
        digital_write(relay_list[i].port, relay_list[i].pin, !ACTIVE_STATE);
    }

    int relay;
    int state;
    char buff[128];

    _delay_ms(100);

    sei();

    while (1) {

        if(USART0_GetStatus() == RECEIVED_OK) {
            USART0_ReadBuffer(buff);

            sscanf(buff, "%d %d", &relay, &state);

            /* First relay for user is 1st and firs relay for code is 0th, so we
            need decrement relay number by 1*/
            relay--;

            if (state == 1)
                digital_write(relay_list[relay].port, relay_list[relay].pin, ACTIVE_STATE);
            else if (state == 0)
                digital_write(relay_list[relay].port, relay_list[relay].pin, !ACTIVE_STATE);

            USART0_DataWasRead();
        }

    }
    return 0;
}
