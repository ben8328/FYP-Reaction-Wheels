/**
  ******************************************************************************
  * @file    stm32f4xx_hal_rcc.h
  * @author  MCD Application Team
  * @brief   Header file of RCC HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2017 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F4xx_HAL_RCC_H
#define __STM32F4xx_HAL_RCC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal_def.h"


typedef struct
{
  __IO uint32_t CR;            /*!< RCC clock control register,                                  Address offset: 0x00 */
  __IO uint32_t PLLCFGR;       /*!< RCC PLL configuration register,                              Address offset: 0x04 */
  __IO uint32_t CFGR;          /*!< RCC clock configuration register,                            Address offset: 0x08 */
  __IO uint32_t CIR;           /*!< RCC clock interrupt register,                                Address offset: 0x0C */
  __IO uint32_t AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
  __IO uint32_t AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
  __IO uint32_t AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */
  uint32_t      RESERVED0;     /*!< Reserved, 0x1C                                                                    */
  __IO uint32_t APB1RSTR;      /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
  __IO uint32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
  uint32_t      RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                               */
  __IO uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
  __IO uint32_t AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
  __IO uint32_t AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */
  uint32_t      RESERVED2;     /*!< Reserved, 0x3C                                                                    */
  __IO uint32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
  __IO uint32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
  uint32_t      RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                               */
  __IO uint32_t AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
  __IO uint32_t AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
  __IO uint32_t AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
  uint32_t      RESERVED4;     /*!< Reserved, 0x5C                                                                    */
  __IO uint32_t APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
  __IO uint32_t APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
  uint32_t      RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */
  __IO uint32_t BDCR;          /*!< RCC Backup domain control register,                          Address offset: 0x70 */
  __IO uint32_t CSR;           /*!< RCC clock control & status register,                         Address offset: 0x74 */
  uint32_t      RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */
  __IO uint32_t SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
  __IO uint32_t PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
  uint32_t      RESERVED7[1];  /*!< Reserved, 0x88                                                                    */
  __IO uint32_t DCKCFGR;       /*!< RCC Dedicated Clocks configuration register,                 Address offset: 0x8C */
} RCC_TypeDef;

extern RCC_TypeDef RCC_Spy;

#define RCC   (&RCC_Spy)

/* Include RCC HAL Extended module */
/* (include on top of file since RCC structures are defined in extended file) */
#include "stm32f4xx_hal_rcc_ex.h"


/** @addtogroup STM32F4xx_HAL_Driver
  * @{
  */

/** @addtogroup RCC
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup RCC_Exported_Types RCC Exported Types
  * @{
  */

/**
  * @brief  RCC Internal/External Oscillator (HSE, HSI, LSE and LSI) configuration structure definition
  */
typedef struct
{
  uint32_t OscillatorType;       /*!< The oscillators to be configured.
                                      This parameter can be a value of @ref RCC_Oscillator_Type                   */

  uint32_t HSEState;             /*!< The new state of the HSE.
                                      This parameter can be a value of @ref RCC_HSE_Config                        */

  uint32_t LSEState;             /*!< The new state of the LSE.
                                      This parameter can be a value of @ref RCC_LSE_Config                        */

  uint32_t HSIState;             /*!< The new state of the HSI.
                                      This parameter can be a value of @ref RCC_HSI_Config                        */

  uint32_t HSICalibrationValue;  /*!< The HSI calibration trimming value (default is RCC_HSICALIBRATION_DEFAULT).
                                       This parameter must be a number between Min_Data = 0x00 and Max_Data = 0x1F */

  uint32_t LSIState;             /*!< The new state of the LSI.
                                      This parameter can be a value of @ref RCC_LSI_Config                        */

  RCC_PLLInitTypeDef PLL;        /*!< PLL structure parameters                                                    */
}RCC_OscInitTypeDef;

/**
  * @brief  RCC System, AHB and APB busses clock configuration structure definition
  */
typedef struct
{
  uint32_t ClockType;             /*!< The clock to be configured.
                                       This parameter can be a value of @ref RCC_System_Clock_Type      */

  uint32_t SYSCLKSource;          /*!< The clock source (SYSCLKS) used as system clock.
                                       This parameter can be a value of @ref RCC_System_Clock_Source    */

  uint32_t AHBCLKDivider;         /*!< The AHB clock (HCLK) divider. This clock is derived from the system clock (SYSCLK).
                                       This parameter can be a value of @ref RCC_AHB_Clock_Source       */

  uint32_t APB1CLKDivider;        /*!< The APB1 clock (PCLK1) divider. This clock is derived from the AHB clock (HCLK).
                                       This parameter can be a value of @ref RCC_APB1_APB2_Clock_Source */

  uint32_t APB2CLKDivider;        /*!< The APB2 clock (PCLK2) divider. This clock is derived from the AHB clock (HCLK).
                                       This parameter can be a value of @ref RCC_APB1_APB2_Clock_Source */

}RCC_ClkInitTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup RCC_Exported_Constants RCC Exported Constants
  * @{
  */

/** @defgroup RCC_Oscillator_Type Oscillator Type
  * @{
  */
#define RCC_OSCILLATORTYPE_NONE            0x00000000U
#define RCC_OSCILLATORTYPE_HSE             0x00000001U
#define RCC_OSCILLATORTYPE_HSI             0x00000002U
#define RCC_OSCILLATORTYPE_LSE             0x00000004U
#define RCC_OSCILLATORTYPE_LSI             0x00000008U
/**
  * @}
  */

/** @defgroup RCC_HSE_Config HSE Config
  * @{
  */
#define RCC_HSE_OFF                      0x00000000U
#define RCC_HSE_ON                       RCC_CR_HSEON
#define RCC_HSE_BYPASS                   ((uint32_t)(RCC_CR_HSEBYP | RCC_CR_HSEON))
/**
  * @}
  */

/** @defgroup RCC_LSE_Config LSE Config
  * @{
  */
#define RCC_LSE_OFF                    0x00000000U
#define RCC_LSE_ON                     RCC_BDCR_LSEON
#define RCC_LSE_BYPASS                 ((uint32_t)(RCC_BDCR_LSEBYP | RCC_BDCR_LSEON))
/**
  * @}
  */

/** @defgroup RCC_HSI_Config HSI Config
  * @{
  */
#define RCC_HSI_OFF                      ((uint8_t)0x00)
#define RCC_HSI_ON                       ((uint8_t)0x01)

#define RCC_HSICALIBRATION_DEFAULT       0x10U         /* Default HSI calibration trimming value */
/**
  * @}
  */

/** @defgroup RCC_LSI_Config LSI Config
  * @{
  */
#define RCC_LSI_OFF                      ((uint8_t)0x00)
#define RCC_LSI_ON                       ((uint8_t)0x01)
/**
  * @}
  */

/** @defgroup RCC_PLL_Config PLL Config
  * @{
  */
#define RCC_PLL_NONE                      ((uint8_t)0x00)
#define RCC_PLL_OFF                       ((uint8_t)0x01)
#define RCC_PLL_ON                        ((uint8_t)0x02)
/**
  * @}
  */

/** @defgroup RCC_PLLP_Clock_Divider PLLP Clock Divider
  * @{
  */
#define RCC_PLLP_DIV2                  0x00000002U
#define RCC_PLLP_DIV4                  0x00000004U
#define RCC_PLLP_DIV6                  0x00000006U
#define RCC_PLLP_DIV8                  0x00000008U
/**
  * @}
  */

/** @defgroup RCC_PLL_Clock_Source PLL Clock Source
  * @{
  */
#define RCC_PLLSOURCE_HSI                RCC_PLLCFGR_PLLSRC_HSI
#define RCC_PLLSOURCE_HSE                RCC_PLLCFGR_PLLSRC_HSE
/**
  * @}
  */

/** @defgroup RCC_System_Clock_Type System Clock Type
  * @{
  */
#define RCC_CLOCKTYPE_SYSCLK             0x00000001U
#define RCC_CLOCKTYPE_HCLK               0x00000002U
#define RCC_CLOCKTYPE_PCLK1              0x00000004U
#define RCC_CLOCKTYPE_PCLK2              0x00000008U
/**
  * @}
  */

/** @defgroup RCC_System_Clock_Source System Clock Source
  * @note     The RCC_SYSCLKSOURCE_PLLRCLK parameter is available only for
  *           STM32F446xx devices.
  * @{
  */
#define RCC_SYSCLKSOURCE_HSI             RCC_CFGR_SW_HSI
#define RCC_SYSCLKSOURCE_HSE             RCC_CFGR_SW_HSE
#define RCC_SYSCLKSOURCE_PLLCLK          RCC_CFGR_SW_PLL
#define RCC_SYSCLKSOURCE_PLLRCLK         ((uint32_t)(RCC_CFGR_SW_0 | RCC_CFGR_SW_1))
/**
  * @}
  */

/** @defgroup RCC_System_Clock_Source_Status System Clock Source Status
  * @note     The RCC_SYSCLKSOURCE_STATUS_PLLRCLK parameter is available only for
  *           STM32F446xx devices.
  * @{
  */
#define RCC_SYSCLKSOURCE_STATUS_HSI     RCC_CFGR_SWS_HSI   /*!< HSI used as system clock */
#define RCC_SYSCLKSOURCE_STATUS_HSE     RCC_CFGR_SWS_HSE   /*!< HSE used as system clock */
#define RCC_SYSCLKSOURCE_STATUS_PLLCLK  RCC_CFGR_SWS_PLL   /*!< PLL used as system clock */
#define RCC_SYSCLKSOURCE_STATUS_PLLRCLK ((uint32_t)(RCC_CFGR_SWS_0 | RCC_CFGR_SWS_1))   /*!< PLLR used as system clock */
/**
  * @}
  */

/** @defgroup RCC_AHB_Clock_Source AHB Clock Source
  * @{
  */
#define RCC_SYSCLK_DIV1                  RCC_CFGR_HPRE_DIV1
#define RCC_SYSCLK_DIV2                  RCC_CFGR_HPRE_DIV2
#define RCC_SYSCLK_DIV4                  RCC_CFGR_HPRE_DIV4
#define RCC_SYSCLK_DIV8                  RCC_CFGR_HPRE_DIV8
#define RCC_SYSCLK_DIV16                 RCC_CFGR_HPRE_DIV16
#define RCC_SYSCLK_DIV64                 RCC_CFGR_HPRE_DIV64
#define RCC_SYSCLK_DIV128                RCC_CFGR_HPRE_DIV128
#define RCC_SYSCLK_DIV256                RCC_CFGR_HPRE_DIV256
#define RCC_SYSCLK_DIV512                RCC_CFGR_HPRE_DIV512
/**
  * @}
  */

/** @defgroup RCC_APB1_APB2_Clock_Source APB1/APB2 Clock Source
  * @{
  */
#define RCC_HCLK_DIV1                    RCC_CFGR_PPRE1_DIV1
#define RCC_HCLK_DIV2                    RCC_CFGR_PPRE1_DIV2
#define RCC_HCLK_DIV4                    RCC_CFGR_PPRE1_DIV4
#define RCC_HCLK_DIV8                    RCC_CFGR_PPRE1_DIV8
#define RCC_HCLK_DIV16                   RCC_CFGR_PPRE1_DIV16
/**
  * @}
  */

/** @defgroup RCC_RTC_Clock_Source RTC Clock Source
  * @{
  */
#define RCC_RTCCLKSOURCE_NO_CLK          0x00000000U
#define RCC_RTCCLKSOURCE_LSE             0x00000100U
#define RCC_RTCCLKSOURCE_LSI             0x00000200U
#define RCC_RTCCLKSOURCE_HSE_DIVX        0x00000300U
#define RCC_RTCCLKSOURCE_HSE_DIV2        0x00020300U
#define RCC_RTCCLKSOURCE_HSE_DIV3        0x00030300U
#define RCC_RTCCLKSOURCE_HSE_DIV4        0x00040300U
#define RCC_RTCCLKSOURCE_HSE_DIV5        0x00050300U
#define RCC_RTCCLKSOURCE_HSE_DIV6        0x00060300U
#define RCC_RTCCLKSOURCE_HSE_DIV7        0x00070300U
#define RCC_RTCCLKSOURCE_HSE_DIV8        0x00080300U
#define RCC_RTCCLKSOURCE_HSE_DIV9        0x00090300U
#define RCC_RTCCLKSOURCE_HSE_DIV10       0x000A0300U
#define RCC_RTCCLKSOURCE_HSE_DIV11       0x000B0300U
#define RCC_RTCCLKSOURCE_HSE_DIV12       0x000C0300U
#define RCC_RTCCLKSOURCE_HSE_DIV13       0x000D0300U
#define RCC_RTCCLKSOURCE_HSE_DIV14       0x000E0300U
#define RCC_RTCCLKSOURCE_HSE_DIV15       0x000F0300U
#define RCC_RTCCLKSOURCE_HSE_DIV16       0x00100300U
#define RCC_RTCCLKSOURCE_HSE_DIV17       0x00110300U
#define RCC_RTCCLKSOURCE_HSE_DIV18       0x00120300U
#define RCC_RTCCLKSOURCE_HSE_DIV19       0x00130300U
#define RCC_RTCCLKSOURCE_HSE_DIV20       0x00140300U
#define RCC_RTCCLKSOURCE_HSE_DIV21       0x00150300U
#define RCC_RTCCLKSOURCE_HSE_DIV22       0x00160300U
#define RCC_RTCCLKSOURCE_HSE_DIV23       0x00170300U
#define RCC_RTCCLKSOURCE_HSE_DIV24       0x00180300U
#define RCC_RTCCLKSOURCE_HSE_DIV25       0x00190300U
#define RCC_RTCCLKSOURCE_HSE_DIV26       0x001A0300U
#define RCC_RTCCLKSOURCE_HSE_DIV27       0x001B0300U
#define RCC_RTCCLKSOURCE_HSE_DIV28       0x001C0300U
#define RCC_RTCCLKSOURCE_HSE_DIV29       0x001D0300U
#define RCC_RTCCLKSOURCE_HSE_DIV30       0x001E0300U
#define RCC_RTCCLKSOURCE_HSE_DIV31       0x001F0300U
/**
  * @}
  */

/** @defgroup RCC_MCO_Index MCO Index
  * @{
  */
#define RCC_MCO1                         0x00000000U
#define RCC_MCO2                         0x00000001U
/**
  * @}
  */

/** @defgroup RCC_MCO1_Clock_Source MCO1 Clock Source
  * @{
  */
#define RCC_MCO1SOURCE_HSI               0x00000000U
#define RCC_MCO1SOURCE_LSE               RCC_CFGR_MCO1_0
#define RCC_MCO1SOURCE_HSE               RCC_CFGR_MCO1_1
#define RCC_MCO1SOURCE_PLLCLK            RCC_CFGR_MCO1
/**
  * @}
  */

/** @defgroup RCC_MCOx_Clock_Prescaler MCOx Clock Prescaler
  * @{
  */
#define RCC_MCODIV_1                    0x00000000U
#define RCC_MCODIV_2                    RCC_CFGR_MCO1PRE_2
#define RCC_MCODIV_3                    ((uint32_t)RCC_CFGR_MCO1PRE_0 | RCC_CFGR_MCO1PRE_2)
#define RCC_MCODIV_4                    ((uint32_t)RCC_CFGR_MCO1PRE_1 | RCC_CFGR_MCO1PRE_2)
#define RCC_MCODIV_5                    RCC_CFGR_MCO1PRE
/**
  * @}
  */

/** @defgroup RCC_Interrupt Interrupts
  * @{
  */
#define RCC_IT_LSIRDY                    ((uint8_t)0x01)
#define RCC_IT_LSERDY                    ((uint8_t)0x02)
#define RCC_IT_HSIRDY                    ((uint8_t)0x04)
#define RCC_IT_HSERDY                    ((uint8_t)0x08)
#define RCC_IT_PLLRDY                    ((uint8_t)0x10)
#define RCC_IT_PLLI2SRDY                 ((uint8_t)0x20)
#define RCC_IT_CSS                       ((uint8_t)0x80)
/**
  * @}
  */

/** @defgroup RCC_Flag Flags
  *        Elements values convention: 0XXYYYYYb
  *           - YYYYY  : Flag position in the register
  *           - 0XX  : Register index
  *                 - 01: CR register
  *                 - 10: BDCR register
  *                 - 11: CSR register
  * @{
  */
/* Flags in the CR register */
#define RCC_FLAG_HSIRDY                  ((uint8_t)0x21)
#define RCC_FLAG_HSERDY                  ((uint8_t)0x31)
#define RCC_FLAG_PLLRDY                  ((uint8_t)0x39)
#define RCC_FLAG_PLLI2SRDY               ((uint8_t)0x3B)

/* Flags in the BDCR register */
#define RCC_FLAG_LSERDY                  ((uint8_t)0x41)

/* Flags in the CSR register */
#define RCC_FLAG_LSIRDY                  ((uint8_t)0x61)
#define RCC_FLAG_BORRST                  ((uint8_t)0x79)
#define RCC_FLAG_PINRST                  ((uint8_t)0x7A)
#define RCC_FLAG_PORRST                  ((uint8_t)0x7B)
#define RCC_FLAG_SFTRST                  ((uint8_t)0x7C)
#define RCC_FLAG_IWDGRST                 ((uint8_t)0x7D)
#define RCC_FLAG_WWDGRST                 ((uint8_t)0x7E)
#define RCC_FLAG_LPWRRST                 ((uint8_t)0x7F)
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup RCC_Exported_Macros RCC Exported Macros
  * @{
  */

/** @defgroup RCC_AHB1_Clock_Enable_Disable AHB1 Peripheral Clock Enable Disable
  * @brief  Enable or disable the AHB1 peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */
#define __HAL_RCC_GPIOA_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg = 0x00U; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN);\
                                        UNUSED(tmpreg); \
                                          } while(0U)
#define __HAL_RCC_GPIOB_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg = 0x00U; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN);\
                                        UNUSED(tmpreg); \
                                          } while(0U)
#define __HAL_RCC_GPIOC_CLK_ENABLE()  do { \
                                        __IO uint32_t tmpreg = 0x00U; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN);\
                                        UNUSED(tmpreg); \
                                          } while(0U)
#define __HAL_RCC_GPIOH_CLK_ENABLE()  do { \
                                        __IO uint32_t tmpreg = 0x00U; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOHEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOHEN);\
                                        UNUSED(tmpreg); \
                                         } while(0U)
#define __HAL_RCC_DMA1_CLK_ENABLE()  do { \
                                        __IO uint32_t tmpreg = 0x00U; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA1EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA1EN);\
                                        UNUSED(tmpreg); \
                                         } while(0U)
#define __HAL_RCC_DMA2_CLK_ENABLE()     do { \
                                        __IO uint32_t tmpreg = 0x00U; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA2EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA2EN);\
                                        UNUSED(tmpreg); \
                                          } while(0U)

#define __HAL_RCC_GPIOA_CLK_DISABLE()        (RCC->AHB1ENR &= ~(RCC_AHB1ENR_GPIOAEN))
#define __HAL_RCC_GPIOB_CLK_DISABLE()        (RCC->AHB1ENR &= ~(RCC_AHB1ENR_GPIOBEN))
#define __HAL_RCC_GPIOC_CLK_DISABLE()        (RCC->AHB1ENR &= ~(RCC_AHB1ENR_GPIOCEN))
#define __HAL_RCC_GPIOH_CLK_DISABLE()        (RCC->AHB1ENR &= ~(RCC_AHB1ENR_GPIOHEN))
#define __HAL_RCC_DMA1_CLK_DISABLE()         (RCC->AHB1ENR &= ~(RCC_AHB1ENR_DMA1EN))
#define __HAL_RCC_DMA2_CLK_DISABLE()         (RCC->AHB1ENR &= ~(RCC_AHB1ENR_DMA2EN))
/**
  * @}
  */

/** @defgroup RCC_AHB1_Peripheral_Clock_Enable_Disable_Status AHB1 Peripheral Clock Enable Disable Status
  * @brief  Get the enable or disable status of the AHB1 peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */
#define __HAL_RCC_GPIOA_IS_CLK_ENABLED()        ((RCC->AHB1ENR &(RCC_AHB1ENR_GPIOAEN)) != RESET)
#define __HAL_RCC_GPIOB_IS_CLK_ENABLED()        ((RCC->AHB1ENR &(RCC_AHB1ENR_GPIOBEN)) != RESET)
#define __HAL_RCC_GPIOC_IS_CLK_ENABLED()        ((RCC->AHB1ENR &(RCC_AHB1ENR_GPIOCEN)) != RESET)
#define __HAL_RCC_GPIOH_IS_CLK_ENABLED()        ((RCC->AHB1ENR &(RCC_AHB1ENR_GPIOHEN)) != RESET)
#define __HAL_RCC_DMA1_IS_CLK_ENABLED()         ((RCC->AHB1ENR &(RCC_AHB1ENR_DMA1EN)) != RESET)
#define __HAL_RCC_DMA2_IS_CLK_ENABLED()         ((RCC->AHB1ENR &(RCC_AHB1ENR_DMA2EN)) != RESET)

#define __HAL_RCC_GPIOA_IS_CLK_DISABLED()       ((RCC->AHB1ENR &(RCC_AHB1ENR_GPIOAEN)) == RESET)
#define __HAL_RCC_GPIOB_IS_CLK_DISABLED()       ((RCC->AHB1ENR &(RCC_AHB1ENR_GPIOBEN)) == RESET)
#define __HAL_RCC_GPIOC_IS_CLK_DISABLED()       ((RCC->AHB1ENR &(RCC_AHB1ENR_GPIOCEN)) == RESET)
#define __HAL_RCC_GPIOH_IS_CLK_DISABLED()       ((RCC->AHB1ENR &(RCC_AHB1ENR_GPIOHEN)) == RESET)
#define __HAL_RCC_DMA1_IS_CLK_DISABLED()        ((RCC->AHB1ENR &(RCC_AHB1ENR_DMA1EN)) == RESET)
#define __HAL_RCC_DMA2_IS_CLK_DISABLED()        ((RCC->AHB1ENR &(RCC_AHB1ENR_DMA2EN)) == RESET)
/**
  * @}
  */

/** @defgroup RCC_APB1_Clock_Enable_Disable APB1 Peripheral Clock Enable Disable
  * @brief  Enable or disable the Low Speed APB (APB1) peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */
#define __HAL_RCC_TIM5_CLK_ENABLE()     do { \
                                        __IO uint32_t tmpreg = 0x00U; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM5EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM5EN);\
                                        UNUSED(tmpreg); \
                                          } while(0U)
#define __HAL_RCC_WWDG_CLK_ENABLE()     do { \
                                        __IO uint32_t tmpreg = 0x00U; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_WWDGEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_WWDGEN);\
                                        UNUSED(tmpreg); \
                                          } while(0U)
#define __HAL_RCC_SPI2_CLK_ENABLE()     do { \
                                        __IO uint32_t tmpreg = 0x00U; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2EN);\
                                        UNUSED(tmpreg); \
                                          } while(0U)
#define __HAL_RCC_USART2_CLK_ENABLE()     do { \
                                        __IO uint32_t tmpreg = 0x00U; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_USART2EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_USART2EN);\
                                        UNUSED(tmpreg); \
                                          } while(0U)
#define __HAL_RCC_I2C1_CLK_ENABLE()     do { \
                                        __IO uint32_t tmpreg = 0x00U; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C1EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C1EN);\
                                        UNUSED(tmpreg); \
                                          } while(0U)
#define __HAL_RCC_I2C2_CLK_ENABLE()     do { \
                                        __IO uint32_t tmpreg = 0x00U; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C2EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C2EN);\
                                        UNUSED(tmpreg); \
                                          } while(0U)
#define __HAL_RCC_PWR_CLK_ENABLE()     do { \
                                        __IO uint32_t tmpreg = 0x00U; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_PWREN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_PWREN);\
                                        UNUSED(tmpreg); \
                                          } while(0U)

#define __HAL_RCC_TIM5_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM5EN))
#define __HAL_RCC_WWDG_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_WWDGEN))
#define __HAL_RCC_SPI2_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_SPI2EN))
#define __HAL_RCC_USART2_CLK_DISABLE() (RCC->APB1ENR &= ~(RCC_APB1ENR_USART2EN))
#define __HAL_RCC_I2C1_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_I2C1EN))
#define __HAL_RCC_I2C2_CLK_DISABLE()   (RCC->APB1ENR &= ~(RCC_APB1ENR_I2C2EN))
#define __HAL_RCC_PWR_CLK_DISABLE()    (RCC->APB1ENR &= ~(RCC_APB1ENR_PWREN))
/**
  * @}
  */

/** @defgroup RCC_APB1_Peripheral_Clock_Enable_Disable_Status APB1 Peripheral Clock Enable Disable Status
  * @brief  Get the enable or disable status of the APB1 peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */
#define __HAL_RCC_TIM5_IS_CLK_ENABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_TIM5EN)) != RESET)
#define __HAL_RCC_WWDG_IS_CLK_ENABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_WWDGEN)) != RESET)
#define __HAL_RCC_SPI2_IS_CLK_ENABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_SPI2EN)) != RESET)
#define __HAL_RCC_USART2_IS_CLK_ENABLED() ((RCC->APB1ENR & (RCC_APB1ENR_USART2EN)) != RESET)
#define __HAL_RCC_I2C1_IS_CLK_ENABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_I2C1EN)) != RESET)
#define __HAL_RCC_I2C2_IS_CLK_ENABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_I2C2EN)) != RESET)
#define __HAL_RCC_PWR_IS_CLK_ENABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_PWREN)) != RESET)

#define __HAL_RCC_TIM5_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_TIM5EN)) == RESET)
#define __HAL_RCC_WWDG_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_WWDGEN)) == RESET)
#define __HAL_RCC_SPI2_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_SPI2EN)) == RESET)
#define __HAL_RCC_USART2_IS_CLK_DISABLED() ((RCC->APB1ENR & (RCC_APB1ENR_USART2EN)) == RESET)
#define __HAL_RCC_I2C1_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_I2C1EN)) == RESET)
#define __HAL_RCC_I2C2_IS_CLK_DISABLED()   ((RCC->APB1ENR & (RCC_APB1ENR_I2C2EN)) == RESET)
#define __HAL_RCC_PWR_IS_CLK_DISABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_PWREN)) == RESET)
/**
  * @}
  */

/** @defgroup RCC_APB2_Clock_Enable_Disable APB2 Peripheral Clock Enable Disable
  * @brief  Enable or disable the High Speed APB (APB2) peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */
 #define __HAL_RCC_TIM1_CLK_ENABLE()     do { \
                                         __IO uint32_t tmpreg = 0x00U; \
                                         SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM1EN);\
                                         /* Delay after an RCC peripheral clock enabling */ \
                                         tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM1EN);\
                                         UNUSED(tmpreg); \
                                           } while(0U)
// #define __HAL_RCC_USART1_CLK_ENABLE()   do { \
//                                         __IO uint32_t tmpreg = 0x00U; \
//                                         SET_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN);\
//                                         /* Delay after an RCC peripheral clock enabling */ \
//                                         tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN);\
//                                         UNUSED(tmpreg); \
//                                           } while(0U)
// #define __HAL_RCC_USART6_CLK_ENABLE()   do { \
//                                         __IO uint32_t tmpreg = 0x00U; \
//                                         SET_BIT(RCC->APB2ENR, RCC_APB2ENR_USART6EN);\
//                                         /* Delay after an RCC peripheral clock enabling */ \
//                                         tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_USART6EN);\
//                                         UNUSED(tmpreg); \
//                                           } while(0U)
 #define __HAL_RCC_ADC1_CLK_ENABLE()     do { \
                                         __IO uint32_t tmpreg = 0x00U; \
                                         SET_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC1EN);\
                                         /* Delay after an RCC peripheral clock enabling */ \
                                         tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC1EN);\
                                         UNUSED(tmpreg); \
                                           } while(0U)
// #define __HAL_RCC_SPI1_CLK_ENABLE()     do { \
//                                         __IO uint32_t tmpreg = 0x00U; \
//                                         SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN);\
//                                         /* Delay after an RCC peripheral clock enabling */ \
//                                         tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN);\
//                                         UNUSED(tmpreg); \
//                                           } while(0U)
// #define __HAL_RCC_SYSCFG_CLK_ENABLE()   do { \
//                                         __IO uint32_t tmpreg = 0x00U; \
//                                         SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SYSCFGEN);\
//                                         /* Delay after an RCC peripheral clock enabling */ \
//                                         tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SYSCFGEN);\
//                                         UNUSED(tmpreg); \
//                                           } while(0U)
// #define __HAL_RCC_TIM9_CLK_ENABLE()     do { \
//                                         __IO uint32_t tmpreg = 0x00U; \
//                                         SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM9EN);\
//                                         /* Delay after an RCC peripheral clock enabling */ \
//                                         tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM9EN);\
//                                         UNUSED(tmpreg); \
//                                           } while(0U)
// #define __HAL_RCC_TIM11_CLK_ENABLE()    do { \
//                                         __IO uint32_t tmpreg = 0x00U; \
//                                         SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM11EN);\
//                                         /* Delay after an RCC peripheral clock enabling */ \
//                                         tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM11EN);\
//                                         UNUSED(tmpreg); \
//                                           } while(0U)

//#define __HAL_RCC_TIM1_CLK_ENABLE()     do {  uint32_t tmpreg = 0x00U;\
//                                              UNUSED(tmpreg); \
//                                        } while(0U)
#define __HAL_RCC_USART1_CLK_ENABLE()   do {  uint32_t tmpreg = 0x00U;\
                                              UNUSED(tmpreg); \
                                        } while(0U)

#define __HAL_RCC_USART6_CLK_ENABLE()   do {  uint32_t tmpreg = 0x00U;\
                                              UNUSED(tmpreg); \
                                        } while(0U)

//#define __HAL_RCC_ADC1_CLK_ENABLE()     do {  uint32_t tmpreg = 0x00U;\
//                                              UNUSED(tmpreg); \
//                                        } while(0U)
#define __HAL_RCC_SPI1_CLK_ENABLE()     do {  uint32_t tmpreg = 0x00U;\
                                              UNUSED(tmpreg); \
                                        } while(0U)
#define __HAL_RCC_SYSCFG_CLK_ENABLE()   do {  uint32_t tmpreg = 0x00U;\
                                              UNUSED(tmpreg); \
                                        } while(0U)
#define __HAL_RCC_TIM9_CLK_ENABLE()     do {  uint32_t tmpreg = 0x00U;\
                                              UNUSED(tmpreg); \
                                        } while(0U)
#define __HAL_RCC_TIM11_CLK_ENABLE()   do {  uint32_t tmpreg = 0x00U;\
                                              UNUSED(tmpreg); \
                                        } while(0U)
#define __HAL_RCC_GPIOD_CLK_ENABLE()   do {  uint32_t tmpreg = 0x00U;\
                                              UNUSED(tmpreg); \
                                        } while(0U)
#define __HAL_RCC_GPIOE_CLK_ENABLE()   do {  uint32_t tmpreg = 0x00U;\
                                              UNUSED(tmpreg); \
                                        } while(0U)
#define __HAL_RCC_CRC_CLK_ENABLE()     do {  uint32_t tmpreg = 0x00U;\
                                              UNUSED(tmpreg); \
                                        } while(0U)
                                       
                                       
                                       

#define __HAL_RCC_TIM1_CLK_DISABLE()   (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM1EN))
#define __HAL_RCC_USART1_CLK_DISABLE() (RCC->APB2ENR &= ~(RCC_APB2ENR_USART1EN))
#define __HAL_RCC_USART6_CLK_DISABLE() (RCC->APB2ENR &= ~(RCC_APB2ENR_USART6EN))
#define __HAL_RCC_ADC1_CLK_DISABLE()   (RCC->APB2ENR &= ~(RCC_APB2ENR_ADC1EN))
#define __HAL_RCC_SPI1_CLK_DISABLE()   (RCC->APB2ENR &= ~(RCC_APB2ENR_SPI1EN))
#define __HAL_RCC_SYSCFG_CLK_DISABLE() (RCC->APB2ENR &= ~(RCC_APB2ENR_SYSCFGEN))
#define __HAL_RCC_TIM9_CLK_DISABLE()   (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM9EN))
#define __HAL_RCC_TIM11_CLK_DISABLE()  (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM11EN))
/**
  * @}
  */

/** @defgroup RCC_APB2_Peripheral_Clock_Enable_Disable_Status APB2 Peripheral Clock Enable Disable Status
  * @brief  Get the enable or disable status of the APB2 peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */
#define __HAL_RCC_TIM1_IS_CLK_ENABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_TIM1EN)) != RESET)
#define __HAL_RCC_USART1_IS_CLK_ENABLED() ((RCC->APB2ENR & (RCC_APB2ENR_USART1EN)) != RESET)
#define __HAL_RCC_USART6_IS_CLK_ENABLED() ((RCC->APB2ENR & (RCC_APB2ENR_USART6EN)) != RESET)
#define __HAL_RCC_ADC1_IS_CLK_ENABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_ADC1EN)) != RESET)
#define __HAL_RCC_SPI1_IS_CLK_ENABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_SPI1EN)) != RESET)
#define __HAL_RCC_SYSCFG_IS_CLK_ENABLED() ((RCC->APB2ENR & (RCC_APB2ENR_SYSCFGEN)) != RESET)
#define __HAL_RCC_TIM9_IS_CLK_ENABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_TIM9EN)) != RESET)
#define __HAL_RCC_TIM11_IS_CLK_ENABLED()  ((RCC->APB2ENR & (RCC_APB2ENR_TIM11EN)) != RESET)

#define __HAL_RCC_TIM1_IS_CLK_DISABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_TIM1EN)) == RESET)
#define __HAL_RCC_USART1_IS_CLK_DISABLED() ((RCC->APB2ENR & (RCC_APB2ENR_USART1EN)) == RESET)
#define __HAL_RCC_USART6_IS_CLK_DISABLED() ((RCC->APB2ENR & (RCC_APB2ENR_USART6EN)) == RESET)
#define __HAL_RCC_ADC1_IS_CLK_DISABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_ADC1EN)) == RESET)
#define __HAL_RCC_SPI1_IS_CLK_DISABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_SPI1EN)) == RESET)
#define __HAL_RCC_SYSCFG_IS_CLK_DISABLED() ((RCC->APB2ENR & (RCC_APB2ENR_SYSCFGEN)) == RESET)
#define __HAL_RCC_TIM9_IS_CLK_DISABLED()   ((RCC->APB2ENR & (RCC_APB2ENR_TIM9EN)) == RESET)
#define __HAL_RCC_TIM11_IS_CLK_DISABLED()  ((RCC->APB2ENR & (RCC_APB2ENR_TIM11EN)) == RESET)
/**
  * @}
  */

/** @defgroup RCC_AHB1_Force_Release_Reset AHB1 Force Release Reset
  * @brief  Force or release AHB1 peripheral reset.
  * @{
  */
#define __HAL_RCC_AHB1_FORCE_RESET()    (RCC->AHB1RSTR = 0xFFFFFFFFU)
#define __HAL_RCC_GPIOA_FORCE_RESET()   (RCC->AHB1RSTR |= (RCC_AHB1RSTR_GPIOARST))
#define __HAL_RCC_GPIOB_FORCE_RESET()   (RCC->AHB1RSTR |= (RCC_AHB1RSTR_GPIOBRST))
#define __HAL_RCC_GPIOC_FORCE_RESET()   (RCC->AHB1RSTR |= (RCC_AHB1RSTR_GPIOCRST))
#define __HAL_RCC_GPIOH_FORCE_RESET()   (RCC->AHB1RSTR |= (RCC_AHB1RSTR_GPIOHRST))
#define __HAL_RCC_DMA1_FORCE_RESET()    (RCC->AHB1RSTR |= (RCC_AHB1RSTR_DMA1RST))
#define __HAL_RCC_DMA2_FORCE_RESET()    (RCC->AHB1RSTR |= (RCC_AHB1RSTR_DMA2RST))

#define __HAL_RCC_AHB1_RELEASE_RESET()  (RCC->AHB1RSTR = 0x00U)
#define __HAL_RCC_GPIOA_RELEASE_RESET() (RCC->AHB1RSTR &= ~(RCC_AHB1RSTR_GPIOARST))
#define __HAL_RCC_GPIOB_RELEASE_RESET() (RCC->AHB1RSTR &= ~(RCC_AHB1RSTR_GPIOBRST))
#define __HAL_RCC_GPIOC_RELEASE_RESET() (RCC->AHB1RSTR &= ~(RCC_AHB1RSTR_GPIOCRST))
#define __HAL_RCC_GPIOH_RELEASE_RESET() (RCC->AHB1RSTR &= ~(RCC_AHB1RSTR_GPIOHRST))
#define __HAL_RCC_DMA1_RELEASE_RESET()  (RCC->AHB1RSTR &= ~(RCC_AHB1RSTR_DMA1RST))
#define __HAL_RCC_DMA2_RELEASE_RESET()  (RCC->AHB1RSTR &= ~(RCC_AHB1RSTR_DMA2RST))
/**
  * @}
  */

/** @defgroup RCC_APB1_Force_Release_Reset APB1 Force Release Reset
  * @brief  Force or release APB1 peripheral reset.
  * @{
  */
#define __HAL_RCC_APB1_FORCE_RESET()     (RCC->APB1RSTR = 0xFFFFFFFFU)
#define __HAL_RCC_TIM5_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM5RST))
#define __HAL_RCC_WWDG_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_WWDGRST))
#define __HAL_RCC_SPI2_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_SPI2RST))
#define __HAL_RCC_USART2_FORCE_RESET()   (RCC->APB1RSTR |= (RCC_APB1RSTR_USART2RST))
#define __HAL_RCC_I2C1_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_I2C1RST))
#define __HAL_RCC_I2C2_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_I2C2RST))
#define __HAL_RCC_PWR_FORCE_RESET()      (RCC->APB1RSTR |= (RCC_APB1RSTR_PWRRST))

#define __HAL_RCC_APB1_RELEASE_RESET()   (RCC->APB1RSTR = 0x00U)
#define __HAL_RCC_TIM5_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM5RST))
#define __HAL_RCC_WWDG_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_WWDGRST))
#define __HAL_RCC_SPI2_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_SPI2RST))
#define __HAL_RCC_USART2_RELEASE_RESET() (RCC->APB1RSTR &= ~(RCC_APB1RSTR_USART2RST))
#define __HAL_RCC_I2C1_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_I2C1RST))
#define __HAL_RCC_I2C2_RELEASE_RESET()   (RCC->APB1RSTR &= ~(RCC_APB1RSTR_I2C2RST))
#define __HAL_RCC_PWR_RELEASE_RESET()    (RCC->APB1RSTR &= ~(RCC_APB1RSTR_PWRRST))
/**
  * @}
  */

/** @defgroup RCC_APB2_Force_Release_Reset APB2 Force Release Reset
  * @brief  Force or release APB2 peripheral reset.
  * @{
  */
#define __HAL_RCC_APB2_FORCE_RESET()     (RCC->APB2RSTR = 0xFFFFFFFFU)
#define __HAL_RCC_TIM1_FORCE_RESET()     (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM1RST))
#define __HAL_RCC_USART1_FORCE_RESET()   (RCC->APB2RSTR |= (RCC_APB2RSTR_USART1RST))
#define __HAL_RCC_USART6_FORCE_RESET()   (RCC->APB2RSTR |= (RCC_APB2RSTR_USART6RST))
#define __HAL_RCC_ADC_FORCE_RESET()      (RCC->APB2RSTR |= (RCC_APB2RSTR_ADCRST))
#define __HAL_RCC_SPI1_FORCE_RESET()     (RCC->APB2RSTR |= (RCC_APB2RSTR_SPI1RST))
#define __HAL_RCC_SYSCFG_FORCE_RESET()   (RCC->APB2RSTR |= (RCC_APB2RSTR_SYSCFGRST))
#define __HAL_RCC_TIM9_FORCE_RESET()     (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM9RST))
#define __HAL_RCC_TIM11_FORCE_RESET()    (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM11RST))

#define __HAL_RCC_APB2_RELEASE_RESET()   (RCC->APB2RSTR = 0x00U)
#define __HAL_RCC_TIM1_RELEASE_RESET()   (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM1RST))
#define __HAL_RCC_USART1_RELEASE_RESET() (RCC->APB2RSTR &= ~(RCC_APB2RSTR_USART1RST))
#define __HAL_RCC_USART6_RELEASE_RESET() (RCC->APB2RSTR &= ~(RCC_APB2RSTR_USART6RST))
#define __HAL_RCC_ADC_RELEASE_RESET()    (RCC->APB2RSTR &= ~(RCC_APB2RSTR_ADCRST))
#define __HAL_RCC_SPI1_RELEASE_RESET()   (RCC->APB2RSTR &= ~(RCC_APB2RSTR_SPI1RST))
#define __HAL_RCC_SYSCFG_RELEASE_RESET() (RCC->APB2RSTR &= ~(RCC_APB2RSTR_SYSCFGRST))
#define __HAL_RCC_TIM9_RELEASE_RESET()   (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM9RST))
#define __HAL_RCC_TIM11_RELEASE_RESET()  (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM11RST))
/**
  * @}
  */

