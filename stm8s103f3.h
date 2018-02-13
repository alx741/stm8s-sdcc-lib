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

volatile __at (0x5005) char PB_ODR;
volatile __at (0x5006) char PB_IDR;
volatile __at (0x5007) char PB_DDR;
volatile __at (0x5008) char PB_CR1;
volatile __at (0x5009) char PB_CR2;
