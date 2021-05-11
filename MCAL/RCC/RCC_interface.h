/*****************************************************************/
/****************** Name    : Ahmed Kishk 	**********************/
/****************** Date    : 9/5/2021  	**********************/
/****************** Version : 1.0V       	**********************/
/****************** SWC     : RCC           **********************/
/*****************************************************************/

#ifndef _RCC_INTERFACE_H
#define _RCC_INTERFACE_H

#define RCC_OK	1
#define RCC_NOK	0

/*********************************************************************
************************     INTERRUPTS ID     ***********************
**********************************************************************/
#define RCC_u8_PLL_READY				12
#define RCC_u8_HSE_READY				11
#define RCC_u8_HSI_READY				10
#define RCC_u8_LSE_READY				9
#define RCC_u8_LSI_READY				8

/*********************************************************************
***************************     FLAG ID     **************************
**********************************************************************/
#define RCC_u8_CLOCK_SECURITY_SYS		23
#define RCC_u8_PLL_READY_FLAG			20
#define RCC_u8_HSE_READY_FLAG			19
#define RCC_u8_HSI_READY_FLAG			18
#define RCC_u8_LSE_READY_FLAG			17
#define RCC_u8_LSI_READY_FLAG			16

/*********************************************************************
***************************     BUS ID     **************************
**********************************************************************/
#define RCC_u8_AHB_BUS					1
#define RCC_u8_APB2_BUS					2
#define RCC_u8_APB1_BUS					3

/*********************************************************************
******************     RESET PRIPHERAL ID (APB2)    ******************
**********************************************************************/
#define RCC_u8_APB2_TIMER11_RESET		21
#define RCC_u8_APB2_TIMER10_RESET		20
#define RCC_u8_APB2_TIMER9_RESET		19
#define RCC_u8_APB2_ADC3_RESET			15
#define RCC_u8_APB2_USART1_RESET		14
#define RCC_u8_APB2_TIMER8_RESET		13
#define RCC_u8_APB2_SPI1_RESET			12
#define RCC_u8_APB2_TIMER1_RESET		11
#define RCC_u8_APB2_ADC2_RESET			10
#define RCC_u8_APB2_ADC1_RESET			9
#define RCC_u8_APB2_IO_PORT_G_RESET		8
#define RCC_u8_APB2_IO_PORT_F_RESET		7
#define RCC_u8_APB2_IO_PORT_E_RESET		6
#define RCC_u8_APB2_IO_PORT_D_RESET		5
#define RCC_u8_APB2_IO_PORT_C_RESET		4
#define RCC_u8_APB2_IO_PORT_B_RESET		3
#define RCC_u8_APB2_IO_PORT_A_RESET		2
#define RCC_u8_APB2_IO_ALTERNATE_RESET	2


/*********************************************************************
******************     RESET PRIPHERAL ID (APB1)    ******************
**********************************************************************/
#define RCC_u8_APB1_DAC_RESET			29
#define RCC_u8_APB1_POWER_RESET			28
#define RCC_u8_APB1_BACKUP_RESET		27
#define RCC_u8_APB1_CAN_RESET			25
#define RCC_u8_APB1_USB_RESET			23
#define RCC_u8_APB1_I2C2_RESET			22
#define RCC_u8_APB1_I2C1_RESET			21
#define RCC_u8_APB1_USART5_RESET		20
#define RCC_u8_APB1_USART4_RESET		19
#define RCC_u8_APB1_USART3_RESET		18
#define RCC_u8_APB1_USART2_RESET		17
#define RCC_u8_APB1_SPI3_RESET			15
#define RCC_u8_APB1_SPI2_RESET			14
#define RCC_u8_APB1_WWD_RESET			11
#define RCC_u8_APB1_TIMER14_RESET		8
#define RCC_u8_APB1_TIMER13_RESET		7
#define RCC_u8_APB1_TIMER12_RESET		6
#define RCC_u8_APB1_TIMER7_RESET		5
#define RCC_u8_APB1_TIMER6_RESET		4
#define RCC_u8_APB1_TIMER5_RESET		3
#define RCC_u8_APB1_TIMER4_RESET		2
#define RCC_u8_APB1_TIMER3_RESET		1
#define RCC_u8_APB1_TIMER2_RESET		0

