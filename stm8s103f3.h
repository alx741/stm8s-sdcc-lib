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
 * Registers
 * ---------
 */

/* Unique ID */
typedef struct
{
    uint16_t X_COORD_WAFER;
    uint16_t Y_COORD_WAFER;
    uint8_t  WAFER_NUMBER;
    uint32_t LOT_NUMBER_LOW;
    uint32_t LOT_NUMBER_HIGH;
} UNIQUE_ID_t;

volatile __at(_UNIQUE_ID_BASE)  UNIQUE_ID_t UNIQUE_ID;


/* GPIO ports */
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


/* Interrupt controller */
typedef struct
{
    unsigned VECT0SPR  : 2;
    unsigned VECT1SPR  : 2;
    unsigned VECT2SPR  : 2;
    unsigned VECT3SPR  : 2;
    unsigned VECT4SPR  : 2;
    unsigned VECT5SPR  : 2;
    unsigned VECT6SPR  : 2;
    unsigned VECT7SPR  : 2;
    unsigned VECT8SPR  : 2;
    unsigned VECT9SPR  : 2;
    unsigned VECT10SPR : 2;
    unsigned VECT11SPR : 2;
    unsigned VECT12SPR : 2;
    unsigned VECT13SPR : 2;
    unsigned VECT14SPR : 2;
    unsigned VECT15SPR : 2;
    unsigned VECT16SPR : 2;
    unsigned VECT17SPR : 2;
    unsigned VECT18SPR : 2;
    unsigned VECT19SPR : 2;
    unsigned VECT20SPR : 2;
    unsigned VECT21SPR : 2;
    unsigned VECT22SPR : 2;
    unsigned VECT23SPR : 2;
    unsigned VECT24SPR : 2;
    unsigned VECT25SPR : 2;
    unsigned VECT26SPR : 2;
    unsigned VECT27SPR : 2;
    unsigned VECT28SPR : 2;
    unsigned VECT29SPR : 2;
} ITC_SPR_t;

#define SPR_LEVEL_0  0b10
#define SPR_LEVEL_1  0b01
#define SPR_LEVEL_2  0b00
#define SPR_LEVEL_3  0b11

volatile __at(0x7F0A) uint8_t   CCR;
volatile __at(0x7F70) ITC_SPR_t ITC_SPR;

volatile __at(0x50A0) uint8_t EXTI_CR1;
volatile __at(0x50A1) uint8_t EXTI_CR2;