/** @defgroup RCC_AHB1_LowPower_Enable_Disable AHB1 Peripheral Low Power Enable Disable
  * @brief  Enable or disable the AHB1 peripheral clock during Low Power (Sleep) mode.
  * @note   Peripheral clock gating in SLEEP mode can be used to further reduce
  *         power consumption.
  * @note   After wake-up from SLEEP mode, the peripheral clock is enabled again.
  * @note   By default, all peripheral clocks are enabled during SLEEP mode.
  * @{
  */
#define __HAL_RCC_GPIOA_CLK_SLEEP_ENABLE()    (RCC->AHB1LPENR |= (RCC_AHB1LPENR_GPIOALPEN))
#define __HAL_RCC_GPIOB_CLK_SLEEP_ENABLE()    (RCC->AHB1LPENR |= (RCC_AHB1LPENR_GPIOBLPEN))
#define __HAL_RCC_GPIOC_CLK_SLEEP_ENABLE()    (RCC->AHB1LPENR |= (RCC_AHB1LPENR_GPIOCLPEN))
#define __HAL_RCC_GPIOH_CLK_SLEEP_ENABLE()    (RCC->AHB1LPENR |= (RCC_AHB1LPENR_GPIOHLPEN))
#define __HAL_RCC_DMA1_CLK_SLEEP_ENABLE()     (RCC->AHB1LPENR |= (RCC_AHB1LPENR_DMA1LPEN))
#define __HAL_RCC_DMA2_CLK_SLEEP_ENABLE()     (RCC->AHB1LPENR |= (RCC_AHB1LPENR_DMA2LPEN))

#define __HAL_RCC_GPIOA_CLK_SLEEP_DISABLE()   (RCC->AHB1LPENR &= ~(RCC_AHB1LPENR_GPIOALPEN))
#define __HAL_RCC_GPIOB_CLK_SLEEP_DISABLE()   (RCC->AHB1LPENR &= ~(RCC_AHB1LPENR_GPIOBLPEN))
#define __HAL_RCC_GPIOC_CLK_SLEEP_DISABLE()   (RCC->AHB1LPENR &= ~(RCC_AHB1LPENR_GPIOCLPEN))
#define __HAL_RCC_GPIOH_CLK_SLEEP_DISABLE()   (RCC->AHB1LPENR &= ~(RCC_AHB1LPENR_GPIOHLPEN))
#define __HAL_RCC_DMA1_CLK_SLEEP_DISABLE()    (RCC->AHB1LPENR &= ~(RCC_AHB1LPENR_DMA1LPEN))
#define __HAL_RCC_DMA2_CLK_SLEEP_DISABLE()    (RCC->AHB1LPENR &= ~(RCC_AHB1LPENR_DMA2LPEN))
/**
  * @}
  */

/** @defgroup RCC_APB1_LowPower_Enable_Disable APB1 Peripheral Low Power Enable Disable
  * @brief  Enable or disable the APB1 peripheral clock during Low Power (Sleep) mode.
  * @note   Peripheral clock gating in SLEEP mode can be used to further reduce
  *         power consumption.
  * @note   After wake-up from SLEEP mode, the peripheral clock is enabled again.
  * @note   By default, all peripheral clocks are enabled during SLEEP mode.
  * @{
  */
#define __HAL_RCC_TIM5_CLK_SLEEP_ENABLE()    (RCC->APB1LPENR |= (RCC_APB1LPENR_TIM5LPEN))
#define __HAL_RCC_WWDG_CLK_SLEEP_ENABLE()    (RCC->APB1LPENR |= (RCC_APB1LPENR_WWDGLPEN))
#define __HAL_RCC_SPI2_CLK_SLEEP_ENABLE()    (RCC->APB1LPENR |= (RCC_APB1LPENR_SPI2LPEN))
#define __HAL_RCC_USART2_CLK_SLEEP_ENABLE()  (RCC->APB1LPENR |= (RCC_APB1LPENR_USART2LPEN))
#define __HAL_RCC_I2C1_CLK_SLEEP_ENABLE()    (RCC->APB1LPENR |= (RCC_APB1LPENR_I2C1LPEN))
#define __HAL_RCC_I2C2_CLK_SLEEP_ENABLE()    (RCC->APB1LPENR |= (RCC_APB1LPENR_I2C2LPEN))
#define __HAL_RCC_PWR_CLK_SLEEP_ENABLE()     (RCC->APB1LPENR |= (RCC_APB1LPENR_PWRLPEN))

#define __HAL_RCC_TIM5_CLK_SLEEP_DISABLE()   (RCC->APB1LPENR &= ~(RCC_APB1LPENR_TIM5LPEN))
#define __HAL_RCC_WWDG_CLK_SLEEP_DISABLE()   (RCC->APB1LPENR &= ~(RCC_APB1LPENR_WWDGLPEN))
#define __HAL_RCC_SPI2_CLK_SLEEP_DISABLE()   (RCC->APB1LPENR &= ~(RCC_APB1LPENR_SPI2LPEN))
#define __HAL_RCC_USART2_CLK_SLEEP_DISABLE() (RCC->APB1LPENR &= ~(RCC_APB1LPENR_USART2LPEN))
#define __HAL_RCC_I2C1_CLK_SLEEP_DISABLE()   (RCC->APB1LPENR &= ~(RCC_APB1LPENR_I2C1LPEN))
#define __HAL_RCC_I2C2_CLK_SLEEP_DISABLE()   (RCC->APB1LPENR &= ~(RCC_APB1LPENR_I2C2LPEN))
#define __HAL_RCC_PWR_CLK_SLEEP_DISABLE()    (RCC->APB1LPENR &= ~(RCC_APB1LPENR_PWRLPEN))
/**
  * @}
  */

/** @defgroup RCC_APB2_LowPower_Enable_Disable APB2 Peripheral Low Power Enable Disable
  * @brief  Enable or disable the APB2 peripheral clock during Low Power (Sleep) mode.
  * @note   Peripheral clock gating in SLEEP mode can be used to further reduce
  *         power consumption.
  * @note   After wake-up from SLEEP mode, the peripheral clock is enabled again.
  * @note   By default, all peripheral clocks are enabled during SLEEP mode.
  * @{
  */
#define __HAL_RCC_TIM1_CLK_SLEEP_ENABLE()    (RCC->APB2LPENR |= (RCC_APB2LPENR_TIM1LPEN))
#define __HAL_RCC_USART1_CLK_SLEEP_ENABLE()  (RCC->APB2LPENR |= (RCC_APB2LPENR_USART1LPEN))
#define __HAL_RCC_USART6_CLK_SLEEP_ENABLE()  (RCC->APB2LPENR |= (RCC_APB2LPENR_USART6LPEN))
#define __HAL_RCC_ADC1_CLK_SLEEP_ENABLE()    (RCC->APB2LPENR |= (RCC_APB2LPENR_ADC1LPEN))
#define __HAL_RCC_SPI1_CLK_SLEEP_ENABLE()    (RCC->APB2LPENR |= (RCC_APB2LPENR_SPI1LPEN))
#define __HAL_RCC_SYSCFG_CLK_SLEEP_ENABLE()  (RCC->APB2LPENR |= (RCC_APB2LPENR_SYSCFGLPEN))
#define __HAL_RCC_TIM9_CLK_SLEEP_ENABLE()    (RCC->APB2LPENR |= (RCC_APB2LPENR_TIM9LPEN))
#define __HAL_RCC_TIM11_CLK_SLEEP_ENABLE()   (RCC->APB2LPENR |= (RCC_APB2LPENR_TIM11LPEN))

#define __HAL_RCC_TIM1_CLK_SLEEP_DISABLE()   (RCC->APB2LPENR &= ~(RCC_APB2LPENR_TIM1LPEN))
#define __HAL_RCC_USART1_CLK_SLEEP_DISABLE() (RCC->APB2LPENR &= ~(RCC_APB2LPENR_USART1LPEN))
#define __HAL_RCC_USART6_CLK_SLEEP_DISABLE() (RCC->APB2LPENR &= ~(RCC_APB2LPENR_USART6LPEN))
#define __HAL_RCC_ADC1_CLK_SLEEP_DISABLE()   (RCC->APB2LPENR &= ~(RCC_APB2LPENR_ADC1LPEN))
#define __HAL_RCC_SPI1_CLK_SLEEP_DISABLE()   (RCC->APB2LPENR &= ~(RCC_APB2LPENR_SPI1LPEN))
#define __HAL_RCC_SYSCFG_CLK_SLEEP_DISABLE() (RCC->APB2LPENR &= ~(RCC_APB2LPENR_SYSCFGLPEN))
#define __HAL_RCC_TIM9_CLK_SLEEP_DISABLE()   (RCC->APB2LPENR &= ~(RCC_APB2LPENR_TIM9LPEN))
#define __HAL_RCC_TIM11_CLK_SLEEP_DISABLE()  (RCC->APB2LPENR &= ~(RCC_APB2LPENR_TIM11LPEN))
/**
  * @}
  */

/** @defgroup RCC_HSI_Configuration HSI Configuration
  * @{
  */

/** @brief  Macros to enable or disable the Internal High Speed oscillator (HSI).
  * @note   The HSI is stopped by hardware when entering STOP and STANDBY modes.
  *         It is used (enabled by hardware) as system clock source after startup
  *         from Reset, wake-up from STOP and STANDBY mode, or in case of failure
  *         of the HSE used directly or indirectly as system clock (if the Clock
  *         Security System CSS is enabled).
  * @note   HSI can not be stopped if it is used as system clock source. In this case,
  *         you have to select another source of the system clock then stop the HSI.
  * @note   After enabling the HSI, the application software should wait on HSIRDY
  *         flag to be set indicating that HSI clock is stable and can be used as
  *         system clock source.
  *         This parameter can be: ENABLE or DISABLE.
  * @note   When the HSI is stopped, HSIRDY flag goes low after 6 HSI oscillator
  *         clock cycles.
  */
#define __HAL_RCC_HSI_ENABLE() (*(__IO uint32_t *) RCC_CR_HSION_BB = ENABLE)
#define __HAL_RCC_HSI_DISABLE() (*(__IO uint32_t *) RCC_CR_HSION_BB = DISABLE)

/** @brief  Macro to adjust the Internal High Speed oscillator (HSI) calibration value.
  * @note   The calibration is used to compensate for the variations in voltage
  *         and temperature that influence the frequency of the internal HSI RC.
  * @param  __HSICalibrationValue__ specifies the calibration trimming value.
  *         (default is RCC_HSICALIBRATION_DEFAULT).
  *         This parameter must be a number between 0 and 0x1F.
  */
#define __HAL_RCC_HSI_CALIBRATIONVALUE_ADJUST(__HSICalibrationValue__) (MODIFY_REG(RCC->CR,\
        RCC_CR_HSITRIM, (uint32_t)(__HSICalibrationValue__) << RCC_CR_HSITRIM_Pos))
/**
  * @}
  */

/** @defgroup RCC_LSI_Configuration LSI Configuration
  * @{
  */

/** @brief  Macros to enable or disable the Internal Low Speed oscillator (LSI).
  * @note   After enabling the LSI, the application software should wait on
  *         LSIRDY flag to be set indicating that LSI clock is stable and can
  *         be used to clock the IWDG and/or the RTC.
  * @note   LSI can not be disabled if the IWDG is running.
  * @note   When the LSI is stopped, LSIRDY flag goes low after 6 LSI oscillator
  *         clock cycles.
  */
#define __HAL_RCC_LSI_ENABLE() (*(__IO uint32_t *) RCC_CSR_LSION_BB = ENABLE)
#define __HAL_RCC_LSI_DISABLE() (*(__IO uint32_t *) RCC_CSR_LSION_BB = DISABLE)
/**
  * @}
  */

/** @defgroup RCC_HSE_Configuration HSE Configuration
  * @{
  */

/**
  * @brief  Macro to configure the External High Speed oscillator (HSE).
  * @note   Transition HSE Bypass to HSE On and HSE On to HSE Bypass are not supported by this macro.
  *         User should request a transition to HSE Off first and then HSE On or HSE Bypass.
  * @note   After enabling the HSE (RCC_HSE_ON or RCC_HSE_Bypass), the application
  *         software should wait on HSERDY flag to be set indicating that HSE clock
  *         is stable and can be used to clock the PLL and/or system clock.
  * @note   HSE state can not be changed if it is used directly or through the
  *         PLL as system clock. In this case, you have to select another source
  *         of the system clock then change the HSE state (ex. disable it).
  * @note   The HSE is stopped by hardware when entering STOP and STANDBY modes.
  * @note   This function reset the CSSON bit, so if the clock security system(CSS)
  *         was previously enabled you have to enable it again after calling this
  *         function.
  * @param  __STATE__ specifies the new state of the HSE.
  *         This parameter can be one of the following values:
  *            @arg RCC_HSE_OFF: turn OFF the HSE oscillator, HSERDY flag goes low after
  *                              6 HSE oscillator clock cycles.
  *            @arg RCC_HSE_ON: turn ON the HSE oscillator.
  *            @arg RCC_HSE_BYPASS: HSE oscillator bypassed with external clock.
  */
#define __HAL_RCC_HSE_CONFIG(__STATE__)                         \
                    do {                                        \
                      if ((__STATE__) == RCC_HSE_ON)            \
                      {                                         \
                        SET_BIT(RCC->CR, RCC_CR_HSEON);         \
                      }                                         \
                      else if ((__STATE__) == RCC_HSE_BYPASS)   \
                      {                                         \
                        SET_BIT(RCC->CR, RCC_CR_HSEBYP);        \
                        SET_BIT(RCC->CR, RCC_CR_HSEON);         \
                      }                                         \
                      else                                      \
                      {                                         \
                        CLEAR_BIT(RCC->CR, RCC_CR_HSEON);       \
                        CLEAR_BIT(RCC->CR, RCC_CR_HSEBYP);      \
                      }                                         \
                    } while(0U)
/**
  * @}
  */

/** @defgroup RCC_LSE_Configuration LSE Configuration
  * @{
  */

/**
  * @brief  Macro to configure the External Low Speed oscillator (LSE).
  * @note   Transition LSE Bypass to LSE On and LSE On to LSE Bypass are not supported by this macro.
  *         User should request a transition to LSE Off first and then LSE On or LSE Bypass.
  * @note   As the LSE is in the Backup domain and write access is denied to
  *         this domain after reset, you have to enable write access using
  *         HAL_PWR_EnableBkUpAccess() function before to configure the LSE
  *         (to be done once after reset).
  * @note   After enabling the LSE (RCC_LSE_ON or RCC_LSE_BYPASS), the application
  *         software should wait on LSERDY flag to be set indicating that LSE clock
  *         is stable and can be used to clock the RTC.
  * @param  __STATE__ specifies the new state of the LSE.
  *         This parameter can be one of the following values:
  *            @arg RCC_LSE_OFF: turn OFF the LSE oscillator, LSERDY flag goes low after
  *                              6 LSE oscillator clock cycles.
  *            @arg RCC_LSE_ON: turn ON the LSE oscillator.
  *            @arg RCC_LSE_BYPASS: LSE oscillator bypassed with external clock.
  */
#define __HAL_RCC_LSE_CONFIG(__STATE__) \
                    do {                                       \
                      if((__STATE__) == RCC_LSE_ON)            \
                      {                                        \
                        SET_BIT(RCC->BDCR, RCC_BDCR_LSEON);    \
                      }                                        \
                      else if((__STATE__) == RCC_LSE_BYPASS)   \
                      {                                        \
                        SET_BIT(RCC->BDCR, RCC_BDCR_LSEBYP);   \
                        SET_BIT(RCC->BDCR, RCC_BDCR_LSEON);    \
                      }                                        \
                      else                                     \
                      {                                        \
                        CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEON);  \
                        CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEBYP); \
                      }                                        \
                    } while(0U)
/**
  * @}
  */

/** @defgroup RCC_Internal_RTC_Clock_Configuration RTC Clock Configuration
  * @{
  */

/** @brief  Macros to enable or disable the RTC clock.
  * @note   These macros must be used only after the RTC clock source was selected.
  */
#define __HAL_RCC_RTC_ENABLE() (*(__IO uint32_t *) RCC_BDCR_RTCEN_BB = ENABLE)
#define __HAL_RCC_RTC_DISABLE() (*(__IO uint32_t *) RCC_BDCR_RTCEN_BB = DISABLE)

/** @brief  Macros to configure the RTC clock (RTCCLK).
  * @note   As the RTC clock configuration bits are in the Backup domain and write
  *         access is denied to this domain after reset, you have to enable write
  *         access using the Power Backup Access macro before to configure
  *         the RTC clock source (to be done once after reset).
  * @note   Once the RTC clock is configured it can't be changed unless the
  *         Backup domain is reset using __HAL_RCC_BackupReset_RELEASE() macro, or by
  *         a Power On Reset (POR).
  * @param  __RTCCLKSource__ specifies the RTC clock source.
  *         This parameter can be one of the following values:
               @arg @ref RCC_RTCCLKSOURCE_NO_CLK: No clock selected as RTC clock.
  *            @arg @ref RCC_RTCCLKSOURCE_LSE: LSE selected as RTC clock.
  *            @arg @ref RCC_RTCCLKSOURCE_LSI: LSI selected as RTC clock.
  *            @arg @ref RCC_RTCCLKSOURCE_HSE_DIVX: HSE clock divided by x selected
  *                                                 as RTC clock, where x:[2,31]
  * @note   If the LSE or LSI is used as RTC clock source, the RTC continues to
  *         work in STOP and STANDBY modes, and can be used as wake-up source.
  *         However, when the HSE clock is used as RTC clock source, the RTC
  *         cannot be used in STOP and STANDBY modes.
  * @note   The maximum input clock frequency for RTC is 1MHz (when using HSE as
  *         RTC clock source).
  */
#define __HAL_RCC_RTC_CLKPRESCALER(__RTCCLKSource__) (((__RTCCLKSource__) & RCC_BDCR_RTCSEL) == RCC_BDCR_RTCSEL) ?    \
                                                 MODIFY_REG(RCC->CFGR, RCC_CFGR_RTCPRE, ((__RTCCLKSource__) & 0xFFFFCFFU)) : CLEAR_BIT(RCC->CFGR, RCC_CFGR_RTCPRE)

#define __HAL_RCC_RTC_CONFIG(__RTCCLKSource__) do { __HAL_RCC_RTC_CLKPRESCALER(__RTCCLKSource__);    \
                                                    RCC->BDCR |= ((__RTCCLKSource__) & 0x00000FFFU);  \
                                                   } while(0U)

/** @brief Macro to get the RTC clock source.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_RTCCLKSOURCE_NO_CLK No clock selected as RTC clock
  *            @arg @ref RCC_RTCCLKSOURCE_LSE LSE selected as RTC clock
  *            @arg @ref RCC_RTCCLKSOURCE_LSI LSI selected as RTC clock
  *            @arg @ref RCC_RTCCLKSOURCE_HSE_DIVX HSE divided by X selected as RTC clock (X can be retrieved thanks to @ref __HAL_RCC_GET_RTC_HSE_PRESCALER()
  */
#define __HAL_RCC_GET_RTC_SOURCE() (READ_BIT(RCC->BDCR, RCC_BDCR_RTCSEL))

/**
  * @brief   Get the RTC and HSE clock divider (RTCPRE).
  * @retval Returned value can be one of the following values:
  *            @arg @ref RCC_RTCCLKSOURCE_HSE_DIVX: HSE clock divided by x selected
  *                                                 as RTC clock, where x:[2,31]
  */
#define  __HAL_RCC_GET_RTC_HSE_PRESCALER() (READ_BIT(RCC->CFGR, RCC_CFGR_RTCPRE) | RCC_BDCR_RTCSEL)

/** @brief  Macros to force or release the Backup domain reset.
  * @note   This function resets the RTC peripheral (including the backup registers)
  *         and the RTC clock source selection in RCC_CSR register.
  * @note   The BKPSRAM is not affected by this reset.
  */
