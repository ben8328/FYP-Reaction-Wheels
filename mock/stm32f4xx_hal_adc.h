/**
  ******************************************************************************
  * @file    stm32f4xx_hal_adc.h
  * @author  MCD Application Team
  * @brief   Header file containing functions prototypes of ADC HAL library.
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
#ifndef __STM32F4xx_ADC_H
#define __STM32F4xx_ADC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
// #include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_def.h"

/** @addtogroup STM32F4xx_HAL_Driver
  * @{
  */

/** @addtogroup ADC
  * @{
  */ 

/** 
  * @brief Analog to Digital Converter  
  */

typedef struct
{
  __IO uint32_t SR;     /*!< ADC status register,                         Address offset: 0x00 */
  __IO uint32_t CR1;    /*!< ADC control register 1,                      Address offset: 0x04 */
  __IO uint32_t CR2;    /*!< ADC control register 2,                      Address offset: 0x08 */
  __IO uint32_t SMPR1;  /*!< ADC sample time register 1,                  Address offset: 0x0C */
  __IO uint32_t SMPR2;  /*!< ADC sample time register 2,                  Address offset: 0x10 */
  __IO uint32_t JOFR1;  /*!< ADC injected channel data offset register 1, Address offset: 0x14 */
  __IO uint32_t JOFR2;  /*!< ADC injected channel data offset register 2, Address offset: 0x18 */
  __IO uint32_t JOFR3;  /*!< ADC injected channel data offset register 3, Address offset: 0x1C */
  __IO uint32_t JOFR4;  /*!< ADC injected channel data offset register 4, Address offset: 0x20 */
  __IO uint32_t HTR;    /*!< ADC watchdog higher threshold register,      Address offset: 0x24 */
  __IO uint32_t LTR;    /*!< ADC watchdog lower threshold register,       Address offset: 0x28 */
  __IO uint32_t SQR1;   /*!< ADC regular sequence register 1,             Address offset: 0x2C */
  __IO uint32_t SQR2;   /*!< ADC regular sequence register 2,             Address offset: 0x30 */
  __IO uint32_t SQR3;   /*!< ADC regular sequence register 3,             Address offset: 0x34 */
  __IO uint32_t JSQR;   /*!< ADC injected sequence register,              Address offset: 0x38*/
  __IO uint32_t JDR1;   /*!< ADC injected data register 1,                Address offset: 0x3C */
  __IO uint32_t JDR2;   /*!< ADC injected data register 2,                Address offset: 0x40 */
  __IO uint32_t JDR3;   /*!< ADC injected data register 3,                Address offset: 0x44 */
  __IO uint32_t JDR4;   /*!< ADC injected data register 4,                Address offset: 0x48 */
  __IO uint32_t DR;     /*!< ADC regular data register,                   Address offset: 0x4C */
} ADC_TypeDef;

typedef struct
{
  __IO uint32_t CSR;    /*!< ADC Common status register,                  Address offset: ADC1 base address + 0x300 */
  __IO uint32_t CCR;    /*!< ADC common control register,                 Address offset: ADC1 base address + 0x304 */
  __IO uint32_t CDR;    /*!< ADC common regular data register for dual
                             AND triple modes,                            Address offset: ADC1 base address + 0x308 */
} ADC_Common_TypeDef;
extern ADC_Common_TypeDef ADC1_COMMON_BASE_spy;
extern ADC_Common_TypeDef ADC1123_COMMON_BASE_spy;
#define ADC1_COMMON         ((ADC_Common_TypeDef *) &ADC1_COMMON_BASE_spy)
#define ADC123_COMMON         ((ADC_Common_TypeDef *) &ADC123_COMMON_BASE_spy)


/* Exported types ------------------------------------------------------------*/
/** @defgroup ADC_Exported_Types ADC Exported Types
  * @{
  */

/** 
  * @brief  Structure definition of ADC and regular group initialization 
  * @note   Parameters of this structure are shared within 2 scopes:
  *          - Scope entire ADC (affects regular and injected groups): ClockPrescaler, Resolution, ScanConvMode, DataAlign, ScanConvMode, EOCSelection, LowPowerAutoWait, LowPowerAutoPowerOff, ChannelsBank.
  *          - Scope regular group: ContinuousConvMode, NbrOfConversion, DiscontinuousConvMode, NbrOfDiscConversion, ExternalTrigConvEdge, ExternalTrigConv.
  * @note   The setting of these parameters with function HAL_ADC_Init() is conditioned to ADC state.
  *         ADC state can be either:
  *          - For all parameters: ADC disabled
  *          - For all parameters except 'Resolution', 'ScanConvMode', 'DiscontinuousConvMode', 'NbrOfDiscConversion' : ADC enabled without conversion on going on regular group.
  *          - For parameters 'ExternalTrigConv' and 'ExternalTrigConvEdge': ADC enabled, even with conversion on going.
  *         If ADC is not in the appropriate state to modify some parameters, these parameters setting is bypassed
  *         without error reporting (as it can be the expected behaviour in case of intended action to update another parameter (which fulfills the ADC state condition) on the fly).
  */
typedef struct
{
  uint32_t ClockPrescaler;        /*!< Select ADC clock prescaler. The clock is common for 
                                       all the ADCs.
                                       This parameter can be a value of @ref ADC_ClockPrescaler */
  uint32_t Resolution;            /*!< Configures the ADC resolution.
                                       This parameter can be a value of @ref ADC_Resolution */
  uint32_t DataAlign;             /*!< Specifies ADC data alignment to right (MSB on register bit 11 and LSB on register bit 0) (default setting)
                                       or to left (if regular group: MSB on register bit 15 and LSB on register bit 4, if injected group (MSB kept as signed value due to potential negative value after offset application): MSB on register bit 14 and LSB on register bit 3).
                                       This parameter can be a value of @ref ADC_Data_align */
  uint32_t ScanConvMode;          /*!< Configures the sequencer of regular and injected groups.
                                       This parameter can be associated to parameter 'DiscontinuousConvMode' to have main sequence subdivided in successive parts.
                                       If disabled: Conversion is performed in single mode (one channel converted, the one defined in rank 1).
                                                    Parameters 'NbrOfConversion' and 'InjectedNbrOfConversion' are discarded (equivalent to set to 1).
                                       If enabled:  Conversions are performed in sequence mode (multiple ranks defined by 'NbrOfConversion'/'InjectedNbrOfConversion' and each channel rank).
                                                    Scan direction is upward: from rank1 to rank 'n'.
                                       This parameter can be set to ENABLE or DISABLE */
  uint32_t EOCSelection;          /*!< Specifies what EOC (End Of Conversion) flag is used for conversion by polling and interruption: end of conversion of each rank or complete sequence.
                                       This parameter can be a value of @ref ADC_EOCSelection.
                                       Note: For injected group, end of conversion (flag&IT) is raised only at the end of the sequence.
                                             Therefore, if end of conversion is set to end of each conversion, injected group should not be used with interruption (HAL_ADCEx_InjectedStart_IT)
                                             or polling (HAL_ADCEx_InjectedStart and HAL_ADCEx_InjectedPollForConversion). By the way, polling is still possible since driver will use an estimated timing for end of injected conversion.
                                       Note: If overrun feature is intended to be used, use ADC in mode 'interruption' (function HAL_ADC_Start_IT() ) with parameter EOCSelection set to end of each conversion or in mode 'transfer by DMA' (function HAL_ADC_Start_DMA()).
                                             If overrun feature is intended to be bypassed, use ADC in mode 'polling' or 'interruption' with parameter EOCSelection must be set to end of sequence */
  uint32_t ContinuousConvMode;    /*!< Specifies whether the conversion is performed in single mode (one conversion) or continuous mode for regular group,
                                       after the selected trigger occurred (software start or external trigger).
                                       This parameter can be set to ENABLE or DISABLE. */
  uint32_t NbrOfConversion;       /*!< Specifies the number of ranks that will be converted within the regular group sequencer.
                                       To use regular group sequencer and convert several ranks, parameter 'ScanConvMode' must be enabled.
                                       This parameter must be a number between Min_Data = 1 and Max_Data = 16. */
  uint32_t DiscontinuousConvMode; /*!< Specifies whether the conversions sequence of regular group is performed in Complete-sequence/Discontinuous-sequence (main sequence subdivided in successive parts).
                                       Discontinuous mode is used only if sequencer is enabled (parameter 'ScanConvMode'). If sequencer is disabled, this parameter is discarded.
                                       Discontinuous mode can be enabled only if continuous mode is disabled. If continuous mode is enabled, this parameter setting is discarded.
                                       This parameter can be set to ENABLE or DISABLE. */
  uint32_t NbrOfDiscConversion;   /*!< Specifies the number of discontinuous conversions in which the  main sequence of regular group (parameter NbrOfConversion) will be subdivided.
                                       If parameter 'DiscontinuousConvMode' is disabled, this parameter is discarded.
                                       This parameter must be a number between Min_Data = 1 and Max_Data = 8. */
  uint32_t ExternalTrigConv;      /*!< Selects the external event used to trigger the conversion start of regular group.
                                       If set to ADC_SOFTWARE_START, external triggers are disabled.
                                       If set to external trigger source, triggering is on event rising edge by default.
                                       This parameter can be a value of @ref ADC_External_trigger_Source_Regular */
  uint32_t ExternalTrigConvEdge;  /*!< Selects the external trigger edge of regular group.
                                       If trigger is set to ADC_SOFTWARE_START, this parameter is discarded.
                                       This parameter can be a value of @ref ADC_External_trigger_edge_Regular */
  uint32_t DMAContinuousRequests; /*!< Specifies whether the DMA requests are performed in one shot mode (DMA transfer stop when number of conversions is reached)
                                       or in Continuous mode (DMA transfer unlimited, whatever number of conversions).
                                       Note: In continuous mode, DMA must be configured in circular mode. Otherwise an overrun will be triggered when DMA buffer maximum pointer is reached.
                                       Note: This parameter must be modified when no conversion is on going on both regular and injected groups (ADC disabled, or ADC enabled without continuous mode or external trigger that could launch a conversion).
                                       This parameter can be set to ENABLE or DISABLE. */
}ADC_InitTypeDef;


/** 
  * @brief  Structure definition of ADC channel for regular group   
  * @note   The setting of these parameters with function HAL_ADC_ConfigChannel() is conditioned to ADC state.
  *         ADC can be either disabled or enabled without conversion on going on regular group.
  */ 
typedef struct 
{
  uint32_t Channel;                /*!< Specifies the channel to configure into ADC regular group.
                                        This parameter can be a value of @ref ADC_channels */
  uint32_t Rank;                   /*!< Specifies the rank in the regular group sequencer.
                                        This parameter must be a number between Min_Data = 1 and Max_Data = 16 */
  uint32_t SamplingTime;           /*!< Sampling time value to be set for the selected channel.
                                        Unit: ADC clock cycles
                                        Conversion time is the addition of sampling time and processing time (12 ADC clock cycles at ADC resolution 12 bits, 11 cycles at 10 bits, 9 cycles at 8 bits, 7 cycles at 6 bits).
                                        This parameter can be a value of @ref ADC_sampling_times
                                        Caution: This parameter updates the parameter property of the channel, that can be used into regular and/or injected groups.
                                                 If this same channel has been previously configured in the other group (regular/injected), it will be updated to last setting.
                                        Note: In case of usage of internal measurement channels (VrefInt/Vbat/TempSensor),
                                              sampling time constraints must be respected (sampling time can be adjusted in function of ADC clock frequency and sampling time setting)
                                              Refer to device datasheet for timings values, parameters TS_vrefint, TS_temp (values rough order: 4us min). */
  uint32_t Offset;                 /*!< Reserved for future use, can be set to 0 */
}ADC_ChannelConfTypeDef;

// ADC_ChannelConfTypeDef ADC_ChannelConf_Spy;
/** 
  * @brief ADC Configuration multi-mode structure definition  
  */ 
typedef struct
{
  uint32_t WatchdogMode;      /*!< Configures the ADC analog watchdog mode.
                                   This parameter can be a value of @ref ADC_analog_watchdog_selection */
  uint32_t HighThreshold;     /*!< Configures the ADC analog watchdog High threshold value.
                                   This parameter must be a 12-bit value. */     
  uint32_t LowThreshold;      /*!< Configures the ADC analog watchdog High threshold value.
                                   This parameter must be a 12-bit value. */
  uint32_t Channel;           /*!< Configures ADC channel for the analog watchdog. 
                                   This parameter has an effect only if watchdog mode is configured on single channel 
                                   This parameter can be a value of @ref ADC_channels */      
  uint32_t ITMode;            /*!< Specifies whether the analog watchdog is configured
                                   is interrupt mode or in polling mode.
                                   This parameter can be set to ENABLE or DISABLE */
  uint32_t WatchdogNumber;    /*!< Reserved for future use, can be set to 0 */
}ADC_AnalogWDGConfTypeDef;

/** 
  * @brief  HAL ADC state machine: ADC states definition (bitfields)
  */ 
/* States of ADC global scope */
#define HAL_ADC_STATE_RESET             0x00000000U    /*!< ADC not yet initialized or disabled */
#define HAL_ADC_STATE_READY             0x00000001U    /*!< ADC peripheral ready for use */
#define HAL_ADC_STATE_BUSY_INTERNAL     0x00000002U    /*!< ADC is busy to internal process (initialization, calibration) */
#define HAL_ADC_STATE_TIMEOUT           0x00000004U    /*!< TimeOut occurrence */

/* States of ADC errors */
#define HAL_ADC_STATE_ERROR_INTERNAL    0x00000010U    /*!< Internal error occurrence */
#define HAL_ADC_STATE_ERROR_CONFIG      0x00000020U    /*!< Configuration error occurrence */
#define HAL_ADC_STATE_ERROR_DMA         0x00000040U    /*!< DMA error occurrence */

/* States of ADC group regular */
#define HAL_ADC_STATE_REG_BUSY          0x00000100U    /*!< A conversion on group regular is ongoing or can occur (either by continuous mode,
                                                            external trigger, low power auto power-on (if feature available), multimode ADC master control (if feature available)) */
#define HAL_ADC_STATE_REG_EOC           0x00000200U    /*!< Conversion data available on group regular */
#define HAL_ADC_STATE_REG_OVR           0x00000400U    /*!< Overrun occurrence */

/* States of ADC group injected */
#define HAL_ADC_STATE_INJ_BUSY          0x00001000U    /*!< A conversion on group injected is ongoing or can occur (either by auto-injection mode,
                                                            external trigger, low power auto power-on (if feature available), multimode ADC master control (if feature available)) */
#define HAL_ADC_STATE_INJ_EOC           0x00002000U    /*!< Conversion data available on group injected */

/* States of ADC analog watchdogs */
#define HAL_ADC_STATE_AWD1              0x00010000U    /*!< Out-of-window occurrence of analog watchdog 1 */
#define HAL_ADC_STATE_AWD2              0x00020000U    /*!< Not available on STM32F4 device: Out-of-window occurrence of analog watchdog 2 */
#define HAL_ADC_STATE_AWD3              0x00040000U    /*!< Not available on STM32F4 device: Out-of-window occurrence of analog watchdog 3 */

