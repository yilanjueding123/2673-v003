#include "gplib_print_string.h"

#if GPLIB_PRINT_STRING_EN == 1

#include <stdarg.h>
#include <stdio.h>

#if _DRV_L1_UART == 1
#define SEND_DATA(x)	uart0_data_send(x, 1)
#define GET_DATA(x)		uart0_data_get(x, 1)
#else
#define SEND_DATA(x)
#define GET_DATA(x)		(*(x) = '\r')
#endif

#ifndef UART_TXSX_DATA
static CHAR print_buf[PRINT_BUF_SIZE];
#endif

void print_string(CHAR *fmt, ...)
{
#ifndef UART_TXSX_DATA
    va_list v_list;
    CHAR *pt;

    va_start(v_list, fmt);
    vsprintf(print_buf, fmt, v_list);
    va_end(v_list);

    print_buf[PRINT_BUF_SIZE - 1] = 0;
    pt = print_buf;
    while (*pt)
    {
        SEND_DATA(*pt);
        pt++;
    }
	
#endif
}

/*****************************************************************************
 * �� �� ��  : uart_send_string
 * �� �� ��  : Zhibo
 * ��������  : 2017��5��10��
 * ��������  : ���ʹ�������
 * �������  : CHAR *fmt   �����͵��ַ���
               INT32U len  �ַ�������
 * �������  : ��
 * �� �� ֵ  : 
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
void uart_send_string(CHAR *fmt, INT32U len)
{
    CHAR *pt;

	pt = fmt;

    while (len)
    {
		len--;
        SEND_DATA(*pt);
        pt++;
    }
}

/*****************************************************************************
 * �� �� ��  : uart_send_data
 * �� �� ��  : Zhibo
 * ��������  : 2017��5��9��
 * ��������  : ���ڷ�������
 * �������  : CHAR data  �����͵�����
 * �������  : ��
 * �� �� ֵ  : 
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
void uart_send_data(CHAR data)
{
	CHAR send_buf[11] = {0}, i = 0;
	INT32S send_temp = 0;
	send_buf[0] = 0x63;
	send_buf[1] = data;

	for(i = 2; i < 11; i++)
	{
		send_buf[i] = 0x00;
	}
	send_buf[6] = 0x88;
	send_buf[7] = 0x88;

	for(i = 0; i < 9; i++)
	{
		send_temp += send_buf[i];
	}
	
	send_buf[10] = (CHAR)send_temp;

	uart_send_string(send_buf, 11);
}

/*****************************************************************************
 * �� �� ��  : uart_recive_data
 * �� �� ��  : Zhibo
 * ��������  : 2017��5��9��
 * ��������  : ���ڽ�������
 * �������  : void  NULL
 * �������  : ��
 * �� �� ֵ  : 
 * ���ù�ϵ  : 
 * ��    ��  : 

*****************************************************************************/
CHAR* uart_recive_data(void)
{
//	CHAR* s;
//    INT8U temp;

//    while (1)
//    {
//        GET_DATA(&temp);
//        SEND_DATA(temp);
//        if (temp == '\r')
//        {
//            *s = 0;
//            return;
//        }
//        *s++ = (CHAR) temp;
//		return s;
//    }
	return NULL;
}


void get_string(CHAR *s)
{
    INT8U temp;

    while (1)
    {
        GET_DATA(&temp);
        SEND_DATA(temp);
        if (temp == '\r')
        {
            *s = 0;
            return;
        }
        *s++ = (CHAR) temp;
    }
}

#else

void print_string(CHAR *fmt, ...)
{
}

void get_string(CHAR *s)
{
}

#endif		// GPLIB_PRINT_STRING_EN
