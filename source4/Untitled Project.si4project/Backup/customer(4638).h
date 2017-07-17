#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__

#include "string.h"

#define CUSTOM_ON       1
#define CUSTOM_OFF      0

// Function enable
#define C_UVC							CUSTOM_ON
#define C_USB_AUDIO						CUSTOM_ON
#define C_MOTION_DETECTION				CUSTOM_OFF
#define C_AUTO_DEL_FILE					CUSTOM_OFF
#define C_CYCLIC_VIDEO_RECORD			CUSTOM_ON
#define C_VIDEO_PREVIEW					CUSTOM_OFF
#define C_BATTERY_DETECT				CUSTOM_OFF
#define SUPPORT_LONGKEY                 CUSTOM_OFF
#define SUPPORT_JTAG					CUSTOM_OFF// ICE

#define DBG_MESSAGE						CUSTOM_ON// UART debug message
#if 0//DBG_MESSAGE
#define __msg(...)    		(print_string("MSG:L%d(%s):", __LINE__, strrchr(__FILE__, '\\')+1),                 \
							     print_string(__VA_ARGS__)									        )
#define DBG_PRINT(...)    		(print_string("MSG:L%d(%s):", __LINE__, strrchr(__FILE__, '\\')+1),                 \
							     print_string(__VA_ARGS__)									        )
#else
#define __msg(...)
#define DBG_PRINT(...)
//#define DBG_PRINT	if (0) print_string
#endif

#define UART_TXSX_DATA

/* add begin by Zhibo, 2017-05-09 ���ڷ��͵�����*/
#define APP_IDLE_STATE					0x00
#define APP_NO_LENS_STATE				0X01
#define APP_NO_STORAGE_STATE			0X02
#define APP_FULL_STORAGE_STATE			0x03
#define APP_CAPUTEING_STATE				0X04
#define APP_RECORDING_STATE				0x05
/* add end by Zhibo, 2017-05-09 */

//configure
#define GPDV_EMU_V2_0					1
#define GPDV_BOARD_VERSION				GPDV_EMU_V2_0

// CPU and system clock
#define INIT_MHZ                    	129.6//129.6//96		// MHz

// SDRAM size: 2MB(0x00200000), 8MB(0x00800000), 16MB(0x01000000), 32MB(0x02000000)
#define SDRAM_SIZE						0x00200000//0x02000000

// Sensor settings
//#define	__OV6680_DRV_C__				1
//#define	__OV7680_DRV_C__				1
//#define	__OV7670_DRV_C__				1
#define	__BF3925_DRV_C__				1
//#define   __OV2643_DRV_C__    			1
//#define	__OV7725_DRV_C__				1
//#define	__GC0308_DRV_C__				1
//#define	__SP0838_DRV_C__				1
//#define	__OV9655_DRV_C__				1
//#define	__OV2655_DRV_C__ 				1
//#define	__OV3640_DRV_C__ 				1
//#define	__OV5642_DRV_C__ 				1

#define SENSOR_WIDTH					1280//640//640//1280
#define SENSOR_HEIGHT					720//480//480//720
#define SENSOR_BUF_FRAME_MODE			1		// Frame mode
#define SENSOR_BUF_FIFO_MODE			2		// FIFO mode
#define VIDEO_ENCODE_USE_MODE			SENSOR_BUF_FIFO_MODE

// AVI recording resolution: 640x480 \ 720x480(FRAME_MODE) \ 1280x960
#define AVI_WIDTH						1280//640
#define AVI_HEIGHT						720//480
#define AVI_Q_VALUE						50//30		// 40, 50, 60
#define AVI_FRAME_RATE					30		// Frame per second

/*
#if VIDEO_ENCODE_USE_MODE == SENSOR_BUF_FRAME_MODE
    #define FileWriteBuffer_Size			24*(32*1024)	//avi pack buffer size, must multiple 32k
#else
    #define FileWriteBuffer_Size			27*(32*1024)	//avi pack buffer size, must multiple 32k
#endif
*/

#define IndexBuffer_Size				(32*1024)//(64*1024)//(32*1024)		// Do not modify this
//#define AVI_FILE_MAX_RECORD_SIZE		1001*1024*1024	//2GB
#define REMAIN_SPACE					10		// MB

#if C_AUTO_DEL_FILE == CUSTOM_ON
#define AUTO_DEL_THREAD_MB	            100
#endif

// Photo resolution and quality
#define PIC_WIDTH						1280
#define PIC_HEIGH						720//960
#define PIC_Q_VALUE						70		// 30, 40, 50, 60, 70, 80, 90