#define __HAL_RCC_BACKUPRESET_FORCE() (*(__IO uint32_t *) RCC_BDCR_BDRST_BB = ENABLE)
#define __HAL_RCC_BACKUPRESET_RELEASE() (*(__IO uint32_t *) RCC_BDCR_BDRST_BB = DISABLE)
/**
  * @}
  */

/** @defgroup RCC_PLL_Configuration PLL Configuration
  * @{
  */

/** @brief  Macros to enable or disable the main PLL.
  * @note   After enabling the main PLL, the application software should wait on
  *         PLLRDY flag to be set indicating that PLL clock is stable and can
  *         be used as system clock source.
  * @note   The main PLL can not be disabled if it is used as system clock source
  * @note   The main PLL is disabled by hardware when entering STOP and STANDBY modes.
  */
#define __HAL_RCC_PLL_ENABLE() (*(__IO uint32_t *) RCC_CR_PLLON_BB = ENABLE)
#define __HAL_RCC_PLL_DISABLE() (*(__IO uint32_t *) RCC_CR_PLLON_BB = DISABLE)

/** @brief  Macro to configure the PLL clock source.
  * @note   This function must be used only when the main PLL is disabled.
  * @param  __PLLSOURCE__ specifies the PLL entry clock source.
  *         This parameter can be one of the following values:
  *            @arg RCC_PLLSOURCE_HSI: HSI oscillator clock selected as PLL clock entry
  *            @arg RCC_PLLSOURCE_HSE: HSE oscillator clock selected as PLL clock entry
  *
  */
#define __HAL_RCC_PLL_PLLSOURCE_CONFIG(__PLLSOURCE__) MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC, (__PLLSOURCE__))

/** @brief  Macro to configure the PLL multiplication factor.
  * @note   This function must be used only when the main PLL is disabled.
  * @param  __PLLM__ specifies the division factor for PLL VCO input clock
  *         This parameter must be a number between Min_Data = 2 and Max_Data = 63.
  * @note   You have to set the PLLM parameter correctly to ensure that the VCO input
  *         frequency ranges from 1 to 2 MHz. It is recommended to select a frequency
  *         of 2 MHz to limit PLL jitter.
  *
  */
#define __HAL_RCC_PLL_PLLM_CONFIG(__PLLM__) MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLM, (__PLLM__))
/**
  * @}
  */

/** @defgroup RCC_Get_Clock_source Get Clock source
  * @{
  */
/**
  * @brief Macro to configure the system clock source.
  * @param __RCC_SYSCLKSOURCE__ specifies the system clock source.
  * This parameter can be one of the following values:
  *              - RCC_SYSCLKSOURCE_HSI: HSI oscillator is used as system clock source.
  *              - RCC_SYSCLKSOURCE_HSE: HSE oscillator is used as system clock source.
  *              - RCC_SYSCLKSOURCE_PLLCLK: PLL output is used as system clock source.
  *              - RCC_SYSCLKSOURCE_PLLRCLK: PLLR output is used as system clock source. This
  *                parameter is available only for STM32F446xx devices.
  */
#define __HAL_RCC_SYSCLK_CONFIG(__RCC_SYSCLKSOURCE__) MODIFY_REG(RCC->CFGR, RCC_CFGR_SW, (__RCC_SYSCLKSOURCE__))

/** @brief  Macro to get the clock source used as system clock.
  * @retval The clock source used as system clock. The returned value can be one
  *         of the following:
  *              - RCC_SYSCLKSOURCE_STATUS_HSI: HSI used as system clock.
  *              - RCC_SYSCLKSOURCE_STATUS_HSE: HSE used as system clock.
  *              - RCC_SYSCLKSOURCE_STATUS_PLLCLK: PLL used as system clock.
  *              - RCC_SYSCLKSOURCE_STATUS_PLLRCLK: PLLR used as system clock. This parameter
  *                is available only for STM32F446xx devices.
  */
#define __HAL_RCC_GET_SYSCLK_SOURCE() (RCC->CFGR & RCC_CFGR_SWS)

/** @brief  Macro to get the oscillator used as PLL clock source.
  * @retval The oscillator used as PLL clock source. The returned value can be one
  *         of the following:
  *              - RCC_PLLSOURCE_HSI: HSI oscillator is used as PLL clock source.
  *              - RCC_PLLSOURCE_HSE: HSE oscillator is used as PLL clock source.
  */
#define __HAL_RCC_GET_PLL_OSCSOURCE() ((uint32_t)(RCC->PLLCFGR & RCC_PLLCFGR_PLLSRC))
/**
  * @}
  */

/** @defgroup RCCEx_MCOx_Clock_Config RCC Extended MCOx Clock Config
  * @{
  */

/** @brief  Macro to configure the MCO1 clock.
  * @param  __MCOCLKSOURCE__ specifies the MCO clock source.
  *          This parameter can be one of the following values:
  *            @arg RCC_MCO1SOURCE_HSI: HSI clock selected as MCO1 source
  *            @arg RCC_MCO1SOURCE_LSE: LSE clock selected as MCO1 source
  *            @arg RCC_MCO1SOURCE_HSE: HSE clock selected as MCO1 source
  *            @arg RCC_MCO1SOURCE_PLLCLK: main PLL clock selected as MCO1 source
  * @param  __MCODIV__ specifies the MCO clock prescaler.
  *          This parameter can be one of the following values:
  *            @arg RCC_MCODIV_1: no division applied to MCOx clock
  *            @arg RCC_MCODIV_2: division by 2 applied to MCOx clock
  *            @arg RCC_MCODIV_3: division by 3 applied to MCOx clock
  *            @arg RCC_MCODIV_4: division by 4 applied to MCOx clock
  *            @arg RCC_MCODIV_5: division by 5 applied to MCOx clock
  */
#define __HAL_RCC_MCO1_CONFIG(__MCOCLKSOURCE__, __MCODIV__) \
                 MODIFY_REG(RCC->CFGR, (RCC_CFGR_MCO1 | RCC_CFGR_MCO1PRE), ((__MCOCLKSOURCE__) | (__MCODIV__)))

/** @brief  Macro to configure the MCO2 clock.
  * @param  __MCOCLKSOURCE__ specifies the MCO clock source.
  *          This parameter can be one of the following values:
  *            @arg RCC_MCO2SOURCE_SYSCLK: System clock (SYSCLK) selected as MCO2 source
  *            @arg RCC_MCO2SOURCE_PLLI2SCLK: PLLI2S clock selected as MCO2 source, available for all STM32F4 devices except STM32F410xx
  *            @arg RCC_MCO2SOURCE_I2SCLK: I2SCLK clock selected as MCO2 source, available only for STM32F410Rx devices
  *            @arg RCC_MCO2SOURCE_HSE: HSE clock selected as MCO2 source
  *            @arg RCC_MCO2SOURCE_PLLCLK: main PLL clock selected as MCO2 source
  * @param  __MCODIV__ specifies the MCO clock prescaler.
  *          This parameter can be one of the following values:
  *            @arg RCC_MCODIV_1: no division applied to MCOx clock
  *            @arg RCC_MCODIV_2: division by 2 applied to MCOx clock
  *            @arg RCC_MCODIV_3: division by 3 applied to MCOx clock
  *            @arg RCC_MCODIV_4: division by 4 applied to MCOx clock
  *            @arg RCC_MCODIV_5: division by 5 applied to MCOx clock
  * @note  For STM32F410Rx devices, to output I2SCLK clock on MCO2, you should have
  *        at least one of the SPI clocks enabled (SPI1, SPI2 or SPI5).
  */
#define __HAL_RCC_MCO2_CONFIG(__MCOCLKSOURCE__, __MCODIV__) \
    MODIFY_REG(RCC->CFGR, (RCC_CFGR_MCO2 | RCC_CFGR_MCO2PRE), ((__MCOCLKSOURCE__) | ((__MCODIV__) << 3U)));
/**
  * @}
  */

/** @defgroup RCC_Flags_Interrupts_Management Flags Interrupts Management
  * @brief macros to manage the specified RCC Flags and interrupts.
  * @{
  */

/** @brief  Enable RCC interrupt (Perform Byte access to RCC_CIR[14:8] bits to enable
  *         the selected interrupts).
  * @param  __INTERRUPT__ specifies the RCC interrupt sources to be enabled.
  *         This parameter can be any combination of the following values:
  *            @arg RCC_IT_LSIRDY: LSI ready interrupt.
  *            @arg RCC_IT_LSERDY: LSE ready interrupt.
  *            @arg RCC_IT_HSIRDY: HSI ready interrupt.
  *            @arg RCC_IT_HSERDY: HSE ready interrupt.
  *            @arg RCC_IT_PLLRDY: Main PLL ready interrupt.
  *            @arg RCC_IT_PLLI2SRDY: PLLI2S ready interrupt.
  */
#define __HAL_RCC_ENABLE_IT(__INTERRUPT__) (*(__IO uint8_t *) RCC_CIR_BYTE1_ADDRESS |= (__INTERRUPT__))

/** @brief Disable RCC interrupt (Perform Byte access to RCC_CIR[14:8] bits to disable
  *        the selected interrupts).
  * @param  __INTERRUPT__ specifies the RCC interrupt sources to be disabled.
  *         This parameter can be any combination of the following values:
  *            @arg RCC_IT_LSIRDY: LSI ready interrupt.
  *            @arg RCC_IT_LSERDY: LSE ready interrupt.
  *            @arg RCC_IT_HSIRDY: HSI ready interrupt.
  *            @arg RCC_IT_HSERDY: HSE ready interrupt.
  *            @arg RCC_IT_PLLRDY: Main PLL ready interrupt.
  *            @arg RCC_IT_PLLI2SRDY: PLLI2S ready interrupt.
  */
#define __HAL_RCC_DISABLE_IT(__INTERRUPT__) (*(__IO uint8_t *) RCC_CIR_BYTE1_ADDRESS &= (uint8_t)(~(__INTERRUPT__)))

/** @brief  Clear the RCC's interrupt pending bits (Perform Byte access to RCC_CIR[23:16]
  *         bits to clear the selected interrupt pending bits.
  * @param  __INTERRUPT__ specifies the interrupt pending bit to clear.
  *         This parameter can be any combination of the following values:
  *            @arg RCC_IT_LSIRDY: LSI ready interrupt.
  *            @arg RCC_IT_LSERDY: LSE ready interrupt.
  *            @arg RCC_IT_HSIRDY: HSI ready interrupt.
  *            @arg RCC_IT_HSERDY: HSE ready interrupt.
  *            @arg RCC_IT_PLLRDY: Main PLL ready interrupt.
  *            @arg RCC_IT_PLLI2SRDY: PLLI2S ready interrupt.
  *            @arg RCC_IT_CSS: Clock Security System interrupt
  */
#define __HAL_RCC_CLEAR_IT(__INTERRUPT__) (*(__IO uint8_t *) RCC_CIR_BYTE2_ADDRESS = (__INTERRUPT__))

/** @brief  Check the RCC's interrupt has occurred or not.
  * @param  __INTERRUPT__ specifies the RCC interrupt source to check.
  *         This parameter can be one of the following values:
  *            @arg RCC_IT_LSIRDY: LSI ready interrupt.
  *            @arg RCC_IT_LSERDY: LSE ready interrupt.
  *            @arg RCC_IT_HSIRDY: HSI ready interrupt.
  *            @arg RCC_IT_HSERDY: HSE ready interrupt.
  *            @arg RCC_IT_PLLRDY: Main PLL ready interrupt.
  *            @arg RCC_IT_PLLI2SRDY: PLLI2S ready interrupt.
  *            @arg RCC_IT_CSS: Clock Security System interrupt
  * @retval The new state of __INTERRUPT__ (TRUE or FALSE).
  */
#define __HAL_RCC_GET_IT(__INTERRUPT__) ((RCC->CIR & (__INTERRUPT__)) == (__INTERRUPT__))

/** @brief Set RMVF bit to clear the reset flags: RCC_FLAG_PINRST, RCC_FLAG_PORRST,
  *        RCC_FLAG_SFTRST, RCC_FLAG_IWDGRST, RCC_FLAG_WWDGRST and RCC_FLAG_LPWRRST.
  */
#define __HAL_RCC_CLEAR_RESET_FLAGS() (RCC->CSR |= RCC_CSR_RMVF)

/** @brief  Check RCC flag is set or not.
  * @param  __FLAG__ specifies the flag to check.
  *         This parameter can be one of the following values:
  *            @arg RCC_FLAG_HSIRDY: HSI oscillator clock ready.
  *            @arg RCC_FLAG_HSERDY: HSE oscillator clock ready.
  *            @arg RCC_FLAG_PLLRDY: Main PLL clock ready.
  *            @arg RCC_FLAG_PLLI2SRDY: PLLI2S clock ready.
  *            @arg RCC_FLAG_LSERDY: LSE oscillator clock ready.
  *            @arg RCC_FLAG_LSIRDY: LSI oscillator clock ready.
  *            @arg RCC_FLAG_BORRST: POR/PDR or BOR reset.
  *            @arg RCC_FLAG_PINRST: Pin reset.
  *            @arg RCC_FLAG_PORRST: POR/PDR reset.
  *            @arg RCC_FLAG_SFTRST: Software reset.
  *            @arg RCC_FLAG_IWDGRST: Independent Watchdog reset.
  *            @arg RCC_FLAG_WWDGRST: Window Watchdog reset.
  *            @arg RCC_FLAG_LPWRRST: Low Power reset.
  * @retval The new state of __FLAG__ (TRUE or FALSE).
  */
#define RCC_FLAG_MASK  ((uint8_t)0x1FU)
#define __HAL_RCC_GET_FLAG(__FLAG__) (((((((__FLAG__) >> 5U) == 1U)? RCC->CR :((((__FLAG__) >> 5U) == 2U) ? RCC->BDCR :((((__FLAG__) >> 5U) == 3U)? RCC->CSR :RCC->CIR))) & (1U << ((__FLAG__) & RCC_FLAG_MASK)))!= 0U)? 1U : 0U)

/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
 /** @addtogroup RCC_Exported_Functions
  * @{
  */

/** @addtogroup RCC_Exported_Functions_Group1
  * @{
  */
/* Initialization and de-initialization functions  ******************************/
HAL_StatusTypeDef HAL_RCC_DeInit(void);
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef *RCC_OscInitStruct);
HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef *RCC_ClkInitStruct, uint32_t FLatency);
/**
  * @}
  */

/** @addtogroup RCC_Exported_Functions_Group2
  * @{
  */
/* Peripheral Control functions  ************************************************/
// void     HAL_RCC_MCOConfig(uint32_t RCC_MCOx, uint32_t RCC_MCOSource, uint32_t RCC_MCODiv);
// void     HAL_RCC_EnableCSS(void);
// void     HAL_RCC_DisableCSS(void);
// uint32_t HAL_RCC_GetSysClockFreq(void);
// uint32_t HAL_RCC_GetHCLKFreq(void);
// uint32_t HAL_RCC_GetPCLK1Freq(void);
// uint32_t HAL_RCC_GetPCLK2Freq(void);
// void     HAL_RCC_GetOscConfig(RCC_OscInitTypeDef *RCC_OscInitStruct);
// void     HAL_RCC_GetClockConfig(RCC_ClkInitTypeDef *RCC_ClkInitStruct, uint32_t *pFLatency);
// 
// /* CSS NMI IRQ handler */
// void HAL_RCC_NMI_IRQHandler(void);
// 
// /* User Callbacks in non blocking mode (IT mode) */
// void HAL_RCC_CSSCallback(void);

/**
  * @}
  */

/**
  * @}
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/** @defgroup RCC_Private_Constants RCC Private Constants
  * @{
  */

/** @defgroup RCC_BitAddress_AliasRegion RCC BitAddress AliasRegion
  * @brief RCC registers bit address in the alias region
  * @{
  */
#define RCC_OFFSET                 (RCC_BASE - PERIPH_BASE)
/* --- CR Register --- */
/* Alias word address of HSION bit */
#define RCC_CR_OFFSET              (RCC_OFFSET + 0x00U)
#define RCC_HSION_BIT_NUMBER       0x00U
#define RCC_CR_HSION_BB            (PERIPH_BB_BASE + (RCC_CR_OFFSET * 32U) + (RCC_HSION_BIT_NUMBER * 4U))
/* Alias word address of CSSON bit */
#define RCC_CSSON_BIT_NUMBER       0x13U
#define RCC_CR_CSSON_BB            (PERIPH_BB_BASE + (RCC_CR_OFFSET * 32U) + (RCC_CSSON_BIT_NUMBER * 4U))
/* Alias word address of PLLON bit */
#define RCC_PLLON_BIT_NUMBER       0x18U
#define RCC_CR_PLLON_BB            (PERIPH_BB_BASE + (RCC_CR_OFFSET * 32U) + (RCC_PLLON_BIT_NUMBER * 4U))

/* --- BDCR Register --- */
/* Alias word address of RTCEN bit */
#define RCC_BDCR_OFFSET            (RCC_OFFSET + 0x70U)
#define RCC_RTCEN_BIT_NUMBER       0x0FU
#define RCC_BDCR_RTCEN_BB          (PERIPH_BB_BASE + (RCC_BDCR_OFFSET * 32U) + (RCC_RTCEN_BIT_NUMBER * 4U))
/* Alias word address of BDRST bit */
#define RCC_BDRST_BIT_NUMBER       0x10U
#define RCC_BDCR_BDRST_BB          (PERIPH_BB_BASE + (RCC_BDCR_OFFSET * 32U) + (RCC_BDRST_BIT_NUMBER * 4U))

/* --- CSR Register --- */
/* Alias word address of LSION bit */
#define RCC_CSR_OFFSET             (RCC_OFFSET + 0x74U)
#define RCC_LSION_BIT_NUMBER        0x00U
#define RCC_CSR_LSION_BB           (PERIPH_BB_BASE + (RCC_CSR_OFFSET * 32U) + (RCC_LSION_BIT_NUMBER * 4U))

/* CR register byte 3 (Bits[23:16]) base address */
#define RCC_CR_BYTE2_ADDRESS       0x40023802U

/* CIR register byte 2 (Bits[15:8]) base address */
#define RCC_CIR_BYTE1_ADDRESS      ((uint32_t)(RCC_BASE + 0x0CU + 0x01U))

/* CIR register byte 3 (Bits[23:16]) base address */
#define RCC_CIR_BYTE2_ADDRESS      ((uint32_t)(RCC_BASE + 0x0CU + 0x02U))

/* BDCR register base address */
#define RCC_BDCR_BYTE0_ADDRESS     (PERIPH_BASE + RCC_BDCR_OFFSET)

#define RCC_DBP_TIMEOUT_VALUE      2U
#define RCC_LSE_TIMEOUT_VALUE      LSE_STARTUP_TIMEOUT

#define HSE_TIMEOUT_VALUE          HSE_STARTUP_TIMEOUT
#define HSI_TIMEOUT_VALUE          2U  /* 2 ms */
#define LSI_TIMEOUT_VALUE          2U  /* 2 ms */
#define CLOCKSWITCH_TIMEOUT_VALUE  5000U /* 5 s */

/**
  * @}
  */

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup RCC_Private_Macros RCC Private Macros
  * @{
  */

/** @defgroup RCC_IS_RCC_Definitions RCC Private macros to check input parameters
  * @{
  */
#define IS_RCC_OSCILLATORTYPE(OSCILLATOR) ((OSCILLATOR) <= 15U)

#define IS_RCC_HSE(HSE) (((HSE) == RCC_HSE_OFF) || ((HSE) == RCC_HSE_ON) || \
                         ((HSE) == RCC_HSE_BYPASS))

#define IS_RCC_LSE(LSE) (((LSE) == RCC_LSE_OFF) || ((LSE) == RCC_LSE_ON) || \
                         ((LSE) == RCC_LSE_BYPASS))

#define IS_RCC_HSI(HSI) (((HSI) == RCC_HSI_OFF) || ((HSI) == RCC_HSI_ON))

#define IS_RCC_LSI(LSI) (((LSI) == RCC_LSI_OFF) || ((LSI) == RCC_LSI_ON))

#define IS_RCC_PLL(PLL) (((PLL) == RCC_PLL_NONE) ||((PLL) == RCC_PLL_OFF) || ((PLL) == RCC_PLL_ON))

#define IS_RCC_PLLSOURCE(SOURCE) (((SOURCE) == RCC_PLLSOURCE_HSI) || \
                                  ((SOURCE) == RCC_PLLSOURCE_HSE))

