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
 *      #include "some/path/stm8s103f3.h"
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

// Available Data Directions
//
// e.g. Pin PA1 as input and Pin PC5 as output
//   ...
//   PORTA.DDR1 = INPUT_MODE;
//   PORTC.DDR5 = OUTPUT_MODE;
//   ...
#define   INPUT_MODE    0
#define   OUTPUT_MODE   1

// Available CR1 I/O modes
//
// e.g. Pin PA1 as floating input and Pin PC5 as output with push-pull
//   ...
//   PORTA.DDR1 = INPUT_MODE;
//   PORTC.DDR5 = OUTPUT_MODE;
//
//   PORTA.CR11 = INPUT_FLOATING;
//   PORTC.CR15 = OUTPUT_PUSH-PULL;
//   ...
#define   INPUT_FLOATING      0
#define   INPUT_PULL-UP       1
#define   OUTPUT_OPEN_DRAIN   0
#define   OUTPUT_PUSH-PULL    1

// Available CR2 I/O interrupts and speed
//
// e.g. Pin PA1 as input with interrupt and Pin PC5 as output at 10MHz
//   ...
//   PORTA.DDR1 = INPUT_MODE;
//   PORTC.DDR5 = OUTPUT_MODE;
//
//   PORTA.CR21 = INPUT_INTERRUPT_ENABLED;
//   PORTC.CR25 = OUTPUT_10MHZ;
//   ...
#define   INPUT_INTERRUPT_ENABLED     0
#define   INPUT_INTERRUPT_DISABLED    1
#define   OUTPUT_2MHZ                 0
#define   OUTPUT_10MHZ                1


typedef struct
{
    union
    {
        uint8_t ODR;
        struct
        {
            unsigned ODR0 : 1;
            unsigned ODR1 : 1;
            unsigned ODR2 : 1;
            unsigned ODR3 : 1;
            unsigned ODR4 : 1;
            unsigned ODR5 : 1;
            unsigned ODR6 : 1;
            unsigned ODR7 : 1;
        };
    };
    union
    {
        uint8_t IDR;
        struct
        {
            unsigned IDR0 : 1;
            unsigned IDR1 : 1;
            unsigned IDR2 : 1;
            unsigned IDR3 : 1;
            unsigned IDR4 : 1;
            unsigned IDR5 : 1;
            unsigned IDR6 : 1;
            unsigned IDR7 : 1;
        };
    };
    union
    {
        uint8_t DDR;
        struct
        {
            unsigned DDR0 : 1;
            unsigned DDR1 : 1;
            unsigned DDR2 : 1;
            unsigned DDR3 : 1;
            unsigned DDR4 : 1;
            unsigned DDR5 : 1;
            unsigned DDR6 : 1;
            unsigned DDR7 : 1;
        };
    };
    union
    {
        uint8_t CR1;
        struct
        {
            unsigned CR10 : 1;
            unsigned CR11 : 1;
            unsigned CR12 : 1;
            unsigned CR13 : 1;
            unsigned CR14 : 1;
            unsigned CR15 : 1;
            unsigned CR16 : 1;
            unsigned CR17 : 1;
        };
    };
    union
    {
        uint8_t CR2;
        struct
        {
            unsigned CR20 : 1;
            unsigned CR21 : 1;
            unsigned CR22 : 1;
            unsigned CR23 : 1;
            unsigned CR24 : 1;
            unsigned CR25 : 1;
            unsigned CR26 : 1;
            unsigned CR27 : 1;
        };
    };
} GPIO_PORT_t;

volatile __at(_GPIO_PERIPH_BASE + 0)  GPIO_PORT_t   PORTA;
volatile __at(_GPIO_PERIPH_BASE + 5)  GPIO_PORT_t   PORTB;
volatile __at(_GPIO_PERIPH_BASE + 10) GPIO_PORT_t   PORTC;
volatile __at(_GPIO_PERIPH_BASE + 15) GPIO_PORT_t   PORTD;
volatile __at(_GPIO_PERIPH_BASE + 20) GPIO_PORT_t   PORTE;
volatile __at(_GPIO_PERIPH_BASE + 25) GPIO_PORT_t   PORTF;




/*
 * Interrupt controller
 */

// Available IRQs
//
// e.g. Create an ISR for external PORTA interrupts
//   ...
//   void custom_isr(void) __interrupt(IRQ_EXTI0_PORTA)
//   {
//       // Handler code here
//   }
//   ...
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

// Available Software Priorities for ITC_SPR registers
//
// e.g. Use level 2 priority for external PORTA interrupts
//   ...
//   ITC_SPR.EXTI0_PORTA = SP_LEVEL_2;
//   ...
#define   SP_LEVEL_0   0b10
#define   SP_LEVEL_1   0b01
#define   SP_LEVEL_2   0b00
#define   SP_LEVEL_3   0b11

// Available external interrupt sensitivities
//
// e.g. Trigger interrupt on rising edge only for external PORTA pins:
//   ...
//   EXTI_CR1.PAIS = RISING_EDGE;
//   ...
#define   FALLING_EDGE_LOW_LEVEL   0b00
#define   RISING_EDGE              0b01
#define   FALLING_EDGE             0b10
#define   RISING_FALLING_EDGE      0b11

typedef struct
{
    unsigned TLI                  : 2;
    unsigned AWU                  : 2;
    unsigned CLK                  : 2;
    unsigned EXTI0_PORTA          : 2;
    unsigned EXTI1_PORTB          : 2;
    unsigned EXTI2_PORTC          : 2;
    unsigned EXTI3_PORTD          : 2;
    unsigned EXTI4_PORTE          : 2;
    unsigned                      : 2;
    unsigned                      : 2;
    unsigned SPI_END_TRANSFER     : 2;
    unsigned TIM1                 : 2;
    unsigned TIM1_CAPTURE_COMPARE : 2;
    unsigned TIM2                 : 2;
    unsigned TIM2_CAPTURE_COMPARE : 2;
    unsigned                      : 2;
    unsigned                      : 2;
    unsigned UART1_TX_COMPLETE    : 2;
    unsigned UART1_DATA_FULL      : 2;
    unsigned I2C                  : 2;
    unsigned                      : 2;
    unsigned                      : 2;
    unsigned ADC1                 : 2;
    unsigned TIM4                 : 2;
    unsigned FLASH                : 2;
} ITC_SPR_t;

typedef struct
{
    unsigned PAIS  : 2;
    unsigned PBIS  : 2;
    unsigned PCIS  : 2;
    unsigned PDIS  : 2;
} EXTI_CR1_t;

typedef struct
{
    unsigned PEIS  : 2;
    unsigned TLIS  : 2;
} EXTI_CR2_t;

volatile __at(0x7F0A) uint8_t     CCR;
volatile __at(0x7F70) ITC_SPR_t   ITC_SPR;
volatile __at(0x50A0) EXTI_CR1_t   EXTI_CR1;
volatile __at(0x50A1) EXTI_CR2_t   EXTI_CR2;