// Motion detection
#define MD_STOP_TIME					30		// when MD_STOP_TIME seconds detect no motion then stop video record
//motion detect sensitive
#define LOW								300
#define MEDIUM							150
#define HIGH							70
#define MD_SENSITIVE					400

//audio record sampling rate
#define AUD_SAMPLING_RATE_8K			8000
#define AUD_SAMPLING_RATE_16K			16000
#define AUD_SAMPLING_RATE_22K			22050
#define AUD_SAMPLING_RATE_44K			44100
#define AUD_REC_SAMPLING_RATE			AUD_SAMPLING_RATE_22K
#define AVI_AUD_SAMPLING_RATE			AUD_SAMPLING_RATE_8K

#define AUD_FORMAT_WAV                 	0
#define AUD_FORMAT_MP3                 	1
#define AUD_REC_FORMAT                 	AUD_FORMAT_MP3

#if AUD_REC_FORMAT == AUD_FORMAT_WAV
#define AUD_FILE_MAX_RECORD_SIZE	300*AUD_REC_SAMPLING_RATE*2	//2GB
#elif AUD_REC_FORMAT == AUD_FORMAT_MP3
#define AUD_FILE_MAX_RECORD_SIZE	300*16000
#endif

// Storage type
#define MINI_DVR_STORAGE_TYPE			2		// T_FLASH

//------------------------------------------------------------------------------------
// key definition
//------------------------------------------------------------------------------------

#define KEY_ACTIVE						DATA_LOW//key active level for IO keys

// ad key level
#define ADKEY_LVL_1						1
#define ADKEY_LVL_2						0
#define ADKEY_LVL_3						2
#define ADKEY_LVL_4						3

// key number definition
#define USE_IOKEY_NO					1 //num of IO key
#define USE_ADKEY_NO					1  //num of ad key

//++++++++++++++++++++++++++++
#if USE_IOKEY_NO == 3 && USE_ADKEY_NO == 1

#define NEXT_KEY						IO_F15
#define PREVIOUS_KEY					IO_F15
#define REC_KEY							IO_F15
#define FUNCTION_KEY					ADKEY_LVL_1 //dummy

//++++++++++++++++++++++++++++
#elif USE_IOKEY_NO == 1 && USE_ADKEY_NO == 1

#define VIDEO_KEY            	 	IO_H3
#define CAPTURE_KEY            		IO_H2
#define FUNCTION_KEY				ADKEY_LVL_1 //dummy

#define VIDEO_ACTIVE_KEY			0
#define CAPTURE_ACTIVE_KEY			0

#else
#error "Key define error, you can redefine in <customer.h> or create a new set here."
#endif
//++++++++++++++++++++++++++++

/* add begin by Zhibo, 2017-05-08 ����*/
#define CAPTURE_CONTINUES_NUMBERS     3
#define CAPTURE_CONTINUES_SHOTS
/* add end by Zhibo, 2017-05-08 */


#define C_USBDEVICE_PIN   				IO_F15//IO_G8//IO_C3
#define	SCCB_SCL      					IO_G8
#define	SCCB_SDA      					IO_G9
#define PW_EN							IO_F15//IO_F5
#define AD_DETECT_PIN					IO_F15//ADC_LINE_2 //ADC_LINE_0
#define LED1							IO_H2//IO_H5//IO_F5//blue
#define LED2							IO_H5//IO_H2//IO_F7//red


#define MCU_GPDV6655B		0 //����ʹ��24M����
#define MCU_GPDV6655C		1 //����Ҫ����
#define MCU_GPDV6655D		2 //����Ҫ����, 3.3V��ѡ���ڲ�LDO�ṩ

#define USED_MCU_NAME       MCU_GPDV6655D

#define LDO_ENABLE			1 //ѡ�������ڲ�LDO, ��ʹ���ⲿLDOʱ, ʵ����ֻ�ǽ��ڲ�LDO������ó���С��
#define MUTE_SWITCH			0 //��������
#define DV_OUT_HIGH_LEVEL	1 //�������500ms �ߵ�ƽ
#define SECRECY_ENABLE		1 //=0, ������; =1,��������

#define GUEST_NAME_2822


#define CAPTURE_KEY_SAVE_VIDEO			1

#define PRODUCT_NUM                     2673
#define PRODUCT_DATA                    20170515
#define PROGRAM_VERSION_NUM             3	//129

//#define SENSOR_IMAGE_INTERVAL			//ͼ��ת

#endif //__CUSTOMER_H__