/* States of ADC multi-mode */
#define HAL_ADC_STATE_MULTIMODE_SLAVE   0x00100000U    /*!< Not available on STM32F4 device: ADC in multimode slave state, controlled by another ADC master ( */


/** 
  * @brief  ADC handle Structure definition
  */ 
typedef struct
{
  ADC_TypeDef                   *Instance;                   /*!< Register base address */

  ADC_InitTypeDef               Init;                        /*!< ADC required parameters */

  __IO uint32_t                 NbrOfCurrentConversionRank;  /*!< ADC number of current conversion rank */

  DMA_HandleTypeDef             *DMA_Handle;                 /*!< Pointer DMA Handler */

  HAL_LockTypeDef               Lock;                        /*!< ADC locking object */

  __IO uint32_t                 State;                       /*!< ADC communication state */

  __IO uint32_t                 ErrorCode;                   /*!< ADC Error code */
}ADC_HandleTypeDef;

#define ADC1 &mock_adc1
extern ADC_TypeDef mock_adc1;
extern ADC_HandleTypeDef ADC_Init_Spy;

extern ADC_ChannelConfTypeDef ADC_ChannelConf_Spy;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup ADC_Exported_Constants ADC Exported Constants
  * @{
  */

/** @defgroup ADC_Error_Code ADC Error Code
  * @{
  */
#define HAL_ADC_ERROR_NONE        0x00U   /*!< No error                                              */
#define HAL_ADC_ERROR_INTERNAL    0x01U   /*!< ADC IP internal error: if problem of clocking, 
                                               enable/disable, erroneous state                       */
#define HAL_ADC_ERROR_OVR         0x02U   /*!< Overrun error                                         */
#define HAL_ADC_ERROR_DMA         0x04U   /*!< DMA transfer error                                    */
/**
  * @}
  */


/** @defgroup ADC_ClockPrescaler  ADC Clock Prescaler
  * @{
  */ 
#define ADC_CLOCK_SYNC_PCLK_DIV2    0x00000000U
#define ADC_CLOCK_SYNC_PCLK_DIV4    ((uint32_t)ADC_CCR_ADCPRE_0)
#define ADC_CLOCK_SYNC_PCLK_DIV6    ((uint32_t)ADC_CCR_ADCPRE_1)
#define ADC_CLOCK_SYNC_PCLK_DIV8    ((uint32_t)ADC_CCR_ADCPRE)
/**
  * @}
  */ 

/** @defgroup ADC_delay_between_2_sampling_phases ADC Delay Between 2 Sampling Phases
  * @{
  */ 
#define ADC_TWOSAMPLINGDELAY_5CYCLES    0x00000000U
#define ADC_TWOSAMPLINGDELAY_6CYCLES    ((uint32_t)ADC_CCR_DELAY_0)
#define ADC_TWOSAMPLINGDELAY_7CYCLES    ((uint32_t)ADC_CCR_DELAY_1)
#define ADC_TWOSAMPLINGDELAY_8CYCLES    ((uint32_t)(ADC_CCR_DELAY_1 | ADC_CCR_DELAY_0))
#define ADC_TWOSAMPLINGDELAY_9CYCLES    ((uint32_t)ADC_CCR_DELAY_2)
#define ADC_TWOSAMPLINGDELAY_10CYCLES   ((uint32_t)(ADC_CCR_DELAY_2 | ADC_CCR_DELAY_0))
#define ADC_TWOSAMPLINGDELAY_11CYCLES   ((uint32_t)(ADC_CCR_DELAY_2 | ADC_CCR_DELAY_1))
#define ADC_TWOSAMPLINGDELAY_12CYCLES   ((uint32_t)(ADC_CCR_DELAY_2 | ADC_CCR_DELAY_1 | ADC_CCR_DELAY_0))
#define ADC_TWOSAMPLINGDELAY_13CYCLES   ((uint32_t)ADC_CCR_DELAY_3)
#define ADC_TWOSAMPLINGDELAY_14CYCLES   ((uint32_t)(ADC_CCR_DELAY_3 | ADC_CCR_DELAY_0))
#define ADC_TWOSAMPLINGDELAY_15CYCLES   ((uint32_t)(ADC_CCR_DELAY_3 | ADC_CCR_DELAY_1))
#define ADC_TWOSAMPLINGDELAY_16CYCLES   ((uint32_t)(ADC_CCR_DELAY_3 | ADC_CCR_DELAY_1 | ADC_CCR_DELAY_0))
#define ADC_TWOSAMPLINGDELAY_17CYCLES   ((uint32_t)(ADC_CCR_DELAY_3 | ADC_CCR_DELAY_2))
#define ADC_TWOSAMPLINGDELAY_18CYCLES   ((uint32_t)(ADC_CCR_DELAY_3 | ADC_CCR_DELAY_2 | ADC_CCR_DELAY_0))
#define ADC_TWOSAMPLINGDELAY_19CYCLES   ((uint32_t)(ADC_CCR_DELAY_3 | ADC_CCR_DELAY_2 | ADC_CCR_DELAY_1))
#define ADC_TWOSAMPLINGDELAY_20CYCLES   ((uint32_t)ADC_CCR_DELAY)
/**
  * @}
  */ 

/** @defgroup ADC_Resolution ADC Resolution
  * @{
  */ 
#define ADC_RESOLUTION_12B  0x00000000U
#define ADC_RESOLUTION_10B  ((uint32_t)ADC_CR1_RES_0)
#define ADC_RESOLUTION_8B   ((uint32_t)ADC_CR1_RES_1)
#define ADC_RESOLUTION_6B   ((uint32_t)ADC_CR1_RES)
/**
  * @}
  */ 

/** @defgroup ADC_External_trigger_edge_Regular ADC External Trigger Edge Regular
  * @{
  */ 
#define ADC_EXTERNALTRIGCONVEDGE_NONE           0x00000000U
#define ADC_EXTERNALTRIGCONVEDGE_RISING         ((uint32_t)ADC_CR2_EXTEN_0)
#define ADC_EXTERNALTRIGCONVEDGE_FALLING        ((uint32_t)ADC_CR2_EXTEN_1)
#define ADC_EXTERNALTRIGCONVEDGE_RISINGFALLING  ((uint32_t)ADC_CR2_EXTEN)
/**
  * @}
  */ 

/** @defgroup ADC_External_trigger_Source_Regular ADC External Trigger Source Regular
  * @{
  */
/* Note: Parameter ADC_SOFTWARE_START is a software parameter used for        */
/*       compatibility with other STM32 devices.                              */
#define ADC_EXTERNALTRIGCONV_T1_CC1    0x00000000U
#define ADC_EXTERNALTRIGCONV_T1_CC2    ((uint32_t)ADC_CR2_EXTSEL_0)
#define ADC_EXTERNALTRIGCONV_T1_CC3    ((uint32_t)ADC_CR2_EXTSEL_1)
#define ADC_EXTERNALTRIGCONV_T2_CC2    ((uint32_t)(ADC_CR2_EXTSEL_1 | ADC_CR2_EXTSEL_0))
#define ADC_EXTERNALTRIGCONV_T2_CC3    ((uint32_t)ADC_CR2_EXTSEL_2)
#define ADC_EXTERNALTRIGCONV_T2_CC4    ((uint32_t)(ADC_CR2_EXTSEL_2 | ADC_CR2_EXTSEL_0))
#define ADC_EXTERNALTRIGCONV_T2_TRGO   ((uint32_t)(ADC_CR2_EXTSEL_2 | ADC_CR2_EXTSEL_1))
#define ADC_EXTERNALTRIGCONV_T3_CC1    ((uint32_t)(ADC_CR2_EXTSEL_2 | ADC_CR2_EXTSEL_1 | ADC_CR2_EXTSEL_0))
#define ADC_EXTERNALTRIGCONV_T3_TRGO   ((uint32_t)ADC_CR2_EXTSEL_3)
#define ADC_EXTERNALTRIGCONV_T4_CC4    ((uint32_t)(ADC_CR2_EXTSEL_3 | ADC_CR2_EXTSEL_0))
#define ADC_EXTERNALTRIGCONV_T5_CC1    ((uint32_t)(ADC_CR2_EXTSEL_3 | ADC_CR2_EXTSEL_1))
#define ADC_EXTERNALTRIGCONV_T5_CC2    ((uint32_t)(ADC_CR2_EXTSEL_3 | ADC_CR2_EXTSEL_1 | ADC_CR2_EXTSEL_0))
#define ADC_EXTERNALTRIGCONV_T5_CC3    ((uint32_t)(ADC_CR2_EXTSEL_3 | ADC_CR2_EXTSEL_2))
#define ADC_EXTERNALTRIGCONV_T8_CC1    ((uint32_t)(ADC_CR2_EXTSEL_3 | ADC_CR2_EXTSEL_2 | ADC_CR2_EXTSEL_0))
#define ADC_EXTERNALTRIGCONV_T8_TRGO   ((uint32_t)(ADC_CR2_EXTSEL_3 | ADC_CR2_EXTSEL_2 | ADC_CR2_EXTSEL_1))
#define ADC_EXTERNALTRIGCONV_Ext_IT11  ((uint32_t)ADC_CR2_EXTSEL)
#define ADC_SOFTWARE_START             ((uint32_t)ADC_CR2_EXTSEL + 1U)
/**
  * @}
  */ 

/** @defgroup ADC_Data_align ADC Data Align
  * @{
  */ 
#define ADC_DATAALIGN_RIGHT      0x00000000U
#define ADC_DATAALIGN_LEFT       ((uint32_t)ADC_CR2_ALIGN)
/**
  * @}
  */ 

/** @defgroup ADC_channels  ADC Common Channels
  * @{
  */ 
#define ADC_CHANNEL_0           0x11111111U //Changed from 0 to detect non-initialisation
// #define ADC_CHANNEL_0           0x00000000U
#define ADC_CHANNEL_1           ((uint32_t)ADC_CR1_AWDCH_0)
#define ADC_CHANNEL_2           ((uint32_t)ADC_CR1_AWDCH_1)
#define ADC_CHANNEL_3           ((uint32_t)(ADC_CR1_AWDCH_1 | ADC_CR1_AWDCH_0))
#define ADC_CHANNEL_4           ((uint32_t)ADC_CR1_AWDCH_2)
#define ADC_CHANNEL_5           ((uint32_t)(ADC_CR1_AWDCH_2 | ADC_CR1_AWDCH_0))
#define ADC_CHANNEL_6           ((uint32_t)(ADC_CR1_AWDCH_2 | ADC_CR1_AWDCH_1))
#define ADC_CHANNEL_7           ((uint32_t)(ADC_CR1_AWDCH_2 | ADC_CR1_AWDCH_1 | ADC_CR1_AWDCH_0))
#define ADC_CHANNEL_8           ((uint32_t)ADC_CR1_AWDCH_3)
#define ADC_CHANNEL_9           ((uint32_t)(ADC_CR1_AWDCH_3 | ADC_CR1_AWDCH_0))
#define ADC_CHANNEL_10          ((uint32_t)(ADC_CR1_AWDCH_3 | ADC_CR1_AWDCH_1))
#define ADC_CHANNEL_11          ((uint32_t)(ADC_CR1_AWDCH_3 | ADC_CR1_AWDCH_1 | ADC_CR1_AWDCH_0))
#define ADC_CHANNEL_12          ((uint32_t)(ADC_CR1_AWDCH_3 | ADC_CR1_AWDCH_2))
#define ADC_CHANNEL_13          ((uint32_t)(ADC_CR1_AWDCH_3 | ADC_CR1_AWDCH_2 | ADC_CR1_AWDCH_0))
#define ADC_CHANNEL_14          ((uint32_t)(ADC_CR1_AWDCH_3 | ADC_CR1_AWDCH_2 | ADC_CR1_AWDCH_1))
#define ADC_CHANNEL_15          ((uint32_t)(ADC_CR1_AWDCH_3 | ADC_CR1_AWDCH_2 | ADC_CR1_AWDCH_1 | ADC_CR1_AWDCH_0))
#define ADC_CHANNEL_16          ((uint32_t)ADC_CR1_AWDCH_4)
#define ADC_CHANNEL_17          ((uint32_t)(ADC_CR1_AWDCH_4 | ADC_CR1_AWDCH_0))
#define ADC_CHANNEL_18          ((uint32_t)(ADC_CR1_AWDCH_4 | ADC_CR1_AWDCH_1))

#define ADC_CHANNEL_VREFINT     ((uint32_t)ADC_CHANNEL_17)
#define ADC_CHANNEL_VBAT        ((uint32_t)ADC_CHANNEL_18)
/**
  * @}
  */ 

/** @defgroup ADC_sampling_times  ADC Sampling Times
  * @{
  */ 
#define ADC_SAMPLETIME_3CYCLES    0x00000000U
#define ADC_SAMPLETIME_15CYCLES   ((uint32_t)ADC_SMPR1_SMP10_0)
#define ADC_SAMPLETIME_28CYCLES   ((uint32_t)ADC_SMPR1_SMP10_1)
#define ADC_SAMPLETIME_56CYCLES   ((uint32_t)(ADC_SMPR1_SMP10_1 | ADC_SMPR1_SMP10_0))
#define ADC_SAMPLETIME_84CYCLES   ((uint32_t)ADC_SMPR1_SMP10_2)
#define ADC_SAMPLETIME_112CYCLES  ((uint32_t)(ADC_SMPR1_SMP10_2 | ADC_SMPR1_SMP10_0))
#define ADC_SAMPLETIME_144CYCLES  ((uint32_t)(ADC_SMPR1_SMP10_2 | ADC_SMPR1_SMP10_1))
#define ADC_SAMPLETIME_480CYCLES  ((uint32_t)ADC_SMPR1_SMP10)
/**
  * @}
  */ 

  /** @defgroup ADC_EOCSelection ADC EOC Selection
  * @{
  */ 
#define ADC_EOC_SEQ_CONV              0x00000000U
#define ADC_EOC_SINGLE_CONV           0x00000001U
#define ADC_EOC_SINGLE_SEQ_CONV       0x00000002U  /*!< reserved for future use */
/**
  * @}
  */ 

/** @defgroup ADC_Event_type ADC Event Type
  * @{
  */ 
#define ADC_AWD_EVENT             ((uint32_t)ADC_FLAG_AWD)
#define ADC_OVR_EVENT             ((uint32_t)ADC_FLAG_OVR)
/**
  * @}
  */

/** @defgroup ADC_analog_watchdog_selection ADC Analog Watchdog Selection
  * @{
  */ 
#define ADC_ANALOGWATCHDOG_SINGLE_REG         ((uint32_t)(ADC_CR1_AWDSGL | ADC_CR1_AWDEN))
#define ADC_ANALOGWATCHDOG_SINGLE_INJEC       ((uint32_t)(ADC_CR1_AWDSGL | ADC_CR1_JAWDEN))
#define ADC_ANALOGWATCHDOG_SINGLE_REGINJEC    ((uint32_t)(ADC_CR1_AWDSGL | ADC_CR1_AWDEN | ADC_CR1_JAWDEN))
#define ADC_ANALOGWATCHDOG_ALL_REG            ((uint32_t)ADC_CR1_AWDEN)
#define ADC_ANALOGWATCHDOG_ALL_INJEC          ((uint32_t)ADC_CR1_JAWDEN)
#define ADC_ANALOGWATCHDOG_ALL_REGINJEC       ((uint32_t)(ADC_CR1_AWDEN | ADC_CR1_JAWDEN))
#define ADC_ANALOGWATCHDOG_NONE               0x00000000U
/**
  * @}
  */ 
    
/** @defgroup ADC_interrupts_definition ADC Interrupts Definition
  * @{
  */ 
#define ADC_IT_EOC      ((uint32_t)ADC_CR1_EOCIE)
#define ADC_IT_AWD      ((uint32_t)ADC_CR1_AWDIE)
#define ADC_IT_JEOC     ((uint32_t)ADC_CR1_JEOCIE)
#define ADC_IT_OVR      ((uint32_t)ADC_CR1_OVRIE)
/**
  * @}
  */ 
    
/** @defgroup ADC_flags_definition ADC Flags Definition
  * @{
  */ 
#define ADC_FLAG_AWD    ((uint32_t)ADC_SR_AWD)
#define ADC_FLAG_EOC    ((uint32_t)ADC_SR_EOC)
#define ADC_FLAG_JEOC   ((uint32_t)ADC_SR_JEOC)
#define ADC_FLAG_JSTRT  ((uint32_t)ADC_SR_JSTRT)
#define ADC_FLAG_STRT   ((uint32_t)ADC_SR_STRT)
#define ADC_FLAG_OVR    ((uint32_t)ADC_SR_OVR)
/**
  * @}
  */ 

/** @defgroup ADC_channels_type ADC Channels Type
  * @{
  */ 
#define ADC_ALL_CHANNELS      0x00000001U
#define ADC_REGULAR_CHANNELS  0x00000002U /*!< reserved for future use */
#define ADC_INJECTED_CHANNELS 0x00000003U /*!< reserved for future use */
/**
  * @}
  */

/**
  * @}
  */ 

/* Exported macro ------------------------------------------------------------*/
/** @defgroup ADC_Exported_Macros ADC Exported Macros
  * @{
  */

/** @brief Reset ADC handle state
  * @param  __HANDLE__ ADC handle
  * @retval None
  */
#define __HAL_ADC_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_ADC_STATE_RESET)

/**
  * @brief  Enable the ADC peripheral.
  * @param  __HANDLE__ ADC handle
  * @retval None
  */
#define __HAL_ADC_ENABLE(__HANDLE__) ((__HANDLE__)->Instance->CR2 |=  ADC_CR2_ADON)

/**
  * @brief  Disable the ADC peripheral.
  * @param  __HANDLE__ ADC handle
  * @retval None
  */
#define __HAL_ADC_DISABLE(__HANDLE__) ((__HANDLE__)->Instance->CR2 &=  ~ADC_CR2_ADON)

/**
  * @brief  Enable the ADC end of conversion interrupt.
  * @param  __HANDLE__ specifies the ADC Handle.
  * @param  __INTERRUPT__ ADC Interrupt.
  * @retval None
  */
#define __HAL_ADC_ENABLE_IT(__HANDLE__, __INTERRUPT__) (((__HANDLE__)->Instance->CR1) |= (__INTERRUPT__))

/**
  * @brief  Disable the ADC end of conversion interrupt.
  * @param  __HANDLE__ specifies the ADC Handle.
  * @param  __INTERRUPT__ ADC interrupt.
  * @retval None
  */
#define __HAL_ADC_DISABLE_IT(__HANDLE__, __INTERRUPT__) (((__HANDLE__)->Instance->CR1) &= ~(__INTERRUPT__))

/** @brief  Check if the specified ADC interrupt source is enabled or disabled.
  * @param  __HANDLE__ specifies the ADC Handle.
  * @param  __INTERRUPT__ specifies the ADC interrupt source to check.
  * @retval The new state of __IT__ (TRUE or FALSE).
  */
#define __HAL_ADC_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__)  (((__HANDLE__)->Instance->CR1 & (__INTERRUPT__)) == (__INTERRUPT__))

/**
  * @brief  Clear the ADC's pending flags.
  * @param  __HANDLE__ specifies the ADC Handle.
  * @param  __FLAG__ ADC flag.
  * @retval None
  */
#define __HAL_ADC_CLEAR_FLAG(__HANDLE__, __FLAG__) (((__HANDLE__)->Instance->SR) = ~(__FLAG__))

/**
  * @brief  Get the selected ADC's flag status.
  * @param  __HANDLE__ specifies the ADC Handle.
  * @param  __FLAG__ ADC flag.
  * @retval None
  */
#define __HAL_ADC_GET_FLAG(__HANDLE__, __FLAG__) ((((__HANDLE__)->Instance->SR) & (__FLAG__)) == (__FLAG__))

/**
  * @}
  */

/* Include ADC HAL Extension module */
#include "stm32f4xx_hal_adc_ex.h"

/* Exported functions --------------------------------------------------------*/
/** @addtogroup ADC_Exported_Functions
  * @{
  */

/** @addtogroup ADC_Exported_Functions_Group1
  * @{
  */
/* Initialization/de-initialization functions ***********************************/
extern HAL_StatusTypeDef (*HAL_ADC_Init)(ADC_HandleTypeDef* hadc);
// HAL_StatusTypeDef HAL_ADC_Init_Impl(ADC_HandleTypeDef* hadc);
HAL_StatusTypeDef HAL_ADC_Init_spyHandle(ADC_HandleTypeDef* hadc);

HAL_StatusTypeDef HAL_ADC_DeInit(ADC_HandleTypeDef *hadc);
void HAL_ADC_MspInit(ADC_HandleTypeDef* hadc);
void HAL_ADC_MspDeInit(ADC_HandleTypeDef* hadc);
/**
  * @}
  */

/** @addtogroup ADC_Exported_Functions_Group2
  * @{
  */
/* I/O operation functions ******************************************************/
HAL_StatusTypeDef HAL_ADC_Start(ADC_HandleTypeDef* hadc);
HAL_StatusTypeDef HAL_ADC_Stop(ADC_HandleTypeDef* hadc);
HAL_StatusTypeDef HAL_ADC_PollForConversion(ADC_HandleTypeDef* hadc, uint32_t Timeout);

HAL_StatusTypeDef HAL_ADC_PollForEvent(ADC_HandleTypeDef* hadc, uint32_t EventType, uint32_t Timeout);

HAL_StatusTypeDef HAL_ADC_Start_IT(ADC_HandleTypeDef* hadc);
HAL_StatusTypeDef HAL_ADC_Stop_IT(ADC_HandleTypeDef* hadc);

void HAL_ADC_IRQHandler(ADC_HandleTypeDef* hadc);

HAL_StatusTypeDef HAL_ADC_Start_DMA(ADC_HandleTypeDef* hadc, uint32_t* pData, uint32_t Length);
HAL_StatusTypeDef HAL_ADC_Stop_DMA(ADC_HandleTypeDef* hadc);

uint32_t HAL_ADC_GetValue(ADC_HandleTypeDef* hadc);

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc);
void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc);
void HAL_ADC_LevelOutOfWindowCallback(ADC_HandleTypeDef* hadc);
void HAL_ADC_ErrorCallback(ADC_HandleTypeDef *hadc);
/**
  * @}
  */

