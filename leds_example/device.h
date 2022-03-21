/*
 * Copyright (c) 2021 Arm Limited. All rights reserved.
 */

#ifndef DEVICE_H
#define DEVICE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


/* -------------------------  Interrupt Number Definition  ------------------------ */

typedef enum IRQn
{
/* -------------------  Processor Exceptions Numbers  ----------------------------- */
  NonMaskableInt_IRQn           = -14,     /*  2 Non Maskable Interrupt */
  HardFault_IRQn                = -13,     /*  3 HardFault Interrupt */
  MemoryManagement_IRQn         = -12,     /*  4 Memory Management Interrupt */
  BusFault_IRQn                 = -11,     /*  5 Bus Fault Interrupt */
  UsageFault_IRQn               = -10,     /*  6 Usage Fault Interrupt */
  SecureFault_IRQn              =  -9,     /*  7 Secure Fault Interrupt */
  SVCall_IRQn                   =  -5,     /* 11 SVC Interrupt */
  DebugMonitor_IRQn             =  -4,     /* 12 Debug Monitor Interrupt */
  PendSV_IRQn                   =  -2,     /* 14 Pend SV Interrupt */
  SysTick_IRQn                  =  -1,     /* 15 System Tick Interrupt */

/* -------------------  Processor Interrupt Numbers  ------------------------------ */
  Interrupt0_IRQn               =   0,
  Interrupt1_IRQn               =   1,
  Interrupt2_IRQn               =   2,
  Interrupt3_IRQn               =   3,
  Interrupt4_IRQn               =   4,
  Interrupt5_IRQn               =   5,
  Interrupt6_IRQn               =   6,
  Interrupt7_IRQn               =   7,
  Interrupt8_IRQn               =   8,
  Interrupt9_IRQn               =   9,
#if (defined(__ARM_ARCH_6M__) && (__ARM_ARCH_6M__ != 0))
  /* Interrupts 10 .. 23 are left out */
  ARM_VSI0_IRQn                 =  24,
  ARM_VSI1_IRQn                 =  25,
  ARM_VSI2_IRQn                 =  26,
  ARM_VSI3_IRQn                 =  27,
  ARM_VSI4_IRQn                 =  28,
  ARM_VSI5_IRQn                 =  29,
  ARM_VSI6_IRQn                 =  30,
  ARM_VSI7_IRQn                 =  31,
#else
  /* Interrupts 10 .. 223 are left out */
  ARM_VSI0_IRQn                 = 224,
  ARM_VSI1_IRQn                 = 225,
  ARM_VSI2_IRQn                 = 226,
  ARM_VSI3_IRQn                 = 227,
  ARM_VSI4_IRQn                 = 228,
  ARM_VSI5_IRQn                 = 229,
  ARM_VSI6_IRQn                 = 230,
  ARM_VSI7_IRQn                 = 231,
  /* Interrupts 232 .. 255 are left out */
#endif
} IRQn_Type;


/* IO definitions (access restrictions to peripheral registers) */
#ifdef __cplusplus
  #define   __I     volatile             /*!< Defines 'read only' permissions */
#else
  #define   __I     volatile const       /*!< Defines 'read only' permissions */
#endif
#define     __O     volatile             /*!< Defines 'write only' permissions */
#define     __IO    volatile             /*!< Defines 'read / write' permissions */

/* following defines should be used for structure members */
#define     __IM     volatile const      /*! Defines 'read only' structure member permissions */
#define     __OM     volatile            /*! Defines 'write only' structure member permissions */
#define     __IOM    volatile            /*! Defines 'read / write' structure member permissions */


#include "arm_vio.h"
#include "arm_vsi.h"
#include "arm_vsocket.h"


#if (defined(__ARM_ARCH_6M__) && (__ARM_ARCH_6M__ != 0))

/**
  \brief  Structure type to access the Nested Vectored Interrupt Controller (NVIC).
 */
typedef struct
{
  __IOM uint32_t ISER[1U];               /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
        uint32_t RESERVED0[31U];
  __IOM uint32_t ICER[1U];               /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
        uint32_t RESERVED1[31U];
  __IOM uint32_t ISPR[1U];               /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
        uint32_t RESERVED2[31U];
  __IOM uint32_t ICPR[1U];               /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
        uint32_t RESERVED3[31U];
        uint32_t RESERVED4[64U];
  __IOM uint32_t IP[8U];                 /*!< Offset: 0x300 (R/W)  Interrupt Priority Register */
}  NVIC_Type;

