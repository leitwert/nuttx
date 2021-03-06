/************************************************************************************
 * arch/arm/src/lpc43xx/lpc43_config.h
 *
 *   Copyright (C) 2012, 2017 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ************************************************************************************/

#ifndef __ARCH_ARM_SRC_LPC43XX_LPC43XX_CONFIG_H
#define __ARCH_ARM_SRC_LPC43XX_LPC43XX_CONFIG_H

/************************************************************************************
 * Included Files
 ************************************************************************************/

#include <nuttx/config.h>

/************************************************************************************
 * Pre-processor Definitions
 ************************************************************************************/

/* Required configuration settings */

/* There are two version of the FPU support built into the most NuttX Cortex-M4 ports.
 * The current LPC43xx port support only one of these options, the "Non-Lazy Floating
 * Point Register Save".  As a consequence, CONFIG_ARMV7M_CMNVECTOR must be defined
 * in *all* LPC43xx configuration files.
 */

#ifndef CONFIG_ARMV7M_CMNVECTOR
#  error "CONFIG_ARMV7M_CMNVECTOR must be defined for the LPC43xx"
#endif

/* Are any UARTs enabled? */

#undef HAVE_UART
#if defined(CONFIG_LPC43_USART0) || defined(CONFIG_LPC43_UART1) || \
    defined(CONFIG_LPC43_USART2) || defined(CONFIG_LPC43_USART3)
#  define HAVE_UART 1
#endif

/* Make sure all features are disabled for diabled U[S]ARTs.  This simplifies
 * checking later.
 */

#ifndef CONFIG_LPC43_USART0
#  undef CONFIG_USART0_SERIAL_CONSOLE
#  undef CONFIG_USART0_RS485MODE
#endif

#ifndef CONFIG_LPC43_UART1
#  undef CONFIG_UART1_SERIAL_CONSOLE
#  undef CONFIG_UART1_RS485MODE
#  undef CONFIG_UART1_RS485_DTRDIR
#endif

#ifndef CONFIG_LPC43_USART2
#  undef CONFIG_USART2_SERIAL_CONSOLE
#  undef CONFIG_USART2_RS485MODE
#endif

#ifndef CONFIG_LPC43_USART3
#  undef CONFIG_USART3_SERIAL_CONSOLE
#  undef CONFIG_USART3_RS485MODE
#endif

/* Is there a serial console? There should be at most one defined.  It could be on
 * any UARTn, n=0,1,2,3 - OR - there might not be any serial console at all.
 */

#if defined(CONFIG_USART0_SERIAL_CONSOLE)
#  undef CONFIG_UART1_SERIAL_CONSOLE
#  undef CONFIG_USART2_SERIAL_CONSOLE
#  undef CONFIG_USART3_SERIAL_CONSOLE
#  define HAVE_SERIAL_CONSOLE 1
#elif defined(CONFIG_UART1_SERIAL_CONSOLE)
#  undef CONFIG_USART0_SERIAL_CONSOLE
#  undef CONFIG_USART2_SERIAL_CONSOLE
#  undef CONFIG_USART3_SERIAL_CONSOLE
#  define HAVE_SERIAL_CONSOLE 1
#elif defined(CONFIG_USART2_SERIAL_CONSOLE)
#  undef CONFIG_USART0_SERIAL_CONSOLE
#  undef CONFIG_UART1_SERIAL_CONSOLE
#  undef CONFIG_USART3_SERIAL_CONSOLE
#  define HAVE_SERIAL_CONSOLE 1
#elif defined(CONFIG_USART3_SERIAL_CONSOLE)
#  undef CONFIG_USART0_SERIAL_CONSOLE
#  undef CONFIG_UART1_SERIAL_CONSOLE
#  undef CONFIG_USART2_SERIAL_CONSOLE
#  define HAVE_SERIAL_CONSOLE 1
#else
#  undef CONFIG_USART0_SERIAL_CONSOLE
#  undef CONFIG_UART1_SERIAL_CONSOLE
#  undef CONFIG_USART2_SERIAL_CONSOLE
#  undef CONFIG_USART3_SERIAL_CONSOLE
#  undef HAVE_SERIAL_CONSOLE
#endif

/* Check UART flow control (Only supported by UART1) */

# undef CONFIG_USART0_FLOWCONTROL
# undef CONFIG_USART2_FLOWCONTROL
# undef CONFIG_USART3_FLOWCONTROL
#ifndef CONFIG_LPC43_UART1
# undef CONFIG_UART1_FLOWCONTROL
#endif

/* Check for RS-485 support (All USARTS & UART1) */

#undef HAVE_RS485
#if defined(CONFIG_USART0_RS485MODE) || defined(CONFIG_UART1_RS485MODE) || \
    defined(CONFIG_USART2_RS485MODE) || defined(CONFIG_USART3_RS485MODE)
#  define HAVE_RS485 1
#endif

/************************************************************************************
 * Public Types
 ************************************************************************************/

/************************************************************************************
 * Public Data
 ************************************************************************************/

/************************************************************************************
 * Public Functions
 ************************************************************************************/

#endif /* __ARCH_ARM_SRC_LPC43XX_LPC43XX_CONFIG_H */
