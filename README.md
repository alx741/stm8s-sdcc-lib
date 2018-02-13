Library for the *STM8S103F3* device and the *SDCC* compiler.

## Using

Copy the `stm3s103f3.h` file into your project directory and include it.

## Example

Blink a LED on PB5 pin.

Let the file `main.c` be:

```c
#include "stm8s103f3.h"

int main()
{
    int delay_cnt;

    PB_DDR = 0x20;
    PB_CR1 = 0x20;

    while (1)
    {
        for (delay_cnt = 0; delay_cnt < 29000; delay_cnt++) {}
        PB_ODR ^= 0x20;
    }
}
```

Compile with:

    $ sdcc -lstm8 -mstm8 --out-fmt-ihx main.c -o main

Flash with:

    $ sdcc -lstm8 -mstm8 --out-fmt-ihx main.c -o main
	$ stm8flash -pstm8s103f3 -cstlinkv2 -w main.ihx
