/*
 * Copyright:
 * ----------------------------------------------------------------
// The confidential and proprietary information contained in this file may
// only be used by a person authorised under and to the extent permitted
// by a subsisting licensing agreement from Arm Limited or its affiliates.
//
//        (C) COPYRIGHT 2016-2021 Arm Limited or its affiliates.
//            ALL RIGHTS RESERVED
//
// This entire notice must be reproduced on all copies of this file
// and copies of this file may only be made by a person if such person is
// permitted to do so under the terms of a subsisting license agreement
// from Arm Limited or its affiliates.
 * ----------------------------------------------------------------
 * File:     uart_stdout.c
 * Release:  Version 2.0
 * ----------------------------------------------------------------
 *
 */

#include <stdio.h>

#include "uart_stdout.h"

#define CNTLQ       0x11
#define CNTLS       0x13
#define DEL         0x7F
#define BACKSPACE   0x08
#define CR          0x0D
#define LF          0x0A
#define ESC         0x1B


void UartStdOutInit(void)
{
  CMSDK_UART0->BAUDDIV = 25000000UL / 115200;  // 115200 at 25MHz

  CMSDK_UART0->CTRL    = ((1ul <<  0) |              /* TX enable */
                          (1ul <<  1) );             /* RX enable */

    return;
}


// Output a character
unsigned char UartPutc(unsigned char my_ch)
{
  while ((CMSDK_UART0->STATE & 1)); // Wait if Transmit Holding register is full

  if (my_ch == '\n')
  {
      CMSDK_UART0->DATA  = '\r';
      while ((CMSDK_UART0->STATE & 1)); // Wait if Transmit Holding register is full
  }

  CMSDK_UART0->DATA = my_ch; // write to transmit holding register

  return (my_ch);
}


// Get a character
unsigned char UartGetc(void)
{
  while ((CMSDK_UART0->STATE & 2)==0); // Wait if Receive Holding register is empty
  return (CMSDK_UART0->DATA);
}


void UartEndSimulation(void)
{
  UartPutc((char) 0x4); // End of simulation
  while (1);
}

