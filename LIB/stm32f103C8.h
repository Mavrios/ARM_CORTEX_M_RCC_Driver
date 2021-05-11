#ifndef _STM32F103C8_H
#define _STM32F103C8_H

typedef struct
{
    volatile u32 CR         ;
    volatile u32 CFGR       ;
    volatile u32 CIR        ;
    volatile u32 APB2RSTR   ;
    volatile u32 APB1RSTR   ;
    volatile u32 AHBENR     ;
    volatile u32 APB2ENR   ;
    volatile u32 APB1ENR   ;
    volatile u32 BDCR       ;
    volatile u32 CSR        ;
    }RCC_RegDef_t;


#define RCC         ((RCC_RegDef_t * ) 0x40021000)

#endif
