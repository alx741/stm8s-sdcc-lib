#include <stm8s.h>

void delay(void)
{
    for (int delay_cnt = 0; delay_cnt < 30000; delay_cnt++) {}
}

int main()
{

    PORTB.DDR5 = DDR_OUTPUT_MODE;
    PORTB.CR15 = CR1_OUTPUT_PUSH_PULL;

    // Blink LED
    while (1)
    {
        delay();
        PORTB.ODR5 ^= 1;
    }
}
