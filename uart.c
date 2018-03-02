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

#include "uart.h"
#include "stm8s.h"
#include <stdint.h>

void uart_init_8bit(uint32_t fmaster, uint32_t baud_rate)
{
    uint16_t uart_div = (fmaster / baud_rate) + 1;

    UART_BRR2 = ((uart_div >> 12) & 0x0F) | (uart_div & 0x0F);
    UART_BRR1 = (uart_div >> 4) & 0xff;

    UART_CR1.UARTD = 0; // UART enabled
    UART_CR1.M     = 0; // 8 bit word
    UART_CR1.PCEN  = 0; // No parity
    UART_CR1.PIEN  = 0; // No parity interrupt
    UART_CR2.TEN = 1;   // Transmitter enabled
    UART_CR2.REN = 1;   // Receiver enabled
}

int putchar(int c)
{
    UART_DR = c;
    while (! UART_SR.TC) {}
    return c;
}

int getchar(void)
{
    while (! UART_SR.RXNE) {}
    return UART_DR;
}
