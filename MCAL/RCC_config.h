/*****************************************************************/
/****************** Name    : Ahmed Kishk 	**********************/
/****************** Date    : 9/5/2021  	**********************/
/****************** Version : 1.0V       	**********************/
/****************** SWC     : RCC           **********************/
/*****************************************************************/

#ifndef _RCC_CONFIG_H
#define _RCC_CONFIG_H


/************CLOCK TYPE************
 * 								  *
 *  Options : 1- RCC_u8_HSI		  *
 * 			  2- RCC_u8_HSE		  *
 * 			  3- RCC_u8_PLL       *
 **********************************/
#define RCC_u8_CLOCK_TYPE	RCC_u8_HSI

/************CLOCK SECURITY************
 * 								  	  *
 *  Options : 1- RCC_u8_SECURITY_ON	  *
 * 			  2- RCC_u8_SECURITY_OFF  *
 *									  */
/*************************************** DESCRIPTION ***************************************
 * When CSSON is set, the clock detector is enabled by hardware when the HSE oscillator    *
 * is ready, and disabled by hardware if a HSE clock failure is detected.                  *
 *******************************************************************************************/
#define RCC_u8_CLOCK_SECURTIY	RCC_u8_SECURITY_OFF

/*********** EXTERNAL BYPASS ***********
 * 								  	   *
 *  Options : 1- RCC_u8_NOT_BYPASSED   *
 * 			  2- RCC_u8_BYPASSED	   *
 ***************************************/
#define RCC_u8_EXTERNAL_CLOCK	RCC_u8_NOT_BYPASSED

/***************** OUTPUT CLOCK ****************
 * 								  	   		   *
 *  Options : 1- RCC_u8_NO_CLOCK	   		   *
 * 			  2- RCC_u8_SYS_CLOCK	    	   *
 * 			  3- RCC_u8_HSI_CLOCK			   *
 * 			  4- RCC_u8_HSE_CLOCK			   *
 * 			  5- RCC_u8_PLL_CLOCK			   *
 *			 (PLL clock divided by 2)		   *
 ***********************************************/
/******************************************* NOTE *******************************************
 * When the System Clock is selected to output to the MCO pin, make sure that this clock    *
 * does not exceed 50 MHz (the maximum IO speed).						                    *
 *******************************************************************************************/
#define RCC_u8_OUTPUT_CLOCK	RCC_u8_NO_CLOCK

/***************  USB PRESCALLER ***************
 * 								  	   		   *
 *  Options : 1- RCC_u8_USB_NO_PRESCALLER	   *
 * 			  2- RCC_u8_USB_PRESCALLER_ON      *
 * 			  (PLL clock is divided by 1.5)    *
 ***********************************************/

#define RCC_u8_USB_PRESCALLER	RCC_u8_USB_PRESCALLER_ON


/***************  PLL MULTIPLICATION FACTOR	***************
 * 								  	   					  *
 *  Options : 1- RCC_u8_PLL_INPUT_CLOCK_x2	  			  *
 * 			  2- RCC_u8_PLL_INPUT_CLOCK_x3	      		  *
 * 			  3- RCC_u8_PLL_INPUT_CLOCK_x4				  *
 * 			  4- RCC_u8_PLL_INPUT_CLOCK_x5				  *
 * 			  5- RCC_u8_PLL_INPUT_CLOCK_x6                *
 * 			  6- RCC_u8_PLL_INPUT_CLOCK_x7				  *
 * 			  7- RCC_u8_PLL_INPUT_CLOCK_x8	      		  *
 * 			  8- RCC_u8_PLL_INPUT_CLOCK_x9				  *
 * 			  9- RCC_u8_PLL_INPUT_CLOCK_x10				  *
 * 			  10- RCC_u8_PLL_INPUT_CLOCK_x11              *
 * 			  11- RCC_u8_PLL_INPUT_CLOCK_x12			  *
 * 			  12- RCC_u8_PLL_INPUT_CLOCK_x13			  *
 * 			  13- RCC_u8_PLL_INPUT_CLOCK_x14	      	  *
 * 			  14- RCC_u8_PLL_INPUT_CLOCK_x15			  *
 * 			  15- RCC_u8_PLL_INPUT_CLOCK_x16			  *
 **********************************************************/
