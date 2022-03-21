/*
 ** Copyright (c) 2021 Arm Limited. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "main.h"

extern ARM_VSI_Type * const ARM_VSI[];

volatile uint32_t irq_status_vsi = 0UL;
volatile uint32_t irq_count_vsi = 0UL;

static void irq_handler_vsi(uint32_t i)
{
  ARM_VSI_Type *pVSI = ARM_VSI[i];

  irq_status_vsi = pVSI->IRQ.Status;
  irq_count_vsi++;
  printf("SW: VSI%d: INTERRUPT CAUGHT! Status: 0x%08x\n", i, irq_status_vsi);
  pVSI->IRQ.Clear = irq_status_vsi;
}

void ARM_VSI0_Handler(void) { irq_handler_vsi(0UL); }
void ARM_VSI1_Handler(void) { irq_handler_vsi(1UL); }
void ARM_VSI2_Handler(void) { irq_handler_vsi(2UL); }
void ARM_VSI3_Handler(void) { irq_handler_vsi(3UL); }
void ARM_VSI4_Handler(void) { irq_handler_vsi(4UL); }
void ARM_VSI5_Handler(void) { irq_handler_vsi(5UL); }
void ARM_VSI6_Handler(void) { irq_handler_vsi(6UL); }
void ARM_VSI7_Handler(void) { irq_handler_vsi(7UL); }
