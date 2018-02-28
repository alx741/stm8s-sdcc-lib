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
#include "../stm8s.h"
#include <string.h>
#include <stdbool.h>

#define MPU_AD0_LOW_ADDR 0b11010000
#define MPU_AD0_HIGH_ADDR 0b11010010

const static float AFS_SEL_0 = 16384;
const static float AFS_SEL_1 = 8192;
const static float AFS_SEL_2 = 4096;
const static float AFS_SEL_3 = 2048;

const static float FS_SEL_0 = 131;
const static float FS_SEL_1 = 65.5;
const static float FS_SEL_2 = 32.8;
const static float FS_SEL_3 = 16.4;

static const float g = 9.80665;
static uint8_t MPU_ADDR = MPU_AD0_LOW_ADDR;

float accel_AFS_factor(void);
float gyro_FS_factor(void);
void accel_raw_to_g(ACCEL_RAW_t *accel_raw, ACCEL_t *accel);
void gyro_raw_to_dps(GYRO_RAW_t *gyro_raw, GYRO_t *gyro);

void mpu6050_select_address(bool ad0)
{
    if (ad0)
    {
        MPU_ADDR = MPU_AD0_HIGH_ADDR;
    }
    else
    {
        MPU_ADDR = MPU_AD0_LOW_ADDR;
    }
}

void mpu6050_wake_up(void)
{
    i2c_start();
    i2c_slave_select(MPU_ADDR, I2C_TRANSMIT);
    i2c_transmit_byte(PWR_MGMT_1);
    i2c_transmit_byte(0x00);
    i2c_stop();
}

uint8_t mpu6050_read_register(uint8_t reg_address)
{
    i2c_start();
    i2c_slave_select(MPU_ADDR, I2C_TRANSMIT);
    i2c_transmit_byte(reg_address);
    i2c_start();
    i2c_slave_select(MPU_ADDR, I2C_RECEIVE);
    return i2c_receive_byte();
}

void mpu6050_read_accel(ACCEL_t *accel)
{
    ACCEL_RAW_t accel_raw;
    i2c_start();
    i2c_slave_select(MPU_ADDR, I2C_TRANSMIT);
    i2c_transmit_byte(ACCEL);
    i2c_start();
    i2c_slave_select(MPU_ADDR, I2C_RECEIVE);
    i2c_receive_bytestring((void*) &accel_raw, 6);
    accel_raw_to_g(&accel_raw, accel);
}

void mpu6050_read_gyro(GYRO_t *gyro)
{
    GYRO_RAW_t gyro_raw;
    i2c_start();
    i2c_slave_select(MPU_ADDR, I2C_TRANSMIT);
    i2c_transmit_byte(GYRO);
    i2c_start();
    i2c_slave_select(MPU_ADDR, I2C_RECEIVE);
    i2c_receive_bytestring((void*) &gyro_raw, 6);
    gyro_raw_to_dps(&gyro_raw, gyro);
}

TEMP_RAW_t mpu6050_read_temp(void)
{
    TEMP_RAW_t temp;
    i2c_start();
    i2c_slave_select(MPU_ADDR, I2C_TRANSMIT);
    i2c_transmit_byte(TEMP);
    i2c_start();
    i2c_slave_select(MPU_ADDR, I2C_RECEIVE);
    i2c_receive_bytestring((void*) &temp, 2);
    return temp;
}

void accel_raw_to_g(ACCEL_RAW_t *accel_raw, ACCEL_t *accel)
{
    float scaling_factor = accel_AFS_factor();
    accel->X = accel_raw->X / scaling_factor;
    accel->Y = accel_raw->Y / scaling_factor;
    accel->Z = accel_raw->Z / scaling_factor;
}

void gyro_raw_to_dps(GYRO_RAW_t *gyro_raw, GYRO_t *gyro)
{
    float scaling_factor = gyro_FS_factor();
    gyro->X = gyro_raw->X / scaling_factor;
    gyro->Y = gyro_raw->Y / scaling_factor;
    gyro->Z = gyro_raw->Z / scaling_factor;
}

float accel_AFS_factor(void)
{
    volatile ACCEL_CONFIG_t accel_config;
    uint8_t accel_config_byte = mpu6050_read_register(ACCEL_CONFIG);
    memcpy(&accel_config, &accel_config_byte, 1);

    switch (accel_config.AFS_SEL)
    {
        case 0:
            return AFS_SEL_0;
            break;
        case 1:
            return AFS_SEL_1;
            break;
        case 2:
            return AFS_SEL_2;
            break;
        case 3:
            return AFS_SEL_3;
            break;
    }
    return 0;
}

float gyro_FS_factor(void)
{
    volatile GYRO_CONFIG_t gyro_config;
    uint8_t gyro_config_byte = mpu6050_read_register(GYRO_CONFIG);
    memcpy(&gyro_config, &gyro_config_byte, 1);

    switch (gyro_config.FS_SEL)
    {
        case 0:
            return FS_SEL_0;
            break;
        case 1:
            return FS_SEL_1;
            break;
        case 2:
            return FS_SEL_2;
            break;
        case 3:
            return FS_SEL_3;
            break;
    }
    return 0;
}
