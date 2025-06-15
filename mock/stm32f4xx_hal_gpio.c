#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "stm32f4xx_hal_gpio.h"

GPIO_TypeDef mock_gpioa;
GPIO_TypeDef mock_gpiob;
GPIO_TypeDef mock_gpioc;
GPIO_TypeDef mock_gpiod;

EXTI_TypeDef mock_exti;

GPIO_InitTypeDef GPIO_Init_Spy;

#define GPIO_MODE             0x00000003U
#define EXTI_MODE             0x10000000U
#define GPIO_MODE_IT          0x00010000U
#define GPIO_MODE_EVT         0x00020000U
#define RISING_EDGE           0x00100000U
#define FALLING_EDGE          0x00200000U
#define GPIO_OUTPUT_TYPE      0x00000010U
#define GPIO_NUMBER           16U

static void HAL_GPIO_Init_Impl(GPIO_TypeDef  *GPIOx, GPIO_InitTypeDef *GPIO_Init)
{
uint32_t position;
uint32_t ioposition = 0x00U;
uint32_t iocurrent = 0x00U;
uint32_t temp = 0x00U;

/* Check the parameters */
// assert_param(IS_GPIO_ALL_INSTANCE(GPIOx));
// assert_param(IS_GPIO_PIN(GPIO_Init->Pin));
// assert_param(IS_GPIO_MODE(GPIO_Init->Mode));
// assert_param(IS_GPIO_PULL(GPIO_Init->Pull));

/* Configure the port pins */
for(position = 0U; position < GPIO_NUMBER; position++)
{
/* Get the IO position */
ioposition = 0x01U << position;
/* Get the current IO position */
iocurrent = (uint32_t)(GPIO_Init->Pin) & ioposition;

if(iocurrent == ioposition)
{
/*--------------------- GPIO Mode Configuration ------------------------*/
/* In case of Alternate function mode selection */
if((GPIO_Init->Mode == GPIO_MODE_AF_PP) || (GPIO_Init->Mode == GPIO_MODE_AF_OD))
{
/* Check the Alternate function parameter */
// assert_param(IS_GPIO_AF(GPIO_Init->Alternate));
/* Configure Alternate function mapped with the current IO */
temp = GPIOx->AFR[position >> 3U];
temp &= ~(0xFU << ((uint32_t)(position & 0x07U) * 4U)) ;
temp |= ((uint32_t)(GPIO_Init->Alternate) << (((uint32_t)position & 0x07U) * 4U));
GPIOx->AFR[position >> 3U] = temp;
}

/* Configure IO Direction mode (Input, Output, Alternate or Analog) */
temp = GPIOx->MODER;
temp &= ~(GPIO_MODER_MODER0 << (position * 2U));
temp |= ((GPIO_Init->Mode & GPIO_MODE) << (position * 2U));
GPIOx->MODER = temp;

/* In case of Output or Alternate function mode selection */
if((GPIO_Init->Mode == GPIO_MODE_OUTPUT_PP) || (GPIO_Init->Mode == GPIO_MODE_AF_PP) ||
 (GPIO_Init->Mode == GPIO_MODE_OUTPUT_OD) || (GPIO_Init->Mode == GPIO_MODE_AF_OD))
{
/* Check the Speed parameter */
// assert_param(IS_GPIO_SPEED(GPIO_Init->Speed));
/* Configure the IO Speed */
temp = GPIOx->OSPEEDR; 
temp &= ~(GPIO_OSPEEDER_OSPEEDR0 << (position * 2U));
temp |= (GPIO_Init->Speed << (position * 2U));
GPIOx->OSPEEDR = temp;

/* Configure the IO Output Type */
temp = GPIOx->OTYPER;
temp &= ~(GPIO_OTYPER_OT_0 << position) ;
temp |= (((GPIO_Init->Mode & GPIO_OUTPUT_TYPE) >> 4U) << position);
GPIOx->OTYPER = temp;
}

/* Activate the Pull-up or Pull down resistor for the current IO */
temp = GPIOx->PUPDR;
temp &= ~(GPIO_PUPDR_PUPDR0 << (position * 2U));
temp |= ((GPIO_Init->Pull) << (position * 2U));
GPIOx->PUPDR = temp;

/*--------------------- EXTI Mode Configuration ------------------------*/
/* Configure the External Interrupt or event for the current IO */
if((GPIO_Init->Mode & EXTI_MODE) == EXTI_MODE)
{
/* Enable SYSCFG Clock */
// __HAL_RCC_SYSCFG_CLK_ENABLE();

// temp = SYSCFG->EXTICR[position >> 2U];
// temp &= ~(0x0FU << (4U * (position & 0x03U)));
// temp |= ((uint32_t)(GPIO_GET_INDEX(GPIOx)) << (4U * (position & 0x03U)));
// SYSCFG->EXTICR[position >> 2U] = temp;

// /* Clear EXTI line configuration */
// temp = EXTI->IMR;
// temp &= ~((uint32_t)iocurrent);
// if((GPIO_Init->Mode & GPIO_MODE_IT) == GPIO_MODE_IT)
// {
//   temp |= iocurrent;
// }
// EXTI->IMR = temp;

// temp = EXTI->EMR;
// temp &= ~((uint32_t)iocurrent);
// if((GPIO_Init->Mode & GPIO_MODE_EVT) == GPIO_MODE_EVT)
// {
//   temp |= iocurrent;
// }
// EXTI->EMR = temp;

// /* Clear Rising Falling edge configuration */
// temp = EXTI->RTSR;
// temp &= ~((uint32_t)iocurrent);
// if((GPIO_Init->Mode & RISING_EDGE) == RISING_EDGE)
// {
//   temp |= iocurrent;
// }
// EXTI->RTSR = temp;

// temp = EXTI->FTSR;
// temp &= ~((uint32_t)iocurrent);
// if((GPIO_Init->Mode & FALLING_EDGE) == FALLING_EDGE)
// {
//   temp |= iocurrent;
// }
// EXTI->FTSR = temp;
}
}
}
}