#else

/**
  \brief  Structure type to access the Nested Vectored Interrupt Controller (NVIC).
 */
typedef struct
{
  __IOM uint32_t ISER[16U];              /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
        uint32_t RESERVED0[16U];
  __IOM uint32_t ICER[16U];              /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
        uint32_t RSERVED1[16U];
  __IOM uint32_t ISPR[16U];              /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
        uint32_t RESERVED2[16U];
  __IOM uint32_t ICPR[16U];              /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
        uint32_t RESERVED3[16U];
  __IOM uint32_t IABR[16U];              /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register */
        uint32_t RESERVED4[16U];
  __IOM uint32_t ITNS[16U];              /*!< Offset: 0x280 (R/W)  Interrupt Non-Secure State Register */
        uint32_t RESERVED5[16U];
  __IOM uint8_t  IPR[496U];              /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
        uint32_t RESERVED6[580U];
  __OM  uint32_t STIR;                   /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register */
}  NVIC_Type;

#endif


/**
  \brief  Structure type to access the System Control Block (SCB).
 */
typedef struct
{
  __IM  uint32_t CPUID;                  /*!< Offset: 0x000 (R/ )  CPUID Base Register */
  __IOM uint32_t ICSR;                   /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register */
  __IOM uint32_t VTOR;                   /*!< Offset: 0x008 (R/W)  Vector Table Offset Register */
  __IOM uint32_t AIRCR;                  /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register */
  __IOM uint32_t SCR;                    /*!< Offset: 0x010 (R/W)  System Control Register */
  __IOM uint32_t CCR;                    /*!< Offset: 0x014 (R/W)  Configuration Control Register */
  __IOM uint8_t  SHPR[12U];              /*!< Offset: 0x018 (R/W)  System Handlers Priority Registers (4-7, 8-11, 12-15) */
  __IOM uint32_t SHCSR;                  /*!< Offset: 0x024 (R/W)  System Handler Control and State Register */
  __IOM uint32_t CFSR;                   /*!< Offset: 0x028 (R/W)  Configurable Fault Status Register */
  __IOM uint32_t HFSR;                   /*!< Offset: 0x02C (R/W)  HardFault Status Register */
  __IOM uint32_t DFSR;                   /*!< Offset: 0x030 (R/W)  Debug Fault Status Register */
  __IOM uint32_t MMFAR;                  /*!< Offset: 0x034 (R/W)  MemManage Fault Address Register */
  __IOM uint32_t BFAR;                   /*!< Offset: 0x038 (R/W)  BusFault Address Register */
  __IOM uint32_t AFSR;                   /*!< Offset: 0x03C (R/W)  Auxiliary Fault Status Register */
  __IM  uint32_t ID_PFR[2U];             /*!< Offset: 0x040 (R/ )  Processor Feature Register */
  __IM  uint32_t ID_DFR;                 /*!< Offset: 0x048 (R/ )  Debug Feature Register */
  __IM  uint32_t ID_ADR;                 /*!< Offset: 0x04C (R/ )  Auxiliary Feature Register */
  __IM  uint32_t ID_MMFR[4U];            /*!< Offset: 0x050 (R/ )  Memory Model Feature Register */
  __IM  uint32_t ID_ISAR[6U];            /*!< Offset: 0x060 (R/ )  Instruction Set Attributes Register */
  __IM  uint32_t CLIDR;                  /*!< Offset: 0x078 (R/ )  Cache Level ID register */
  __IM  uint32_t CTR;                    /*!< Offset: 0x07C (R/ )  Cache Type register */
  __IM  uint32_t CCSIDR;                 /*!< Offset: 0x080 (R/ )  Cache Size ID Register */
  __IOM uint32_t CSSELR;                 /*!< Offset: 0x084 (R/W)  Cache Size Selection Register */
  __IOM uint32_t CPACR;                  /*!< Offset: 0x088 (R/W)  Coprocessor Access Control Register */
  __IOM uint32_t NSACR;                  /*!< Offset: 0x08C (R/W)  Non-Secure Access Control Register */
        uint32_t RESERVED3[92U];
  __OM  uint32_t STIR;                   /*!< Offset: 0x200 ( /W)  Software Triggered Interrupt Register */
  __IOM uint32_t RFSR;                   /*!< Offset: 0x204 (R/W)  RAS Fault Status Register */
        uint32_t RESERVED4[14U];
  __IM  uint32_t MVFR0;                  /*!< Offset: 0x240 (R/ )  Media and VFP Feature Register 0 */
  __IM  uint32_t MVFR1;                  /*!< Offset: 0x244 (R/ )  Media and VFP Feature Register 1 */
  __IM  uint32_t MVFR2;                  /*!< Offset: 0x248 (R/ )  Media and VFP Feature Register 2 */
        uint32_t RESERVED5[1U];
  __OM  uint32_t ICIALLU;                /*!< Offset: 0x250 ( /W)  I-Cache Invalidate All to PoU */
        uint32_t RESERVED6[1U];
  __OM  uint32_t ICIMVAU;                /*!< Offset: 0x258 ( /W)  I-Cache Invalidate by MVA to PoU */
  __OM  uint32_t DCIMVAC;                /*!< Offset: 0x25C ( /W)  D-Cache Invalidate by MVA to PoC */
  __OM  uint32_t DCISW;                  /*!< Offset: 0x260 ( /W)  D-Cache Invalidate by Set-way */
  __OM  uint32_t DCCMVAU;                /*!< Offset: 0x264 ( /W)  D-Cache Clean by MVA to PoU */
  __OM  uint32_t DCCMVAC;                /*!< Offset: 0x268 ( /W)  D-Cache Clean by MVA to PoC */
  __OM  uint32_t DCCSW;                  /*!< Offset: 0x26C ( /W)  D-Cache Clean by Set-way */
  __OM  uint32_t DCCIMVAC;               /*!< Offset: 0x270 ( /W)  D-Cache Clean and Invalidate by MVA to PoC */
  __OM  uint32_t DCCISW;                 /*!< Offset: 0x274 ( /W)  D-Cache Clean and Invalidate by Set-way */
  __OM  uint32_t BPIALL;                 /*!< Offset: 0x278 ( /W)  Branch Predictor Invalidate All */
} SCB_Type;

