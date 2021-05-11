/*****************************************************************/
/****************** Name    : Ahmed Kishk 	**********************/
/****************** Date    : 9/5/2021  	**********************/
/****************** Version : 1.0V       	**********************/
/****************** SWC     : RCC           **********************/
/*****************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "stm32f103C8.h"

#include "RCC_interface.h"
#include "RCC_config.h"
#include "RCC_private.h"



u8 RCC_u8InitSysClock(void){
	u8 LOC_u8Feedback	=	RCC_OK;
	u32 LOC_u32Iterator	=	0	;

	/*********************************************************************
	********************     CLOCK TYPE HSE ENABLE     *******************
	*********************************************************************/
	#if 	RCC_u8_CLOCK_TYPE == RCC_u8_HSE
		SET_BIT(RCC->CR,16);
		/* LOOP TO MAKE THE HSE IS READY TO RUN */
		for(LOC_u32Iterator = 0 ; LOC_u32Iterator < 10000 ; LOC_u32Iterator++){
			if(GET_BIT(RCC->CR,17) == 0){
				LOC_u8Feedback	=	RCC_NOK;
			}
			else{
				LOC_u8Feedback	=	RCC_OK;
				break;
			}
		}
		if(LOC_u8Feedback	==	RCC_OK){
		SET_BIT(RCC->CFGR,0);
		CLR_BIT(RCC->CFGR,1);
		for(LOC_u32Iterator = 0 ; LOC_u32Iterator < 10000 ; LOC_u32Iterator++){
			if(GET_BIT(RCC->CFGR,3) == 0 && GET_BIT(RCC->CFGR,2) == 1 ){
				LOC_u8Feedback	=	RCC_OK;
				break;
			}
			else{
				LOC_u8Feedback	=	RCC_NOK;
			}
		}
		}
	/*********************************************************************
	********************     CLOCK TYPE HSI ENABLE     *******************
	*********************************************************************/
	#elif	RCC_u8_CLOCK_TYPE == RCC_u8_HSI
		SET_BIT(RCC->CR,0);
		/* LOOP TO MAKE THE HSI IS READY TO RUN */
		for(LOC_u32Iterator = 0 ; LOC_u32Iterator < 10000 ; LOC_u32Iterator++){
			if(GET_BIT(RCC->CR,1) == 0){
				LOC_u8Feedback	=	RCC_NOK;
			}
			else{
				LOC_u8Feedback	=	RCC_OK;
				break;
			}
		}
		if(LOC_u8Feedback	==	RCC_OK){
		CLR_BIT(RCC->CFGR,0);
		CLR_BIT(RCC->CFGR,1);
		for(LOC_u32Iterator = 0 ; LOC_u32Iterator < 10000 ; LOC_u32Iterator++){
			if(GET_BIT(RCC->CFGR,3) == 0 && GET_BIT(RCC->CFGR,2) == 0 ){
				LOC_u8Feedback	=	RCC_OK;
				break;
			}
			else{
				LOC_u8Feedback	=	RCC_NOK;
			}
		}
		}
	/*********************************************************************
	********************     CLOCK TYPE PLL ENABLE     *******************
	*********************************************************************/
	#elif 	RCC_u8_CLOCK_TYPE == RCC_u8_PLL
		/*********************************************************************
		********************     PLL CLOCK ENTRY SOURCE    *******************
		*********************************************************************/
		#if	RCC_u8_PLL_ENTRY	==	RCC_u8_HSI_CLOCK_DIVIDED_BY_2
			CLR_BIT(RCC->CFGR , 16);
		#elif RCC_u8_HSE_DIVIDER	==	RCC_u8_HSE_NOT_DIVIDED
			CLR_BIT(RCC->CFGR , 17);
			SET_BIT(RCC->CFGR , 16);
		#elif RCC_u8_HSE_DIVIDER	==	RCC_u8_HSE_DIVIDED_BY_2
			SET_BIT(RCC->CFGR , 17);
			SET_BIT(RCC->CFGR , 16);
		#endif
		SET_BIT(RCC->CR,24);
		/* LOOP TO MAKE THE PLL IS READY TO RUN */
		for(LOC_u32Iterator = 0 ; LOC_u32Iterator < 10000 ; LOC_u32Iterator++){
			if(GET_BIT(RCC->CR,25) == 0){
				LOC_u8Feedback	=	RCC_NOK;
			}
			else{
				LOC_u8Feedback	=	RCC_OK;
				break;
			}
		}
		if(LOC_u8Feedback	==	RCC_OK){
			CLR_BIT(RCC->CFGR,0);
			SET_BIT(RCC->CFGR,1);
			for(LOC_u32Iterator = 0 ; LOC_u32Iterator < 10000 ; LOC_u32Iterator++){
				if(GET_BIT(RCC->CFGR,3) == 1 && GET_BIT(RCC->CFGR,2) == 0 ){
					LOC_u8Feedback	=	RCC_OK;
					break;
				}
				else{
					LOC_u8Feedback	=	RCC_NOK;
				}
			}
		}
	#else
		#warning "Wrong Choice Clock Type"
	#endif
		/*********************************************************************
		*************************     RCC SECURITY     ***********************
		*********************************************************************/
	#if RCC_u8_CLOCK_SECURTIY == RCC_u8_SECURITY_ON
		SET_BIT(RCC->CR,19);
	#endif
		/*********************************************************************
		*************************     RCC BYPASSED     ***********************
		*********************************************************************/
	#if RCC_u8_EXTERNAL_CLOCK == RCC_u8_BYPASSED
		SET_BIT(RCC->CR , 18);
	#endif
		/*********************************************************************
		*************************     OUTPUT CLOCK     ***********************
		*********************************************************************/
	#if RCC_u8_OUTPUT_CLOCK	==	RCC_u8_SYS_CLOCK
		SET_BIT(RCC->CFGR , 26);
	#elif RCC_u8_OUTPUT_CLOCK	==	RCC_u8_HSI_CLOCK
		SET_BIT(RCC->CFGR , 26);
		SET_BIT(RCC->CFGR , 24);
	#elif RCC_u8_OUTPUT_CLOCK	==	RCC_u8_HSE_CLOCK
		SET_BIT(RCC->CFGR , 26);
		SET_BIT(RCC->CFGR , 25);
	#elif RCC_u8_OUTPUT_CLOCK	==	RCC_u8_PLL_CLOCK
		SET_BIT(RCC->CFGR , 26);
		SET_BIT(RCC->CFGR , 25);
		SET_BIT(RCC->CFGR , 24);
	#else
		CLR_BIT(RCC->CFGR , 26);
		CLR_BIT(RCC->CFGR , 25);
		CLR_BIT(RCC->CFGR , 24);
	#endif
		/*********************************************************************
		************************     USB PRESCALLER     **********************
		*********************************************************************/
	#if RCC_u8_USB_PRESCALLER	==	RCC_u8_USB_NO_PRESCALLER
		SET_BIT(RCC->CFGR , 22);
	#elif RCC_u8_USB_PRESCALLER	==	RCC_u8_USB_PRESCALLER
		CLR_BIT(RCC->CFGR , 22);
	#endif
		/*********************************************************************
		****************     PLL MULTIPLICATION FACTOR     *******************
		*********************************************************************/
	#if RCC_u8_PLL_MULTIPLICATION_FACTOR	==	RCC_u8_PLL_INPUT_CLOCK_x2
		CLR_BIT(RCC->CFGR , 18);
		CLR_BIT(RCC->CFGR , 19);
		CLR_BIT(RCC->CFGR , 20);
		CLR_BIT(RCC->CFGR , 21);

	#elif RCC_u8_PLL_MULTIPLICATION_FACTOR	==	RCC_u8_PLL_INPUT_CLOCK_x3
		SET_BIT(RCC->CFGR , 18);
		CLR_BIT(RCC->CFGR , 19);
		CLR_BIT(RCC->CFGR , 20);
		CLR_BIT(RCC->CFGR , 21);

	#elif RCC_u8_PLL_MULTIPLICATION_FACTOR	==	RCC_u8_PLL_INPUT_CLOCK_x4
		CLR_BIT(RCC->CFGR , 18);
		SET_BIT(RCC->CFGR , 19);
		CLR_BIT(RCC->CFGR , 20);
		CLR_BIT(RCC->CFGR , 21);

	#elif RCC_u8_PLL_MULTIPLICATION_FACTOR	==	RCC_u8_PLL_INPUT_CLOCK_x5
		SET_BIT(RCC->CFGR , 18);
		SET_BIT(RCC->CFGR , 19);
		CLR_BIT(RCC->CFGR , 20);
		CLR_BIT(RCC->CFGR , 21);

	#elif RCC_u8_PLL_MULTIPLICATION_FACTOR	==	RCC_u8_PLL_INPUT_CLOCK_x6
		CLR_BIT(RCC->CFGR , 18);
		CLR_BIT(RCC->CFGR , 19);
		SET_BIT(RCC->CFGR , 20);
		CLR_BIT(RCC->CFGR , 21);

	#elif RCC_u8_PLL_MULTIPLICATION_FACTOR	==	RCC_u8_PLL_INPUT_CLOCK_x7
		SET_BIT(RCC->CFGR , 18);
		CLR_BIT(RCC->CFGR , 19);
		SET_BIT(RCC->CFGR , 20);
		CLR_BIT(RCC->CFGR , 21);

	#elif RCC_u8_PLL_MULTIPLICATION_FACTOR	==	RCC_u8_PLL_INPUT_CLOCK_x8
		CLR_BIT(RCC->CFGR , 18);
		SET_BIT(RCC->CFGR , 19);
		SET_BIT(RCC->CFGR , 20);
		CLR_BIT(RCC->CFGR , 21);

	#elif RCC_u8_PLL_MULTIPLICATION_FACTOR	==	RCC_u8_PLL_INPUT_CLOCK_x9
		SET_BIT(RCC->CFGR , 18);
		SET_BIT(RCC->CFGR , 19);
		SET_BIT(RCC->CFGR , 20);
		CLR_BIT(RCC->CFGR , 21);

	#elif RCC_u8_PLL_MULTIPLICATION_FACTOR	==	RCC_u8_PLL_INPUT_CLOCK_x10
		CLR_BIT(RCC->CFGR , 18);
		CLR_BIT(RCC->CFGR , 19);
		CLR_BIT(RCC->CFGR , 20);
		SET_BIT(RCC->CFGR , 21);

	#elif RCC_u8_PLL_MULTIPLICATION_FACTOR	==	RCC_u8_PLL_INPUT_CLOCK_x11
		SET_BIT(RCC->CFGR , 18);
		CLR_BIT(RCC->CFGR , 19);
		CLR_BIT(RCC->CFGR , 20);
		SET_BIT(RCC->CFGR , 21);

	#elif RCC_u8_PLL_MULTIPLICATION_FACTOR	==	RCC_u8_PLL_INPUT_CLOCK_x12
		CLR_BIT(RCC->CFGR , 18);
		SET_BIT(RCC->CFGR , 19);
		CLR_BIT(RCC->CFGR , 20);
		SET_BIT(RCC->CFGR , 21);

	#elif RCC_u8_PLL_MULTIPLICATION_FACTOR	==	RCC_u8_PLL_INPUT_CLOCK_x13
		SET_BIT(RCC->CFGR , 18);
		SET_BIT(RCC->CFGR , 19);
		CLR_BIT(RCC->CFGR , 20);
		SET_BIT(RCC->CFGR , 21);

	#elif RCC_u8_PLL_MULTIPLICATION_FACTOR	==	RCC_u8_PLL_INPUT_CLOCK_x14
		CLR_BIT(RCC->CFGR , 18);
		CLR_BIT(RCC->CFGR , 19);
		SET_BIT(RCC->CFGR , 20);
		SET_BIT(RCC->CFGR , 21);

	#elif RCC_u8_PLL_MULTIPLICATION_FACTOR	==	RCC_u8_PLL_INPUT_CLOCK_x15
		SET_BIT(RCC->CFGR , 18);
		CLR_BIT(RCC->CFGR , 19);
		SET_BIT(RCC->CFGR , 20);
		SET_BIT(RCC->CFGR , 21);

	#elif RCC_u8_PLL_MULTIPLICATION_FACTOR	==	RCC_u8_PLL_INPUT_CLOCK_x15
		SET_BIT(RCC->CFGR , 18);
		CLR_BIT(RCC->CFGR , 19);
		SET_BIT(RCC->CFGR , 20);
		SET_BIT(RCC->CFGR , 21);

	#elif RCC_u8_PLL_MULTIPLICATION_FACTOR	==	RCC_u8_PLL_INPUT_CLOCK_x16
		SET_BIT(RCC->CFGR , 18);
		SET_BIT(RCC->CFGR , 19);
		SET_BIT(RCC->CFGR , 20);
		SET_BIT(RCC->CFGR , 21);
	#endif
		/*********************************************************************
		************************     ADC PRESCALLER     **********************
		*********************************************************************/
	#if RCC_u8_ADC_PRESCALLER	==	RCC_u8_ADC_CLOCK_DIVIDED_BY_2
		CLR_BIT(RCC->CFGR , 14);
		CLR_BIT(RCC->CFGR , 15);
	#elif RCC_u8_ADC_PRESCALLER	==	RCC_u8_ADC_CLOCK_DIVIDED_BY_4
		SET_BIT(RCC->CFGR , 14);
		CLR_BIT(RCC->CFGR , 15);
	#elif RCC_u8_ADC_PRESCALLER	==	RCC_u8_ADC_CLOCK_DIVIDED_BY_6
		CLR_BIT(RCC->CFGR , 14);
		SET_BIT(RCC->CFGR , 15);
	#elif RCC_u8_ADC_PRESCALLER	==	RCC_u8_ADC_CLOCK_DIVIDED_BY_8
		SET_BIT(RCC->CFGR , 14);
		SET_BIT(RCC->CFGR , 15);
	#endif
		/*********************************************************************
		************************     APB2 PRESCALLER     **********************
		*********************************************************************/
	#if RCC_u8_APB2_PRESCALLER	==	RCC_u8_APB2_CLOCK_NOT_DIVIDED
			CLR_BIT(RCC->CFGR , 13);
	#elif	RCC_u8_APB2_PRESCALLER	==	RCC_u8_APB2_CLOCK_DIVIDED_BY_2
			SET_BIT(RCC->CFGR , 13);
	#elif	RCC_u8_APB2_PRESCALLER	==	RCC_u8_APB2_CLOCK_DIVIDED_BY_4
			SET_BIT(RCC->CFGR , 13);
			SET_BIT(RCC->CFGR , 11);
	#elif	RCC_u8_APB2_PRESCALLER	==	RCC_u8_APB2_CLOCK_DIVIDED_BY_8
			SET_BIT(RCC->CFGR , 13);
			SET_BIT(RCC->CFGR , 12);
	#elif	RCC_u8_APB2_PRESCALLER	==	RCC_u8_APB2_CLOCK_DIVIDED_BY_16
			SET_BIT(RCC->CFGR , 13);
			SET_BIT(RCC->CFGR , 12);
			SET_BIT(RCC->CFGR , 11);
	#endif

		/*********************************************************************
		************************     APB1 PRESCALLER     **********************
		*********************************************************************/
	#if RCC_u8_APB1_PRESCALLER	==	RCC_u8_APB1_CLOCK_NOT_DIVIDED
			CLR_BIT(RCC->CFGR , 10);
	#elif	RCC_u8_APB1_PRESCALLER	==	RCC_u8_APB1_CLOCK_DIVIDED_BY_2
			SET_BIT(RCC->CFGR , 10);
	#elif	RCC_u8_APB1_PRESCALLER	==	RCC_u8_APB1_CLOCK_DIVIDED_BY_4
			SET_BIT(RCC->CFGR , 10);
			SET_BIT(RCC->CFGR , 8);
	#elif	RCC_u8_APB1_PRESCALLER	==	RCC_u8_APB1_CLOCK_DIVIDED_BY_8
			SET_BIT(RCC->CFGR , 10);
			SET_BIT(RCC->CFGR , 9);
	#elif	RCC_u8_APB1_PRESCALLER	==	RCC_u8_APB1_CLOCK_DIVIDED_BY_16
			SET_BIT(RCC->CFGR , 10);
			SET_BIT(RCC->CFGR , 9);
			SET_BIT(RCC->CFGR , 8);
	#endif

		/*********************************************************************
		************************     AHB PRESCALLER     **********************
		*********************************************************************/
	#if RCC_u8_AHB_PRESCALLER	==	RCC_u8_AHB_CLOCK_NOT_DIVIDED
			CLR_BIT(RCC->CFGR , 7);
	#elif	RCC_u8_AHB_PRESCALLER	==	RCC_u8_AHB_CLOCK_DIVIDED_BY_2
			SET_BIT(RCC->CFGR , 7);
	#elif	RCC_u8_AHB_PRESCALLER	==	RCC_u8_AHB_CLOCK_DIVIDED_BY_4
			SET_BIT(RCC->CFGR , 7);
			SET_BIT(RCC->CFGR , 4);
	#elif	RCC_u8_AHB_PRESCALLER	==	RCC_u8_AHB_CLOCK_DIVIDED_BY_8
			SET_BIT(RCC->CFGR , 7);
			SET_BIT(RCC->CFGR , 5);
	#elif	RCC_u8_AHB_PRESCALLER	==	RCC_u8_AHB_CLOCK_DIVIDED_BY_16
			SET_BIT(RCC->CFGR , 7);
			SET_BIT(RCC->CFGR , 5);
			SET_BIT(RCC->CFGR , 4);
	#elif	RCC_u8_AHB_PRESCALLER	==	RCC_u8_AHB_CLOCK_DIVIDED_BY_64
			SET_BIT(RCC->CFGR , 7);
			SET_BIT(RCC->CFGR , 6);
	#elif	RCC_u8_AHB_PRESCALLER	==	RCC_u8_AHB_CLOCK_DIVIDED_BY_128
			SET_BIT(RCC->CFGR , 7);
			SET_BIT(RCC->CFGR , 6);
			SET_BIT(RCC->CFGR , 4);
	#elif	RCC_u8_AHB_PRESCALLER	==	RCC_u8_AHB_CLOCK_DIVIDED_BY_256
			SET_BIT(RCC->CFGR , 7);
			SET_BIT(RCC->CFGR , 6);
			SET_BIT(RCC->CFGR , 5);
	#elif	RCC_u8_AHB_PRESCALLER	==	RCC_u8_AHB_CLOCK_DIVIDED_BY_512
			SET_BIT(RCC->CFGR , 7);
			SET_BIT(RCC->CFGR , 6);
			SET_BIT(RCC->CFGR , 5);
			SET_BIT(RCC->CFGR , 4);
	#endif

		/*********************************************************************
		******************    RTC EXTERNAL CLOCK BYPASS    *******************
		**********************************************************************/
	#if	RCC_u8_RTC_EXTERNAL_CLOCK_BYPASS == RCC_u8_RTC_EXTERNAL_BYPASS_ENABLE
		SET_BIT(RCC->BDCR , 2);
	#else
		CLR_BIT(RCC->BDCR , 2);
	#endif

		/*********************************************************************
		************************    RTC CLOCK SOURCE    **********************
		*********************************************************************/
	#if	RCC_u8_RTC_CLOCK_SOURCE		==	RCC_u8_RTC_LSE_SOURCE
		SET_BIT(RCC->BDCR , 0);
		for(LOC_u32Iterator = 0 ; LOC_u32Iterator < 10000 ; LOC_u32Iterator++){
					if(GET_BIT(RCC->BDCR,1) == 0){
						LOC_u8Feedback	=	RCC_NOK;
					}
					else{
						LOC_u8Feedback	=	RCC_OK;
						break;
					}
		}
		SET_BIT(RCC->BDCR , 8);
		CLR_BIT(RCC->BDCR , 9);
		SET_BIT(RCC->BDCR , 15);

	#elif	RCC_u8_RTC_CLOCK_SOURCE	==	RCC_u8_RTC_LSI_SOURCE
		CLR_BIT(RCC->BDCR , 8);
		SET_BIT(RCC->BDCR , 9);
		SET_BIT(RCC->BDCR , 15);
	#elif	RCC_u8_RTC_CLOCK_SOURCE	==	RCC_u8_RTC_HSE_SOURCE
		SET_BIT(RCC->BDCR , 8);
		SET_BIT(RCC->BDCR , 9);
		SET_BIT(RCC->BDCR , 15);
	#endif

	return LOC_u8Feedback;
}