/** @addtogroup ADC_Exported_Functions_Group3
  * @{
  */
/* Peripheral Control functions *************************************************/

extern HAL_StatusTypeDef (*HAL_ADC_ConfigChannel)(ADC_HandleTypeDef* hadc, ADC_ChannelConfTypeDef* sConfig);
// HAL_StatusTypeDef HAL_ADC_ConfigChannel_Impl(ADC_HandleTypeDef* hadc, ADC_ChannelConfTypeDef* sConfig);
HAL_StatusTypeDef HAL_ADC_ConfigChannel_spy(ADC_HandleTypeDef* hadc, ADC_ChannelConfTypeDef* sConfig);

HAL_StatusTypeDef HAL_ADC_AnalogWDGConfig(ADC_HandleTypeDef* hadc, ADC_AnalogWDGConfTypeDef* AnalogWDGConfig);
/**
  * @}
  */

/** @addtogroup ADC_Exported_Functions_Group4
  * @{
  */
/* Peripheral State functions ***************************************************/
uint32_t HAL_ADC_GetState(ADC_HandleTypeDef* hadc);
uint32_t HAL_ADC_GetError(ADC_HandleTypeDef *hadc);
/**
  * @}
  */

/**
  * @}
  */
/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/** @defgroup ADC_Private_Constants ADC Private Constants
  * @{
  */
/* Delay for ADC stabilization time.                                        */
/* Maximum delay is 1us (refer to device datasheet, parameter tSTAB).       */
/* Unit: us                                                                 */
#define ADC_STAB_DELAY_US               3U
/* Delay for temperature sensor stabilization time.                         */
/* Maximum delay is 10us (refer to device datasheet, parameter tSTART).     */
/* Unit: us                                                                 */
#define ADC_TEMPSENSOR_DELAY_US         10U
/**
  * @}
  */

/* Private macro ------------------------------------------------------------*/

/** @defgroup ADC_Private_Macros ADC Private Macros
  * @{
  */
/* Macro reserved for internal HAL driver usage, not intended to be used in
   code of final user */

/**
  * @brief Verification of ADC state: enabled or disabled
  * @param __HANDLE__ ADC handle
  * @retval SET (ADC enabled) or RESET (ADC disabled)
  */
#define ADC_IS_ENABLE(__HANDLE__)                                              \
  ((( ((__HANDLE__)->Instance->SR & ADC_CR2_ADON) == ADC_CR2_ADON )            \
  ) ? SET : RESET)

  // ((( ((__HANDLE__)->Instance->SR & ADC_SR_ADONS) == ADC_SR_ADONS )           
/**
  * @brief Test if conversion trigger of regular group is software start
  *        or external trigger.
  * @param __HANDLE__ ADC handle
  * @retval SET (software start) or RESET (external trigger)
  */
#define ADC_IS_SOFTWARE_START_REGULAR(__HANDLE__)                              \
  (((__HANDLE__)->Instance->CR2 & ADC_CR2_EXTEN) == RESET)

/**
  * @brief Test if conversion trigger of injected group is software start
  *        or external trigger.
  * @param __HANDLE__ ADC handle
  * @retval SET (software start) or RESET (external trigger)
  */
#define ADC_IS_SOFTWARE_START_INJECTED(__HANDLE__)                             \
  (((__HANDLE__)->Instance->CR2 & ADC_CR2_JEXTEN) == RESET)

/**
  * @brief Simultaneously clears and sets specific bits of the handle State
  * @note: ADC_STATE_CLR_SET() macro is merely aliased to generic macro MODIFY_REG(),
  *        the first parameter is the ADC handle State, the second parameter is the
  *        bit field to clear, the third and last parameter is the bit field to set.
  * @retval None
  */
#define ADC_STATE_CLR_SET MODIFY_REG

/**
  * @brief Clear ADC error code (set it to error code: "no error")
  * @param __HANDLE__ ADC handle
  * @retval None
  */
#define ADC_CLEAR_ERRORCODE(__HANDLE__)                                        \
  ((__HANDLE__)->ErrorCode = HAL_ADC_ERROR_NONE)

    
#define IS_ADC_CLOCKPRESCALER(ADC_CLOCK)     (((ADC_CLOCK) == ADC_CLOCK_SYNC_PCLK_DIV2) || \
                                              ((ADC_CLOCK) == ADC_CLOCK_SYNC_PCLK_DIV4) || \
                                              ((ADC_CLOCK) == ADC_CLOCK_SYNC_PCLK_DIV6) || \
                                              ((ADC_CLOCK) == ADC_CLOCK_SYNC_PCLK_DIV8))
#define IS_ADC_SAMPLING_DELAY(DELAY) (((DELAY) == ADC_TWOSAMPLINGDELAY_5CYCLES)  || \
                                      ((DELAY) == ADC_TWOSAMPLINGDELAY_6CYCLES)  || \
                                      ((DELAY) == ADC_TWOSAMPLINGDELAY_7CYCLES)  || \
                                      ((DELAY) == ADC_TWOSAMPLINGDELAY_8CYCLES)  || \
                                      ((DELAY) == ADC_TWOSAMPLINGDELAY_9CYCLES)  || \
                                      ((DELAY) == ADC_TWOSAMPLINGDELAY_10CYCLES) || \
                                      ((DELAY) == ADC_TWOSAMPLINGDELAY_11CYCLES) || \
                                      ((DELAY) == ADC_TWOSAMPLINGDELAY_12CYCLES) || \
                                      ((DELAY) == ADC_TWOSAMPLINGDELAY_13CYCLES) || \
                                      ((DELAY) == ADC_TWOSAMPLINGDELAY_14CYCLES) || \
                                      ((DELAY) == ADC_TWOSAMPLINGDELAY_15CYCLES) || \
                                      ((DELAY) == ADC_TWOSAMPLINGDELAY_16CYCLES) || \
                                      ((DELAY) == ADC_TWOSAMPLINGDELAY_17CYCLES) || \
                                      ((DELAY) == ADC_TWOSAMPLINGDELAY_18CYCLES) || \
                                      ((DELAY) == ADC_TWOSAMPLINGDELAY_19CYCLES) || \
                                      ((DELAY) == ADC_TWOSAMPLINGDELAY_20CYCLES))
#define IS_ADC_RESOLUTION(RESOLUTION) (((RESOLUTION) == ADC_RESOLUTION_12B) || \
                                       ((RESOLUTION) == ADC_RESOLUTION_10B) || \
                                       ((RESOLUTION) == ADC_RESOLUTION_8B)  || \
                                       ((RESOLUTION) == ADC_RESOLUTION_6B))
#define IS_ADC_EXT_TRIG_EDGE(EDGE) (((EDGE) == ADC_EXTERNALTRIGCONVEDGE_NONE)    || \
                                    ((EDGE) == ADC_EXTERNALTRIGCONVEDGE_RISING)  || \
                                    ((EDGE) == ADC_EXTERNALTRIGCONVEDGE_FALLING) || \
                                    ((EDGE) == ADC_EXTERNALTRIGCONVEDGE_RISINGFALLING))
