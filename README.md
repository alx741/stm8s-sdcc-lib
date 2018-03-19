Library for *STM8S* devices and the *SDCC* compiler.

## Using

Compile the library

    $ make

Copy the content of the `example` directory to your project

    $ cp example/* ~/me/my-project

Configure the parameters in the `Makefile`

* STM8SLIB_DIR
* SRC_DIR
* BINARY
* PARTNO


## Implemented

* Low level registers are available in `stm8s.h` to be used like in `register.bit = value;`
* UART
* I2C

### External drivers

* MPU6050