u8	RCC_u8EnablePeripheralClock(u8 Copy_u8BusId, u8 Copy_u8PeriId){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_u8PeriId < 32){
		switch (Copy_u8BusId){
		case RCC_u8_AHB_BUS:
			SET_BIT(RCC->AHBENR , Copy_u8PeriId);
			break;
		case RCC_u8_APB2_BUS:
			SET_BIT(RCC->APB2ENR , Copy_u8PeriId);
			break;
		case RCC_u8_APB1_BUS:
			SET_BIT(RCC->APB1ENR , Copy_u8PeriId);
			break;
		default:
			Local_u8ErrorState = STD_TYPES_NOK;
			break;
		}
	}
	else{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}




u8	RCC_u8DisablePeripheralClock(u8 Copy_u8BusId, u8 Copy_u8PeriId){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_u8PeriId < 32){
		switch (Copy_u8BusId){
		case RCC_u8_AHB_BUS:
			CLR_BIT(RCC->AHBENR , Copy_u8PeriId);
			break;
		case RCC_u8_APB2_BUS:
			CLR_BIT(RCC->APB2ENR , Copy_u8PeriId);
			break;
		case RCC_u8_APB1_BUS:
			CLR_BIT(RCC->APB1ENR , Copy_u8PeriId);
			break;
		default:
			Local_u8ErrorState = STD_TYPES_NOK;
			break;
		}
	}
	else{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}