/**************************** NOTE *****************************
 * Caution: The PLL output frequency must not exceed 72 MHz    *
 ***************************************************************/
#define RCC_u8_PLL_MULTIPLICATION_FACTOR	RCC_u8_PLL_INPUT_CLOCK_x2



/***************** PLL ENTRY CLOCK SOURCE *****************
 * 								  	   		   			  *
 *  Options : 1- RCC_u8_HSI_CLOCK_DIVIDED_BY_2			  *
 * 			  2- RCC_u8_HSE_NOT_DIVIDED     			  *
 * 			  2- RCC_u8_HSE_DIVIDED_BY_2     			  *
 **********************************************************/

#define RCC_u8_PLL_ENTRY	RCC_u8_HSI_CLOCK_DIVIDED_BY_2


/********************* ADC PRESCALER **********************
 * 								  	   		   			  *
 *  Options : 1- RCC_u8_ADC_CLOCK_DIVIDED_BY_2			  *
 * 			  2- RCC_u8_ADC_CLOCK_DIVIDED_BY_4    		  *
 * 			  3- RCC_u8_ADC_CLOCK_DIVIDED_BY_6   		  *
 * 			  4- RCC_u8_ADC_CLOCK_DIVIDED_BY_8   		  *
 **********************************************************/

#define RCC_u8_ADC_PRESCALLER	RCC_u8_ADC_CLOCK_DIVIDED_BY_2

/********************* APB2 PRESCALER **********************
 * 								  	   		   			  *
 *  Options : 1- RCC_u8_APB2_CLOCK_NOT_DIVIDED			  *
 * 			  2- RCC_u8_APB2_CLOCK_DIVIDED_BY_2    		  *
 * 			  3- RCC_u8_APB2_CLOCK_DIVIDED_BY_4    		  *
 * 			  4- RCC_u8_APB2_CLOCK_DIVIDED_BY_8   		  *
 * 			  5- RCC_u8_APB2_CLOCK_DIVIDED_BY_16   		  *
 **********************************************************/

#define RCC_u8_APB2_PRESCALLER	RCC_u8_APB2_CLOCK_NOT_DIVIDED

/********************* APB1 PRESCALER **********************
 * 								  	   		   			  *
 *  Options : 1- RCC_u8_APB1_CLOCK_NOT_DIVIDED			  *
 * 			  2- RCC_u8_APB1_CLOCK_DIVIDED_BY_2    		  *
 * 			  3- RCC_u8_APB1_CLOCK_DIVIDED_BY_4    		  *
 * 			  4- RCC_u8_APB1_CLOCK_DIVIDED_BY_8   		  *
 * 			  5- RCC_u8_APB1_CLOCK_DIVIDED_BY_16   		  *
 **********************************************************/

#define RCC_u8_APB1_PRESCALLER	RCC_u8_APB1_CLOCK_NOT_DIVIDED



/********************* AHB PRESCALER **********************
 * 								  	   		   			  *
 *  Options : 1- RCC_u8_AHB_CLOCK_NOT_DIVIDED			  *
 * 			  2- RCC_u8_AHB_CLOCK_DIVIDED_BY_2    		  *
 * 			  3- RCC_u8_AHB_CLOCK_DIVIDED_BY_4    		  *
 * 			  4- RCC_u8_AHB_CLOCK_DIVIDED_BY_8   		  *
 * 			  5- RCC_u8_AHB_CLOCK_DIVIDED_BY_16   		  *
 * 			  6- RCC_u8_AHB_CLOCK_DIVIDED_BY_64    		  *
 * 			  7- RCC_u8_AHB_CLOCK_DIVIDED_BY_128   		  *
 * 			  8- RCC_u8_AHB_CLOCK_DIVIDED_BY_256   		  *
 * 			  9- RCC_u8_AHB_CLOCK_DIVIDED_BY_512   		  *
 **********************************************************/

#define RCC_u8_AHB_PRESCALLER	RCC_u8_AHB_CLOCK_NOT_DIVIDED

#endif
