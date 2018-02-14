/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


/*
 * This file declares registers for the STM8S103F3 device
 *
 * To use it, include this file in your C code:
 *      #include "/path/stm8s103f3.h"
 */

#pragma once

#include <stdint.h>


/*
 * Memory map
 */
#define _RAM_BASE           0x0000
#define _EEPROM_BASE        0x4000
#define _OPTION_BYTES_BASE  0x4800
#define _UNIQUE_ID_BASE     0x4865
#define _GPIO_PERIPH_BASE   0x5000
#define _CPU_ITC_BASE       0x7F00


/*
 * Unique ID
 */
typedef struct
{
    uint16_t X_COORD_WAFER;
    uint16_t Y_COORD_WAFER;
    uint8_t  WAFER_NUMBER;
    uint32_t LOT_NUMBER_LOW;
    uint32_t LOT_NUMBER_HIGH;
} UNIQUE_ID_t;

volatile __at(_UNIQUE_ID_BASE)  UNIQUE_ID_t UNIQUE_ID;


/*
 * GPIO ports
 */
typedef struct
{
    union
    {
        uint8_t ODR;
        struct
        {
            unsigned OP0 : 1;
            unsigned OP1 : 1;
            unsigned OP2 : 1;
            unsigned OP3 : 1;
            unsigned OP4 : 1;
            unsigned OP5 : 1;
            unsigned OP6 : 1;
            unsigned OP7 : 1;
        };
    };
    union
    {
        uint8_t IDR;
        struct
        {
            unsigned IP0 : 1;
            unsigned IP1 : 1;
            unsigned IP2 : 1;
            unsigned IP3 : 1;
            unsigned IP4 : 1;
            unsigned IP5 : 1;
            unsigned IP6 : 1;
            unsigned IP7 : 1;
        };
    };
    uint8_t DDR;
    uint8_t CR1;
    uint8_t CR2;
} GPIO_PORT_t;

volatile __at(_GPIO_PERIPH_BASE + 0)  GPIO_PORT_t PORTA;
volatile __at(_GPIO_PERIPH_BASE + 5)  GPIO_PORT_t PORTB;
volatile __at(_GPIO_PERIPH_BASE + 10) GPIO_PORT_t PORTC;
volatile __at(_GPIO_PERIPH_BASE + 15) GPIO_PORT_t PORTD;
volatile __at(_GPIO_PERIPH_BASE + 20) GPIO_PORT_t PORTE;
volatile __at(_GPIO_PERIPH_BASE + 25) GPIO_PORT_t PORTF;


/*
 * Interrupt controller
 */
#define IRQ0  0        #define IRQ11 11      #define IRQ22 22
#define IRQ1  1        #define IRQ12 12      #define IRQ23 23
#define IRQ2  2        #define IRQ13 13      #define IRQ24 24
#define IRQ3  3        #define IRQ14 14      #define IRQ25 25
#define IRQ4  4        #define IRQ15 15      #define IRQ26 26
#define IRQ5  5        #define IRQ16 16      #define IRQ27 27
#define IRQ6  6        #define IRQ17 17      #define IRQ28 28
#define IRQ7  7        #define IRQ18 18      #define IRQ29 29
#define IRQ8  8        #define IRQ19 19
#define IRQ9  9        #define IRQ20 20
#define IRQ10 10       #define IRQ21 21

// Available IRQs
//
// e.g.   void custom_isr(void) __interrupt(IRQ_EXTI0_PORTA) { }
#define   IRQ_TLI                        0
#define   IRQ_AWU                        1
#define   IRQ_CLK                        2
#define   IRQ_EXTI0_PORTA                3
#define   IRQ_EXTI1_PORTB                4
#define   IRQ_EXTI2_PORTC                5
#define   IRQ_EXTI3_PORTD                6
#define   IRQ_EXTI4_PORTE                7
#define   IRQ_SPI_END_TRANSFER           10
#define   IRQ_TIM1                       11
#define   IRQ_TIM1_CAPTURE_COMPARE       12
#define   IRQ_TIM2                       13
#define   IRQ_TIM2_CAPTURE_COMPARE       14
#define   IRQ_UART1_TX_COMPLETE          17
#define   IRQ_UART1_DATA_FULL            18
#define   IRQ_I2C                        19
#define   IRQ_ADC1                       22
#define   IRQ_TIM4                       23
#define   IRQ_FLASH                      24

typedef struct
{
    unsigned SP_TLI                  : 2;
    unsigned SP_AWU                  : 2;
    unsigned SP_CLK                  : 2;
    unsigned SP_EXTI0_PORTA          : 2;
    unsigned SP_EXTI1_PORTB          : 2;
    unsigned SP_EXTI2_PORTC          : 2;
    unsigned SP_EXTI3_PORTD          : 2;
    unsigned SP_EXTI4_PORTE          : 2;
    unsigned                         : 2;
    unsigned                         : 2;
    unsigned SP_SPI_END_TRANSFER     : 2;
    unsigned SP_TIM1                 : 2;
    unsigned SP_TIM1_CAPTURE_COMPARE : 2;
    unsigned SP_TIM2                 : 2;
    unsigned SP_TIM2_CAPTURE_COMPARE : 2;
    unsigned                         : 2;
    unsigned                         : 2;
    unsigned SP_UART1_TX_COMPLETE    : 2;
    unsigned SP_UART1_DATA_FULL      : 2;
    unsigned SP_I2C                  : 2;
    unsigned                         : 2;
    unsigned                         : 2;
    unsigned SP_ADC1                 : 2;
    unsigned SP_TIM4                 : 2;
    unsigned SP_FLASH                : 2;
} ITC_SPR_t;

volatile __at(0x7F0A) uint8_t   CCR;
volatile __at(0x7F70) ITC_SPR_t ITC_SPR;

// Available Software Priorities for ITC_SPR registers
//
// e.g.   ITC_SPR.SP_EXTI0_PORTA = SP_LEVEL_2;
#define SP_LEVEL_0  0b10
#define SP_LEVEL_1  0b01
#define SP_LEVEL_2  0b00
#define SP_LEVEL_3  0b11


volatile __at(0x50A0) uint8_t EXTI_CR1;
volatile __at(0x50A1) uint8_t EXTI_CR2;