#define IS_ADC_EXT_TRIG(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC1)  || \
                                  ((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC2)  || \
                                  ((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC3)  || \
                                  ((REGTRIG) == ADC_EXTERNALTRIGCONV_T2_CC2)  || \
                                  ((REGTRIG) == ADC_EXTERNALTRIGCONV_T2_CC3)  || \
                                  ((REGTRIG) == ADC_EXTERNALTRIGCONV_T2_CC4)  || \
                                  ((REGTRIG) == ADC_EXTERNALTRIGCONV_T2_TRGO) || \
                                  ((REGTRIG) == ADC_EXTERNALTRIGCONV_T3_CC1)  || \
                                  ((REGTRIG) == ADC_EXTERNALTRIGCONV_T3_TRGO) || \
                                  ((REGTRIG) == ADC_EXTERNALTRIGCONV_T4_CC4)  || \
                                  ((REGTRIG) == ADC_EXTERNALTRIGCONV_T5_CC1)  || \
                                  ((REGTRIG) == ADC_EXTERNALTRIGCONV_T5_CC2)  || \
                                  ((REGTRIG) == ADC_EXTERNALTRIGCONV_T5_CC3)  || \
                                  ((REGTRIG) == ADC_EXTERNALTRIGCONV_T8_CC1)  || \
                                  ((REGTRIG) == ADC_EXTERNALTRIGCONV_T8_TRGO) || \
                                  ((REGTRIG) == ADC_EXTERNALTRIGCONV_Ext_IT11)|| \
                                  ((REGTRIG) == ADC_SOFTWARE_START))
#define IS_ADC_DATA_ALIGN(ALIGN) (((ALIGN) == ADC_DATAALIGN_RIGHT) || \
                                  ((ALIGN) == ADC_DATAALIGN_LEFT))
#define IS_ADC_SAMPLE_TIME(TIME) (((TIME) == ADC_SAMPLETIME_3CYCLES)   || \
                                  ((TIME) == ADC_SAMPLETIME_15CYCLES)  || \
                                  ((TIME) == ADC_SAMPLETIME_28CYCLES)  || \
                                  ((TIME) == ADC_SAMPLETIME_56CYCLES)  || \
                                  ((TIME) == ADC_SAMPLETIME_84CYCLES)  || \
                                  ((TIME) == ADC_SAMPLETIME_112CYCLES) || \
                                  ((TIME) == ADC_SAMPLETIME_144CYCLES) || \
                                  ((TIME) == ADC_SAMPLETIME_480CYCLES))
#define IS_ADC_EOCSelection(EOCSelection) (((EOCSelection) == ADC_EOC_SINGLE_CONV)   || \
                                           ((EOCSelection) == ADC_EOC_SEQ_CONV)  || \
                                           ((EOCSelection) == ADC_EOC_SINGLE_SEQ_CONV))
#define IS_ADC_EVENT_TYPE(EVENT) (((EVENT) == ADC_AWD_EVENT) || \
                                  ((EVENT) == ADC_OVR_EVENT))
#define IS_ADC_ANALOG_WATCHDOG(WATCHDOG) (((WATCHDOG) == ADC_ANALOGWATCHDOG_SINGLE_REG)        || \
                                          ((WATCHDOG) == ADC_ANALOGWATCHDOG_SINGLE_INJEC)      || \
                                          ((WATCHDOG) == ADC_ANALOGWATCHDOG_SINGLE_REGINJEC)   || \
                                          ((WATCHDOG) == ADC_ANALOGWATCHDOG_ALL_REG)           || \
                                          ((WATCHDOG) == ADC_ANALOGWATCHDOG_ALL_INJEC)         || \
                                          ((WATCHDOG) == ADC_ANALOGWATCHDOG_ALL_REGINJEC)      || \
                                          ((WATCHDOG) == ADC_ANALOGWATCHDOG_NONE))
#define IS_ADC_CHANNELS_TYPE(CHANNEL_TYPE) (((CHANNEL_TYPE) == ADC_ALL_CHANNELS) || \
                                            ((CHANNEL_TYPE) == ADC_REGULAR_CHANNELS) || \
                                            ((CHANNEL_TYPE) == ADC_INJECTED_CHANNELS))
#define IS_ADC_THRESHOLD(THRESHOLD) ((THRESHOLD) <= 0xFFFU)

#define IS_ADC_REGULAR_LENGTH(LENGTH) (((LENGTH) >= 1U) && ((LENGTH) <= 16U))
#define IS_ADC_REGULAR_RANK(RANK) (((RANK) >= 1U) && ((RANK) <= (16U)))
#define IS_ADC_REGULAR_DISC_NUMBER(NUMBER) (((NUMBER) >= 1U) && ((NUMBER) <= 8U))
#define IS_ADC_RANGE(RESOLUTION, ADC_VALUE)                                     \
   ((((RESOLUTION) == ADC_RESOLUTION_12B) && ((ADC_VALUE) <= 0x0FFFU)) || \
    (((RESOLUTION) == ADC_RESOLUTION_10B) && ((ADC_VALUE) <= 0x03FFU)) || \
    (((RESOLUTION) == ADC_RESOLUTION_8B)  && ((ADC_VALUE) <= 0x00FFU)) || \
    (((RESOLUTION) == ADC_RESOLUTION_6B)  && ((ADC_VALUE) <= 0x003FU)))

/**
  * @brief  Set ADC Regular channel sequence length.
  * @param  _NbrOfConversion_ Regular channel sequence length. 
  * @retval None
  */
#define ADC_SQR1(_NbrOfConversion_) (((_NbrOfConversion_) - (uint8_t)1U) << 20U)

/**
  * @brief  Set the ADC's sample time for channel numbers between 10 and 18.
  * @param  _SAMPLETIME_ Sample time parameter.
  * @param  _CHANNELNB_ Channel number.  
  * @retval None
  */
#define ADC_SMPR1(_SAMPLETIME_, _CHANNELNB_) ((_SAMPLETIME_) << (3U * (((uint32_t)((uint16_t)(_CHANNELNB_))) - 10U)))

/**
  * @brief  Set the ADC's sample time for channel numbers between 0 and 9.
  * @param  _SAMPLETIME_ Sample time parameter.
  * @param  _CHANNELNB_ Channel number.  
  * @retval None
  */
#define ADC_SMPR2(_SAMPLETIME_, _CHANNELNB_) ((_SAMPLETIME_) << (3U * ((uint32_t)((uint16_t)(_CHANNELNB_)))))

/**
  * @brief  Set the selected regular channel rank for rank between 1 and 6.
  * @param  _CHANNELNB_ Channel number.
  * @param  _RANKNB_ Rank number.    
  * @retval None
  */
#define ADC_SQR3_RK(_CHANNELNB_, _RANKNB_) (((uint32_t)((uint16_t)(_CHANNELNB_))) << (5U * ((_RANKNB_) - 1U)))

/**
  * @brief  Set the selected regular channel rank for rank between 7 and 12.
  * @param  _CHANNELNB_ Channel number.
  * @param  _RANKNB_ Rank number.    
  * @retval None
  */
#define ADC_SQR2_RK(_CHANNELNB_, _RANKNB_) (((uint32_t)((uint16_t)(_CHANNELNB_))) << (5U * ((_RANKNB_) - 7U)))

/**
  * @brief  Set the selected regular channel rank for rank between 13 and 16.
  * @param  _CHANNELNB_ Channel number.
  * @param  _RANKNB_ Rank number.    
  * @retval None
  */
#define ADC_SQR1_RK(_CHANNELNB_, _RANKNB_) (((uint32_t)((uint16_t)(_CHANNELNB_))) << (5U * ((_RANKNB_) - 13U)))

/**
  * @brief  Enable ADC continuous conversion mode.
  * @param  _CONTINUOUS_MODE_ Continuous mode.
  * @retval None
  */
#define ADC_CR2_CONTINUOUS(_CONTINUOUS_MODE_) ((_CONTINUOUS_MODE_) << 1U)

/**
  * @brief  Configures the number of discontinuous conversions for the regular group channels.
  * @param  _NBR_DISCONTINUOUSCONV_ Number of discontinuous conversions.
  * @retval None
  */
#define ADC_CR1_DISCONTINUOUS(_NBR_DISCONTINUOUSCONV_) (((_NBR_DISCONTINUOUSCONV_) - 1U) << ADC_CR1_DISCNUM_Pos)

/**
  * @brief  Enable ADC scan mode.
  * @param  _SCANCONV_MODE_ Scan conversion mode.
  * @retval None
  */
#define ADC_CR1_SCANCONV(_SCANCONV_MODE_) ((_SCANCONV_MODE_) << 8U)

/**
  * @brief  Enable the ADC end of conversion selection.
  * @param  _EOCSelection_MODE_ End of conversion selection mode.
  * @retval None
  */
#define ADC_CR2_EOCSelection(_EOCSelection_MODE_) ((_EOCSelection_MODE_) << 10U)

/**
  * @brief  Enable the ADC DMA continuous request.
  * @param  _DMAContReq_MODE_ DMA continuous request mode.
  * @retval None
  */
#define ADC_CR2_DMAContReq(_DMAContReq_MODE_) ((_DMAContReq_MODE_) << 9U)

/**
  * @brief Return resolution bits in CR1 register.
  * @param __HANDLE__ ADC handle
  * @retval None
  */
#define ADC_GET_RESOLUTION(__HANDLE__) (((__HANDLE__)->Instance->CR1) & ADC_CR1_RES)

/**
  * @}
  */

/* Private functions ---------------------------------------------------------*/
/** @defgroup ADC_Private_Functions ADC Private Functions
  * @{
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



/******************************************************************************/
/*                         Peripheral Registers_Bits_Definition               */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                        Analog to Digital Converter                         */
/*                                                                            */
/******************************************************************************/

/********************  Bit definition for ADC_SR register  ********************/
#define ADC_SR_AWD_Pos            (0U)                                         
#define ADC_SR_AWD_Msk            (0x1U << ADC_SR_AWD_Pos)                     /*!< 0x00000001 */
#define ADC_SR_AWD                ADC_SR_AWD_Msk                               /*!<Analog watchdog flag */
#define ADC_SR_EOC_Pos            (1U)                                         
#define ADC_SR_EOC_Msk            (0x1U << ADC_SR_EOC_Pos)                     /*!< 0x00000002 */
#define ADC_SR_EOC                ADC_SR_EOC_Msk                               /*!<End of conversion */
#define ADC_SR_JEOC_Pos           (2U)                                         
#define ADC_SR_JEOC_Msk           (0x1U << ADC_SR_JEOC_Pos)                    /*!< 0x00000004 */
#define ADC_SR_JEOC               ADC_SR_JEOC_Msk                              /*!<Injected channel end of conversion */
#define ADC_SR_JSTRT_Pos          (3U)                                         
#define ADC_SR_JSTRT_Msk          (0x1U << ADC_SR_JSTRT_Pos)                   /*!< 0x00000008 */
#define ADC_SR_JSTRT              ADC_SR_JSTRT_Msk                             /*!<Injected channel Start flag */
#define ADC_SR_STRT_Pos           (4U)                                         
#define ADC_SR_STRT_Msk           (0x1U << ADC_SR_STRT_Pos)                    /*!< 0x00000010 */
#define ADC_SR_STRT               ADC_SR_STRT_Msk                              /*!<Regular channel Start flag */
#define ADC_SR_OVR_Pos            (5U)                                         
#define ADC_SR_OVR_Msk            (0x1U << ADC_SR_OVR_Pos)                     /*!< 0x00000020 */
#define ADC_SR_OVR                ADC_SR_OVR_Msk                               /*!<Overrun flag */

/*******************  Bit definition for ADC_CR1 register  ********************/
#define ADC_CR1_AWDCH_Pos         (0U)                                         
#define ADC_CR1_AWDCH_Msk         (0x1FU << ADC_CR1_AWDCH_Pos)                 /*!< 0x0000001F */
#define ADC_CR1_AWDCH             ADC_CR1_AWDCH_Msk                            /*!<AWDCH[4:0] bits (Analog watchdog channel select bits) */
#define ADC_CR1_AWDCH_0           (0x01U << ADC_CR1_AWDCH_Pos)                 /*!< 0x00000001 */
#define ADC_CR1_AWDCH_1           (0x02U << ADC_CR1_AWDCH_Pos)                 /*!< 0x00000002 */
#define ADC_CR1_AWDCH_2           (0x04U << ADC_CR1_AWDCH_Pos)                 /*!< 0x00000004 */
#define ADC_CR1_AWDCH_3           (0x08U << ADC_CR1_AWDCH_Pos)                 /*!< 0x00000008 */
#define ADC_CR1_AWDCH_4           (0x10U << ADC_CR1_AWDCH_Pos)                 /*!< 0x00000010 */
#define ADC_CR1_EOCIE_Pos         (5U)                                         
#define ADC_CR1_EOCIE_Msk         (0x1U << ADC_CR1_EOCIE_Pos)                  /*!< 0x00000020 */
#define ADC_CR1_EOCIE             ADC_CR1_EOCIE_Msk                            /*!<Interrupt enable for EOC */
#define ADC_CR1_AWDIE_Pos         (6U)                                         
#define ADC_CR1_AWDIE_Msk         (0x1U << ADC_CR1_AWDIE_Pos)                  /*!< 0x00000040 */
#define ADC_CR1_AWDIE             ADC_CR1_AWDIE_Msk                            /*!<AAnalog Watchdog interrupt enable */
#define ADC_CR1_JEOCIE_Pos        (7U)                                         
#define ADC_CR1_JEOCIE_Msk        (0x1U << ADC_CR1_JEOCIE_Pos)                 /*!< 0x00000080 */
#define ADC_CR1_JEOCIE            ADC_CR1_JEOCIE_Msk                           /*!<Interrupt enable for injected channels */
#define ADC_CR1_SCAN_Pos          (8U)                                         
#define ADC_CR1_SCAN_Msk          (0x1U << ADC_CR1_SCAN_Pos)                   /*!< 0x00000100 */
#define ADC_CR1_SCAN              ADC_CR1_SCAN_Msk                             /*!<Scan mode */
#define ADC_CR1_AWDSGL_Pos        (9U)                                         
#define ADC_CR1_AWDSGL_Msk        (0x1U << ADC_CR1_AWDSGL_Pos)                 /*!< 0x00000200 */
#define ADC_CR1_AWDSGL            ADC_CR1_AWDSGL_Msk                           /*!<Enable the watchdog on a single channel in scan mode */
#define ADC_CR1_JAUTO_Pos         (10U)                                        
#define ADC_CR1_JAUTO_Msk         (0x1U << ADC_CR1_JAUTO_Pos)                  /*!< 0x00000400 */
#define ADC_CR1_JAUTO             ADC_CR1_JAUTO_Msk                            /*!<Automatic injected group conversion */
#define ADC_CR1_DISCEN_Pos        (11U)                                        
#define ADC_CR1_DISCEN_Msk        (0x1U << ADC_CR1_DISCEN_Pos)                 /*!< 0x00000800 */
#define ADC_CR1_DISCEN            ADC_CR1_DISCEN_Msk                           /*!<Discontinuous mode on regular channels */
#define ADC_CR1_JDISCEN_Pos       (12U)                                        
#define ADC_CR1_JDISCEN_Msk       (0x1U << ADC_CR1_JDISCEN_Pos)                /*!< 0x00001000 */
#define ADC_CR1_JDISCEN           ADC_CR1_JDISCEN_Msk                          /*!<Discontinuous mode on injected channels */
#define ADC_CR1_DISCNUM_Pos       (13U)                                        
#define ADC_CR1_DISCNUM_Msk       (0x7U << ADC_CR1_DISCNUM_Pos)                /*!< 0x0000E000 */
#define ADC_CR1_DISCNUM           ADC_CR1_DISCNUM_Msk                          /*!<DISCNUM[2:0] bits (Discontinuous mode channel count) */
#define ADC_CR1_DISCNUM_0         (0x1U << ADC_CR1_DISCNUM_Pos)                /*!< 0x00002000 */
#define ADC_CR1_DISCNUM_1         (0x2U << ADC_CR1_DISCNUM_Pos)                /*!< 0x00004000 */
#define ADC_CR1_DISCNUM_2         (0x4U << ADC_CR1_DISCNUM_Pos)                /*!< 0x00008000 */
#define ADC_CR1_JAWDEN_Pos        (22U)                                        
#define ADC_CR1_JAWDEN_Msk        (0x1U << ADC_CR1_JAWDEN_Pos)                 /*!< 0x00400000 */
#define ADC_CR1_JAWDEN            ADC_CR1_JAWDEN_Msk                           /*!<Analog watchdog enable on injected channels */
#define ADC_CR1_AWDEN_Pos         (23U)                                        
#define ADC_CR1_AWDEN_Msk         (0x1U << ADC_CR1_AWDEN_Pos)                  /*!< 0x00800000 */
#define ADC_CR1_AWDEN             ADC_CR1_AWDEN_Msk                            /*!<Analog watchdog enable on regular channels */
#define ADC_CR1_RES_Pos           (24U)                                        
#define ADC_CR1_RES_Msk           (0x3U << ADC_CR1_RES_Pos)                    /*!< 0x03000000 */
#define ADC_CR1_RES               ADC_CR1_RES_Msk                              /*!<RES[2:0] bits (Resolution) */
#define ADC_CR1_RES_0             (0x1U << ADC_CR1_RES_Pos)                    /*!< 0x01000000 */
#define ADC_CR1_RES_1             (0x2U << ADC_CR1_RES_Pos)                    /*!< 0x02000000 */
#define ADC_CR1_OVRIE_Pos         (26U)                                        
#define ADC_CR1_OVRIE_Msk         (0x1U << ADC_CR1_OVRIE_Pos)                  /*!< 0x04000000 */
#define ADC_CR1_OVRIE             ADC_CR1_OVRIE_Msk                            /*!<overrun interrupt enable */
  