#define IS_RCC_SYSCLKSOURCE(SOURCE) (((SOURCE) == RCC_SYSCLKSOURCE_HSI) || \
                                     ((SOURCE) == RCC_SYSCLKSOURCE_HSE) || \
                                     ((SOURCE) == RCC_SYSCLKSOURCE_PLLCLK) || \
                                     ((SOURCE) == RCC_SYSCLKSOURCE_PLLRCLK))

#define IS_RCC_RTCCLKSOURCE(__SOURCE__) (((__SOURCE__) == RCC_RTCCLKSOURCE_LSE) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_LSI) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV2) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV3) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV4) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV5) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV6) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV7) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV8) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV9) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV10) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV11) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV12) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV13) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV14) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV15) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV16) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV17) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV18) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV19) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV20) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV21) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV22) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV23) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV24) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV25) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV26) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV27) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV28) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV29) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV30) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV31))

#define IS_RCC_PLLM_VALUE(VALUE) ((VALUE) <= 63U)

#define IS_RCC_PLLP_VALUE(VALUE) (((VALUE) == 2U) || ((VALUE) == 4U) || ((VALUE) == 6U) || ((VALUE) == 8U))

#define IS_RCC_PLLQ_VALUE(VALUE) ((2U <= (VALUE)) && ((VALUE) <= 15U))

#define IS_RCC_HCLK(HCLK) (((HCLK) == RCC_SYSCLK_DIV1)   || ((HCLK) == RCC_SYSCLK_DIV2)   || \
                           ((HCLK) == RCC_SYSCLK_DIV4)   || ((HCLK) == RCC_SYSCLK_DIV8)   || \
                           ((HCLK) == RCC_SYSCLK_DIV16)  || ((HCLK) == RCC_SYSCLK_DIV64)  || \
                           ((HCLK) == RCC_SYSCLK_DIV128) || ((HCLK) == RCC_SYSCLK_DIV256) || \
                           ((HCLK) == RCC_SYSCLK_DIV512))

#define IS_RCC_CLOCKTYPE(CLK) ((1U <= (CLK)) && ((CLK) <= 15U))

#define IS_RCC_PCLK(PCLK) (((PCLK) == RCC_HCLK_DIV1) || ((PCLK) == RCC_HCLK_DIV2) || \
                           ((PCLK) == RCC_HCLK_DIV4) || ((PCLK) == RCC_HCLK_DIV8) || \
                           ((PCLK) == RCC_HCLK_DIV16))

#define IS_RCC_MCO(MCOx) (((MCOx) == RCC_MCO1) || ((MCOx) == RCC_MCO2))

#define IS_RCC_MCO1SOURCE(SOURCE) (((SOURCE) == RCC_MCO1SOURCE_HSI) || ((SOURCE) == RCC_MCO1SOURCE_LSE) || \
                                   ((SOURCE) == RCC_MCO1SOURCE_HSE) || ((SOURCE) == RCC_MCO1SOURCE_PLLCLK))

#define IS_RCC_MCODIV(DIV) (((DIV) == RCC_MCODIV_1)  || ((DIV) == RCC_MCODIV_2) || \
                             ((DIV) == RCC_MCODIV_3) || ((DIV) == RCC_MCODIV_4) || \
                             ((DIV) == RCC_MCODIV_5))
#define IS_RCC_CALIBRATION_VALUE(VALUE) ((VALUE) <= 0x1FU)

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif


/******************************************************************************/
/*                                                                            */
/*                         Reset and Clock Control                            */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for RCC_CR register  ********************/
#define RCC_CR_HSION_Pos                   (0U)                                
#define RCC_CR_HSION_Msk                   (0x1U << RCC_CR_HSION_Pos)          /*!< 0x00000001 */
#define RCC_CR_HSION                       RCC_CR_HSION_Msk                    
#define RCC_CR_HSIRDY_Pos                  (1U)                                
#define RCC_CR_HSIRDY_Msk                  (0x1U << RCC_CR_HSIRDY_Pos)         /*!< 0x00000002 */
#define RCC_CR_HSIRDY                      RCC_CR_HSIRDY_Msk                   
#define RCC_CR_HSITRIM_Pos                 (3U)                                
#define RCC_CR_HSITRIM_Msk                 (0x1FU << RCC_CR_HSITRIM_Pos)       /*!< 0x000000F8 */
#define RCC_CR_HSITRIM                     RCC_CR_HSITRIM_Msk                  
#define RCC_CR_HSITRIM_0                   (0x01U << RCC_CR_HSITRIM_Pos)       /*!< 0x00000008 */
#define RCC_CR_HSITRIM_1                   (0x02U << RCC_CR_HSITRIM_Pos)       /*!< 0x00000010 */
#define RCC_CR_HSITRIM_2                   (0x04U << RCC_CR_HSITRIM_Pos)       /*!< 0x00000020 */
#define RCC_CR_HSITRIM_3                   (0x08U << RCC_CR_HSITRIM_Pos)       /*!< 0x00000040 */
#define RCC_CR_HSITRIM_4                   (0x10U << RCC_CR_HSITRIM_Pos)       /*!< 0x00000080 */
#define RCC_CR_HSICAL_Pos                  (8U)                                
#define RCC_CR_HSICAL_Msk                  (0xFFU << RCC_CR_HSICAL_Pos)        /*!< 0x0000FF00 */
#define RCC_CR_HSICAL                      RCC_CR_HSICAL_Msk                   
#define RCC_CR_HSICAL_0                    (0x01U << RCC_CR_HSICAL_Pos)        /*!< 0x00000100 */
#define RCC_CR_HSICAL_1                    (0x02U << RCC_CR_HSICAL_Pos)        /*!< 0x00000200 */
#define RCC_CR_HSICAL_2                    (0x04U << RCC_CR_HSICAL_Pos)        /*!< 0x00000400 */
#define RCC_CR_HSICAL_3                    (0x08U << RCC_CR_HSICAL_Pos)        /*!< 0x00000800 */
#define RCC_CR_HSICAL_4                    (0x10U << RCC_CR_HSICAL_Pos)        /*!< 0x00001000 */
#define RCC_CR_HSICAL_5                    (0x20U << RCC_CR_HSICAL_Pos)        /*!< 0x00002000 */
#define RCC_CR_HSICAL_6                    (0x40U << RCC_CR_HSICAL_Pos)        /*!< 0x00004000 */
#define RCC_CR_HSICAL_7                    (0x80U << RCC_CR_HSICAL_Pos)        /*!< 0x00008000 */
#define RCC_CR_HSEON_Pos                   (16U)                               
#define RCC_CR_HSEON_Msk                   (0x1U << RCC_CR_HSEON_Pos)          /*!< 0x00010000 */
#define RCC_CR_HSEON                       RCC_CR_HSEON_Msk                    
#define RCC_CR_HSERDY_Pos                  (17U)                               
#define RCC_CR_HSERDY_Msk                  (0x1U << RCC_CR_HSERDY_Pos)         /*!< 0x00020000 */
#define RCC_CR_HSERDY                      RCC_CR_HSERDY_Msk                   
#define RCC_CR_HSEBYP_Pos                  (18U)                               
#define RCC_CR_HSEBYP_Msk                  (0x1U << RCC_CR_HSEBYP_Pos)         /*!< 0x00040000 */
#define RCC_CR_HSEBYP                      RCC_CR_HSEBYP_Msk                   
#define RCC_CR_CSSON_Pos                   (19U)                               
#define RCC_CR_CSSON_Msk                   (0x1U << RCC_CR_CSSON_Pos)          /*!< 0x00080000 */
#define RCC_CR_CSSON                       RCC_CR_CSSON_Msk                    
#define RCC_CR_PLLON_Pos                   (24U)                               
#define RCC_CR_PLLON_Msk                   (0x1U << RCC_CR_PLLON_Pos)          /*!< 0x01000000 */
#define RCC_CR_PLLON                       RCC_CR_PLLON_Msk                    
#define RCC_CR_PLLRDY_Pos                  (25U)                               
#define RCC_CR_PLLRDY_Msk                  (0x1U << RCC_CR_PLLRDY_Pos)         /*!< 0x02000000 */
#define RCC_CR_PLLRDY                      RCC_CR_PLLRDY_Msk                   
/*
 * @brief Specific device feature definitions (not present on all devices in the STM32F4 serie)
 */
