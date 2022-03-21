/*
 ** Copyright (c) 2021 Arm Limited. All rights reserved.
 */

#include <stdio.h>
#include <stdint.h>
#include "uart_stdout.h"
#include "main.h"



#ifdef CACHE_ENABLE
static void cache_enable(void)
{
  // Invalidate caches
  SCB->ICIALLU = 0UL;
  // Enable both I & D caches
  SCB->CCR = SCB_CCR_IC_Msk | SCB_CCR_DC_Msk;
}
#endif


void delay10MCycles(){
    reset_timer();
    start_timer();
    while(getCycles() < 10000000);
    stop_timer();
}


int main(void)
{
  uint32_t val, pattern;
  int32_t ival ,ipattern;
  uint32_t i;

#ifdef CACHE_ENABLE
  cache_enable();
#endif

#ifdef UART
  UartStdOutInit();
  printf("UART started.\n");
#endif

  while(1)
  {
    ARM_VIO->Value[0] = 1;
    printf("SW: VIO: Red LED turned on\n");

    delay10MCycles();

    ARM_VIO->Value[0] = 0;
    printf("SW: VIO: Red LED turned off\n");
    ARM_VIO->Value[1] = 1;
    printf("SW: VIO: Green LED turned on\n");

    delay10MCycles();

    ARM_VIO->Value[1] = 0;
    printf("SW: VIO: Green LED turned off\n");
    ARM_VIO->Value[2] = 1;
    printf("SW: VIO: Blue LED turned on\n");

    delay10MCycles();

    ARM_VIO->Value[2] = 0;
    printf("SW: VIO: Blue LED turned off\n");
  }
}