void (*HAL_GPIO_Init)(GPIO_TypeDef  *GPIOx, GPIO_InitTypeDef *GPIO_Init) = HAL_GPIO_Init_Impl;

void HAL_GPIO_Init_spyInitTypeDef(GPIO_TypeDef  *GPIOx, GPIO_InitTypeDef *GPIO_Init)
{
    GPIO_Init_Spy.Pin = GPIO_Init->Pin;
    GPIO_Init_Spy.Mode = GPIO_Init->Mode;
    GPIO_Init_Spy.Pull = GPIO_Init->Pull;
    GPIO_Init_Spy.Speed = GPIO_Init->Speed;
    GPIO_Init_Spy.Alternate = GPIO_Init->Alternate;
    GPIOx->BSRR = 0;    // Set register for WritePin() to zero on init. 
    //TODO: Change this so that it can shift this bit out into ODR later
}

GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    GPIO_PinState bitstatus;

    // Check the parameters 
    // assert_param(IS_GPIO_PIN(GPIO_Pin));

    if((GPIOx->IDR & GPIO_Pin) != (uint32_t)GPIO_PIN_RESET)
    {
        bitstatus = GPIO_PIN_SET;
    }
    else
    {
        bitstatus = GPIO_PIN_RESET;
    }
    return bitstatus;
}

void HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
{
    if(PinState != GPIO_PIN_RESET)
    {
        GPIOx->BSRR = GPIO_Pin;
    }
    else
    {
        GPIOx->BSRR = (uint32_t)GPIO_Pin << 16U;
    }
}
void HAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    GPIOx->ODR ^= GPIO_Pin;
}

void HAL_GPIO_EXTI_IRQHandler(uint16_t GPIO_Pin)
{
  /* EXTI line interrupt detected */
  if(__HAL_GPIO_EXTI_GET_IT(GPIO_Pin) != 0)
  {
    __HAL_GPIO_EXTI_CLEAR_IT(GPIO_Pin);
    // HAL_GPIO_EXTI_Callback(GPIO_Pin);
  }
}