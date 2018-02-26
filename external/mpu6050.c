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
 *
 * Copyright 2018 Daniel Campoverde Carrión [alx741]
 */

#include "mpu6050.h"
#include "mpu6050_registers.h"
#include "../i2c.h"


#define MPU_ADDR 0b11010000

void mpu6050_wake_up(void)
{
    i2c_start();
    i2c_slave_select(MPU_ADDR, I2C_TRANSMIT);
    i2c_transmit_byte(PWR_MGMT_1);
    i2c_transmit_byte(0x00);
    i2c_stop();
}