/* SCB Configuration Control Register Definitions */
#define SCB_CCR_TRD_Pos                    20U                                            /*!< SCB CCR: TRD Position */
#define SCB_CCR_TRD_Msk                    (1UL << SCB_CCR_TRD_Pos)                       /*!< SCB CCR: TRD Mask */

#define SCB_CCR_LOB_Pos                    19U                                            /*!< SCB CCR: LOB Position */
#define SCB_CCR_LOB_Msk                    (1UL << SCB_CCR_LOB_Pos)                       /*!< SCB CCR: LOB Mask */

#define SCB_CCR_BP_Pos                     18U                                            /*!< SCB CCR: BP Position */
#define SCB_CCR_BP_Msk                     (1UL << SCB_CCR_BP_Pos)                        /*!< SCB CCR: BP Mask */

#define SCB_CCR_IC_Pos                     17U                                            /*!< SCB CCR: IC Position */
#define SCB_CCR_IC_Msk                     (1UL << SCB_CCR_IC_Pos)                        /*!< SCB CCR: IC Mask */

#define SCB_CCR_DC_Pos                     16U                                            /*!< SCB CCR: DC Position */
#define SCB_CCR_DC_Msk                     (1UL << SCB_CCR_DC_Pos)                        /*!< SCB CCR: DC Mask */

#define SCB_CCR_STKOFHFNMIGN_Pos           10U                                            /*!< SCB CCR: STKOFHFNMIGN Position */
#define SCB_CCR_STKOFHFNMIGN_Msk           (1UL << SCB_CCR_STKOFHFNMIGN_Pos)              /*!< SCB CCR: STKOFHFNMIGN Mask */

#define SCB_CCR_BFHFNMIGN_Pos               8U                                            /*!< SCB CCR: BFHFNMIGN Position */
#define SCB_CCR_BFHFNMIGN_Msk              (1UL << SCB_CCR_BFHFNMIGN_Pos)                 /*!< SCB CCR: BFHFNMIGN Mask */

#define SCB_CCR_DIV_0_TRP_Pos               4U                                            /*!< SCB CCR: DIV_0_TRP Position */
#define SCB_CCR_DIV_0_TRP_Msk              (1UL << SCB_CCR_DIV_0_TRP_Pos)                 /*!< SCB CCR: DIV_0_TRP Mask */

#define SCB_CCR_UNALIGN_TRP_Pos             3U                                            /*!< SCB CCR: UNALIGN_TRP Position */
#define SCB_CCR_UNALIGN_TRP_Msk            (1UL << SCB_CCR_UNALIGN_TRP_Pos)               /*!< SCB CCR: UNALIGN_TRP Mask */