/*******************  Bit definition for ADC_CR2 register  ********************/
#define ADC_CR2_ADON_Pos          (0U)                                         
#define ADC_CR2_ADON_Msk          (0x1U << ADC_CR2_ADON_Pos)                   /*!< 0x00000001 */
#define ADC_CR2_ADON              ADC_CR2_ADON_Msk                             /*!<A/D Converter ON / OFF */
#define ADC_CR2_CONT_Pos          (1U)                                         
#define ADC_CR2_CONT_Msk          (0x1U << ADC_CR2_CONT_Pos)                   /*!< 0x00000002 */
#define ADC_CR2_CONT              ADC_CR2_CONT_Msk                             /*!<Continuous Conversion */
#define ADC_CR2_DMA_Pos           (8U)                                         
#define ADC_CR2_DMA_Msk           (0x1U << ADC_CR2_DMA_Pos)                    /*!< 0x00000100 */
#define ADC_CR2_DMA               ADC_CR2_DMA_Msk                              /*!<Direct Memory access mode */
#define ADC_CR2_DDS_Pos           (9U)                                         
#define ADC_CR2_DDS_Msk           (0x1U << ADC_CR2_DDS_Pos)                    /*!< 0x00000200 */
#define ADC_CR2_DDS               ADC_CR2_DDS_Msk                              /*!<DMA disable selection (Single ADC) */
#define ADC_CR2_EOCS_Pos          (10U)                                        
#define ADC_CR2_EOCS_Msk          (0x1U << ADC_CR2_EOCS_Pos)                   /*!< 0x00000400 */
#define ADC_CR2_EOCS              ADC_CR2_EOCS_Msk                             /*!<End of conversion selection */
#define ADC_CR2_ALIGN_Pos         (11U)                                        
#define ADC_CR2_ALIGN_Msk         (0x1U << ADC_CR2_ALIGN_Pos)                  /*!< 0x00000800 */
#define ADC_CR2_ALIGN             ADC_CR2_ALIGN_Msk                            /*!<Data Alignment */
#define ADC_CR2_JEXTSEL_Pos       (16U)                                        
#define ADC_CR2_JEXTSEL_Msk       (0xFU << ADC_CR2_JEXTSEL_Pos)                /*!< 0x000F0000 */
#define ADC_CR2_JEXTSEL           ADC_CR2_JEXTSEL_Msk                          /*!<JEXTSEL[3:0] bits (External event select for injected group) */
#define ADC_CR2_JEXTSEL_0         (0x1U << ADC_CR2_JEXTSEL_Pos)                /*!< 0x00010000 */
#define ADC_CR2_JEXTSEL_1         (0x2U << ADC_CR2_JEXTSEL_Pos)                /*!< 0x00020000 */
#define ADC_CR2_JEXTSEL_2         (0x4U << ADC_CR2_JEXTSEL_Pos)                /*!< 0x00040000 */
#define ADC_CR2_JEXTSEL_3         (0x8U << ADC_CR2_JEXTSEL_Pos)                /*!< 0x00080000 */
#define ADC_CR2_JEXTEN_Pos        (20U)                                        
#define ADC_CR2_JEXTEN_Msk        (0x3U << ADC_CR2_JEXTEN_Pos)                 /*!< 0x00300000 */
#define ADC_CR2_JEXTEN            ADC_CR2_JEXTEN_Msk                           /*!<JEXTEN[1:0] bits (External Trigger Conversion mode for injected channelsp) */
#define ADC_CR2_JEXTEN_0          (0x1U << ADC_CR2_JEXTEN_Pos)                 /*!< 0x00100000 */
#define ADC_CR2_JEXTEN_1          (0x2U << ADC_CR2_JEXTEN_Pos)                 /*!< 0x00200000 */
#define ADC_CR2_JSWSTART_Pos      (22U)                                        
#define ADC_CR2_JSWSTART_Msk      (0x1U << ADC_CR2_JSWSTART_Pos)               /*!< 0x00400000 */
#define ADC_CR2_JSWSTART          ADC_CR2_JSWSTART_Msk                         /*!<Start Conversion of injected channels */
#define ADC_CR2_EXTSEL_Pos        (24U)                                        
#define ADC_CR2_EXTSEL_Msk        (0xFU << ADC_CR2_EXTSEL_Pos)                 /*!< 0x0F000000 */
#define ADC_CR2_EXTSEL            ADC_CR2_EXTSEL_Msk                           /*!<EXTSEL[3:0] bits (External Event Select for regular group) */
#define ADC_CR2_EXTSEL_0          (0x1U << ADC_CR2_EXTSEL_Pos)                 /*!< 0x01000000 */
#define ADC_CR2_EXTSEL_1          (0x2U << ADC_CR2_EXTSEL_Pos)                 /*!< 0x02000000 */
#define ADC_CR2_EXTSEL_2          (0x4U << ADC_CR2_EXTSEL_Pos)                 /*!< 0x04000000 */
#define ADC_CR2_EXTSEL_3          (0x8U << ADC_CR2_EXTSEL_Pos)                 /*!< 0x08000000 */
#define ADC_CR2_EXTEN_Pos         (28U)                                        
#define ADC_CR2_EXTEN_Msk         (0x3U << ADC_CR2_EXTEN_Pos)                  /*!< 0x30000000 */
#define ADC_CR2_EXTEN             ADC_CR2_EXTEN_Msk                            /*!<EXTEN[1:0] bits (External Trigger Conversion mode for regular channelsp) */
#define ADC_CR2_EXTEN_0           (0x1U << ADC_CR2_EXTEN_Pos)                  /*!< 0x10000000 */
#define ADC_CR2_EXTEN_1           (0x2U << ADC_CR2_EXTEN_Pos)                  /*!< 0x20000000 */
#define ADC_CR2_SWSTART_Pos       (30U)                                        
#define ADC_CR2_SWSTART_Msk       (0x1U << ADC_CR2_SWSTART_Pos)                /*!< 0x40000000 */
#define ADC_CR2_SWSTART           ADC_CR2_SWSTART_Msk                          /*!<Start Conversion of regular channels */

/******************  Bit definition for ADC_SMPR1 register  *******************/
#define ADC_SMPR1_SMP10_Pos       (0U)                                         
#define ADC_SMPR1_SMP10_Msk       (0x7U << ADC_SMPR1_SMP10_Pos)                /*!< 0x00000007 */
#define ADC_SMPR1_SMP10           ADC_SMPR1_SMP10_Msk                          /*!<SMP10[2:0] bits (Channel 10 Sample time selection) */
#define ADC_SMPR1_SMP10_0         (0x1U << ADC_SMPR1_SMP10_Pos)                /*!< 0x00000001 */
#define ADC_SMPR1_SMP10_1         (0x2U << ADC_SMPR1_SMP10_Pos)                /*!< 0x00000002 */
#define ADC_SMPR1_SMP10_2         (0x4U << ADC_SMPR1_SMP10_Pos)                /*!< 0x00000004 */
#define ADC_SMPR1_SMP11_Pos       (3U)                                         
#define ADC_SMPR1_SMP11_Msk       (0x7U << ADC_SMPR1_SMP11_Pos)                /*!< 0x00000038 */
#define ADC_SMPR1_SMP11           ADC_SMPR1_SMP11_Msk                          /*!<SMP11[2:0] bits (Channel 11 Sample time selection) */
#define ADC_SMPR1_SMP11_0         (0x1U << ADC_SMPR1_SMP11_Pos)                /*!< 0x00000008 */
#define ADC_SMPR1_SMP11_1         (0x2U << ADC_SMPR1_SMP11_Pos)                /*!< 0x00000010 */
#define ADC_SMPR1_SMP11_2         (0x4U << ADC_SMPR1_SMP11_Pos)                /*!< 0x00000020 */
#define ADC_SMPR1_SMP12_Pos       (6U)                                         
#define ADC_SMPR1_SMP12_Msk       (0x7U << ADC_SMPR1_SMP12_Pos)                /*!< 0x000001C0 */
#define ADC_SMPR1_SMP12           ADC_SMPR1_SMP12_Msk                          /*!<SMP12[2:0] bits (Channel 12 Sample time selection) */
#define ADC_SMPR1_SMP12_0         (0x1U << ADC_SMPR1_SMP12_Pos)                /*!< 0x00000040 */
#define ADC_SMPR1_SMP12_1         (0x2U << ADC_SMPR1_SMP12_Pos)                /*!< 0x00000080 */
#define ADC_SMPR1_SMP12_2         (0x4U << ADC_SMPR1_SMP12_Pos)                /*!< 0x00000100 */
#define ADC_SMPR1_SMP13_Pos       (9U)                                         
#define ADC_SMPR1_SMP13_Msk       (0x7U << ADC_SMPR1_SMP13_Pos)                /*!< 0x00000E00 */
#define ADC_SMPR1_SMP13           ADC_SMPR1_SMP13_Msk                          /*!<SMP13[2:0] bits (Channel 13 Sample time selection) */
#define ADC_SMPR1_SMP13_0         (0x1U << ADC_SMPR1_SMP13_Pos)                /*!< 0x00000200 */
#define ADC_SMPR1_SMP13_1         (0x2U << ADC_SMPR1_SMP13_Pos)                /*!< 0x00000400 */
#define ADC_SMPR1_SMP13_2         (0x4U << ADC_SMPR1_SMP13_Pos)                /*!< 0x00000800 */
#define ADC_SMPR1_SMP14_Pos       (12U)                                        
#define ADC_SMPR1_SMP14_Msk       (0x7U << ADC_SMPR1_SMP14_Pos)                /*!< 0x00007000 */
#define ADC_SMPR1_SMP14           ADC_SMPR1_SMP14_Msk                          /*!<SMP14[2:0] bits (Channel 14 Sample time selection) */
#define ADC_SMPR1_SMP14_0         (0x1U << ADC_SMPR1_SMP14_Pos)                /*!< 0x00001000 */
#define ADC_SMPR1_SMP14_1         (0x2U << ADC_SMPR1_SMP14_Pos)                /*!< 0x00002000 */
#define ADC_SMPR1_SMP14_2         (0x4U << ADC_SMPR1_SMP14_Pos)                /*!< 0x00004000 */
#define ADC_SMPR1_SMP15_Pos       (15U)                                        
#define ADC_SMPR1_SMP15_Msk       (0x7U << ADC_SMPR1_SMP15_Pos)                /*!< 0x00038000 */
#define ADC_SMPR1_SMP15           ADC_SMPR1_SMP15_Msk                          /*!<SMP15[2:0] bits (Channel 15 Sample time selection) */
#define ADC_SMPR1_SMP15_0         (0x1U << ADC_SMPR1_SMP15_Pos)                /*!< 0x00008000 */
#define ADC_SMPR1_SMP15_1         (0x2U << ADC_SMPR1_SMP15_Pos)                /*!< 0x00010000 */
#define ADC_SMPR1_SMP15_2         (0x4U << ADC_SMPR1_SMP15_Pos)                /*!< 0x00020000 */
#define ADC_SMPR1_SMP16_Pos       (18U)                                        
#define ADC_SMPR1_SMP16_Msk       (0x7U << ADC_SMPR1_SMP16_Pos)                /*!< 0x001C0000 */
#define ADC_SMPR1_SMP16           ADC_SMPR1_SMP16_Msk                          /*!<SMP16[2:0] bits (Channel 16 Sample time selection) */
#define ADC_SMPR1_SMP16_0         (0x1U << ADC_SMPR1_SMP16_Pos)                /*!< 0x00040000 */
#define ADC_SMPR1_SMP16_1         (0x2U << ADC_SMPR1_SMP16_Pos)                /*!< 0x00080000 */
#define ADC_SMPR1_SMP16_2         (0x4U << ADC_SMPR1_SMP16_Pos)                /*!< 0x00100000 */
#define ADC_SMPR1_SMP17_Pos       (21U)                                        
#define ADC_SMPR1_SMP17_Msk       (0x7U << ADC_SMPR1_SMP17_Pos)                /*!< 0x00E00000 */
#define ADC_SMPR1_SMP17           ADC_SMPR1_SMP17_Msk                          /*!<SMP17[2:0] bits (Channel 17 Sample time selection) */
#define ADC_SMPR1_SMP17_0         (0x1U << ADC_SMPR1_SMP17_Pos)                /*!< 0x00200000 */
#define ADC_SMPR1_SMP17_1         (0x2U << ADC_SMPR1_SMP17_Pos)                /*!< 0x00400000 */
#define ADC_SMPR1_SMP17_2         (0x4U << ADC_SMPR1_SMP17_Pos)                /*!< 0x00800000 */
#define ADC_SMPR1_SMP18_Pos       (24U)                                        
#define ADC_SMPR1_SMP18_Msk       (0x7U << ADC_SMPR1_SMP18_Pos)                /*!< 0x07000000 */
#define ADC_SMPR1_SMP18           ADC_SMPR1_SMP18_Msk                          /*!<SMP18[2:0] bits (Channel 18 Sample time selection) */
#define ADC_SMPR1_SMP18_0         (0x1U << ADC_SMPR1_SMP18_Pos)                /*!< 0x01000000 */
#define ADC_SMPR1_SMP18_1         (0x2U << ADC_SMPR1_SMP18_Pos)                /*!< 0x02000000 */
#define ADC_SMPR1_SMP18_2         (0x4U << ADC_SMPR1_SMP18_Pos)                /*!< 0x04000000 */