#define RCC_PLLI2S_SUPPORT                                                     /*!< Support PLLI2S oscillator */
#define RCC_CR_PLLI2SON_Pos                (26U)                               
#define RCC_CR_PLLI2SON_Msk                (0x1U << RCC_CR_PLLI2SON_Pos)       /*!< 0x04000000 */
#define RCC_CR_PLLI2SON                    RCC_CR_PLLI2SON_Msk                 
#define RCC_CR_PLLI2SRDY_Pos               (27U)                               
#define RCC_CR_PLLI2SRDY_Msk               (0x1U << RCC_CR_PLLI2SRDY_Pos)      /*!< 0x08000000 */
#define RCC_CR_PLLI2SRDY                   RCC_CR_PLLI2SRDY_Msk                
/********************  Bit definition for RCC_PLLCFGR register  ***************/
#define RCC_PLLCFGR_PLLM_Pos               (0U)                                
#define RCC_PLLCFGR_PLLM_Msk               (0x3FU << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x0000003F */
#define RCC_PLLCFGR_PLLM                   RCC_PLLCFGR_PLLM_Msk                
#define RCC_PLLCFGR_PLLM_0                 (0x01U << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000001 */
#define RCC_PLLCFGR_PLLM_1                 (0x02U << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000002 */
#define RCC_PLLCFGR_PLLM_2                 (0x04U << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000004 */
#define RCC_PLLCFGR_PLLM_3                 (0x08U << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000008 */
#define RCC_PLLCFGR_PLLM_4                 (0x10U << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000010 */
#define RCC_PLLCFGR_PLLM_5                 (0x20U << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000020 */
#define RCC_PLLCFGR_PLLN_Pos               (6U)                                
#define RCC_PLLCFGR_PLLN_Msk               (0x1FFU << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00007FC0 */
#define RCC_PLLCFGR_PLLN                   RCC_PLLCFGR_PLLN_Msk                
#define RCC_PLLCFGR_PLLN_0                 (0x001U << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000040 */
#define RCC_PLLCFGR_PLLN_1                 (0x002U << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000080 */
#define RCC_PLLCFGR_PLLN_2                 (0x004U << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000100 */
#define RCC_PLLCFGR_PLLN_3                 (0x008U << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000200 */
#define RCC_PLLCFGR_PLLN_4                 (0x010U << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000400 */
#define RCC_PLLCFGR_PLLN_5                 (0x020U << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000800 */
#define RCC_PLLCFGR_PLLN_6                 (0x040U << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00001000 */
#define RCC_PLLCFGR_PLLN_7                 (0x080U << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00002000 */
#define RCC_PLLCFGR_PLLN_8                 (0x100U << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00004000 */
#define RCC_PLLCFGR_PLLP_Pos               (16U)                               
#define RCC_PLLCFGR_PLLP_Msk               (0x3U << RCC_PLLCFGR_PLLP_Pos)      /*!< 0x00030000 */
#define RCC_PLLCFGR_PLLP                   RCC_PLLCFGR_PLLP_Msk                
#define RCC_PLLCFGR_PLLP_0                 (0x1U << RCC_PLLCFGR_PLLP_Pos)      /*!< 0x00010000 */
#define RCC_PLLCFGR_PLLP_1                 (0x2U << RCC_PLLCFGR_PLLP_Pos)      /*!< 0x00020000 */
#define RCC_PLLCFGR_PLLSRC_Pos             (22U)                               
#define RCC_PLLCFGR_PLLSRC_Msk             (0x1U << RCC_PLLCFGR_PLLSRC_Pos)    /*!< 0x00400000 */
#define RCC_PLLCFGR_PLLSRC                 RCC_PLLCFGR_PLLSRC_Msk              
#define RCC_PLLCFGR_PLLSRC_HSE_Pos         (22U)                               
#define RCC_PLLCFGR_PLLSRC_HSE_Msk         (0x1U << RCC_PLLCFGR_PLLSRC_HSE_Pos) /*!< 0x00400000 */
#define RCC_PLLCFGR_PLLSRC_HSE             RCC_PLLCFGR_PLLSRC_HSE_Msk          
#define RCC_PLLCFGR_PLLSRC_HSI             0x00000000U                         
#define RCC_PLLCFGR_PLLQ_Pos               (24U)                               
#define RCC_PLLCFGR_PLLQ_Msk               (0xFU << RCC_PLLCFGR_PLLQ_Pos)      /*!< 0x0F000000 */
#define RCC_PLLCFGR_PLLQ                   RCC_PLLCFGR_PLLQ_Msk                
#define RCC_PLLCFGR_PLLQ_0                 (0x1U << RCC_PLLCFGR_PLLQ_Pos)      /*!< 0x01000000 */
#define RCC_PLLCFGR_PLLQ_1                 (0x2U << RCC_PLLCFGR_PLLQ_Pos)      /*!< 0x02000000 */
#define RCC_PLLCFGR_PLLQ_2                 (0x4U << RCC_PLLCFGR_PLLQ_Pos)      /*!< 0x04000000 */
#define RCC_PLLCFGR_PLLQ_3                 (0x8U << RCC_PLLCFGR_PLLQ_Pos)      /*!< 0x08000000 */
/********************  Bit definition for RCC_CFGR register  ******************/
/*!< SW configuration */
#define RCC_CFGR_SW_Pos                    (0U)                                
#define RCC_CFGR_SW_Msk                    (0x3U << RCC_CFGR_SW_Pos)           /*!< 0x00000003 */
#define RCC_CFGR_SW                        RCC_CFGR_SW_Msk                     /*!< SW[1:0] bits (System clock Switch) */
#define RCC_CFGR_SW_0                      (0x1U << RCC_CFGR_SW_Pos)           /*!< 0x00000001 */
#define RCC_CFGR_SW_1                      (0x2U << RCC_CFGR_SW_Pos)           /*!< 0x00000002 */
#define RCC_CFGR_SW_HSI                    0x00000000U                         /*!< HSI selected as system clock */
#define RCC_CFGR_SW_HSE                    0x00000001U                         /*!< HSE selected as system clock */
#define RCC_CFGR_SW_PLL                    0x00000002U                         /*!< PLL selected as system clock */
/*!< SWS configuration */
#define RCC_CFGR_SWS_Pos                   (2U)                                
#define RCC_CFGR_SWS_Msk                   (0x3U << RCC_CFGR_SWS_Pos)          /*!< 0x0000000C */
#define RCC_CFGR_SWS                       RCC_CFGR_SWS_Msk                    /*!< SWS[1:0] bits (System Clock Switch Stat
#define RCC_CFGR_SWS_0                     (0x1U << RCC_CFGR_SWS_Pos)          /*!< 0x00000004 */
#define RCC_CFGR_SWS_1                     (0x2U << RCC_CFGR_SWS_Pos)          /*!< 0x00000008 */
#define RCC_CFGR_SWS_HSI                   0x00000000U                         /*!< HSI oscillator used as system clock    
#define RCC_CFGR_SWS_HSE                   0x00000004U                         /*!< HSE oscillator used as system clock    
#define RCC_CFGR_SWS_PLL                   0x00000008U                         /*!< PLL used as system clock               
/*!< HPRE configuration */
#define RCC_CFGR_HPRE_Pos                  (4U)                                
#define RCC_CFGR_HPRE_Msk                  (0xFU << RCC_CFGR_HPRE_Pos)         /*!< 0x000000F0 */
#define RCC_CFGR_HPRE                      RCC_CFGR_HPRE_Msk                   /*!< HPRE[3:0] bits (AHB prescaler) */
#define RCC_CFGR_HPRE_0                    (0x1U << RCC_CFGR_HPRE_Pos)         /*!< 0x00000010 */
#define RCC_CFGR_HPRE_1                    (0x2U << RCC_CFGR_HPRE_Pos)         /*!< 0x00000020 */
#define RCC_CFGR_HPRE_2                    (0x4U << RCC_CFGR_HPRE_Pos)         /*!< 0x00000040 */
#define RCC_CFGR_HPRE_3                    (0x8U << RCC_CFGR_HPRE_Pos)         /*!< 0x00000080 */
#define RCC_CFGR_HPRE_DIV1                 0x00000000U                         /*!< SYSCLK not divided    */
#define RCC_CFGR_HPRE_DIV2                 0x00000080U                         /*!< SYSCLK divided by 2   */
#define RCC_CFGR_HPRE_DIV4                 0x00000090U                         /*!< SYSCLK divided by 4   */
#define RCC_CFGR_HPRE_DIV8                 0x000000A0U                         /*!< SYSCLK divided by 8   */
#define RCC_CFGR_HPRE_DIV16                0x000000B0U                         /*!< SYSCLK divided by 16  */
#define RCC_CFGR_HPRE_DIV64                0x000000C0U                         /*!< SYSCLK divided by 64  */
#define RCC_CFGR_HPRE_DIV128               0x000000D0U                         /*!< SYSCLK divided by 128 */
#define RCC_CFGR_HPRE_DIV256               0x000000E0U                         /*!< SYSCLK divided by 256 */
#define RCC_CFGR_HPRE_DIV512               0x000000F0U                         /*!< SYSCLK divided by 512 */
/*!< PPRE1 configuration */
#define RCC_CFGR_PPRE1_Pos                 (10U)                               
#define RCC_CFGR_PPRE1_Msk                 (0x7U << RCC_CFGR_PPRE1_Pos)        /*!< 0x00001C00 */
#define RCC_CFGR_PPRE1                     RCC_CFGR_PPRE1_Msk                  /*!< PRE1[2:0] bits (APB1 prescaler) */
#define RCC_CFGR_PPRE1_0                   (0x1U << RCC_CFGR_PPRE1_Pos)        /*!< 0x00000400 */
#define RCC_CFGR_PPRE1_1                   (0x2U << RCC_CFGR_PPRE1_Pos)        /*!< 0x00000800 */
#define RCC_CFGR_PPRE1_2                   (0x4U << RCC_CFGR_PPRE1_Pos)        /*!< 0x00001000 */
#define RCC_CFGR_PPRE1_DIV1                0x00000000U                         /*!< HCLK not divided   */
#define RCC_CFGR_PPRE1_DIV2                0x00001000U                         /*!< HCLK divided by 2  */
#define RCC_CFGR_PPRE1_DIV4                0x00001400U                         /*!< HCLK divided by 4  */
#define RCC_CFGR_PPRE1_DIV8                0x00001800U                         /*!< HCLK divided by 8  */
#define RCC_CFGR_PPRE1_DIV16               0x00001C00U                         /*!< HCLK divided by 16 */
/*!< PPRE2 configuration */
#define RCC_CFGR_PPRE2_Pos                 (13U)                               
#define RCC_CFGR_PPRE2_Msk                 (0x7U << RCC_CFGR_PPRE2_Pos)        /*!< 0x0000E000 */
#define RCC_CFGR_PPRE2                     RCC_CFGR_PPRE2_Msk                  /*!< PRE2[2:0] bits (APB2 prescaler) */
#define RCC_CFGR_PPRE2_0                   (0x1U << RCC_CFGR_PPRE2_Pos)        /*!< 0x00002000 */
#define RCC_CFGR_PPRE2_1                   (0x2U << RCC_CFGR_PPRE2_Pos)        /*!< 0x00004000 */
#define RCC_CFGR_PPRE2_2                   (0x4U << RCC_CFGR_PPRE2_Pos)        /*!< 0x00008000 */
#define RCC_CFGR_PPRE2_DIV1                0x00000000U                         /*!< HCLK not divided   */
#define RCC_CFGR_PPRE2_DIV2                0x00008000U                         /*!< HCLK divided by 2  */
#define RCC_CFGR_PPRE2_DIV4                0x0000A000U                         /*!< HCLK divided by 4  */
#define RCC_CFGR_PPRE2_DIV8                0x0000C000U                         /*!< HCLK divided by 8  */
#define RCC_CFGR_PPRE2_DIV16               0x0000E000U                         /*!< HCLK divided by 16 */
/*!< RTCPRE configuration */
#define RCC_CFGR_RTCPRE_Pos                (16U)                               
#define RCC_CFGR_RTCPRE_Msk                (0x1FU << RCC_CFGR_RTCPRE_Pos)      /*!< 0x001F0000 */
#define RCC_CFGR_RTCPRE                    RCC_CFGR_RTCPRE_Msk                 
#define RCC_CFGR_RTCPRE_0                  (0x01U << RCC_CFGR_RTCPRE_Pos)      /*!< 0x00010000 */
#define RCC_CFGR_RTCPRE_1                  (0x02U << RCC_CFGR_RTCPRE_Pos)      /*!< 0x00020000 */
#define RCC_CFGR_RTCPRE_2                  (0x04U << RCC_CFGR_RTCPRE_Pos)      /*!< 0x00040000 */
#define RCC_CFGR_RTCPRE_3                  (0x08U << RCC_CFGR_RTCPRE_Pos)      /*!< 0x00080000 */
#define RCC_CFGR_RTCPRE_4                  (0x10U << RCC_CFGR_RTCPRE_Pos)      /*!< 0x00100000 */
/*!< MCO1 configuration */
#define RCC_CFGR_MCO1_Pos                  (21U)                               
#define RCC_CFGR_MCO1_Msk                  (0x3U << RCC_CFGR_MCO1_Pos)         /*!< 0x00600000 */
#define RCC_CFGR_MCO1                      RCC_CFGR_MCO1_Msk                   
#define RCC_CFGR_MCO1_0                    (0x1U << RCC_CFGR_MCO1_Pos)         /*!< 0x00200000 */
#define RCC_CFGR_MCO1_1                    (0x2U << RCC_CFGR_MCO1_Pos)         /*!< 0x00400000 */
#define RCC_CFGR_I2SSRC_Pos                (23U)                               
#define RCC_CFGR_I2SSRC_Msk                (0x1U << RCC_CFGR_I2SSRC_Pos)       /*!< 0x00800000 */
#define RCC_CFGR_I2SSRC                    RCC_CFGR_I2SSRC_Msk                 
#define RCC_CFGR_MCO1PRE_Pos               (24U)                               
#define RCC_CFGR_MCO1PRE_Msk               (0x7U << RCC_CFGR_MCO1PRE_Pos)      /*!< 0x07000000 */
#define RCC_CFGR_MCO1PRE                   RCC_CFGR_MCO1PRE_Msk                
#define RCC_CFGR_MCO1PRE_0                 (0x1U << RCC_CFGR_MCO1PRE_Pos)      /*!< 0x01000000 */
#define RCC_CFGR_MCO1PRE_1                 (0x2U << RCC_CFGR_MCO1PRE_Pos)      /*!< 0x02000000 */
#define RCC_CFGR_MCO1PRE_2                 (0x4U << RCC_CFGR_MCO1PRE_Pos)      /*!< 0x04000000 */
#define RCC_CFGR_MCO2PRE_Pos               (27U)                               
#define RCC_CFGR_MCO2PRE_Msk               (0x7U << RCC_CFGR_MCO2PRE_Pos)      /*!< 0x38000000 */
#define RCC_CFGR_MCO2PRE                   RCC_CFGR_MCO2PRE_Msk                
#define RCC_CFGR_MCO2PRE_0                 (0x1U << RCC_CFGR_MCO2PRE_Pos)      /*!< 0x08000000 */
#define RCC_CFGR_MCO2PRE_1                 (0x2U << RCC_CFGR_MCO2PRE_Pos)      /*!< 0x10000000 */
#define RCC_CFGR_MCO2PRE_2                 (0x4U << RCC_CFGR_MCO2PRE_Pos)      /*!< 0x20000000 */
#define RCC_CFGR_MCO2_Pos                  (30U)                               
#define RCC_CFGR_MCO2_Msk                  (0x3U << RCC_CFGR_MCO2_Pos)         /*!< 0xC0000000 */
#define RCC_CFGR_MCO2                      RCC_CFGR_MCO2_Msk                   
#define RCC_CFGR_MCO2_0                    (0x1U << RCC_CFGR_MCO2_Pos)         /*!< 0x40000000 */
#define RCC_CFGR_MCO2_1                    (0x2U << RCC_CFGR_MCO2_Pos)         /*!< 0x80000000 */
/********************  Bit definition for RCC_CIR register  *******************/
#define RCC_CIR_LSIRDYF_Pos                (0U)                                
#define RCC_CIR_LSIRDYF_Msk                (0x1U << RCC_CIR_LSIRDYF_Pos)       /*!< 0x00000001 */
#define RCC_CIR_LSIRDYF                    RCC_CIR_LSIRDYF_Msk                 
#define RCC_CIR_LSERDYF_Pos                (1U)                                
#define RCC_CIR_LSERDYF_Msk                (0x1U << RCC_CIR_LSERDYF_Pos)       /*!< 0x00000002 */
#define RCC_CIR_LSERDYF                    RCC_CIR_LSERDYF_Msk                 
#define RCC_CIR_HSIRDYF_Pos                (2U)                                
#define RCC_CIR_HSIRDYF_Msk                (0x1U << RCC_CIR_HSIRDYF_Pos)       /*!< 0x00000004 */
#define RCC_CIR_HSIRDYF                    RCC_CIR_HSIRDYF_Msk                 
#define RCC_CIR_HSERDYF_Pos                (3U)                                
#define RCC_CIR_HSERDYF_Msk                (0x1U << RCC_CIR_HSERDYF_Pos)       /*!< 0x00000008 */
#define RCC_CIR_HSERDYF                    RCC_CIR_HSERDYF_Msk                 
#define RCC_CIR_PLLRDYF_Pos                (4U)                                
#define RCC_CIR_PLLRDYF_Msk                (0x1U << RCC_CIR_PLLRDYF_Pos)       /*!< 0x00000010 */
#define RCC_CIR_PLLRDYF                    RCC_CIR_PLLRDYF_Msk                 
#define RCC_CIR_PLLI2SRDYF_Pos             (5U)                                
#define RCC_CIR_PLLI2SRDYF_Msk             (0x1U << RCC_CIR_PLLI2SRDYF_Pos)    /*!< 0x00000020 */
#define RCC_CIR_PLLI2SRDYF                 RCC_CIR_PLLI2SRDYF_Msk              
#define RCC_CIR_CSSF_Pos                   (7U)                                
#define RCC_CIR_CSSF_Msk                   (0x1U << RCC_CIR_CSSF_Pos)          /*!< 0x00000080 */
#define RCC_CIR_CSSF                       RCC_CIR_CSSF_Msk                    
#define RCC_CIR_LSIRDYIE_Pos               (8U)                                
#define RCC_CIR_LSIRDYIE_Msk               (0x1U << RCC_CIR_LSIRDYIE_Pos)      /*!< 0x00000100 */
#define RCC_CIR_LSIRDYIE                   RCC_CIR_LSIRDYIE_Msk                
#define RCC_CIR_LSERDYIE_Pos               (9U)                                
#define RCC_CIR_LSERDYIE_Msk               (0x1U << RCC_CIR_LSERDYIE_Pos)      /*!< 0x00000200 */
#define RCC_CIR_LSERDYIE                   RCC_CIR_LSERDYIE_Msk                
#define RCC_CIR_HSIRDYIE_Pos               (10U)                               
#define RCC_CIR_HSIRDYIE_Msk               (0x1U << RCC_CIR_HSIRDYIE_Pos)      /*!< 0x00000400 */
#define RCC_CIR_HSIRDYIE                   RCC_CIR_HSIRDYIE_Msk                
#define RCC_CIR_HSERDYIE_Pos               (11U)                               
#define RCC_CIR_HSERDYIE_Msk               (0x1U << RCC_CIR_HSERDYIE_Pos)      /*!< 0x00000800 */
#define RCC_CIR_HSERDYIE                   RCC_CIR_HSERDYIE_Msk                
#define RCC_CIR_PLLRDYIE_Pos               (12U)                               
#define RCC_CIR_PLLRDYIE_Msk               (0x1U << RCC_CIR_PLLRDYIE_Pos)      /*!< 0x00001000 */
#define RCC_CIR_PLLRDYIE                   RCC_CIR_PLLRDYIE_Msk                
#define RCC_CIR_PLLI2SRDYIE_Pos            (13U)                               
#define RCC_CIR_PLLI2SRDYIE_Msk            (0x1U << RCC_CIR_PLLI2SRDYIE_Pos)   /*!< 0x00002000 */
#define RCC_CIR_PLLI2SRDYIE                RCC_CIR_PLLI2SRDYIE_Msk             
#define RCC_CIR_LSIRDYC_Pos                (16U)                               
#define RCC_CIR_LSIRDYC_Msk                (0x1U << RCC_CIR_LSIRDYC_Pos)       /*!< 0x00010000 */
#define RCC_CIR_LSIRDYC                    RCC_CIR_LSIRDYC_Msk                 
#define RCC_CIR_LSERDYC_Pos                (17U)                               
#define RCC_CIR_LSERDYC_Msk                (0x1U << RCC_CIR_LSERDYC_Pos)       /*!< 0x00020000 */
#define RCC_CIR_LSERDYC                    RCC_CIR_LSERDYC_Msk                 
#define RCC_CIR_HSIRDYC_Pos                (18U)                               
#define RCC_CIR_HSIRDYC_Msk                (0x1U << RCC_CIR_HSIRDYC_Pos)       /*!< 0x00040000 */
#define RCC_CIR_HSIRDYC                    RCC_CIR_HSIRDYC_Msk                 
#define RCC_CIR_HSERDYC_Pos                (19U)                               
#define RCC_CIR_HSERDYC_Msk                (0x1U << RCC_CIR_HSERDYC_Pos)       /*!< 0x00080000 */
#define RCC_CIR_HSERDYC                    RCC_CIR_HSERDYC_Msk                 
#define RCC_CIR_PLLRDYC_Pos                (20U)                               
#define RCC_CIR_PLLRDYC_Msk                (0x1U << RCC_CIR_PLLRDYC_Pos)       /*!< 0x00100000 */
#define RCC_CIR_PLLRDYC                    RCC_CIR_PLLRDYC_Msk                 
#define RCC_CIR_PLLI2SRDYC_Pos             (21U)                               
#define RCC_CIR_PLLI2SRDYC_Msk             (0x1U << RCC_CIR_PLLI2SRDYC_Pos)    /*!< 0x00200000 */
#define RCC_CIR_PLLI2SRDYC                 RCC_CIR_PLLI2SRDYC_Msk              
#define RCC_CIR_CSSC_Pos                   (23U)                               
#define RCC_CIR_CSSC_Msk                   (0x1U << RCC_CIR_CSSC_Pos)          /*!< 0x00800000 */
#define RCC_CIR_CSSC                       RCC_CIR_CSSC_Msk                    
/********************  Bit definition for RCC_AHB1RSTR register  **************/
#define RCC_AHB1RSTR_GPIOARST_Pos          (0U)                                
#define RCC_AHB1RSTR_GPIOARST_Msk          (0x1U << RCC_AHB1RSTR_GPIOARST_Pos) /*!< 0x00000001 */
#define RCC_AHB1RSTR_GPIOARST              RCC_AHB1RSTR_GPIOARST_Msk           
#define RCC_AHB1RSTR_GPIOBRST_Pos          (1U)                                
#define RCC_AHB1RSTR_GPIOBRST_Msk          (0x1U << RCC_AHB1RSTR_GPIOBRST_Pos) /*!< 0x00000002 */
#define RCC_AHB1RSTR_GPIOBRST              RCC_AHB1RSTR_GPIOBRST_Msk           
#define RCC_AHB1RSTR_GPIOCRST_Pos          (2U)                                
#define RCC_AHB1RSTR_GPIOCRST_Msk          (0x1U << RCC_AHB1RSTR_GPIOCRST_Pos) /*!< 0x00000004 */
#define RCC_AHB1RSTR_GPIOCRST              RCC_AHB1RSTR_GPIOCRST_Msk           
#define RCC_AHB1RSTR_GPIODRST_Pos          (3U)                                
#define RCC_AHB1RSTR_GPIODRST_Msk          (0x1U << RCC_AHB1RSTR_GPIODRST_Pos) /*!< 0x00000008 */
#define RCC_AHB1RSTR_GPIODRST              RCC_AHB1RSTR_GPIODRST_Msk           
#define RCC_AHB1RSTR_GPIOERST_Pos          (4U)                                
#define RCC_AHB1RSTR_GPIOERST_Msk          (0x1U << RCC_AHB1RSTR_GPIOERST_Pos) /*!< 0x00000010 */
#define RCC_AHB1RSTR_GPIOERST              RCC_AHB1RSTR_GPIOERST_Msk           
#define RCC_AHB1RSTR_GPIOHRST_Pos          (7U)                                
#define RCC_AHB1RSTR_GPIOHRST_Msk          (0x1U << RCC_AHB1RSTR_GPIOHRST_Pos) /*!< 0x00000080 */
#define RCC_AHB1RSTR_GPIOHRST              RCC_AHB1RSTR_GPIOHRST_Msk           
#define RCC_AHB1RSTR_CRCRST_Pos            (12U)                               
#define RCC_AHB1RSTR_CRCRST_Msk            (0x1U << RCC_AHB1RSTR_CRCRST_Pos)   /*!< 0x00001000 */
#define RCC_AHB1RSTR_CRCRST                RCC_AHB1RSTR_CRCRST_Msk             
#define RCC_AHB1RSTR_DMA1RST_Pos           (21U)                               
#define RCC_AHB1RSTR_DMA1RST_Msk           (0x1U << RCC_AHB1RSTR_DMA1RST_Pos)  /*!< 0x00200000 */
#define RCC_AHB1RSTR_DMA1RST               RCC_AHB1RSTR_DMA1RST_Msk            
#define RCC_AHB1RSTR_DMA2RST_Pos           (22U)                               
#define RCC_AHB1RSTR_DMA2RST_Msk           (0x1U << RCC_AHB1RSTR_DMA2RST_Pos)  /*!< 0x00400000 */
#define RCC_AHB1RSTR_DMA2RST               RCC_AHB1RSTR_DMA2RST_Msk            
/********************  Bit definition for RCC_AHB2RSTR register  **************/
#define RCC_AHB2RSTR_OTGFSRST_Pos          (7U)                                
#define RCC_AHB2RSTR_OTGFSRST_Msk          (0x1U << RCC_AHB2RSTR_OTGFSRST_Pos) /*!< 0x00000080 */
#define RCC_AHB2RSTR_OTGFSRST              RCC_AHB2RSTR_OTGFSRST_Msk           
/********************  Bit definition for RCC_AHB3RSTR register  **************/
/********************  Bit definition for RCC_APB1RSTR register  **************/
#define RCC_APB1RSTR_TIM2RST_Pos           (0U)                                
#define RCC_APB1RSTR_TIM2RST_Msk           (0x1U << RCC_APB1RSTR_TIM2RST_Pos)  /*!< 0x00000001 */
#define RCC_APB1RSTR_TIM2RST               RCC_APB1RSTR_TIM2RST_Msk            
#define RCC_APB1RSTR_TIM3RST_Pos           (1U)                                
#define RCC_APB1RSTR_TIM3RST_Msk           (0x1U << RCC_APB1RSTR_TIM3RST_Pos)  /*!< 0x00000002 */
#define RCC_APB1RSTR_TIM3RST               RCC_APB1RSTR_TIM3RST_Msk            
#define RCC_APB1RSTR_TIM4RST_Pos           (2U)                                
#define RCC_APB1RSTR_TIM4RST_Msk           (0x1U << RCC_APB1RSTR_TIM4RST_Pos)  /*!< 0x00000004 */
#define RCC_APB1RSTR_TIM4RST               RCC_APB1RSTR_TIM4RST_Msk            
#define RCC_APB1RSTR_TIM5RST_Pos           (3U)                                
#define RCC_APB1RSTR_TIM5RST_Msk           (0x1U << RCC_APB1RSTR_TIM5RST_Pos)  /*!< 0x00000008 */
#define RCC_APB1RSTR_TIM5RST               RCC_APB1RSTR_TIM5RST_Msk            
#define RCC_APB1RSTR_WWDGRST_Pos           (11U)                               
#define RCC_APB1RSTR_WWDGRST_Msk           (0x1U << RCC_APB1RSTR_WWDGRST_Pos)  /*!< 0x00000800 */
#define RCC_APB1RSTR_WWDGRST               RCC_APB1RSTR_WWDGRST_Msk            
#define RCC_APB1RSTR_SPI2RST_Pos           (14U)                               
#define RCC_APB1RSTR_SPI2RST_Msk           (0x1U << RCC_APB1RSTR_SPI2RST_Pos)  /*!< 0x00004000 */
#define RCC_APB1RSTR_SPI2RST               RCC_APB1RSTR_SPI2RST_Msk            
#define RCC_APB1RSTR_SPI3RST_Pos           (15U)                               
#define RCC_APB1RSTR_SPI3RST_Msk           (0x1U << RCC_APB1RSTR_SPI3RST_Pos)  /*!< 0x00008000 */
#define RCC_APB1RSTR_SPI3RST               RCC_APB1RSTR_SPI3RST_Msk            
#define RCC_APB1RSTR_USART2RST_Pos         (17U)                               
#define RCC_APB1RSTR_USART2RST_Msk         (0x1U << RCC_APB1RSTR_USART2RST_Pos) /*!< 0x00020000 */
#define RCC_APB1RSTR_USART2RST             RCC_APB1RSTR_USART2RST_Msk          
#define RCC_APB1RSTR_I2C1RST_Pos           (21U)                               
#define RCC_APB1RSTR_I2C1RST_Msk           (0x1U << RCC_APB1RSTR_I2C1RST_Pos)  /*!< 0x00200000 */
#define RCC_APB1RSTR_I2C1RST               RCC_APB1RSTR_I2C1RST_Msk            
#define RCC_APB1RSTR_I2C2RST_Pos           (22U)                               
#define RCC_APB1RSTR_I2C2RST_Msk           (0x1U << RCC_APB1RSTR_I2C2RST_Pos)  /*!< 0x00400000 */
#define RCC_APB1RSTR_I2C2RST               RCC_APB1RSTR_I2C2RST_Msk            
#define RCC_APB1RSTR_I2C3RST_Pos           (23U)                               
#define RCC_APB1RSTR_I2C3RST_Msk           (0x1U << RCC_APB1RSTR_I2C3RST_Pos)  /*!< 0x00800000 */
#define RCC_APB1RSTR_I2C3RST               RCC_APB1RSTR_I2C3RST_Msk            
#define RCC_APB1RSTR_PWRRST_Pos            (28U)                               
#define RCC_APB1RSTR_PWRRST_Msk            (0x1U << RCC_APB1RSTR_PWRRST_Pos)   /*!< 0x10000000 */
#define RCC_APB1RSTR_PWRRST                RCC_APB1RSTR_PWRRST_Msk             
/********************  Bit definition for RCC_APB2RSTR register  **************/
#define RCC_APB2RSTR_TIM1RST_Pos           (0U)                                
#define RCC_APB2RSTR_TIM1RST_Msk           (0x1U << RCC_APB2RSTR_TIM1RST_Pos)  /*!< 0x00000001 */
#define RCC_APB2RSTR_TIM1RST               RCC_APB2RSTR_TIM1RST_Msk            
#define RCC_APB2RSTR_USART1RST_Pos         (4U)                                
#define RCC_APB2RSTR_USART1RST_Msk         (0x1U << RCC_APB2RSTR_USART1RST_Pos) /*!< 0x00000010 */
#define RCC_APB2RSTR_USART1RST             RCC_APB2RSTR_USART1RST_Msk          
#define RCC_APB2RSTR_USART6RST_Pos         (5U)                                
#define RCC_APB2RSTR_USART6RST_Msk         (0x1U << RCC_APB2RSTR_USART6RST_Pos) /*!< 0x00000020 */
#define RCC_APB2RSTR_USART6RST             RCC_APB2RSTR_USART6RST_Msk          
#define RCC_APB2RSTR_ADCRST_Pos            (8U)                                
#define RCC_APB2RSTR_ADCRST_Msk            (0x1U << RCC_APB2RSTR_ADCRST_Pos)   /*!< 0x00000100 */
#define RCC_APB2RSTR_ADCRST                RCC_APB2RSTR_ADCRST_Msk             
#define RCC_APB2RSTR_SDIORST_Pos           (11U)                               
#define RCC_APB2RSTR_SDIORST_Msk           (0x1U << RCC_APB2RSTR_SDIORST_Pos)  /*!< 0x00000800 */
#define RCC_APB2RSTR_SDIORST               RCC_APB2RSTR_SDIORST_Msk            
#define RCC_APB2RSTR_SPI1RST_Pos           (12U)                               
#define RCC_APB2RSTR_SPI1RST_Msk           (0x1U << RCC_APB2RSTR_SPI1RST_Pos)  /*!< 0x00001000 */
#define RCC_APB2RSTR_SPI1RST               RCC_APB2RSTR_SPI1RST_Msk            
#define RCC_APB2RSTR_SPI4RST_Pos           (13U)                               
#define RCC_APB2RSTR_SPI4RST_Msk           (0x1U << RCC_APB2RSTR_SPI4RST_Pos)  /*!< 0x00002000 */
#define RCC_APB2RSTR_SPI4RST               RCC_APB2RSTR_SPI4RST_Msk            
#define RCC_APB2RSTR_SYSCFGRST_Pos         (14U)                               
#define RCC_APB2RSTR_SYSCFGRST_Msk         (0x1U << RCC_APB2RSTR_SYSCFGRST_Pos) /*!< 0x00004000 */
#define RCC_APB2RSTR_SYSCFGRST             RCC_APB2RSTR_SYSCFGRST_Msk          
#define RCC_APB2RSTR_TIM9RST_Pos           (16U)                               
#define RCC_APB2RSTR_TIM9RST_Msk           (0x1U << RCC_APB2RSTR_TIM9RST_Pos)  /*!< 0x00010000 */
#define RCC_APB2RSTR_TIM9RST               RCC_APB2RSTR_TIM9RST_Msk            
#define RCC_APB2RSTR_TIM10RST_Pos          (17U)                               
#define RCC_APB2RSTR_TIM10RST_Msk          (0x1U << RCC_APB2RSTR_TIM10RST_Pos) /*!< 0x00020000 */
#define RCC_APB2RSTR_TIM10RST              RCC_APB2RSTR_TIM10RST_Msk           
#define RCC_APB2RSTR_TIM11RST_Pos          (18U)                               
#define RCC_APB2RSTR_TIM11RST_Msk          (0x1U << RCC_APB2RSTR_TIM11RST_Pos) /*!< 0x00040000 */
#define RCC_APB2RSTR_TIM11RST              RCC_APB2RSTR_TIM11RST_Msk           
#define RCC_APB2RSTR_SPI5RST_Pos           (20U)                               
#define RCC_APB2RSTR_SPI5RST_Msk           (0x1U << RCC_APB2RSTR_SPI5RST_Pos)  /*!< 0x00100000 */
#define RCC_APB2RSTR_SPI5RST               RCC_APB2RSTR_SPI5RST_Msk            
/* Old SPI1RST bit definition, maintained for legacy purpose */
#define  RCC_APB2RSTR_SPI1                   RCC_APB2RSTR_SPI1RST
/********************  Bit definition for RCC_AHB1ENR register  ***************/
#define RCC_AHB1ENR_GPIOAEN_Pos            (0U)                                
#define RCC_AHB1ENR_GPIOAEN_Msk            (0x1U << RCC_AHB1ENR_GPIOAEN_Pos)   /*!< 0x00000001 */
#define RCC_AHB1ENR_GPIOAEN                RCC_AHB1ENR_GPIOAEN_Msk             
#define RCC_AHB1ENR_GPIOBEN_Pos            (1U)                                
#define RCC_AHB1ENR_GPIOBEN_Msk            (0x1U << RCC_AHB1ENR_GPIOBEN_Pos)   /*!< 0x00000002 */
#define RCC_AHB1ENR_GPIOBEN                RCC_AHB1ENR_GPIOBEN_Msk             
#define RCC_AHB1ENR_GPIOCEN_Pos            (2U)                                
#define RCC_AHB1ENR_GPIOCEN_Msk            (0x1U << RCC_AHB1ENR_GPIOCEN_Pos)   /*!< 0x00000004 */
#define RCC_AHB1ENR_GPIOCEN                RCC_AHB1ENR_GPIOCEN_Msk             
#define RCC_AHB1ENR_GPIODEN_Pos            (3U)                                
#define RCC_AHB1ENR_GPIODEN_Msk            (0x1U << RCC_AHB1ENR_GPIODEN_Pos)   /*!< 0x00000008 */
#define RCC_AHB1ENR_GPIODEN                RCC_AHB1ENR_GPIODEN_Msk             
#define RCC_AHB1ENR_GPIOEEN_Pos            (4U)                                
#define RCC_AHB1ENR_GPIOEEN_Msk            (0x1U << RCC_AHB1ENR_GPIOEEN_Pos)   /*!< 0x00000010 */
#define RCC_AHB1ENR_GPIOEEN                RCC_AHB1ENR_GPIOEEN_Msk             
#define RCC_AHB1ENR_GPIOHEN_Pos            (7U)                                
#define RCC_AHB1ENR_GPIOHEN_Msk            (0x1U << RCC_AHB1ENR_GPIOHEN_Pos)   /*!< 0x00000080 */
#define RCC_AHB1ENR_GPIOHEN                RCC_AHB1ENR_GPIOHEN_Msk             
#define RCC_AHB1ENR_CRCEN_Pos              (12U)                               
#define RCC_AHB1ENR_CRCEN_Msk              (0x1U << RCC_AHB1ENR_CRCEN_Pos)     /*!< 0x00001000 */
#define RCC_AHB1ENR_CRCEN                  RCC_AHB1ENR_CRCEN_Msk               
#define RCC_AHB1ENR_DMA1EN_Pos             (21U)                               
#define RCC_AHB1ENR_DMA1EN_Msk             (0x1U << RCC_AHB1ENR_DMA1EN_Pos)    /*!< 0x00200000 */
#define RCC_AHB1ENR_DMA1EN                 RCC_AHB1ENR_DMA1EN_Msk              
#define RCC_AHB1ENR_DMA2EN_Pos             (22U)                               
#define RCC_AHB1ENR_DMA2EN_Msk             (0x1U << RCC_AHB1ENR_DMA2EN_Pos)    /*!< 0x00400000 */
#define RCC_AHB1ENR_DMA2EN                 RCC_AHB1ENR_DMA2EN_Msk              
/********************  Bit definition for RCC_AHB2ENR register  ***************/
/*
 * @brief Specific device feature definitions (not present on all devices in the STM32F4 serie)
 */
