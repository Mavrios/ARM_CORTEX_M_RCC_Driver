/*****************************************************************/
/****************** Name    : Ahmed Kishk 	**********************/
/****************** Date    : 9/5/2021  	**********************/
/****************** Version : 1.0V       	**********************/
/****************** SWC     : RCC           **********************/
/*****************************************************************/

#ifndef _RCC_PRIVATE_H
#define _RCC_PRIVATE_H

#define RCC_u8_HSI		1
#define RCC_u8_HSE		2
#define RCC_u8_PLL		3


#define RCC_u8_SECURITY_ON	1
#define RCC_u8_SECURITY_OFF	0

#define RCC_u8_NOT_BYPASSED	0
#define RCC_u8_BYPASSED		1

#define RCC_u8_NO_CLOCK		0
#define RCC_u8_SYS_CLOCK	1
#define RCC_u8_HSI_CLOCK	2
#define RCC_u8_HSE_CLOCK	3
#define RCC_u8_PLL_CLOCK	4


#define RCC_u8_USB_NO_PRESCALLER	0
#define RCC_u8_USB_PRESCALLER_ON	1



#define	RCC_u8_PLL_INPUT_CLOCK_x2		0
#define	RCC_u8_PLL_INPUT_CLOCK_x3		1
#define	RCC_u8_PLL_INPUT_CLOCK_x4		2
#define	RCC_u8_PLL_INPUT_CLOCK_x5		3
#define	RCC_u8_PLL_INPUT_CLOCK_x6		4
#define	RCC_u8_PLL_INPUT_CLOCK_x7		5
#define	RCC_u8_PLL_INPUT_CLOCK_x8		6
#define	RCC_u8_PLL_INPUT_CLOCK_x9		7
#define	RCC_u8_PLL_INPUT_CLOCK_x10		8
#define	RCC_u8_PLL_INPUT_CLOCK_x11		9
#define	RCC_u8_PLL_INPUT_CLOCK_x12		10
#define	RCC_u8_PLL_INPUT_CLOCK_x13		11
#define	RCC_u8_PLL_INPUT_CLOCK_x14		12
#define	RCC_u8_PLL_INPUT_CLOCK_x15		13
#define	RCC_u8_PLL_INPUT_CLOCK_x		14



#define RCC_u8_HSI_CLOCK_DIVIDED_BY_2	0
#define RCC_u8_HSE_NOT_DIVIDED			0
#define RCC_u8_HSE_DIVIDED_BY_2			1


#define RCC_u8_ADC_CLOCK_DIVIDED_BY_2	0
#define RCC_u8_ADC_CLOCK_DIVIDED_BY_4	1
#define RCC_u8_ADC_CLOCK_DIVIDED_BY_6	2
#define RCC_u8_ADC_CLOCK_DIVIDED_BY_8	3


#define RCC_u8_APB2_CLOCK_NOT_DIVIDED		0
#define RCC_u8_APB2_CLOCK_DIVIDED_BY_2		1
#define RCC_u8_APB2_CLOCK_DIVIDED_BY_4		2
#define RCC_u8_APB2_CLOCK_DIVIDED_BY_8		3
#define RCC_u8_APB2_CLOCK_DIVIDED_BY_16		4


#define RCC_u8_APB1_CLOCK_NOT_DIVIDED		0
#define RCC_u8_APB1_CLOCK_DIVIDED_BY_2		1
#define RCC_u8_APB1_CLOCK_DIVIDED_BY_4		2
#define RCC_u8_APB1_CLOCK_DIVIDED_BY_8		3
#define RCC_u8_APB1_CLOCK_DIVIDED_BY_16		4


#define RCC_u8_AHB_CLOCK_NOT_DIVIDED			0
#define RCC_u8_AHB_CLOCK_DIVIDED_BY_2			1
#define RCC_u8_AHB_CLOCK_DIVIDED_BY_4			2
#define RCC_u8_AHB_CLOCK_DIVIDED_BY_8			3
#define RCC_u8_AHB_CLOCK_DIVIDED_BY_16			4
#define RCC_u8_AHB_CLOCK_DIVIDED_BY_64			5
#define RCC_u8_AHB_CLOCK_DIVIDED_BY_128			6
#define RCC_u8_AHB_CLOCK_DIVIDED_BY_256			7
#define RCC_u8_AHB_CLOCK_DIVIDED_BY_512			8



#define RCC_u8_RTC_NO_SOURCE	0
#define RCC_u8_RTC_LSE_SOURCE	1
#define RCC_u8_RTC_LSI_SOURCE	1
#define RCC_u8_RTC_HSE_SOURCE	1



#define RCC_u8_RTC_EXTERNAL_NO_BYPASS		0
#define RCC_u8_RTC_EXTERNAL_BYPASS_ENABLE	1


#endif

