/*
 ** Copyright (c) 2021 Arm Limited. All rights reserved.
 */

#include <stdio.h>
#include <stdint.h>
#include "main.h"


volatile unsigned int *DWT_CYCCNT  ;
volatile unsigned int *DWT_CONTROL ;
volatile unsigned int *SCB_DEMCR   ;

void reset_timer(){
  DWT_CYCCNT   = (unsigned int *)0xE0001004; //address of the register
  DWT_CONTROL  = (unsigned int *)0xE0001000; //address of the register
  SCB_DEMCR    = (unsigned int *)0xE000EDFC; //address of the register
  *SCB_DEMCR   = *SCB_DEMCR | 0x01000000;
  *DWT_CYCCNT  = 0; // reset the counter
  *DWT_CONTROL = 0; 
}


void start_timer()
{
  *DWT_CONTROL = *DWT_CONTROL | 1 ; // enable the counter
}


void stop_timer()
{
  *DWT_CONTROL = *DWT_CONTROL | 0 ; // disable the counter
}


unsigned int getCycles()
{
  return *DWT_CYCCNT;
}


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
    ARM_VIO->Value[0] = 0;
    ARM_VIO->Value[1] = 0;
    ARM_VIO->Value[2] = 0;
    printf("SW: VIO: All LED turned off\n");

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
  }
}