#define SCB_CCR_USERSETMPEND_Pos            1U                                            /*!< SCB CCR: USERSETMPEND Position */
#define SCB_CCR_USERSETMPEND_Msk           (1UL << SCB_CCR_USERSETMPEND_Pos)              /*!< SCB CCR: USERSETMPEND Mask */


/**
  \brief  Structure type to access the System Timer (SysTick).
 */
typedef struct
{
  __IOM uint32_t CTRL;                   /*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
  __IOM uint32_t LOAD;                   /*!< Offset: 0x004 (R/W)  SysTick Reload Value Register */
  __IOM uint32_t VAL;                    /*!< Offset: 0x008 (R/W)  SysTick Current Value Register */
  __IM  uint32_t CALIB;                  /*!< Offset: 0x00C (R/ )  SysTick Calibration Register */
} SysTick_Type;

/* SysTick Control / Status Register Definitions */
#define SysTick_CTRL_COUNTFLAG_Pos         16U                                            /*!< SysTick CTRL: COUNTFLAG Position */
#define SysTick_CTRL_COUNTFLAG_Msk         (1UL << SysTick_CTRL_COUNTFLAG_Pos)            /*!< SysTick CTRL: COUNTFLAG Mask */

#define SysTick_CTRL_CLKSOURCE_Pos          2U                                            /*!< SysTick CTRL: CLKSOURCE Position */
#define SysTick_CTRL_CLKSOURCE_Msk         (1UL << SysTick_CTRL_CLKSOURCE_Pos)            /*!< SysTick CTRL: CLKSOURCE Mask */

#define SysTick_CTRL_TICKINT_Pos            1U                                            /*!< SysTick CTRL: TICKINT Position */
#define SysTick_CTRL_TICKINT_Msk           (1UL << SysTick_CTRL_TICKINT_Pos)              /*!< SysTick CTRL: TICKINT Mask */

#define SysTick_CTRL_ENABLE_Pos             0U                                            /*!< SysTick CTRL: ENABLE Position */
#define SysTick_CTRL_ENABLE_Msk            (1UL /*<< SysTick_CTRL_ENABLE_Pos*/)           /*!< SysTick CTRL: ENABLE Mask */

/* SysTick Reload Register Definitions */
#define SysTick_LOAD_RELOAD_Pos             0U                                            /*!< SysTick LOAD: RELOAD Position */
#define SysTick_LOAD_RELOAD_Msk            (0xFFFFFFUL /*<< SysTick_LOAD_RELOAD_Pos*/)    /*!< SysTick LOAD: RELOAD Mask */

/* SysTick Current Register Definitions */
#define SysTick_VAL_CURRENT_Pos             0U                                            /*!< SysTick VAL: CURRENT Position */
#define SysTick_VAL_CURRENT_Msk            (0xFFFFFFUL /*<< SysTick_VAL_CURRENT_Pos*/)    /*!< SysTick VAL: CURRENT Mask */

/* SysTick Calibration Register Definitions */
#define SysTick_CALIB_NOREF_Pos            31U                                            /*!< SysTick CALIB: NOREF Position */
#define SysTick_CALIB_NOREF_Msk            (1UL << SysTick_CALIB_NOREF_Pos)               /*!< SysTick CALIB: NOREF Mask */

#define SysTick_CALIB_SKEW_Pos             30U                                            /*!< SysTick CALIB: SKEW Position */
#define SysTick_CALIB_SKEW_Msk             (1UL << SysTick_CALIB_SKEW_Pos)                /*!< SysTick CALIB: SKEW Mask */

#define SysTick_CALIB_TENMS_Pos             0U                                            /*!< SysTick CALIB: TENMS Position */
#define SysTick_CALIB_TENMS_Msk            (0xFFFFFFUL /*<< SysTick_CALIB_TENMS_Pos*/)    /*!< SysTick CALIB: TENMS Mask */


/* Memory mapping of Core Hardware */
#define SCS_BASE            (0xE000E000UL)                            /*!< System Control Space Base Address */
#define SysTick_BASE        (SCS_BASE +  0x0010UL)                    /*!< SysTick Base Address */
#define NVIC_BASE           (SCS_BASE +  0x0100UL)                    /*!< NVIC Base Address */
#define SCB_BASE            (SCS_BASE +  0x0D00UL)                    /*!< System Control Block Base Address */
#define SCB                 ((SCB_Type       *)     SCB_BASE      )   /*!< SCB configuration struct */
#define SysTick             ((SysTick_Type   *)     SysTick_BASE  )   /*!< SysTick configuration struct */
#define NVIC                ((NVIC_Type      *)     NVIC_BASE     )   /*!< NVIC configuration struct */

