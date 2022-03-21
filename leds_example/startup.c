/*
** Copyright (c) 2018-2021 Arm Limited. All rights reserved.
*/

// Initial Setup
//----------------------------------------------------------------
extern unsigned int Image$$ARM_LIB_STACKHEAP$$ZI$$Limit;            /* for (default) One Region model */
typedef void(* const ExecFuncPtr)(void) __attribute__((interrupt)); /* typedef for the function pointers in the vector table */
extern int __main(void);

// Reset Handler
//----------------------------------------------------------------
void ResetHandler(void)
{
    __main();
}

// Exception Vector Table & Handlers
//----------------------------------------------------------------
void NMIException(void)          {while(1);}
void HardFaultException(void)    {while(1);}
void SVCHandler(void)            {while(1);}
void PendSVHandler(void)         {while(1);}
void SysTickHandler(void)        {while(1);}
void InterruptHandler(void)      {while(1);}

__attribute__((weak)) void ARM_VSI0_Handler(void) {while(1);} // Interrupt handler VSI0
__attribute__((weak)) void ARM_VSI1_Handler(void) {while(1);} // Interrupt handler VSI1
__attribute__((weak)) void ARM_VSI2_Handler(void) {while(1);} // Interrupt handler VSI2
__attribute__((weak)) void ARM_VSI3_Handler(void) {while(1);} // Interrupt handler VSI3
__attribute__((weak)) void ARM_VSI4_Handler(void) {while(1);} // Interrupt handler VSI4
__attribute__((weak)) void ARM_VSI5_Handler(void) {while(1);} // Interrupt handler VSI5
__attribute__((weak)) void ARM_VSI6_Handler(void) {while(1);} // Interrupt handler VSI6
__attribute__((weak)) void ARM_VSI7_Handler(void) {while(1);} // Interrupt handler VSI7

ExecFuncPtr vector_table[] __attribute__((section("BOOT"))) = {
    (ExecFuncPtr)&Image$$ARM_LIB_STACKHEAP$$ZI$$Limit,  // initial SP
    ResetHandler,                                       // initial PC/Reset
    NMIException,
    HardFaultException,
    0,                                                  // Memory Manage Fault
    0,                                                  // Bus Fault
    0,                                                  // Usage Fault
    0,                                                  // RESERVED
    0,                                                  // RESERVED
    0,                                                  // RESERVED
    0,                                                  // RESERVED
    SVCHandler,
    0,                                                  // RESERVED for debug
    0,                                                  // RESERVED
    PendSVHandler,
    SysTickHandler,
    InterruptHandler,                                   // IRQ0
    InterruptHandler,                                   // IRQ1
    InterruptHandler,                                   // IRQ2
    InterruptHandler,                                   // IRQ..
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
#if (defined(__ARM_ARCH_6M__) && (__ARM_ARCH_6M__ != 0))
    ARM_VSI0_Handler,                                   // VSI0 (IRQ24)
    ARM_VSI1_Handler,                                   // VSI1 (IRQ25)
    ARM_VSI2_Handler,                                   // VSI2 (IRQ26)
    ARM_VSI3_Handler,                                   // VSI3 (IRQ27)
    ARM_VSI4_Handler,                                   // VSI4 (IRQ28)
    ARM_VSI5_Handler,                                   // VSI5 (IRQ29)
    ARM_VSI6_Handler,                                   // VSI6 (IRQ30)
    ARM_VSI7_Handler,                                   // VSI7 (IRQ31)
#else
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,                                   // IRQ31
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,                                   // IRQ63
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,                                   // IRQ127
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    ARM_VSI0_Handler,                                   // VSI0 (IRQ224)
    ARM_VSI1_Handler,                                   // VSI1 (IRQ225)
    ARM_VSI2_Handler,                                   // VSI2 (IRQ226)
    ARM_VSI3_Handler,                                   // VSI3 (IRQ227)
    ARM_VSI4_Handler,                                   // VSI4 (IRQ228)
    ARM_VSI5_Handler,                                   // VSI5 (IRQ229)
    ARM_VSI6_Handler,                                   // VSI6 (IRQ230)
    ARM_VSI7_Handler,                                   // VSI7 (IRQ231)
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler,
    InterruptHandler                                    // IRQ255
#endif
};
