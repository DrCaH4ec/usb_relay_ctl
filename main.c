#include "defines.h"

static const struct relay_t relay_list[RELAYS_AMOUNT] = {
    {'D', 2}, // rel_1
    {'D', 3}, // rel_2
    {'D', 4}, // rel_3
    {'D', 5}, // rel_4
    {'D', 6}, // rel_5
    {'D', 7}, // rel_6
    {'B', 0}, // rel_7
    {'B', 1}, // rel_8
    {'B', 2}, // rel_9
    {'B', 3}, // rel_10
    {'B', 4}, // rel_11
    {'B', 5}, // rel_12
    {'C', 0}, // rel_13
    {'C', 1}, // rel_14
    {'C', 2}, // rel_15
    {'C', 3}, // rel_16
};

int main(void)
{
    USART0_init();

    for (uint8_t i = 0; i < RELAYS_AMOUNT; i++) {
        pin_mode(relay_list[i].port, relay_list[i].pin, OUTPUT);
        digital_write(relay_list[i].port, relay_list[i].pin, !ACTIVE_STATE);

        _delay_ms(1);
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
