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

#pragma once

#include "mpu6050_registers.h"
#include <stdint.h>
#include <stdbool.h>

/* MPU6050 boots up into sleep mode. All registers, except for PWR_MGMT_1 and
 * WHO_I_AM, will have a reset value of 0x00, until the device wakes up.
 *
 * Booting, resetting and waking up operations can take up to 100ms. Make sure
 * to give the device some time.
 */

typedef struct
{
    float X, Y, Z;
} ACCEL_t;

typedef struct
{
    float X, Y, Z;
} GYRO_t;

void mpu6050_select_address(bool ad0);
void mpu6050_wake_up(void);
uint8_t mpu6050_read_register(uint8_t reg);
void mpu6050_read_accel(ACCEL_t *accel);
void mpu6050_read_gyro(GYRO_t *gyro);
TEMP_RAW_t mpu6050_read_temp(void);