/* Memory mapping of VIO peripheral */
#define ARM_VIO_BASE_S      (0x5FEF0000UL)                            /*!< VIO Base Address (secure address space) */
#define ARM_VIO_BASE_NS     (0x4FEF0000UL)                            /*!< VIO Base Address (non-secure address space) */
#define ARM_VIO_S           ((ARM_VIO_Type *)ARM_VIO_BASE_S)          /*!< VIO struct (secure address space) */
#define ARM_VIO_NS          ((ARM_VIO_Type *)ARM_VIO_BASE_NS)         /*!< VIO struct (non-secure address space) */
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
#define ARM_VIO             ARM_VIO_S
#else
#define ARM_VIO             ARM_VIO_NS
#endif

/* Memory mapping of 8 VSI peripherals */
#define ARM_VSI0_BASE_S     (0x5FF00000UL)                            /*!< VSI 0 Base Address (secure address space) */
#define ARM_VSI1_BASE_S     (0x5FF10000UL)                            /*!< VSI 1 Base Address (secure address space) */
#define ARM_VSI2_BASE_S     (0x5FF20000UL)                            /*!< VSI 2 Base Address (secure address space) */
#define ARM_VSI3_BASE_S     (0x5FF30000UL)                            /*!< VSI 3 Base Address (secure address space) */
#define ARM_VSI4_BASE_S     (0x5FF40000UL)                            /*!< VSI 4 Base Address (secure address space) */
#define ARM_VSI5_BASE_S     (0x5FF50000UL)                            /*!< VSI 5 Base Address (secure address space) */
#define ARM_VSI6_BASE_S     (0x5FF60000UL)                            /*!< VSI 6 Base Address (secure address space) */
#define ARM_VSI7_BASE_S     (0x5FF70000UL)                            /*!< VSI 7 Base Address (secure address space) */
#define ARM_VSI0_BASE_NS    (0x4FF00000UL)                            /*!< VSI 0 Base Address (non-secure address space) */
#define ARM_VSI1_BASE_NS    (0x4FF10000UL)                            /*!< VSI 1 Base Address (non-secure address space) */
#define ARM_VSI2_BASE_NS    (0x4FF20000UL)                            /*!< VSI 2 Base Address (non-secure address space) */
#define ARM_VSI3_BASE_NS    (0x4FF30000UL)                            /*!< VSI 3 Base Address (non-secure address space) */
#define ARM_VSI4_BASE_NS    (0x4FF40000UL)                            /*!< VSI 4 Base Address (non-secure address space) */
#define ARM_VSI5_BASE_NS    (0x4FF50000UL)                            /*!< VSI 5 Base Address (non-secure address space) */
#define ARM_VSI6_BASE_NS    (0x4FF60000UL)                            /*!< VSI 6 Base Address (non-secure address space) */
#define ARM_VSI7_BASE_NS    (0x4FF70000UL)                            /*!< VSI 7 Base Address (non-secure address space) */
#define ARM_VSI0_S          ((ARM_VSI_Type *)ARM_VSI0_BASE_S)         /*!< VSI 0 struct (secure address space) */
#define ARM_VSI1_S          ((ARM_VSI_Type *)ARM_VSI1_BASE_S)         /*!< VSI 1 struct (secure address space) */
#define ARM_VSI2_S          ((ARM_VSI_Type *)ARM_VSI2_BASE_S)         /*!< VSI 2 struct (secure address space) */
#define ARM_VSI3_S          ((ARM_VSI_Type *)ARM_VSI3_BASE_S)         /*!< VSI 3 struct (secure address space) */
#define ARM_VSI4_S          ((ARM_VSI_Type *)ARM_VSI4_BASE_S)         /*!< VSI 4 struct (secure address space) */
#define ARM_VSI5_S          ((ARM_VSI_Type *)ARM_VSI5_BASE_S)         /*!< VSI 5 struct (secure address space) */
#define ARM_VSI6_S          ((ARM_VSI_Type *)ARM_VSI6_BASE_S)         /*!< VSI 6 struct (secure address space) */
#define ARM_VSI7_S          ((ARM_VSI_Type *)ARM_VSI7_BASE_S)         /*!< VSI 7 struct (secure address space) */
#define ARM_VSI0_NS         ((ARM_VSI_Type *)ARM_VSI0_BASE_NS)        /*!< VSI 0 struct (non-secure address space) */
#define ARM_VSI1_NS         ((ARM_VSI_Type *)ARM_VSI1_BASE_NS)        /*!< VSI 1 struct (non-secure address space) */
#define ARM_VSI2_NS         ((ARM_VSI_Type *)ARM_VSI2_BASE_NS)        /*!< VSI 2 struct (non-secure address space) */
#define ARM_VSI3_NS         ((ARM_VSI_Type *)ARM_VSI3_BASE_NS)        /*!< VSI 3 struct (non-secure address space) */
#define ARM_VSI4_NS         ((ARM_VSI_Type *)ARM_VSI4_BASE_NS)        /*!< VSI 4 struct (non-secure address space) */
#define ARM_VSI5_NS         ((ARM_VSI_Type *)ARM_VSI5_BASE_NS)        /*!< VSI 5 struct (non-secure address space) */
#define ARM_VSI6_NS         ((ARM_VSI_Type *)ARM_VSI6_BASE_NS)        /*!< VSI 6 struct (non-secure address space) */
#define ARM_VSI7_NS         ((ARM_VSI_Type *)ARM_VSI7_BASE_NS)        /*!< VSI 7 struct (non-secure address space) */
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
#define ARM_VSI0            ARM_VSI0_S
#define ARM_VSI1            ARM_VSI1_S
#define ARM_VSI2            ARM_VSI2_S
#define ARM_VSI3            ARM_VSI3_S
#define ARM_VSI4            ARM_VSI4_S
#define ARM_VSI5            ARM_VSI5_S
#define ARM_VSI6            ARM_VSI6_S
#define ARM_VSI7            ARM_VSI7_S
#else
#define ARM_VSI0            ARM_VSI0_NS
#define ARM_VSI1            ARM_VSI1_NS
#define ARM_VSI2            ARM_VSI2_NS
#define ARM_VSI3            ARM_VSI3_NS
#define ARM_VSI4            ARM_VSI4_NS
#define ARM_VSI5            ARM_VSI5_NS
#define ARM_VSI6            ARM_VSI6_NS
#define ARM_VSI7            ARM_VSI7_NS
#endif