#define RCC_AHB2_SUPPORT                   /*!< AHB2 Bus is supported */
#define RCC_AHB2ENR_OTGFSEN_Pos            (7U)                                
#define RCC_AHB2ENR_OTGFSEN_Msk            (0x1U << RCC_AHB2ENR_OTGFSEN_Pos)   /*!< 0x00000080 */
#define RCC_AHB2ENR_OTGFSEN                RCC_AHB2ENR_OTGFSEN_Msk             
/********************  Bit definition for RCC_APB1ENR register  ***************/
#define RCC_APB1ENR_TIM2EN_Pos             (0U)                                
#define RCC_APB1ENR_TIM2EN_Msk             (0x1U << RCC_APB1ENR_TIM2EN_Pos)    /*!< 0x00000001 */
#define RCC_APB1ENR_TIM2EN                 RCC_APB1ENR_TIM2EN_Msk              
#define RCC_APB1ENR_TIM3EN_Pos             (1U)                                
#define RCC_APB1ENR_TIM3EN_Msk             (0x1U << RCC_APB1ENR_TIM3EN_Pos)    /*!< 0x00000002 */
#define RCC_APB1ENR_TIM3EN                 RCC_APB1ENR_TIM3EN_Msk              
#define RCC_APB1ENR_TIM4EN_Pos             (2U)                                
#define RCC_APB1ENR_TIM4EN_Msk             (0x1U << RCC_APB1ENR_TIM4EN_Pos)    /*!< 0x00000004 */
#define RCC_APB1ENR_TIM4EN                 RCC_APB1ENR_TIM4EN_Msk              
#define RCC_APB1ENR_TIM5EN_Pos             (3U)                                
#define RCC_APB1ENR_TIM5EN_Msk             (0x1U << RCC_APB1ENR_TIM5EN_Pos)    /*!< 0x00000008 */
#define RCC_APB1ENR_TIM5EN                 RCC_APB1ENR_TIM5EN_Msk              
#define RCC_APB1ENR_WWDGEN_Pos             (11U)                               
#define RCC_APB1ENR_WWDGEN_Msk             (0x1U << RCC_APB1ENR_WWDGEN_Pos)    /*!< 0x00000800 */
#define RCC_APB1ENR_WWDGEN                 RCC_APB1ENR_WWDGEN_Msk              
#define RCC_APB1ENR_SPI2EN_Pos             (14U)                               
#define RCC_APB1ENR_SPI2EN_Msk             (0x1U << RCC_APB1ENR_SPI2EN_Pos)    /*!< 0x00004000 */
#define RCC_APB1ENR_SPI2EN                 RCC_APB1ENR_SPI2EN_Msk              
#define RCC_APB1ENR_SPI3EN_Pos             (15U)                               
#define RCC_APB1ENR_SPI3EN_Msk             (0x1U << RCC_APB1ENR_SPI3EN_Pos)    /*!< 0x00008000 */
#define RCC_APB1ENR_SPI3EN                 RCC_APB1ENR_SPI3EN_Msk              
#define RCC_APB1ENR_USART2EN_Pos           (17U)                               
#define RCC_APB1ENR_USART2EN_Msk           (0x1U << RCC_APB1ENR_USART2EN_Pos)  /*!< 0x00020000 */
#define RCC_APB1ENR_USART2EN               RCC_APB1ENR_USART2EN_Msk            
#define RCC_APB1ENR_I2C1EN_Pos             (21U)                               
#define RCC_APB1ENR_I2C1EN_Msk             (0x1U << RCC_APB1ENR_I2C1EN_Pos)    /*!< 0x00200000 */
#define RCC_APB1ENR_I2C1EN                 RCC_APB1ENR_I2C1EN_Msk              
#define RCC_APB1ENR_I2C2EN_Pos             (22U)                               
#define RCC_APB1ENR_I2C2EN_Msk             (0x1U << RCC_APB1ENR_I2C2EN_Pos)    /*!< 0x00400000 */
#define RCC_APB1ENR_I2C2EN                 RCC_APB1ENR_I2C2EN_Msk              
#define RCC_APB1ENR_I2C3EN_Pos             (23U)                               
#define RCC_APB1ENR_I2C3EN_Msk             (0x1U << RCC_APB1ENR_I2C3EN_Pos)    /*!< 0x00800000 */
#define RCC_APB1ENR_I2C3EN                 RCC_APB1ENR_I2C3EN_Msk              
#define RCC_APB1ENR_PWREN_Pos              (28U)                               
#define RCC_APB1ENR_PWREN_Msk              (0x1U << RCC_APB1ENR_PWREN_Pos)     /*!< 0x10000000 */
#define RCC_APB1ENR_PWREN                  RCC_APB1ENR_PWREN_Msk               
/********************  Bit definition for RCC_APB2ENR register  ***************/
#define RCC_APB2ENR_TIM1EN_Pos             (0U)                                
#define RCC_APB2ENR_TIM1EN_Msk             (0x1U << RCC_APB2ENR_TIM1EN_Pos)    /*!< 0x00000001 */
#define RCC_APB2ENR_TIM1EN                 RCC_APB2ENR_TIM1EN_Msk              
#define RCC_APB2ENR_USART1EN_Pos           (4U)                                
#define RCC_APB2ENR_USART1EN_Msk           (0x1U << RCC_APB2ENR_USART1EN_Pos)  /*!< 0x00000010 */
#define RCC_APB2ENR_USART1EN               RCC_APB2ENR_USART1EN_Msk            
#define RCC_APB2ENR_USART6EN_Pos           (5U)                                
#define RCC_APB2ENR_USART6EN_Msk           (0x1U << RCC_APB2ENR_USART6EN_Pos)  /*!< 0x00000020 */
#define RCC_APB2ENR_USART6EN               RCC_APB2ENR_USART6EN_Msk            
#define RCC_APB2ENR_ADC1EN_Pos             (8U)                                
#define RCC_APB2ENR_ADC1EN_Msk             (0x1U << RCC_APB2ENR_ADC1EN_Pos)    /*!< 0x00000100 */
#define RCC_APB2ENR_ADC1EN                 RCC_APB2ENR_ADC1EN_Msk              
#define RCC_APB2ENR_SDIOEN_Pos             (11U)                               
#define RCC_APB2ENR_SDIOEN_Msk             (0x1U << RCC_APB2ENR_SDIOEN_Pos)    /*!< 0x00000800 */
#define RCC_APB2ENR_SDIOEN                 RCC_APB2ENR_SDIOEN_Msk              
#define RCC_APB2ENR_SPI1EN_Pos             (12U)                               
#define RCC_APB2ENR_SPI1EN_Msk             (0x1U << RCC_APB2ENR_SPI1EN_Pos)    /*!< 0x00001000 */
#define RCC_APB2ENR_SPI1EN                 RCC_APB2ENR_SPI1EN_Msk              
#define RCC_APB2ENR_SPI4EN_Pos             (13U)                               
#define RCC_APB2ENR_SPI4EN_Msk             (0x1U << RCC_APB2ENR_SPI4EN_Pos)    /*!< 0x00002000 */
#define RCC_APB2ENR_SPI4EN                 RCC_APB2ENR_SPI4EN_Msk              
#define RCC_APB2ENR_SYSCFGEN_Pos           (14U)                               
#define RCC_APB2ENR_SYSCFGEN_Msk           (0x1U << RCC_APB2ENR_SYSCFGEN_Pos)  /*!< 0x00004000 */
#define RCC_APB2ENR_SYSCFGEN               RCC_APB2ENR_SYSCFGEN_Msk            
#define RCC_APB2ENR_TIM9EN_Pos             (16U)                               
#define RCC_APB2ENR_TIM9EN_Msk             (0x1U << RCC_APB2ENR_TIM9EN_Pos)    /*!< 0x00010000 */
#define RCC_APB2ENR_TIM9EN                 RCC_APB2ENR_TIM9EN_Msk              
#define RCC_APB2ENR_TIM10EN_Pos            (17U)                               
#define RCC_APB2ENR_TIM10EN_Msk            (0x1U << RCC_APB2ENR_TIM10EN_Pos)   /*!< 0x00020000 */
#define RCC_APB2ENR_TIM10EN                RCC_APB2ENR_TIM10EN_Msk             
#define RCC_APB2ENR_TIM11EN_Pos            (18U)                               
#define RCC_APB2ENR_TIM11EN_Msk            (0x1U << RCC_APB2ENR_TIM11EN_Pos)   /*!< 0x00040000 */
#define RCC_APB2ENR_TIM11EN                RCC_APB2ENR_TIM11EN_Msk             
#define RCC_APB2ENR_SPI5EN_Pos             (20U)                               
#define RCC_APB2ENR_SPI5EN_Msk             (0x1U << RCC_APB2ENR_SPI5EN_Pos)    /*!< 0x00100000 */
#define RCC_APB2ENR_SPI5EN                 RCC_APB2ENR_SPI5EN_Msk              
/********************  Bit definition for RCC_AHB1LPENR register  *************/
#define RCC_AHB1LPENR_GPIOALPEN_Pos        (0U)                                
#define RCC_AHB1LPENR_GPIOALPEN_Msk        (0x1U << RCC_AHB1LPENR_GPIOALPEN_Pos) /*!< 0x00000001 */
#define RCC_AHB1LPENR_GPIOALPEN            RCC_AHB1LPENR_GPIOALPEN_Msk         
#define RCC_AHB1LPENR_GPIOBLPEN_Pos        (1U)                                
#define RCC_AHB1LPENR_GPIOBLPEN_Msk        (0x1U << RCC_AHB1LPENR_GPIOBLPEN_Pos) /*!< 0x00000002 */
#define RCC_AHB1LPENR_GPIOBLPEN            RCC_AHB1LPENR_GPIOBLPEN_Msk         
#define RCC_AHB1LPENR_GPIOCLPEN_Pos        (2U)                                
#define RCC_AHB1LPENR_GPIOCLPEN_Msk        (0x1U << RCC_AHB1LPENR_GPIOCLPEN_Pos) /*!< 0x00000004 */
#define RCC_AHB1LPENR_GPIOCLPEN            RCC_AHB1LPENR_GPIOCLPEN_Msk         
#define RCC_AHB1LPENR_GPIODLPEN_Pos        (3U)                                
#define RCC_AHB1LPENR_GPIODLPEN_Msk        (0x1U << RCC_AHB1LPENR_GPIODLPEN_Pos) /*!< 0x00000008 */
#define RCC_AHB1LPENR_GPIODLPEN            RCC_AHB1LPENR_GPIODLPEN_Msk         
#define RCC_AHB1LPENR_GPIOELPEN_Pos        (4U)                                
#define RCC_AHB1LPENR_GPIOELPEN_Msk        (0x1U << RCC_AHB1LPENR_GPIOELPEN_Pos) /*!< 0x00000010 */
#define RCC_AHB1LPENR_GPIOELPEN            RCC_AHB1LPENR_GPIOELPEN_Msk         
#define RCC_AHB1LPENR_GPIOHLPEN_Pos        (7U)                                
#define RCC_AHB1LPENR_GPIOHLPEN_Msk        (0x1U << RCC_AHB1LPENR_GPIOHLPEN_Pos) /*!< 0x00000080 */
#define RCC_AHB1LPENR_GPIOHLPEN            RCC_AHB1LPENR_GPIOHLPEN_Msk         
#define RCC_AHB1LPENR_CRCLPEN_Pos          (12U)                               
#define RCC_AHB1LPENR_CRCLPEN_Msk          (0x1U << RCC_AHB1LPENR_CRCLPEN_Pos) /*!< 0x00001000 */
#define RCC_AHB1LPENR_CRCLPEN              RCC_AHB1LPENR_CRCLPEN_Msk           
#define RCC_AHB1LPENR_FLITFLPEN_Pos        (15U)                               
#define RCC_AHB1LPENR_FLITFLPEN_Msk        (0x1U << RCC_AHB1LPENR_FLITFLPEN_Pos) /*!< 0x00008000 */
#define RCC_AHB1LPENR_FLITFLPEN            RCC_AHB1LPENR_FLITFLPEN_Msk         
#define RCC_AHB1LPENR_SRAM1LPEN_Pos        (16U)                               
#define RCC_AHB1LPENR_SRAM1LPEN_Msk        (0x1U << RCC_AHB1LPENR_SRAM1LPEN_Pos) /*!< 0x00010000 */
#define RCC_AHB1LPENR_SRAM1LPEN            RCC_AHB1LPENR_SRAM1LPEN_Msk         
#define RCC_AHB1LPENR_DMA1LPEN_Pos         (21U)                               
#define RCC_AHB1LPENR_DMA1LPEN_Msk         (0x1U << RCC_AHB1LPENR_DMA1LPEN_Pos) /*!< 0x00200000 */
#define RCC_AHB1LPENR_DMA1LPEN             RCC_AHB1LPENR_DMA1LPEN_Msk          
#define RCC_AHB1LPENR_DMA2LPEN_Pos         (22U)                               
#define RCC_AHB1LPENR_DMA2LPEN_Msk         (0x1U << RCC_AHB1LPENR_DMA2LPEN_Pos) /*!< 0x00400000 */
#define RCC_AHB1LPENR_DMA2LPEN             RCC_AHB1LPENR_DMA2LPEN_Msk          
/********************  Bit definition for RCC_AHB2LPENR register  *************/
#define RCC_AHB2LPENR_OTGFSLPEN_Pos        (7U)                                
#define RCC_AHB2LPENR_OTGFSLPEN_Msk        (0x1U << RCC_AHB2LPENR_OTGFSLPEN_Pos) /*!< 0x00000080 */
#define RCC_AHB2LPENR_OTGFSLPEN            RCC_AHB2LPENR_OTGFSLPEN_Msk         
/********************  Bit definition for RCC_AHB3LPENR register  *************/
/********************  Bit definition for RCC_APB1LPENR register  *************/
#define RCC_APB1LPENR_TIM2LPEN_Pos         (0U)                                
#define RCC_APB1LPENR_TIM2LPEN_Msk         (0x1U << RCC_APB1LPENR_TIM2LPEN_Pos) /*!< 0x00000001 */
#define RCC_APB1LPENR_TIM2LPEN             RCC_APB1LPENR_TIM2LPEN_Msk          
#define RCC_APB1LPENR_TIM3LPEN_Pos         (1U)                                
#define RCC_APB1LPENR_TIM3LPEN_Msk         (0x1U << RCC_APB1LPENR_TIM3LPEN_Pos) /*!< 0x00000002 */
#define RCC_APB1LPENR_TIM3LPEN             RCC_APB1LPENR_TIM3LPEN_Msk          
#define RCC_APB1LPENR_TIM4LPEN_Pos         (2U)                                
#define RCC_APB1LPENR_TIM4LPEN_Msk         (0x1U << RCC_APB1LPENR_TIM4LPEN_Pos) /*!< 0x00000004 */
#define RCC_APB1LPENR_TIM4LPEN             RCC_APB1LPENR_TIM4LPEN_Msk          
#define RCC_APB1LPENR_TIM5LPEN_Pos         (3U)                                
#define RCC_APB1LPENR_TIM5LPEN_Msk         (0x1U << RCC_APB1LPENR_TIM5LPEN_Pos) /*!< 0x00000008 */
#define RCC_APB1LPENR_TIM5LPEN             RCC_APB1LPENR_TIM5LPEN_Msk          
#define RCC_APB1LPENR_WWDGLPEN_Pos         (11U)                               
#define RCC_APB1LPENR_WWDGLPEN_Msk         (0x1U << RCC_APB1LPENR_WWDGLPEN_Pos) /*!< 0x00000800 */
#define RCC_APB1LPENR_WWDGLPEN             RCC_APB1LPENR_WWDGLPEN_Msk          
#define RCC_APB1LPENR_SPI2LPEN_Pos         (14U)                               
#define RCC_APB1LPENR_SPI2LPEN_Msk         (0x1U << RCC_APB1LPENR_SPI2LPEN_Pos) /*!< 0x00004000 */
#define RCC_APB1LPENR_SPI2LPEN             RCC_APB1LPENR_SPI2LPEN_Msk          
#define RCC_APB1LPENR_SPI3LPEN_Pos         (15U)                               
#define RCC_APB1LPENR_SPI3LPEN_Msk         (0x1U << RCC_APB1LPENR_SPI3LPEN_Pos) /*!< 0x00008000 */
#define RCC_APB1LPENR_SPI3LPEN             RCC_APB1LPENR_SPI3LPEN_Msk          
#define RCC_APB1LPENR_USART2LPEN_Pos       (17U)                               
#define RCC_APB1LPENR_USART2LPEN_Msk       (0x1U << RCC_APB1LPENR_USART2LPEN_Pos) /*!< 0x00020000 */
#define RCC_APB1LPENR_USART2LPEN           RCC_APB1LPENR_USART2LPEN_Msk        
#define RCC_APB1LPENR_I2C1LPEN_Pos         (21U)                               
#define RCC_APB1LPENR_I2C1LPEN_Msk         (0x1U << RCC_APB1LPENR_I2C1LPEN_Pos) /*!< 0x00200000 */
#define RCC_APB1LPENR_I2C1LPEN             RCC_APB1LPENR_I2C1LPEN_Msk          
#define RCC_APB1LPENR_I2C2LPEN_Pos         (22U)                               
#define RCC_APB1LPENR_I2C2LPEN_Msk         (0x1U << RCC_APB1LPENR_I2C2LPEN_Pos) /*!< 0x00400000 */
#define RCC_APB1LPENR_I2C2LPEN             RCC_APB1LPENR_I2C2LPEN_Msk          
#define RCC_APB1LPENR_I2C3LPEN_Pos         (23U)                               
#define RCC_APB1LPENR_I2C3LPEN_Msk         (0x1U << RCC_APB1LPENR_I2C3LPEN_Pos) /*!< 0x00800000 */
#define RCC_APB1LPENR_I2C3LPEN             RCC_APB1LPENR_I2C3LPEN_Msk          
#define RCC_APB1LPENR_PWRLPEN_Pos          (28U)                               
#define RCC_APB1LPENR_PWRLPEN_Msk          (0x1U << RCC_APB1LPENR_PWRLPEN_Pos) /*!< 0x10000000 */
#define RCC_APB1LPENR_PWRLPEN              RCC_APB1LPENR_PWRLPEN_Msk           
/********************  Bit definition for RCC_APB2LPENR register  *************/
#define RCC_APB2LPENR_TIM1LPEN_Pos         (0U)                                
#define RCC_APB2LPENR_TIM1LPEN_Msk         (0x1U << RCC_APB2LPENR_TIM1LPEN_Pos) /*!< 0x00000001 */
#define RCC_APB2LPENR_TIM1LPEN             RCC_APB2LPENR_TIM1LPEN_Msk          
#define RCC_APB2LPENR_USART1LPEN_Pos       (4U)                                
#define RCC_APB2LPENR_USART1LPEN_Msk       (0x1U << RCC_APB2LPENR_USART1LPEN_Pos) /*!< 0x00000010 */
#define RCC_APB2LPENR_USART1LPEN           RCC_APB2LPENR_USART1LPEN_Msk        
#define RCC_APB2LPENR_USART6LPEN_Pos       (5U)                                
#define RCC_APB2LPENR_USART6LPEN_Msk       (0x1U << RCC_APB2LPENR_USART6LPEN_Pos) /*!< 0x00000020 */
#define RCC_APB2LPENR_USART6LPEN           RCC_APB2LPENR_USART6LPEN_Msk        
#define RCC_APB2LPENR_ADC1LPEN_Pos         (8U)                                
#define RCC_APB2LPENR_ADC1LPEN_Msk         (0x1U << RCC_APB2LPENR_ADC1LPEN_Pos) /*!< 0x00000100 */
#define RCC_APB2LPENR_ADC1LPEN             RCC_APB2LPENR_ADC1LPEN_Msk          
#define RCC_APB2LPENR_SDIOLPEN_Pos         (11U)                               
#define RCC_APB2LPENR_SDIOLPEN_Msk         (0x1U << RCC_APB2LPENR_SDIOLPEN_Pos) /*!< 0x00000800 */
#define RCC_APB2LPENR_SDIOLPEN             RCC_APB2LPENR_SDIOLPEN_Msk          
#define RCC_APB2LPENR_SPI1LPEN_Pos         (12U)                               
#define RCC_APB2LPENR_SPI1LPEN_Msk         (0x1U << RCC_APB2LPENR_SPI1LPEN_Pos) /*!< 0x00001000 */
#define RCC_APB2LPENR_SPI1LPEN             RCC_APB2LPENR_SPI1LPEN_Msk          
#define RCC_APB2LPENR_SPI4LPEN_Pos         (13U)                               
#define RCC_APB2LPENR_SPI4LPEN_Msk         (0x1U << RCC_APB2LPENR_SPI4LPEN_Pos) /*!< 0x00002000 */
#define RCC_APB2LPENR_SPI4LPEN             RCC_APB2LPENR_SPI4LPEN_Msk          
#define RCC_APB2LPENR_SYSCFGLPEN_Pos       (14U)                               
#define RCC_APB2LPENR_SYSCFGLPEN_Msk       (0x1U << RCC_APB2LPENR_SYSCFGLPEN_Pos) /*!< 0x00004000 */
#define RCC_APB2LPENR_SYSCFGLPEN           RCC_APB2LPENR_SYSCFGLPEN_Msk        
#define RCC_APB2LPENR_TIM9LPEN_Pos         (16U)                               
#define RCC_APB2LPENR_TIM9LPEN_Msk         (0x1U << RCC_APB2LPENR_TIM9LPEN_Pos) /*!< 0x00010000 */
#define RCC_APB2LPENR_TIM9LPEN             RCC_APB2LPENR_TIM9LPEN_Msk          
#define RCC_APB2LPENR_TIM10LPEN_Pos        (17U)                               
#define RCC_APB2LPENR_TIM10LPEN_Msk        (0x1U << RCC_APB2LPENR_TIM10LPEN_Pos) /*!< 0x00020000 */
#define RCC_APB2LPENR_TIM10LPEN            RCC_APB2LPENR_TIM10LPEN_Msk         
#define RCC_APB2LPENR_TIM11LPEN_Pos        (18U)                               
#define RCC_APB2LPENR_TIM11LPEN_Msk        (0x1U << RCC_APB2LPENR_TIM11LPEN_Pos) /*!< 0x00040000 */
#define RCC_APB2LPENR_TIM11LPEN            RCC_APB2LPENR_TIM11LPEN_Msk         
#define RCC_APB2LPENR_SPI5LPEN_Pos         (20U)                               
#define RCC_APB2LPENR_SPI5LPEN_Msk         (0x1U << RCC_APB2LPENR_SPI5LPEN_Pos) /*!< 0x00100000 */
#define RCC_APB2LPENR_SPI5LPEN             RCC_APB2LPENR_SPI5LPEN_Msk          
/********************  Bit definition for RCC_BDCR register  ******************/
#define RCC_BDCR_LSEON_Pos                 (0U)                                
#define RCC_BDCR_LSEON_Msk                 (0x1U << RCC_BDCR_LSEON_Pos)        /*!< 0x00000001 */
#define RCC_BDCR_LSEON                     RCC_BDCR_LSEON_Msk                  
#define RCC_BDCR_LSERDY_Pos                (1U)                                
#define RCC_BDCR_LSERDY_Msk                (0x1U << RCC_BDCR_LSERDY_Pos)       /*!< 0x00000002 */
#define RCC_BDCR_LSERDY                    RCC_BDCR_LSERDY_Msk                 
#define RCC_BDCR_LSEBYP_Pos                (2U)                                
#define RCC_BDCR_LSEBYP_Msk                (0x1U << RCC_BDCR_LSEBYP_Pos)       /*!< 0x00000004 */
#define RCC_BDCR_LSEBYP                    RCC_BDCR_LSEBYP_Msk                 
#define RCC_BDCR_LSEMOD_Pos                (3U)                                
#define RCC_BDCR_LSEMOD_Msk                (0x1U << RCC_BDCR_LSEMOD_Pos)       /*!< 0x00000008 */
#define RCC_BDCR_LSEMOD                    RCC_BDCR_LSEMOD_Msk                 
#define RCC_BDCR_RTCSEL_Pos                (8U)                                
#define RCC_BDCR_RTCSEL_Msk                (0x3U << RCC_BDCR_RTCSEL_Pos)       /*!< 0x00000300 */
#define RCC_BDCR_RTCSEL                    RCC_BDCR_RTCSEL_Msk                 
#define RCC_BDCR_RTCSEL_0                  (0x1U << RCC_BDCR_RTCSEL_Pos)       /*!< 0x00000100 */
#define RCC_BDCR_RTCSEL_1                  (0x2U << RCC_BDCR_RTCSEL_Pos)       /*!< 0x00000200 */
#define RCC_BDCR_RTCEN_Pos                 (15U)                               
#define RCC_BDCR_RTCEN_Msk                 (0x1U << RCC_BDCR_RTCEN_Pos)        /*!< 0x00008000 */
#define RCC_BDCR_RTCEN                     RCC_BDCR_RTCEN_Msk                  
#define RCC_BDCR_BDRST_Pos                 (16U)                               
#define RCC_BDCR_BDRST_Msk                 (0x1U << RCC_BDCR_BDRST_Pos)        /*!< 0x00010000 */
#define RCC_BDCR_BDRST                     RCC_BDCR_BDRST_Msk                  
/********************  Bit definition for RCC_CSR register  *******************/
#define RCC_CSR_LSION_Pos                  (0U)                                
#define RCC_CSR_LSION_Msk                  (0x1U << RCC_CSR_LSION_Pos)         /*!< 0x00000001 */
#define RCC_CSR_LSION                      RCC_CSR_LSION_Msk                   
#define RCC_CSR_LSIRDY_Pos                 (1U)                                
#define RCC_CSR_LSIRDY_Msk                 (0x1U << RCC_CSR_LSIRDY_Pos)        /*!< 0x00000002 */
#define RCC_CSR_LSIRDY                     RCC_CSR_LSIRDY_Msk                  
#define RCC_CSR_RMVF_Pos                   (24U)                               
#define RCC_CSR_RMVF_Msk                   (0x1U << RCC_CSR_RMVF_Pos)          /*!< 0x01000000 */
#define RCC_CSR_RMVF                       RCC_CSR_RMVF_Msk                    
#define RCC_CSR_BORRSTF_Pos                (25U)                               
#define RCC_CSR_BORRSTF_Msk                (0x1U << RCC_CSR_BORRSTF_Pos)       /*!< 0x02000000 */
#define RCC_CSR_BORRSTF                    RCC_CSR_BORRSTF_Msk                 
#define RCC_CSR_PINRSTF_Pos                (26U)
#define RCC_CSR_PINRSTF_Msk                (0x1U << RCC_CSR_PINRSTF_Pos)       /*!< 0x04000000 */
#define RCC_CSR_PINRSTF                    RCC_CSR_PINRSTF_Msk
#define RCC_CSR_PORRSTF_Pos                (27U)                               
#define RCC_CSR_PORRSTF_Msk                (0x1U << RCC_CSR_PORRSTF_Pos)       /*!< 0x08000000 */
#define RCC_CSR_PORRSTF                    RCC_CSR_PORRSTF_Msk                 
#define RCC_CSR_SFTRSTF_Pos                (28U)                               
#define RCC_CSR_SFTRSTF_Msk                (0x1U << RCC_CSR_SFTRSTF_Pos)       /*!< 0x10000000 */
#define RCC_CSR_SFTRSTF                    RCC_CSR_SFTRSTF_Msk                 
#define RCC_CSR_IWDGRSTF_Pos               (29U)
#define RCC_CSR_IWDGRSTF_Msk               (0x1U << RCC_CSR_IWDGRSTF_Pos)      /*!< 0x20000000 */
#define RCC_CSR_IWDGRSTF                   RCC_CSR_IWDGRSTF_Msk
#define RCC_CSR_WWDGRSTF_Pos               (30U)                               
#define RCC_CSR_WWDGRSTF_Msk               (0x1U << RCC_CSR_WWDGRSTF_Pos)      /*!< 0x40000000 */
#define RCC_CSR_WWDGRSTF                   RCC_CSR_WWDGRSTF_Msk                
#define RCC_CSR_LPWRRSTF_Pos               (31U)                               
#define RCC_CSR_LPWRRSTF_Msk               (0x1U << RCC_CSR_LPWRRSTF_Pos)      /*!< 0x80000000 */
#define RCC_CSR_LPWRRSTF                   RCC_CSR_LPWRRSTF_Msk
/* Legacy defines */
#define RCC_CSR_PADRSTF                    RCC_CSR_PINRSTF
#define RCC_CSR_WDGRSTF                    RCC_CSR_IWDGRSTF
/********************  Bit definition for RCC_SSCGR register  *****************/
#define RCC_SSCGR_MODPER_Pos               (0U)                                
#define RCC_SSCGR_MODPER_Msk               (0x1FFFU << RCC_SSCGR_MODPER_Pos)   /*!< 0x00001FFF */
#define RCC_SSCGR_MODPER                   RCC_SSCGR_MODPER_Msk                
#define RCC_SSCGR_INCSTEP_Pos              (13U)                               
#define RCC_SSCGR_INCSTEP_Msk              (0x7FFFU << RCC_SSCGR_INCSTEP_Pos)  /*!< 0x0FFFE000 */
#define RCC_SSCGR_INCSTEP                  RCC_SSCGR_INCSTEP_Msk               
#define RCC_SSCGR_SPREADSEL_Pos            (30U)                               
#define RCC_SSCGR_SPREADSEL_Msk            (0x1U << RCC_SSCGR_SPREADSEL_Pos)   /*!< 0x40000000 */
#define RCC_SSCGR_SPREADSEL                RCC_SSCGR_SPREADSEL_Msk             
#define RCC_SSCGR_SSCGEN_Pos               (31U)                               
#define RCC_SSCGR_SSCGEN_Msk               (0x1U << RCC_SSCGR_SSCGEN_Pos)      /*!< 0x80000000 */
#define RCC_SSCGR_SSCGEN                   RCC_SSCGR_SSCGEN_Msk                
/********************  Bit definition for RCC_PLLI2SCFGR register  ************/
#define RCC_PLLI2SCFGR_PLLI2SM_Pos         (0U)                                
#define RCC_PLLI2SCFGR_PLLI2SM_Msk         (0x3FU << RCC_PLLI2SCFGR_PLLI2SM_Pos) /*!< 0x0000003F */
#define RCC_PLLI2SCFGR_PLLI2SM             RCC_PLLI2SCFGR_PLLI2SM_Msk          
#define RCC_PLLI2SCFGR_PLLI2SM_0           (0x01U << RCC_PLLI2SCFGR_PLLI2SM_Pos) /*!< 0x00000001 */
#define RCC_PLLI2SCFGR_PLLI2SM_1           (0x02U << RCC_PLLI2SCFGR_PLLI2SM_Pos) /*!< 0x00000002 */
#define RCC_PLLI2SCFGR_PLLI2SM_2           (0x04U << RCC_PLLI2SCFGR_PLLI2SM_Pos) /*!< 0x00000004 */
#define RCC_PLLI2SCFGR_PLLI2SM_3           (0x08U << RCC_PLLI2SCFGR_PLLI2SM_Pos) /*!< 0x00000008 */
#define RCC_PLLI2SCFGR_PLLI2SM_4           (0x10U << RCC_PLLI2SCFGR_PLLI2SM_Pos) /*!< 0x00000010 */
#define RCC_PLLI2SCFGR_PLLI2SM_5           (0x20U << RCC_PLLI2SCFGR_PLLI2SM_Pos) /*!< 0x00000020 */
#define RCC_PLLI2SCFGR_PLLI2SN_Pos         (6U)                                
#define RCC_PLLI2SCFGR_PLLI2SN_Msk         (0x1FFU << RCC_PLLI2SCFGR_PLLI2SN_Pos) /*!< 0x00007FC0 */
#define RCC_PLLI2SCFGR_PLLI2SN             RCC_PLLI2SCFGR_PLLI2SN_Msk          
#define RCC_PLLI2SCFGR_PLLI2SN_0           (0x001U << RCC_PLLI2SCFGR_PLLI2SN_Pos) /*!< 0x00000040 */
#define RCC_PLLI2SCFGR_PLLI2SN_1           (0x002U << RCC_PLLI2SCFGR_PLLI2SN_Pos) /*!< 0x00000080 */
#define RCC_PLLI2SCFGR_PLLI2SN_2           (0x004U << RCC_PLLI2SCFGR_PLLI2SN_Pos) /*!< 0x00000100 */
#define RCC_PLLI2SCFGR_PLLI2SN_3           (0x008U << RCC_PLLI2SCFGR_PLLI2SN_Pos) /*!< 0x00000200 */
#define RCC_PLLI2SCFGR_PLLI2SN_4           (0x010U << RCC_PLLI2SCFGR_PLLI2SN_Pos) /*!< 0x00000400 */
#define RCC_PLLI2SCFGR_PLLI2SN_5           (0x020U << RCC_PLLI2SCFGR_PLLI2SN_Pos) /*!< 0x00000800 */
#define RCC_PLLI2SCFGR_PLLI2SN_6           (0x040U << RCC_PLLI2SCFGR_PLLI2SN_Pos) /*!< 0x00001000 */
#define RCC_PLLI2SCFGR_PLLI2SN_7           (0x080U << RCC_PLLI2SCFGR_PLLI2SN_Pos) /*!< 0x00002000 */
#define RCC_PLLI2SCFGR_PLLI2SN_8           (0x100U << RCC_PLLI2SCFGR_PLLI2SN_Pos) /*!< 0x00004000 */
#define RCC_PLLI2SCFGR_PLLI2SR_Pos         (28U)                               
#define RCC_PLLI2SCFGR_PLLI2SR_Msk         (0x7U << RCC_PLLI2SCFGR_PLLI2SR_Pos) /*!< 0x70000000 */
#define RCC_PLLI2SCFGR_PLLI2SR             RCC_PLLI2SCFGR_PLLI2SR_Msk          
#define RCC_PLLI2SCFGR_PLLI2SR_0           (0x1U << RCC_PLLI2SCFGR_PLLI2SR_Pos) /*!< 0x10000000 */
#define RCC_PLLI2SCFGR_PLLI2SR_1           (0x2U << RCC_PLLI2SCFGR_PLLI2SR_Pos) /*!< 0x20000000 */
#define RCC_PLLI2SCFGR_PLLI2SR_2           (0x4U << RCC_PLLI2SCFGR_PLLI2SR_Pos) /*!< 0x40000000 */
/********************  Bit definition for RCC_DCKCFGR register  ***************/
#define RCC_DCKCFGR_TIMPRE_Pos             (24U)                               
#define RCC_DCKCFGR_TIMPRE_Msk             (0x1U << RCC_DCKCFGR_TIMPRE_Pos)    /*!< 0x01000000 */
#define RCC_DCKCFGR_TIMPRE                 RCC_DCKCFGR_TIMPRE_Msk              

#endif /* __STM32F4xx_HAL_RCC_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