/******************  Bit definition for ADC_SMPR2 register  *******************/
#define ADC_SMPR2_SMP0_Pos        (0U)                                         
#define ADC_SMPR2_SMP0_Msk        (0x7U << ADC_SMPR2_SMP0_Pos)                 /*!< 0x00000007 */
#define ADC_SMPR2_SMP0            ADC_SMPR2_SMP0_Msk                           /*!<SMP0[2:0] bits (Channel 0 Sample time selection) */
#define ADC_SMPR2_SMP0_0          (0x1U << ADC_SMPR2_SMP0_Pos)                 /*!< 0x00000001 */
#define ADC_SMPR2_SMP0_1          (0x2U << ADC_SMPR2_SMP0_Pos)                 /*!< 0x00000002 */
#define ADC_SMPR2_SMP0_2          (0x4U << ADC_SMPR2_SMP0_Pos)                 /*!< 0x00000004 */
#define ADC_SMPR2_SMP1_Pos        (3U)                                         
#define ADC_SMPR2_SMP1_Msk        (0x7U << ADC_SMPR2_SMP1_Pos)                 /*!< 0x00000038 */
#define ADC_SMPR2_SMP1            ADC_SMPR2_SMP1_Msk                           /*!<SMP1[2:0] bits (Channel 1 Sample time selection) */
#define ADC_SMPR2_SMP1_0          (0x1U << ADC_SMPR2_SMP1_Pos)                 /*!< 0x00000008 */
#define ADC_SMPR2_SMP1_1          (0x2U << ADC_SMPR2_SMP1_Pos)                 /*!< 0x00000010 */
#define ADC_SMPR2_SMP1_2          (0x4U << ADC_SMPR2_SMP1_Pos)                 /*!< 0x00000020 */
#define ADC_SMPR2_SMP2_Pos        (6U)                                         
#define ADC_SMPR2_SMP2_Msk        (0x7U << ADC_SMPR2_SMP2_Pos)                 /*!< 0x000001C0 */
#define ADC_SMPR2_SMP2            ADC_SMPR2_SMP2_Msk                           /*!<SMP2[2:0] bits (Channel 2 Sample time selection) */
#define ADC_SMPR2_SMP2_0          (0x1U << ADC_SMPR2_SMP2_Pos)                 /*!< 0x00000040 */
#define ADC_SMPR2_SMP2_1          (0x2U << ADC_SMPR2_SMP2_Pos)                 /*!< 0x00000080 */
#define ADC_SMPR2_SMP2_2          (0x4U << ADC_SMPR2_SMP2_Pos)                 /*!< 0x00000100 */
#define ADC_SMPR2_SMP3_Pos        (9U)                                         
#define ADC_SMPR2_SMP3_Msk        (0x7U << ADC_SMPR2_SMP3_Pos)                 /*!< 0x00000E00 */
#define ADC_SMPR2_SMP3            ADC_SMPR2_SMP3_Msk                           /*!<SMP3[2:0] bits (Channel 3 Sample time selection) */
#define ADC_SMPR2_SMP3_0          (0x1U << ADC_SMPR2_SMP3_Pos)                 /*!< 0x00000200 */
#define ADC_SMPR2_SMP3_1          (0x2U << ADC_SMPR2_SMP3_Pos)                 /*!< 0x00000400 */
#define ADC_SMPR2_SMP3_2          (0x4U << ADC_SMPR2_SMP3_Pos)                 /*!< 0x00000800 */
#define ADC_SMPR2_SMP4_Pos        (12U)                                        
#define ADC_SMPR2_SMP4_Msk        (0x7U << ADC_SMPR2_SMP4_Pos)                 /*!< 0x00007000 */
#define ADC_SMPR2_SMP4            ADC_SMPR2_SMP4_Msk                           /*!<SMP4[2:0] bits (Channel 4 Sample time selection) */
#define ADC_SMPR2_SMP4_0          (0x1U << ADC_SMPR2_SMP4_Pos)                 /*!< 0x00001000 */
#define ADC_SMPR2_SMP4_1          (0x2U << ADC_SMPR2_SMP4_Pos)                 /*!< 0x00002000 */
#define ADC_SMPR2_SMP4_2          (0x4U << ADC_SMPR2_SMP4_Pos)                 /*!< 0x00004000 */
#define ADC_SMPR2_SMP5_Pos        (15U)                                        
#define ADC_SMPR2_SMP5_Msk        (0x7U << ADC_SMPR2_SMP5_Pos)                 /*!< 0x00038000 */
#define ADC_SMPR2_SMP5            ADC_SMPR2_SMP5_Msk                           /*!<SMP5[2:0] bits (Channel 5 Sample time selection) */
#define ADC_SMPR2_SMP5_0          (0x1U << ADC_SMPR2_SMP5_Pos)                 /*!< 0x00008000 */
#define ADC_SMPR2_SMP5_1          (0x2U << ADC_SMPR2_SMP5_Pos)                 /*!< 0x00010000 */
#define ADC_SMPR2_SMP5_2          (0x4U << ADC_SMPR2_SMP5_Pos)                 /*!< 0x00020000 */
#define ADC_SMPR2_SMP6_Pos        (18U)                                        
#define ADC_SMPR2_SMP6_Msk        (0x7U << ADC_SMPR2_SMP6_Pos)                 /*!< 0x001C0000 */
#define ADC_SMPR2_SMP6            ADC_SMPR2_SMP6_Msk                           /*!<SMP6[2:0] bits (Channel 6 Sample time selection) */
#define ADC_SMPR2_SMP6_0          (0x1U << ADC_SMPR2_SMP6_Pos)                 /*!< 0x00040000 */
#define ADC_SMPR2_SMP6_1          (0x2U << ADC_SMPR2_SMP6_Pos)                 /*!< 0x00080000 */
#define ADC_SMPR2_SMP6_2          (0x4U << ADC_SMPR2_SMP6_Pos)                 /*!< 0x00100000 */
#define ADC_SMPR2_SMP7_Pos        (21U)                                        
#define ADC_SMPR2_SMP7_Msk        (0x7U << ADC_SMPR2_SMP7_Pos)                 /*!< 0x00E00000 */
#define ADC_SMPR2_SMP7            ADC_SMPR2_SMP7_Msk                           /*!<SMP7[2:0] bits (Channel 7 Sample time selection) */
#define ADC_SMPR2_SMP7_0          (0x1U << ADC_SMPR2_SMP7_Pos)                 /*!< 0x00200000 */
#define ADC_SMPR2_SMP7_1          (0x2U << ADC_SMPR2_SMP7_Pos)                 /*!< 0x00400000 */
#define ADC_SMPR2_SMP7_2          (0x4U << ADC_SMPR2_SMP7_Pos)                 /*!< 0x00800000 */
#define ADC_SMPR2_SMP8_Pos        (24U)                                        
#define ADC_SMPR2_SMP8_Msk        (0x7U << ADC_SMPR2_SMP8_Pos)                 /*!< 0x07000000 */
#define ADC_SMPR2_SMP8            ADC_SMPR2_SMP8_Msk                           /*!<SMP8[2:0] bits (Channel 8 Sample time selection) */
#define ADC_SMPR2_SMP8_0          (0x1U << ADC_SMPR2_SMP8_Pos)                 /*!< 0x01000000 */
#define ADC_SMPR2_SMP8_1          (0x2U << ADC_SMPR2_SMP8_Pos)                 /*!< 0x02000000 */
#define ADC_SMPR2_SMP8_2          (0x4U << ADC_SMPR2_SMP8_Pos)                 /*!< 0x04000000 */
#define ADC_SMPR2_SMP9_Pos        (27U)                                        
#define ADC_SMPR2_SMP9_Msk        (0x7U << ADC_SMPR2_SMP9_Pos)                 /*!< 0x38000000 */
#define ADC_SMPR2_SMP9            ADC_SMPR2_SMP9_Msk                           /*!<SMP9[2:0] bits (Channel 9 Sample time selection) */
#define ADC_SMPR2_SMP9_0          (0x1U << ADC_SMPR2_SMP9_Pos)                 /*!< 0x08000000 */
#define ADC_SMPR2_SMP9_1          (0x2U << ADC_SMPR2_SMP9_Pos)                 /*!< 0x10000000 */
#define ADC_SMPR2_SMP9_2          (0x4U << ADC_SMPR2_SMP9_Pos)                 /*!< 0x20000000 */

/******************  Bit definition for ADC_JOFR1 register  *******************/
#define ADC_JOFR1_JOFFSET1_Pos    (0U)                                         
#define ADC_JOFR1_JOFFSET1_Msk    (0xFFFU << ADC_JOFR1_JOFFSET1_Pos)           /*!< 0x00000FFF */
#define ADC_JOFR1_JOFFSET1        ADC_JOFR1_JOFFSET1_Msk                       /*!<Data offset for injected channel 1 */

/******************  Bit definition for ADC_JOFR2 register  *******************/
#define ADC_JOFR2_JOFFSET2_Pos    (0U)                                         
#define ADC_JOFR2_JOFFSET2_Msk    (0xFFFU << ADC_JOFR2_JOFFSET2_Pos)           /*!< 0x00000FFF */
#define ADC_JOFR2_JOFFSET2        ADC_JOFR2_JOFFSET2_Msk                       /*!<Data offset for injected channel 2 */

/******************  Bit definition for ADC_JOFR3 register  *******************/
#define ADC_JOFR3_JOFFSET3_Pos    (0U)                                         
#define ADC_JOFR3_JOFFSET3_Msk    (0xFFFU << ADC_JOFR3_JOFFSET3_Pos)           /*!< 0x00000FFF */
#define ADC_JOFR3_JOFFSET3        ADC_JOFR3_JOFFSET3_Msk                       /*!<Data offset for injected channel 3 */

/******************  Bit definition for ADC_JOFR4 register  *******************/
#define ADC_JOFR4_JOFFSET4_Pos    (0U)                                         
#define ADC_JOFR4_JOFFSET4_Msk    (0xFFFU << ADC_JOFR4_JOFFSET4_Pos)           /*!< 0x00000FFF */
#define ADC_JOFR4_JOFFSET4        ADC_JOFR4_JOFFSET4_Msk                       /*!<Data offset for injected channel 4 */

/*******************  Bit definition for ADC_HTR register  ********************/
#define ADC_HTR_HT_Pos            (0U)                                         
#define ADC_HTR_HT_Msk            (0xFFFU << ADC_HTR_HT_Pos)                   /*!< 0x00000FFF */
#define ADC_HTR_HT                ADC_HTR_HT_Msk                               /*!<Analog watchdog high threshold */

/*******************  Bit definition for ADC_LTR register  ********************/
#define ADC_LTR_LT_Pos            (0U)                                         
#define ADC_LTR_LT_Msk            (0xFFFU << ADC_LTR_LT_Pos)                   /*!< 0x00000FFF */
#define ADC_LTR_LT                ADC_LTR_LT_Msk                               /*!<Analog watchdog low threshold */

/*******************  Bit definition for ADC_SQR1 register  *******************/
#define ADC_SQR1_SQ13_Pos         (0U)                                         
#define ADC_SQR1_SQ13_Msk         (0x1FU << ADC_SQR1_SQ13_Pos)                 /*!< 0x0000001F */
#define ADC_SQR1_SQ13             ADC_SQR1_SQ13_Msk                            /*!<SQ13[4:0] bits (13th conversion in regular sequence) */
#define ADC_SQR1_SQ13_0           (0x01U << ADC_SQR1_SQ13_Pos)                 /*!< 0x00000001 */
#define ADC_SQR1_SQ13_1           (0x02U << ADC_SQR1_SQ13_Pos)                 /*!< 0x00000002 */
#define ADC_SQR1_SQ13_2           (0x04U << ADC_SQR1_SQ13_Pos)                 /*!< 0x00000004 */
#define ADC_SQR1_SQ13_3           (0x08U << ADC_SQR1_SQ13_Pos)                 /*!< 0x00000008 */
#define ADC_SQR1_SQ13_4           (0x10U << ADC_SQR1_SQ13_Pos)                 /*!< 0x00000010 */
#define ADC_SQR1_SQ14_Pos         (5U)                                         
#define ADC_SQR1_SQ14_Msk         (0x1FU << ADC_SQR1_SQ14_Pos)                 /*!< 0x000003E0 */
#define ADC_SQR1_SQ14             ADC_SQR1_SQ14_Msk                            /*!<SQ14[4:0] bits (14th conversion in regular sequence) */
#define ADC_SQR1_SQ14_0           (0x01U << ADC_SQR1_SQ14_Pos)                 /*!< 0x00000020 */
#define ADC_SQR1_SQ14_1           (0x02U << ADC_SQR1_SQ14_Pos)                 /*!< 0x00000040 */
#define ADC_SQR1_SQ14_2           (0x04U << ADC_SQR1_SQ14_Pos)                 /*!< 0x00000080 */
#define ADC_SQR1_SQ14_3           (0x08U << ADC_SQR1_SQ14_Pos)                 /*!< 0x00000100 */
#define ADC_SQR1_SQ14_4           (0x10U << ADC_SQR1_SQ14_Pos)                 /*!< 0x00000200 */
#define ADC_SQR1_SQ15_Pos         (10U)                                        
#define ADC_SQR1_SQ15_Msk         (0x1FU << ADC_SQR1_SQ15_Pos)                 /*!< 0x00007C00 */
#define ADC_SQR1_SQ15             ADC_SQR1_SQ15_Msk                            /*!<SQ15[4:0] bits (15th conversion in regular sequence) */
#define ADC_SQR1_SQ15_0           (0x01U << ADC_SQR1_SQ15_Pos)                 /*!< 0x00000400 */
#define ADC_SQR1_SQ15_1           (0x02U << ADC_SQR1_SQ15_Pos)                 /*!< 0x00000800 */
#define ADC_SQR1_SQ15_2           (0x04U << ADC_SQR1_SQ15_Pos)                 /*!< 0x00001000 */
#define ADC_SQR1_SQ15_3           (0x08U << ADC_SQR1_SQ15_Pos)                 /*!< 0x00002000 */
#define ADC_SQR1_SQ15_4           (0x10U << ADC_SQR1_SQ15_Pos)                 /*!< 0x00004000 */
#define ADC_SQR1_SQ16_Pos         (15U)                                        
#define ADC_SQR1_SQ16_Msk         (0x1FU << ADC_SQR1_SQ16_Pos)                 /*!< 0x000F8000 */
#define ADC_SQR1_SQ16             ADC_SQR1_SQ16_Msk                            /*!<SQ16[4:0] bits (16th conversion in regular sequence) */
#define ADC_SQR1_SQ16_0           (0x01U << ADC_SQR1_SQ16_Pos)                 /*!< 0x00008000 */
#define ADC_SQR1_SQ16_1           (0x02U << ADC_SQR1_SQ16_Pos)                 /*!< 0x00010000 */
#define ADC_SQR1_SQ16_2           (0x04U << ADC_SQR1_SQ16_Pos)                 /*!< 0x00020000 */
#define ADC_SQR1_SQ16_3           (0x08U << ADC_SQR1_SQ16_Pos)                 /*!< 0x00040000 */
#define ADC_SQR1_SQ16_4           (0x10U << ADC_SQR1_SQ16_Pos)                 /*!< 0x00080000 */
#define ADC_SQR1_L_Pos            (20U)                                        
#define ADC_SQR1_L_Msk            (0xFU << ADC_SQR1_L_Pos)                     /*!< 0x00F00000 */
#define ADC_SQR1_L                ADC_SQR1_L_Msk                               /*!<L[3:0] bits (Regular channel sequence length) */
#define ADC_SQR1_L_0              (0x1U << ADC_SQR1_L_Pos)                     /*!< 0x00100000 */
#define ADC_SQR1_L_1              (0x2U << ADC_SQR1_L_Pos)                     /*!< 0x00200000 */
#define ADC_SQR1_L_2              (0x4U << ADC_SQR1_L_Pos)                     /*!< 0x00400000 */
#define ADC_SQR1_L_3              (0x8U << ADC_SQR1_L_Pos)                     /*!< 0x00800000 */

