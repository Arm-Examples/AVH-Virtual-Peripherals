/*
 * Copyright:
 * ----------------------------------------------------------------
// The confidential and proprietary information contained in this file may
// only be used by a person authorised under and to the extent permitted
// by a subsisting licensing agreement from Arm Limited or its affiliates.
//
//        (C) COPYRIGHT 2016-2019 Arm Limited or its affiliates.
//            ALL RIGHTS RESERVED
//
// This entire notice must be reproduced on all copies of this file
// and copies of this file may only be made by a person if such person is
// permitted to do so under the terms of a subsisting license agreement
// from Arm Limited or its affiliates.
 * ----------------------------------------------------------------
 * File:     uart_stdout.h
 * Release:  Version 2.0
 * ----------------------------------------------------------------
 */

#ifndef _UART_STDOUT_H_
#define _UART_STDOUT_H_

#include <stdint.h>

#ifdef  VHT_MPS2
#ifdef  IOTKIT
#define CMSDK_UART0_BASE         (0x40200000ul)       /* UART 0 Base Address */
#else
#define CMSDK_UART0_BASE         (0x40004000ul)       /* UART 0 Base Address */
#endif
#endif
#ifdef  VHT_MPS3
#define CMSDK_UART0_BASE         (0x49303000ul)       /* UART 0 Base Address */
#endif
#define CMSDK_UART0             ((CMSDK_UART_TypeDef   *) CMSDK_UART0_BASE   )

#define     __I     volatile const       /*!< Defines 'read only' permissions */
#define     __O     volatile             /*!< Defines 'write only' permissions */
#define     __IO    volatile             /*!< Defines 'read / write' permissions */

typedef struct
{
  __IO   uint32_t  DATA;                     /* Offset: 0x000 (R/W) Data Register    */
  __IO   uint32_t  STATE;                    /* Offset: 0x004 (R/W) Status Register  */
  __IO   uint32_t  CTRL;                     /* Offset: 0x008 (R/W) Control Register */
  union {
    __I    uint32_t  INTSTATUS;              /* Offset: 0x00C (R/ ) Interrupt Status Register */
    __O    uint32_t  INTCLEAR;               /* Offset: 0x00C ( /W) Interrupt Clear Register  */
    };
  __IO   uint32_t  BAUDDIV;                  /* Offset: 0x010 (R/W) Baudrate Divider Register */

} CMSDK_UART_TypeDef;


/* Functions for stdout during simulation */
/* The functions are implemented in uart_stdout.c */

extern void UartStdOutInit(void);
extern unsigned char UartPutc(unsigned char my_ch);
extern unsigned char UartGetc(void);
extern void UartEndSimulation(void);

#endif