u8 RCC_u8InterruptEnable(u8 Copy_u8InterruptId){
	u8 LOC_u8ErrorState = STD_TYPES_OK;
	if(Copy_u8InterruptId >= RCC_u8_LSI_READY  && Copy_u8InterruptId <= RCC_u8_PLL_READY)
	{
		SET_BIT(RCC->CIR , Copy_u8InterruptId );
	}
	else{
		LOC_u8ErrorState = STD_TYPES_NOK;
	}
	return LOC_u8ErrorState;
}


u8	 RCC_u8InterruptDisable(u8 Copy_u8InterruptId){
	u8 LOC_u8ErrorState = STD_TYPES_OK;
	if(Copy_u8InterruptId >= RCC_u8_LSI_READY  && Copy_u8InterruptId <= RCC_u8_PLL_READY)
	{
		CLR_BIT(RCC->CIR , Copy_u8InterruptId );
	}
	else{
		LOC_u8ErrorState = STD_TYPES_NOK;
	}
	return LOC_u8ErrorState;
}

u8	 RCC_u8ClearInterruptFlag(u8 Copy_u8FlagId){
	u8 LOC_u8ErrorState = STD_TYPES_OK;
	if((Copy_u8FlagId >= RCC_u8_LSI_READY_FLAG  && Copy_u8FlagId <= RCC_u8_PLL_READY_FLAG) || Copy_u8FlagId == RCC_u8_CLOCK_SECURITY_SYS)
	{
		SET_BIT(RCC->CIR , Copy_u8FlagId );
	}
	else{
		LOC_u8ErrorState = STD_TYPES_NOK;
	}
	return LOC_u8ErrorState;
}


u8	 RCC_u8PeripheralResetRegister(u8 Copy_u8BusId, u8 Copy_u8PeriId){
	u8 LOC_u8ErrorState = STD_TYPES_OK;
	if(Copy_u8PeriId < 32){
	switch (Copy_u8BusId){
		case RCC_u8_APB2_BUS:
			SET_BIT(RCC->APB2RSTR , Copy_u8PeriId);
			break;

		case RCC_u8_APB1_BUS:
			SET_BIT(RCC->APB1RSTR , Copy_u8PeriId);
			break;
		default:
			LOC_u8ErrorState = STD_TYPES_NOK;
			break;
		}
	}
	else{
		LOC_u8ErrorState = STD_TYPES_NOK;
	}
	return LOC_u8ErrorState;
}


void RCC_voidBackupDomainReset(void){
	SET_BIT(RCC->BDCR , 16);
}

