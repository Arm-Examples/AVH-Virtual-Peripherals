/*
 ** Copyright (c) 2018-2021 Arm Limited. All rights reserved.
 */

#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdint.h>

#ifdef _RTE_
#include "RTE_Components.h"
#endif
#include CMSIS_device_header

#ifndef SYSCLK
#define SYSCLK                  25000000U
#endif

#ifndef DMA_MEMORY_ADDRESS0
#define DMA_MEMORY_ADDRESS0     0x20007000UL
#endif

#ifndef DMA_MEMORY_ADDRESS1
#define DMA_MEMORY_ADDRESS1     0x21000000UL
#endif

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

#endif
