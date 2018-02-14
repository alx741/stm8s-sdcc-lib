Library for *STM8S* devices and the *SDCC* compiler.

## Using

Copy the `stm3s.h` file into your project directory and include it.

## Example

Blink a LED on PB5 pin.

Let the file `main.c` be:

```c
#include "stm8s.h"

void delay(void)
{
    for (int delay_cnt = 0; delay_cnt < 30000; delay_cnt++) {}
}

int main()
{

    PORTB.DDR5 = OUTPUT_MODE;
    PORTB.CR15 = CR1_OUTPUT_PUSH_PULL;

    while (1)
    {
        delay();
        PORTB.ODR5 ^= 1;
    }
}
```

Compile with:

    $ sdcc -lstm8 -mstm8 --out-fmt-ihx main.c -o main

Flash with (assuming the STM8S103F3 part. Change accordingly):

	$ stm8flash -pstm8s103f3 -cstlinkv2 -w main.ihx
