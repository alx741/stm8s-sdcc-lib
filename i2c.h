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

#pragma once

#include <stdint.h>

typedef enum I2C_MODE_t {I2C_READ, I2C_WRITE} I2C_MODE;

void i2c_init_100khz(void);
void i2c_start(void);
void i2c_stop(void);
void i2c_select_slave(uint8_t addr, I2C_MODE mode);
void i2c_transmit_byte(uint8_t data);
uint8_t i2c_receive_byte(void);