/* Memory mapping of VSocket peripheral */
#define ARM_VSOCKET_BASE_S  (0x5FEE0000UL)                            /*!< VSocket Base Address (secure address space) */
#define ARM_VSOCKET_BASE_NS (0x4FEE0000UL)                            /*!< VSocket Base Address (non-secure address space) */
#define ARM_VSOCKET_S       ((ARM_VSocket_Type *)ARM_VSOCKET_BASE_S)  /*!< VSocket struct (secure address space) */
#define ARM_VSOCKET_NS      ((ARM_VSocket_Type *)ARM_VSOCKET_BASE_NS) /*!< VSocket struct (non-secure address space) */
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
#define ARM_VSOCKET         ARM_VSOCKET_S
#else
#define ARM_VSOCKET         ARM_VSOCKET_NS
#endif


/* CMSIS compiler specific defines */
#ifndef   __ASM
  #define __ASM                                  __asm
#endif
#ifndef   __STATIC_FORCEINLINE
  #define __STATIC_FORCEINLINE                   __attribute__((always_inline)) static inline
#endif


/**
  \brief   No Operation
  \details No Operation does nothing. This instruction can be used for code alignment purposes.
 */
#define __NOP() __ASM volatile ("nop")

/**
  \brief   Instruction Synchronization Barrier
  \details Instruction Synchronization Barrier flushes the pipeline in the processor,
           so that all instructions following the ISB are fetched from cache or memory,
           after the instruction has been completed.
 */
__STATIC_FORCEINLINE void __ISB(void)
{
  __ASM volatile ("isb 0xF":::"memory");
}

/**
  \brief   Data Synchronization Barrier
  \details Acts as a special kind of Data Memory Barrier.
           It completes when all explicit memory accesses before this instruction complete.
 */
__STATIC_FORCEINLINE void __DSB(void)
{
  __ASM volatile ("dsb 0xF":::"memory");
}


#ifdef __cplusplus
}
#endif

#endif  /* DEVICE_H */
