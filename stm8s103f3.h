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
    uint8_t ODR;
    uint8_t IDR;
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
