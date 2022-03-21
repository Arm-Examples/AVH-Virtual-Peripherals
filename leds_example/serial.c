/*
** Copyright (c) 2018 Arm Limited. All rights reserved.
*/

#include "uart_stdout.h"
#include <stdio.h>


// ReTargeting Code
// ================
#ifdef UART


struct __FILE {int handle;};
FILE __stdout;
FILE __stdin;
FILE __stderr;

int fputc(int ch, FILE *f)
{
  char tempch = ch;
  (void)UartPutc(tempch);
  return ch;
}


int fgetc(FILE *f)
{
  return UartPutc(UartGetc());
}


void _ttywrch(int ch)
{
  char tempch = ch;
  (void)UartPutc(tempch);
}


#endif
