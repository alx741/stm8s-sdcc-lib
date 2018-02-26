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

/* MPU6050 boots up into sleep mode, clear the PWR_MGMT_1.SLEEP bit
 * in order to wake it up.
 *
 * All registers, except for PWR_MGMT_1 and WHO_I_AM, will have a
 * reset value of 0x00, until the device wakes up.
 *
 * Booting, resetting and waking up operations can take up to 100ms. Make sure
 * to give the device some time.
 */


/* ----------------------------------------------
 *   Power Management
 * ----------------------------------------------
 */

#define PWR_MGMT_1   0x6B

typedef struct
{
    unsigned              : 3;
    unsigned TEMP_DIS     : 1;
    unsigned              : 1;
    unsigned CYCLE        : 1;
    unsigned SLEEP        : 1;
    unsigned DEVICE_RESET : 1;
} PWR_MGMT_1_t;


/* ----------------------------------------------
 *   Accelerometer
 * ----------------------------------------------
 */

#define ACCEL   0x3B

typedef struct
{
    uint16_t X;
    uint16_t Y;
    uint16_t Z;
} ACCEL_t;


/* ----------------------------------------------
 *   Gyroscope
 * ----------------------------------------------
 */

#define GYRO   0x43

typedef struct
{
    uint16_t X;
    uint16_t Y;
    uint16_t Z;
} GYRO_t;


/* ----------------------------------------------
 *   Temperature
 * ----------------------------------------------
 */

#define TEMP   0x41
typedef uint16_t  TEMP_t;


/* ----------------------------------------------
 *   Who Am I
 * ----------------------------------------------
 */

#define WHO_AM_I   0x75
typedef uint8_t  WHO_AM_I_t;
