#ifndef __GPLIB_PRINT_STRING_H__
#define __GPLIB_PRINT_STRING_H__


#include "gplib.h"

#if GPLIB_PRINT_STRING_EN == 1
extern void print_string(CHAR *fmt, ...);
#endif
extern void get_string(CHAR *s);
extern 	void uart_send_string(CHAR *fmt, INT32U len);
extern 	void uart_send_data(CHAR data);
#endif 		// __GPLIB_PRINT_STRING_H__
