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

#include "i2c.h"
#include "stm8s.h"
#include <stdint.h>
#include <stdbool.h>

void i2c_init_100khz(void)
{
    I2C_FREQR = 2;     // 2 MHz
    I2C_CCR = 0x000A;  // 100 KHz
    I2C_CR1.PE = true; // Enable peripheral
}

void i2c_start(void)
{
    I2C_CR2.START = true;
    while (! I2C_SR1.SB);
}

void i2c_stop(void)
{
    I2C_CR2.STOP = true;
    while (I2C_SR3.MSL);
}

void i2c_select_slave(uint8_t addr, I2C_MODE mode)
{
    volatile uint8_t dummy;

    switch (mode)
    {
        case I2C_READ:
            I2C_DR = addr | 0x01;
            break;
        case I2C_WRITE:
            I2C_DR = addr | 0x00;
            break;
    }
    while (! I2C_SR1.ADDR);
    dummy = (uint8_t) I2C_SR1.ADDR;
    dummy = (uint8_t) I2C_SR3.BUSY;
}

void i2c_transmit_byte(uint8_t data)
{
    I2C_DR = data;
    while (! I2C_SR1.TXE);
}

uint8_t i2c_receive_byte(void)
{
    while (! I2C_SR1.RXNE);
    return I2C_DR;
}