/*******************  Bit definition for ADC_SQR2 register  *******************/
#define ADC_SQR2_SQ7_Pos          (0U)                                         
#define ADC_SQR2_SQ7_Msk          (0x1FU << ADC_SQR2_SQ7_Pos)                  /*!< 0x0000001F */
#define ADC_SQR2_SQ7              ADC_SQR2_SQ7_Msk                             /*!<SQ7[4:0] bits (7th conversion in regular sequence) */
#define ADC_SQR2_SQ7_0            (0x01U << ADC_SQR2_SQ7_Pos)                  /*!< 0x00000001 */
#define ADC_SQR2_SQ7_1            (0x02U << ADC_SQR2_SQ7_Pos)                  /*!< 0x00000002 */
#define ADC_SQR2_SQ7_2            (0x04U << ADC_SQR2_SQ7_Pos)                  /*!< 0x00000004 */
#define ADC_SQR2_SQ7_3            (0x08U << ADC_SQR2_SQ7_Pos)                  /*!< 0x00000008 */
#define ADC_SQR2_SQ7_4            (0x10U << ADC_SQR2_SQ7_Pos)                  /*!< 0x00000010 */
#define ADC_SQR2_SQ8_Pos          (5U)                                         
#define ADC_SQR2_SQ8_Msk          (0x1FU << ADC_SQR2_SQ8_Pos)                  /*!< 0x000003E0 */
#define ADC_SQR2_SQ8              ADC_SQR2_SQ8_Msk                             /*!<SQ8[4:0] bits (8th conversion in regular sequence) */
#define ADC_SQR2_SQ8_0            (0x01U << ADC_SQR2_SQ8_Pos)                  /*!< 0x00000020 */
#define ADC_SQR2_SQ8_1            (0x02U << ADC_SQR2_SQ8_Pos)                  /*!< 0x00000040 */
#define ADC_SQR2_SQ8_2            (0x04U << ADC_SQR2_SQ8_Pos)                  /*!< 0x00000080 */
#define ADC_SQR2_SQ8_3            (0x08U << ADC_SQR2_SQ8_Pos)                  /*!< 0x00000100 */
#define ADC_SQR2_SQ8_4            (0x10U << ADC_SQR2_SQ8_Pos)                  /*!< 0x00000200 */
#define ADC_SQR2_SQ9_Pos          (10U)                                        
#define ADC_SQR2_SQ9_Msk          (0x1FU << ADC_SQR2_SQ9_Pos)                  /*!< 0x00007C00 */
#define ADC_SQR2_SQ9              ADC_SQR2_SQ9_Msk                             /*!<SQ9[4:0] bits (9th conversion in regular sequence) */
#define ADC_SQR2_SQ9_0            (0x01U << ADC_SQR2_SQ9_Pos)                  /*!< 0x00000400 */
#define ADC_SQR2_SQ9_1            (0x02U << ADC_SQR2_SQ9_Pos)                  /*!< 0x00000800 */
#define ADC_SQR2_SQ9_2            (0x04U << ADC_SQR2_SQ9_Pos)                  /*!< 0x00001000 */
#define ADC_SQR2_SQ9_3            (0x08U << ADC_SQR2_SQ9_Pos)                  /*!< 0x00002000 */
#define ADC_SQR2_SQ9_4            (0x10U << ADC_SQR2_SQ9_Pos)                  /*!< 0x00004000 */
#define ADC_SQR2_SQ10_Pos         (15U)                                        
#define ADC_SQR2_SQ10_Msk         (0x1FU << ADC_SQR2_SQ10_Pos)                 /*!< 0x000F8000 */
#define ADC_SQR2_SQ10             ADC_SQR2_SQ10_Msk                            /*!<SQ10[4:0] bits (10th conversion in regular sequence) */
#define ADC_SQR2_SQ10_0           (0x01U << ADC_SQR2_SQ10_Pos)                 /*!< 0x00008000 */
#define ADC_SQR2_SQ10_1           (0x02U << ADC_SQR2_SQ10_Pos)                 /*!< 0x00010000 */
#define ADC_SQR2_SQ10_2           (0x04U << ADC_SQR2_SQ10_Pos)                 /*!< 0x00020000 */
#define ADC_SQR2_SQ10_3           (0x08U << ADC_SQR2_SQ10_Pos)                 /*!< 0x00040000 */
#define ADC_SQR2_SQ10_4           (0x10U << ADC_SQR2_SQ10_Pos)                 /*!< 0x00080000 */
#define ADC_SQR2_SQ11_Pos         (20U)                                        
#define ADC_SQR2_SQ11_Msk         (0x1FU << ADC_SQR2_SQ11_Pos)                 /*!< 0x01F00000 */
#define ADC_SQR2_SQ11             ADC_SQR2_SQ11_Msk                            /*!<SQ11[4:0] bits (11th conversion in regular sequence) */
#define ADC_SQR2_SQ11_0           (0x01U << ADC_SQR2_SQ11_Pos)                 /*!< 0x00100000 */
#define ADC_SQR2_SQ11_1           (0x02U << ADC_SQR2_SQ11_Pos)                 /*!< 0x00200000 */
#define ADC_SQR2_SQ11_2           (0x04U << ADC_SQR2_SQ11_Pos)                 /*!< 0x00400000 */
#define ADC_SQR2_SQ11_3           (0x08U << ADC_SQR2_SQ11_Pos)                 /*!< 0x00800000 */
#define ADC_SQR2_SQ11_4           (0x10U << ADC_SQR2_SQ11_Pos)                 /*!< 0x01000000 */
#define ADC_SQR2_SQ12_Pos         (25U)                                        
#define ADC_SQR2_SQ12_Msk         (0x1FU << ADC_SQR2_SQ12_Pos)                 /*!< 0x3E000000 */
#define ADC_SQR2_SQ12             ADC_SQR2_SQ12_Msk                            /*!<SQ12[4:0] bits (12th conversion in regular sequence) */
#define ADC_SQR2_SQ12_0           (0x01U << ADC_SQR2_SQ12_Pos)                 /*!< 0x02000000 */
#define ADC_SQR2_SQ12_1           (0x02U << ADC_SQR2_SQ12_Pos)                 /*!< 0x04000000 */
#define ADC_SQR2_SQ12_2           (0x04U << ADC_SQR2_SQ12_Pos)                 /*!< 0x08000000 */
#define ADC_SQR2_SQ12_3           (0x08U << ADC_SQR2_SQ12_Pos)                 /*!< 0x10000000 */
#define ADC_SQR2_SQ12_4           (0x10U << ADC_SQR2_SQ12_Pos)                 /*!< 0x20000000 */

/*******************  Bit definition for ADC_SQR3 register  *******************/
#define ADC_SQR3_SQ1_Pos          (0U)                                         
#define ADC_SQR3_SQ1_Msk          (0x1FU << ADC_SQR3_SQ1_Pos)                  /*!< 0x0000001F */
#define ADC_SQR3_SQ1              ADC_SQR3_SQ1_Msk                             /*!<SQ1[4:0] bits (1st conversion in regular sequence) */
#define ADC_SQR3_SQ1_0            (0x01U << ADC_SQR3_SQ1_Pos)                  /*!< 0x00000001 */
#define ADC_SQR3_SQ1_1            (0x02U << ADC_SQR3_SQ1_Pos)                  /*!< 0x00000002 */
#define ADC_SQR3_SQ1_2            (0x04U << ADC_SQR3_SQ1_Pos)                  /*!< 0x00000004 */
#define ADC_SQR3_SQ1_3            (0x08U << ADC_SQR3_SQ1_Pos)                  /*!< 0x00000008 */
#define ADC_SQR3_SQ1_4            (0x10U << ADC_SQR3_SQ1_Pos)                  /*!< 0x00000010 */
#define ADC_SQR3_SQ2_Pos          (5U)                                         
#define ADC_SQR3_SQ2_Msk          (0x1FU << ADC_SQR3_SQ2_Pos)                  /*!< 0x000003E0 */
#define ADC_SQR3_SQ2              ADC_SQR3_SQ2_Msk                             /*!<SQ2[4:0] bits (2nd conversion in regular sequence) */
#define ADC_SQR3_SQ2_0            (0x01U << ADC_SQR3_SQ2_Pos)                  /*!< 0x00000020 */
#define ADC_SQR3_SQ2_1            (0x02U << ADC_SQR3_SQ2_Pos)                  /*!< 0x00000040 */
#define ADC_SQR3_SQ2_2            (0x04U << ADC_SQR3_SQ2_Pos)                  /*!< 0x00000080 */
#define ADC_SQR3_SQ2_3            (0x08U << ADC_SQR3_SQ2_Pos)                  /*!< 0x00000100 */
#define ADC_SQR3_SQ2_4            (0x10U << ADC_SQR3_SQ2_Pos)                  /*!< 0x00000200 */
#define ADC_SQR3_SQ3_Pos          (10U)                                        
#define ADC_SQR3_SQ3_Msk          (0x1FU << ADC_SQR3_SQ3_Pos)                  /*!< 0x00007C00 */
#define ADC_SQR3_SQ3              ADC_SQR3_SQ3_Msk                             /*!<SQ3[4:0] bits (3rd conversion in regular sequence) */
#define ADC_SQR3_SQ3_0            (0x01U << ADC_SQR3_SQ3_Pos)                  /*!< 0x00000400 */
#define ADC_SQR3_SQ3_1            (0x02U << ADC_SQR3_SQ3_Pos)                  /*!< 0x00000800 */
#define ADC_SQR3_SQ3_2            (0x04U << ADC_SQR3_SQ3_Pos)                  /*!< 0x00001000 */
#define ADC_SQR3_SQ3_3            (0x08U << ADC_SQR3_SQ3_Pos)                  /*!< 0x00002000 */
#define ADC_SQR3_SQ3_4            (0x10U << ADC_SQR3_SQ3_Pos)                  /*!< 0x00004000 */
#define ADC_SQR3_SQ4_Pos          (15U)                                        
#define ADC_SQR3_SQ4_Msk          (0x1FU << ADC_SQR3_SQ4_Pos)                  /*!< 0x000F8000 */
#define ADC_SQR3_SQ4              ADC_SQR3_SQ4_Msk                             /*!<SQ4[4:0] bits (4th conversion in regular sequence) */
#define ADC_SQR3_SQ4_0            (0x01U << ADC_SQR3_SQ4_Pos)                  /*!< 0x00008000 */
#define ADC_SQR3_SQ4_1            (0x02U << ADC_SQR3_SQ4_Pos)                  /*!< 0x00010000 */
#define ADC_SQR3_SQ4_2            (0x04U << ADC_SQR3_SQ4_Pos)                  /*!< 0x00020000 */
#define ADC_SQR3_SQ4_3            (0x08U << ADC_SQR3_SQ4_Pos)                  /*!< 0x00040000 */
#define ADC_SQR3_SQ4_4            (0x10U << ADC_SQR3_SQ4_Pos)                  /*!< 0x00080000 */
#define ADC_SQR3_SQ5_Pos          (20U)                                        
#define ADC_SQR3_SQ5_Msk          (0x1FU << ADC_SQR3_SQ5_Pos)                  /*!< 0x01F00000 */
#define ADC_SQR3_SQ5              ADC_SQR3_SQ5_Msk                             /*!<SQ5[4:0] bits (5th conversion in regular sequence) */
#define ADC_SQR3_SQ5_0            (0x01U << ADC_SQR3_SQ5_Pos)                  /*!< 0x00100000 */
#define ADC_SQR3_SQ5_1            (0x02U << ADC_SQR3_SQ5_Pos)                  /*!< 0x00200000 */
#define ADC_SQR3_SQ5_2            (0x04U << ADC_SQR3_SQ5_Pos)                  /*!< 0x00400000 */
#define ADC_SQR3_SQ5_3            (0x08U << ADC_SQR3_SQ5_Pos)                  /*!< 0x00800000 */
#define ADC_SQR3_SQ5_4            (0x10U << ADC_SQR3_SQ5_Pos)                  /*!< 0x01000000 */
#define ADC_SQR3_SQ6_Pos          (25U)                                        
#define ADC_SQR3_SQ6_Msk          (0x1FU << ADC_SQR3_SQ6_Pos)                  /*!< 0x3E000000 */
#define ADC_SQR3_SQ6              ADC_SQR3_SQ6_Msk                             /*!<SQ6[4:0] bits (6th conversion in regular sequence) */
#define ADC_SQR3_SQ6_0            (0x01U << ADC_SQR3_SQ6_Pos)                  /*!< 0x02000000 */
#define ADC_SQR3_SQ6_1            (0x02U << ADC_SQR3_SQ6_Pos)                  /*!< 0x04000000 */
#define ADC_SQR3_SQ6_2            (0x04U << ADC_SQR3_SQ6_Pos)                  /*!< 0x08000000 */
#define ADC_SQR3_SQ6_3            (0x08U << ADC_SQR3_SQ6_Pos)                  /*!< 0x10000000 */
#define ADC_SQR3_SQ6_4            (0x10U << ADC_SQR3_SQ6_Pos)                  /*!< 0x20000000 */