/*********************************************************************
*****************     ENABLE PRIPHERAL CLOCK (AHB)    ****************
**********************************************************************/
#define RCC_u8_AHB_SDIO_ENABLE			10
#define RCC_u8_AHB_FSMC_ENABLE			8
#define RCC_u8_AHB_CRC_ENABLE			6
#define RCC_u8_AHB_FLITF_ENABLE			4
#define RCC_u8_AHB_SRAM_ENABLE			2
#define RCC_u8_AHB_DMA2_ENABLE			1
#define RCC_u8_AHB_DMA1_ENABLE			0

/*********************************************************************
****************     ENABLE PRIPHERAL CLOCK (APB2)    ****************
**********************************************************************/
#define RCC_u8_APB2_TIMER11_ENABLE		21
#define RCC_u8_APB2_TIMER10_ENABLE		20
#define RCC_u8_APB2_TIMER9_ENABLE		19
#define RCC_u8_APB2_ADC3_ENABLE			15
#define RCC_u8_APB2_USART_ENABLE		14
#define RCC_u8_APB2_TIMER8_ENABLE		13
#define RCC_u8_APB2_SPI1_ENABLE			12
#define RCC_u8_APB2_TIMER1_ENABLE		11
#define RCC_u8_APB2_ADC2_ENABLE			10
#define RCC_u8_APB2_ADC1_ENABLE			9
#define RCC_u8_APB2_IO_PORT_G_ENABLE	8
#define RCC_u8_APB2_IO_PORT_F_ENABLE	7
#define RCC_u8_APB2_IO_PORT_E_ENABLE	6
#define RCC_u8_APB2_IO_PORT_D_ENABLE	5
#define RCC_u8_APB2_IO_PORT_C_ENABLE	4
#define RCC_u8_APB2_IO_PORT_B_ENABLE	3
#define RCC_u8_APB2_IO_PORT_A_ENABLE	2
#define RCC_u8_APB2_IO_ALTERNATE_ENABLE	0


/*********************************************************************
****************     ENABLE PRIPHERAL CLOCK (APB1)    ****************
**********************************************************************/
#define RCC_u8_APB1_DAC_ENABLE			29
#define RCC_u8_APB1_POWER_ENABLE		28
#define RCC_u8_APB1_BACKUP_ENABLE		27
#define RCC_u8_APB1_CAN_ENABLE			25
#define RCC_u8_APB1_USB_ENABLE			23
#define RCC_u8_APB1_I2C2_ENABLE			22
#define RCC_u8_APB1_I2C1_ENABLE			21
#define RCC_u8_APB1_USART5_ENABLE		20
#define RCC_u8_APB1_USART4_ENABLE		19
#define RCC_u8_APB1_USART3_ENABLE		18
#define RCC_u8_APB1_USART2_ENABLE		17
#define RCC_u8_APB1_SPI3_ENABLE			15
#define RCC_u8_APB1_SPI2_ENABLE			14
#define RCC_u8_APB1_WWD_ENABLE			11
#define RCC_u8_APB1_TIMER14_ENABLE		8
#define RCC_u8_APB1_TIMER13_ENABLE		7
#define RCC_u8_APB1_TIMER12_ENABLE		6
#define RCC_u8_APB1_TIMER7_ENABLE		5
#define RCC_u8_APB1_TIMER6_ENABLE		4
#define RCC_u8_APB1_TIMER5_ENABLE		3
#define RCC_u8_APB1_TIMER4_ENABLE		2
#define RCC_u8_APB1_TIMER3_ENABLE		1
#define RCC_u8_APB1_TIMER2_ENABLE		0


/*********************************************************************
*********************     FUNCTIONS PROTOTYPE     ********************
**********************************************************************/

u8   RCC_u8InitSysClock(void);
u8	 RCC_u8EnablePeripheralClock(u8 Copy_u8BusId, u8 Copy_u8PeriId);
u8	 RCC_u8DisablePeripheralClock(u8 Copy_u8BusId, u8 Copy_u8PeriId);
u8	 RCC_u8InterruptEnable(u8 Copy_u8InterruptId);
u8	 RCC_u8InterruptDisable(u8 Copy_u8InterruptId);
u8	 RCC_u8ClearInterruptFlag(u8 Copy_u8FlagId);
u8	 RCC_u8PeripheralResetRegister(u8 Copy_u8BusId, u8 Copy_u8PeriId);
void RCC_voidBackupDomainReset(void);

#endif
