/*
 ** Copyright (c) 2021 Arm Limited. All rights reserved.
 */

#include <stdio.h>
#include <stdint.h>
#include "uart_stdout.h"
#include "main.h"


void delay5MCycles()
{
    reset_timer();
    start_timer();
    while(getCycles() < 5000000);
    stop_timer();
}


void boot_sequence()
{
    // Turn all LEDs off
    ARM_VIO->SignalOut.signal = 0x00000000UL;
    delay5MCycles();
    printf("SW: VIO: Turn red LED on\n");
    ARM_VIO->SignalOut.signal = 1 << 0;
    delay5MCycles();
    printf("SW: VIO: Turn green LED on\n");
    ARM_VIO->SignalOut.signal = 1 << 1;
    delay5MCycles();
    printf("SW: VIO: Turn blue LED on\n");
    ARM_VIO->SignalOut.signal = 1 << 2;
    delay5MCycles();
    printf("SW: VIO: Turn all LEDs off\n");
    ARM_VIO->SignalOut.signal = 0x00000000UL;
}


int main(void)
{
  uint32_t val, pattern;
  int32_t ival ,ipattern;
  uint32_t i;

#ifdef UART
  UartStdOutInit();
  printf("UART started.\n");
#endif

  ARM_VIO->SignalOut.mask = 0x00000007UL;
  ARM_VIO->SignalIn.mask = 0x00000007UL;

  printf("SW: VIO: Boot sequence...\n");
  boot_sequence();

  printf("SW: VIO: Main loop...\n");
  while(1)
  {
    ARM_VIO->SignalOut.signal = ARM_VIO->SignalIn.signal & ARM_VIO->SignalOut.mask;
  }
}