/*******************  Bit definition for ADC_JSQR register  *******************/
#define ADC_JSQR_JSQ1_Pos         (0U)                                         
#define ADC_JSQR_JSQ1_Msk         (0x1FU << ADC_JSQR_JSQ1_Pos)                 /*!< 0x0000001F */
#define ADC_JSQR_JSQ1             ADC_JSQR_JSQ1_Msk                            /*!<JSQ1[4:0] bits (1st conversion in injected sequence) */  
#define ADC_JSQR_JSQ1_0           (0x01U << ADC_JSQR_JSQ1_Pos)                 /*!< 0x00000001 */
#define ADC_JSQR_JSQ1_1           (0x02U << ADC_JSQR_JSQ1_Pos)                 /*!< 0x00000002 */
#define ADC_JSQR_JSQ1_2           (0x04U << ADC_JSQR_JSQ1_Pos)                 /*!< 0x00000004 */
#define ADC_JSQR_JSQ1_3           (0x08U << ADC_JSQR_JSQ1_Pos)                 /*!< 0x00000008 */
#define ADC_JSQR_JSQ1_4           (0x10U << ADC_JSQR_JSQ1_Pos)                 /*!< 0x00000010 */
#define ADC_JSQR_JSQ2_Pos         (5U)                                         
#define ADC_JSQR_JSQ2_Msk         (0x1FU << ADC_JSQR_JSQ2_Pos)                 /*!< 0x000003E0 */
#define ADC_JSQR_JSQ2             ADC_JSQR_JSQ2_Msk                            /*!<JSQ2[4:0] bits (2nd conversion in injected sequence) */
#define ADC_JSQR_JSQ2_0           (0x01U << ADC_JSQR_JSQ2_Pos)                 /*!< 0x00000020 */
#define ADC_JSQR_JSQ2_1           (0x02U << ADC_JSQR_JSQ2_Pos)                 /*!< 0x00000040 */
#define ADC_JSQR_JSQ2_2           (0x04U << ADC_JSQR_JSQ2_Pos)                 /*!< 0x00000080 */
#define ADC_JSQR_JSQ2_3           (0x08U << ADC_JSQR_JSQ2_Pos)                 /*!< 0x00000100 */
#define ADC_JSQR_JSQ2_4           (0x10U << ADC_JSQR_JSQ2_Pos)                 /*!< 0x00000200 */
#define ADC_JSQR_JSQ3_Pos         (10U)                                        
#define ADC_JSQR_JSQ3_Msk         (0x1FU << ADC_JSQR_JSQ3_Pos)                 /*!< 0x00007C00 */
#define ADC_JSQR_JSQ3             ADC_JSQR_JSQ3_Msk                            /*!<JSQ3[4:0] bits (3rd conversion in injected sequence) */
#define ADC_JSQR_JSQ3_0           (0x01U << ADC_JSQR_JSQ3_Pos)                 /*!< 0x00000400 */
#define ADC_JSQR_JSQ3_1           (0x02U << ADC_JSQR_JSQ3_Pos)                 /*!< 0x00000800 */
#define ADC_JSQR_JSQ3_2           (0x04U << ADC_JSQR_JSQ3_Pos)                 /*!< 0x00001000 */
#define ADC_JSQR_JSQ3_3           (0x08U << ADC_JSQR_JSQ3_Pos)                 /*!< 0x00002000 */
#define ADC_JSQR_JSQ3_4           (0x10U << ADC_JSQR_JSQ3_Pos)                 /*!< 0x00004000 */
#define ADC_JSQR_JSQ4_Pos         (15U)                                        
#define ADC_JSQR_JSQ4_Msk         (0x1FU << ADC_JSQR_JSQ4_Pos)                 /*!< 0x000F8000 */
#define ADC_JSQR_JSQ4             ADC_JSQR_JSQ4_Msk                            /*!<JSQ4[4:0] bits (4th conversion in injected sequence) */
#define ADC_JSQR_JSQ4_0           (0x01U << ADC_JSQR_JSQ4_Pos)                 /*!< 0x00008000 */
#define ADC_JSQR_JSQ4_1           (0x02U << ADC_JSQR_JSQ4_Pos)                 /*!< 0x00010000 */
#define ADC_JSQR_JSQ4_2           (0x04U << ADC_JSQR_JSQ4_Pos)                 /*!< 0x00020000 */
#define ADC_JSQR_JSQ4_3           (0x08U << ADC_JSQR_JSQ4_Pos)                 /*!< 0x00040000 */
#define ADC_JSQR_JSQ4_4           (0x10U << ADC_JSQR_JSQ4_Pos)                 /*!< 0x00080000 */
#define ADC_JSQR_JL_Pos           (20U)                                        
#define ADC_JSQR_JL_Msk           (0x3U << ADC_JSQR_JL_Pos)                    /*!< 0x00300000 */
#define ADC_JSQR_JL               ADC_JSQR_JL_Msk                              /*!<JL[1:0] bits (Injected Sequence length) */
#define ADC_JSQR_JL_0             (0x1U << ADC_JSQR_JL_Pos)                    /*!< 0x00100000 */
#define ADC_JSQR_JL_1             (0x2U << ADC_JSQR_JL_Pos)                    /*!< 0x00200000 */

/*******************  Bit definition for ADC_JDR1 register  *******************/
#define ADC_JDR1_JDATA_Pos        (0U)                                         
#define ADC_JDR1_JDATA_Msk        (0xFFFFU << ADC_JDR1_JDATA_Pos)              /*!< 0x0000FFFF */
#define ADC_JDR1_JDATA            ADC_JDR1_JDATA_Msk                           /*!<Injected data */

/*******************  Bit definition for ADC_JDR2 register  *******************/
#define ADC_JDR2_JDATA_Pos        (0U)                                         
#define ADC_JDR2_JDATA_Msk        (0xFFFFU << ADC_JDR2_JDATA_Pos)              /*!< 0x0000FFFF */
#define ADC_JDR2_JDATA            ADC_JDR2_JDATA_Msk                           /*!<Injected data */

/*******************  Bit definition for ADC_JDR3 register  *******************/
#define ADC_JDR3_JDATA_Pos        (0U)                                         
#define ADC_JDR3_JDATA_Msk        (0xFFFFU << ADC_JDR3_JDATA_Pos)              /*!< 0x0000FFFF */
#define ADC_JDR3_JDATA            ADC_JDR3_JDATA_Msk                           /*!<Injected data */

/*******************  Bit definition for ADC_JDR4 register  *******************/
#define ADC_JDR4_JDATA_Pos        (0U)                                         
#define ADC_JDR4_JDATA_Msk        (0xFFFFU << ADC_JDR4_JDATA_Pos)              /*!< 0x0000FFFF */
#define ADC_JDR4_JDATA            ADC_JDR4_JDATA_Msk                           /*!<Injected data */

/********************  Bit definition for ADC_DR register  ********************/
#define ADC_DR_DATA_Pos           (0U)                                         
#define ADC_DR_DATA_Msk           (0xFFFFU << ADC_DR_DATA_Pos)                 /*!< 0x0000FFFF */
#define ADC_DR_DATA               ADC_DR_DATA_Msk                              /*!<Regular data */
#define ADC_DR_ADC2DATA_Pos       (16U)                                        
#define ADC_DR_ADC2DATA_Msk       (0xFFFFU << ADC_DR_ADC2DATA_Pos)             /*!< 0xFFFF0000 */
#define ADC_DR_ADC2DATA           ADC_DR_ADC2DATA_Msk                          /*!<ADC2 data */

/*******************  Bit definition for ADC_CSR register  ********************/
#define ADC_CSR_AWD1_Pos          (0U)                                         
#define ADC_CSR_AWD1_Msk          (0x1U << ADC_CSR_AWD1_Pos)                   /*!< 0x00000001 */
#define ADC_CSR_AWD1              ADC_CSR_AWD1_Msk                             /*!<ADC1 Analog watchdog flag */
#define ADC_CSR_EOC1_Pos          (1U)                                         
#define ADC_CSR_EOC1_Msk          (0x1U << ADC_CSR_EOC1_Pos)                   /*!< 0x00000002 */
#define ADC_CSR_EOC1              ADC_CSR_EOC1_Msk                             /*!<ADC1 End of conversion */
#define ADC_CSR_JEOC1_Pos         (2U)                                         
#define ADC_CSR_JEOC1_Msk         (0x1U << ADC_CSR_JEOC1_Pos)                  /*!< 0x00000004 */
#define ADC_CSR_JEOC1             ADC_CSR_JEOC1_Msk                            /*!<ADC1 Injected channel end of conversion */
#define ADC_CSR_JSTRT1_Pos        (3U)                                         
#define ADC_CSR_JSTRT1_Msk        (0x1U << ADC_CSR_JSTRT1_Pos)                 /*!< 0x00000008 */
#define ADC_CSR_JSTRT1            ADC_CSR_JSTRT1_Msk                           /*!<ADC1 Injected channel Start flag */
#define ADC_CSR_STRT1_Pos         (4U)                                         
#define ADC_CSR_STRT1_Msk         (0x1U << ADC_CSR_STRT1_Pos)                  /*!< 0x00000010 */
#define ADC_CSR_STRT1             ADC_CSR_STRT1_Msk                            /*!<ADC1 Regular channel Start flag */
#define ADC_CSR_OVR1_Pos          (5U)                                         
#define ADC_CSR_OVR1_Msk          (0x1U << ADC_CSR_OVR1_Pos)                   /*!< 0x00000020 */
#define ADC_CSR_OVR1              ADC_CSR_OVR1_Msk                             /*!<ADC1 DMA overrun  flag */

/* Legacy defines */
#define  ADC_CSR_DOVR1                        ADC_CSR_OVR1

/*******************  Bit definition for ADC_CCR register  ********************/
#define ADC_CCR_MULTI_Pos         (0U)                                         
#define ADC_CCR_MULTI_Msk         (0x1FU << ADC_CCR_MULTI_Pos)                 /*!< 0x0000001F */
#define ADC_CCR_MULTI             ADC_CCR_MULTI_Msk                            /*!<MULTI[4:0] bits (Multi-ADC mode selection) */  
#define ADC_CCR_MULTI_0           (0x01U << ADC_CCR_MULTI_Pos)                 /*!< 0x00000001 */
#define ADC_CCR_MULTI_1           (0x02U << ADC_CCR_MULTI_Pos)                 /*!< 0x00000002 */
#define ADC_CCR_MULTI_2           (0x04U << ADC_CCR_MULTI_Pos)                 /*!< 0x00000004 */
#define ADC_CCR_MULTI_3           (0x08U << ADC_CCR_MULTI_Pos)                 /*!< 0x00000008 */
#define ADC_CCR_MULTI_4           (0x10U << ADC_CCR_MULTI_Pos)                 /*!< 0x00000010 */
#define ADC_CCR_DELAY_Pos         (8U)                                         
#define ADC_CCR_DELAY_Msk         (0xFU << ADC_CCR_DELAY_Pos)                  /*!< 0x00000F00 */
#define ADC_CCR_DELAY             ADC_CCR_DELAY_Msk                            /*!<DELAY[3:0] bits (Delay between 2 sampling phases) */  
#define ADC_CCR_DELAY_0           (0x1U << ADC_CCR_DELAY_Pos)                  /*!< 0x00000100 */
#define ADC_CCR_DELAY_1           (0x2U << ADC_CCR_DELAY_Pos)                  /*!< 0x00000200 */
#define ADC_CCR_DELAY_2           (0x4U << ADC_CCR_DELAY_Pos)                  /*!< 0x00000400 */
#define ADC_CCR_DELAY_3           (0x8U << ADC_CCR_DELAY_Pos)                  /*!< 0x00000800 */
#define ADC_CCR_DDS_Pos           (13U)                                        
#define ADC_CCR_DDS_Msk           (0x1U << ADC_CCR_DDS_Pos)                    /*!< 0x00002000 */
#define ADC_CCR_DDS               ADC_CCR_DDS_Msk                              /*!<DMA disable selection (Multi-ADC mode) */
#define ADC_CCR_DMA_Pos           (14U)                                        
#define ADC_CCR_DMA_Msk           (0x3U << ADC_CCR_DMA_Pos)                    /*!< 0x0000C000 */
#define ADC_CCR_DMA               ADC_CCR_DMA_Msk                              /*!<DMA[1:0] bits (Direct Memory Access mode for multimode) */  
#define ADC_CCR_DMA_0             (0x1U << ADC_CCR_DMA_Pos)                    /*!< 0x00004000 */
#define ADC_CCR_DMA_1             (0x2U << ADC_CCR_DMA_Pos)                    /*!< 0x00008000 */
#define ADC_CCR_ADCPRE_Pos        (16U)                                        
#define ADC_CCR_ADCPRE_Msk        (0x3U << ADC_CCR_ADCPRE_Pos)                 /*!< 0x00030000 */
#define ADC_CCR_ADCPRE            ADC_CCR_ADCPRE_Msk                           /*!<ADCPRE[1:0] bits (ADC prescaler) */  
#define ADC_CCR_ADCPRE_0          (0x1U << ADC_CCR_ADCPRE_Pos)                 /*!< 0x00010000 */
#define ADC_CCR_ADCPRE_1          (0x2U << ADC_CCR_ADCPRE_Pos)                 /*!< 0x00020000 */
#define ADC_CCR_VBATE_Pos         (22U)                                        
#define ADC_CCR_VBATE_Msk         (0x1U << ADC_CCR_VBATE_Pos)                  /*!< 0x00400000 */
#define ADC_CCR_VBATE             ADC_CCR_VBATE_Msk                            /*!<VBAT Enable */
#define ADC_CCR_TSVREFE_Pos       (23U)                                        
#define ADC_CCR_TSVREFE_Msk       (0x1U << ADC_CCR_TSVREFE_Pos)                /*!< 0x00800000 */
#define ADC_CCR_TSVREFE           ADC_CCR_TSVREFE_Msk                          /*!<Temperature Sensor and VREFINT Enable */

/*******************  Bit definition for ADC_CDR register  ********************/
#define ADC_CDR_DATA1_Pos         (0U)                                         
#define ADC_CDR_DATA1_Msk         (0xFFFFU << ADC_CDR_DATA1_Pos)               /*!< 0x0000FFFF */
#define ADC_CDR_DATA1             ADC_CDR_DATA1_Msk                            /*!<1st data of a pair of regular conversions */
#define ADC_CDR_DATA2_Pos         (16U)                                        
#define ADC_CDR_DATA2_Msk         (0xFFFFU << ADC_CDR_DATA2_Pos)               /*!< 0xFFFF0000 */
#define ADC_CDR_DATA2             ADC_CDR_DATA2_Msk                            /*!<2nd data of a pair of regular conversions */

/* Legacy defines */
#define ADC_CDR_RDATA_MST         ADC_CDR_DATA1
#define ADC_CDR_RDATA_SLV         ADC_CDR_DATA2


#ifdef __cplusplus
}
#endif

#endif /*__STM32F4xx_ADC_H */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
