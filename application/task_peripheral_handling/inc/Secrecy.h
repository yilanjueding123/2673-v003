#ifndef __SECRECY_H__
#define __SECRECY_H__
//===============================================================================================
#include "project.h"

#if SECRECY_ENABLE
//===============================================================================================
#define SECRECY_SDA						IO_H4
#define SECRECY_SCL						IO_C10
//-------------------------------------------------------------------------------------------------------------------------------
#define SECRECY_IC_ADDR			0x80 //加密IC 地址

/*以下如果是我写iic驱动时的风格*/
//#define SECRECY_SDA_HIGH		gpio_write_io(SECRECY_SDA, DATA_HIGH)	
//#define SECRECY_SDA_LOW			gpio_write_io(SECRECY_SDA, DATA_LOW)	
//#define SECRECY_SCL_HIGH		gpio_write_io(SECRECY_SCL, DATA_HIGH)	
//#define SECRECY_SCL_LOW			gpio_write_io(SECRECY_SCL, DATA_LOW)	

//#define SECRECY_PLAIN_CODE      0x20160630  //加密明码
//-------------------------------------------------------------------------------------------------------------------------------
extern void Secrecy_Function(void);
extern void read_card_size_set(INT32U val);

extern volatile INT8U Secrecy_Failure_Flag;
//===============================================================================================
#endif
#endif

