/**
  ******************************************************************************
  * @file    stm32f4xx_hal_dma.h
  * @author  MCD Application Team
  * @brief   Header file of DMA HAL module.
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
#ifndef __STM32F4xx_HAL_DMA_H
#define __STM32F4xx_HAL_DMA_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal_def.h"

/** @addtogroup STM32F4xx_HAL_Driver
  * @{
  */

/** @addtogroup DMA
  * @{
  */ 

/* Exported types ------------------------------------------------------------*/

/** @defgroup DMA_Exported_Types DMA Exported Types
  * @brief    DMA Exported Types 
  * @{
  */
   
/** 
  * @brief DMA Controller
  */

// #define __HAL_RCC_ADC1_CLK_ENABLE()     (0U)

typedef struct
{
  __IO uint32_t CR;     /*!< DMA stream x configuration register      */
  __IO uint32_t NDTR;   /*!< DMA stream x number of data register     */
  __IO uint32_t PAR;    /*!< DMA stream x peripheral address register */
  __IO uint32_t M0AR;   /*!< DMA stream x memory 0 address register   */
  __IO uint32_t M1AR;   /*!< DMA stream x memory 1 address register   */
  __IO uint32_t FCR;    /*!< DMA stream x FIFO control register       */
} DMA_Stream_TypeDef;

typedef struct
{
  __IO uint32_t LISR;   /*!< DMA low interrupt status register,      Address offset: 0x00 */
  __IO uint32_t HISR;   /*!< DMA high interrupt status register,     Address offset: 0x04 */
  __IO uint32_t LIFCR;  /*!< DMA low interrupt flag clear register,  Address offset: 0x08 */
  __IO uint32_t HIFCR;  /*!< DMA high interrupt flag clear register, Address offset: 0x0C */
} DMA_TypeDef;


/** 
  * @brief  DMA Configuration Structure definition
  */
typedef struct
{
  uint32_t Channel;              /*!< Specifies the channel used for the specified stream. 
                                      This parameter can be a value of @ref DMA_Channel_selection                    */

  uint32_t Direction;            /*!< Specifies if the data will be transferred from memory to peripheral, 
                                      from memory to memory or from peripheral to memory.
                                      This parameter can be a value of @ref DMA_Data_transfer_direction              */

  uint32_t PeriphInc;            /*!< Specifies whether the Peripheral address register should be incremented or not.
                                      This parameter can be a value of @ref DMA_Peripheral_incremented_mode          */

  uint32_t MemInc;               /*!< Specifies whether the memory address register should be incremented or not.
                                      This parameter can be a value of @ref DMA_Memory_incremented_mode              */

  uint32_t PeriphDataAlignment;  /*!< Specifies the Peripheral data width.
                                      This parameter can be a value of @ref DMA_Peripheral_data_size                 */

  uint32_t MemDataAlignment;     /*!< Specifies the Memory data width.
                                      This parameter can be a value of @ref DMA_Memory_data_size                     */

  uint32_t Mode;                 /*!< Specifies the operation mode of the DMAy Streamx.
                                      This parameter can be a value of @ref DMA_mode
                                      @note The circular buffer mode cannot be used if the memory-to-memory
                                            data transfer is configured on the selected Stream                        */

  uint32_t Priority;             /*!< Specifies the software priority for the DMAy Streamx.
                                      This parameter can be a value of @ref DMA_Priority_level                       */

  uint32_t FIFOMode;             /*!< Specifies if the FIFO mode or Direct mode will be used for the specified stream.
                                      This parameter can be a value of @ref DMA_FIFO_direct_mode
                                      @note The Direct mode (FIFO mode disabled) cannot be used if the 
                                            memory-to-memory data transfer is configured on the selected stream       */

  uint32_t FIFOThreshold;        /*!< Specifies the FIFO threshold level.
                                      This parameter can be a value of @ref DMA_FIFO_threshold_level                  */

  uint32_t MemBurst;             /*!< Specifies the Burst transfer configuration for the memory transfers. 
                                      It specifies the amount of data to be transferred in a single non interruptible
                                      transaction.
                                      This parameter can be a value of @ref DMA_Memory_burst 
                                      @note The burst mode is possible only if the address Increment mode is enabled. */

  uint32_t PeriphBurst;          /*!< Specifies the Burst transfer configuration for the peripheral transfers. 
                                      It specifies the amount of data to be transferred in a single non interruptible 
                                      transaction. 
                                      This parameter can be a value of @ref DMA_Peripheral_burst
                                      @note The burst mode is possible only if the address Increment mode is enabled. */
}DMA_InitTypeDef;


/** 
  * @brief  HAL DMA State structures definition
  */
typedef enum
{
  HAL_DMA_STATE_RESET             = 0x00U,  /*!< DMA not yet initialized or disabled */
  HAL_DMA_STATE_READY             = 0x01U,  /*!< DMA initialized and ready for use   */
  HAL_DMA_STATE_BUSY              = 0x02U,  /*!< DMA process is ongoing              */
  HAL_DMA_STATE_TIMEOUT           = 0x03U,  /*!< DMA timeout state                   */
  HAL_DMA_STATE_ERROR             = 0x04U,  /*!< DMA error state                     */
  HAL_DMA_STATE_ABORT             = 0x05U,  /*!< DMA Abort state                     */
}HAL_DMA_StateTypeDef;

/** 
  * @brief  HAL DMA Error Code structure definition
  */
typedef enum
{
  HAL_DMA_FULL_TRANSFER           = 0x00U,  /*!< Full transfer     */
  HAL_DMA_HALF_TRANSFER           = 0x01U   /*!< Half Transfer     */
}HAL_DMA_LevelCompleteTypeDef;

/** 
  * @brief  HAL DMA Error Code structure definition
  */
typedef enum
{
  HAL_DMA_XFER_CPLT_CB_ID         = 0x00U,  /*!< Full transfer     */
  HAL_DMA_XFER_HALFCPLT_CB_ID     = 0x01U,  /*!< Half Transfer     */
  HAL_DMA_XFER_M1CPLT_CB_ID       = 0x02U,  /*!< M1 Full Transfer  */
  HAL_DMA_XFER_M1HALFCPLT_CB_ID   = 0x03U,  /*!< M1 Half Transfer  */
  HAL_DMA_XFER_ERROR_CB_ID        = 0x04U,  /*!< Error             */
  HAL_DMA_XFER_ABORT_CB_ID        = 0x05U,  /*!< Abort             */
  HAL_DMA_XFER_ALL_CB_ID          = 0x06U   /*!< All               */
}HAL_DMA_CallbackIDTypeDef;

/** 
  * @brief  DMA handle Structure definition
  */
typedef struct __DMA_HandleTypeDef
{
  DMA_Stream_TypeDef         *Instance;                                                        /*!< Register base address                  */

  DMA_InitTypeDef            Init;                                                             /*!< DMA communication parameters           */ 

  HAL_LockTypeDef            Lock;                                                             /*!< DMA locking object                     */  

  __IO HAL_DMA_StateTypeDef  State;                                                            /*!< DMA transfer state                     */

  void                       *Parent;                                                          /*!< Parent object state                    */ 

  void                       (* XferCpltCallback)( struct __DMA_HandleTypeDef * hdma);         /*!< DMA transfer complete callback         */

  void                       (* XferHalfCpltCallback)( struct __DMA_HandleTypeDef * hdma);     /*!< DMA Half transfer complete callback    */

  void                       (* XferM1CpltCallback)( struct __DMA_HandleTypeDef * hdma);       /*!< DMA transfer complete Memory1 callback */
  
  void                       (* XferM1HalfCpltCallback)( struct __DMA_HandleTypeDef * hdma);   /*!< DMA transfer Half complete Memory1 callback */
  
  void                       (* XferErrorCallback)( struct __DMA_HandleTypeDef * hdma);        /*!< DMA transfer error callback            */
  
  void                       (* XferAbortCallback)( struct __DMA_HandleTypeDef * hdma);        /*!< DMA transfer Abort callback            */  

  __IO uint32_t              ErrorCode;                                                        /*!< DMA Error code                          */
  
  uint32_t                   StreamBaseAddress;                                                /*!< DMA Stream Base Address                */

  uint32_t                   StreamIndex;                                                      /*!< DMA Stream Index                       */
 
}DMA_HandleTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/

/** @defgroup DMA_Exported_Constants DMA Exported Constants
  * @brief    DMA Exported constants 
  * @{
  */

/** @defgroup DMA_Error_Code DMA Error Code
  * @brief    DMA Error Code 
  * @{
  */ 
#define HAL_DMA_ERROR_NONE            0x00000000U    /*!< No error                               */
#define HAL_DMA_ERROR_TE              0x00000001U    /*!< Transfer error                         */
#define HAL_DMA_ERROR_FE              0x00000002U    /*!< FIFO error                             */
#define HAL_DMA_ERROR_DME             0x00000004U    /*!< Direct Mode error                      */
#define HAL_DMA_ERROR_TIMEOUT         0x00000020U    /*!< Timeout error                          */
#define HAL_DMA_ERROR_PARAM           0x00000040U    /*!< Parameter error                        */
#define HAL_DMA_ERROR_NO_XFER         0x00000080U    /*!< Abort requested with no Xfer ongoing   */
#define HAL_DMA_ERROR_NOT_SUPPORTED   0x00000100U    /*!< Not supported mode                     */
/**
  * @}
  */

/** @defgroup DMA_Channel_selection DMA Channel selection
  * @brief    DMA channel selection 
  * @{
  */ 
#define DMA_CHANNEL_0                 0x00000000U    /*!< DMA Channel 0 */
#define DMA_CHANNEL_1                 0x02000000U    /*!< DMA Channel 1 */
#define DMA_CHANNEL_2                 0x04000000U    /*!< DMA Channel 2 */
#define DMA_CHANNEL_3                 0x06000000U    /*!< DMA Channel 3 */
#define DMA_CHANNEL_4                 0x08000000U    /*!< DMA Channel 4 */
#define DMA_CHANNEL_5                 0x0A000000U    /*!< DMA Channel 5 */
#define DMA_CHANNEL_6                 0x0C000000U    /*!< DMA Channel 6 */
#define DMA_CHANNEL_7                 0x0E000000U    /*!< DMA Channel 7 */
#if defined (DMA_SxCR_CHSEL_3)
#define DMA_CHANNEL_8                 0x10000000U    /*!< DMA Channel 8 */
#define DMA_CHANNEL_9                 0x12000000U    /*!< DMA Channel 9 */
#define DMA_CHANNEL_10                0x14000000U    /*!< DMA Channel 10 */
#define DMA_CHANNEL_11                0x16000000U    /*!< DMA Channel 11 */
#define DMA_CHANNEL_12                0x18000000U    /*!< DMA Channel 12 */
#define DMA_CHANNEL_13                0x1A000000U    /*!< DMA Channel 13 */
#define DMA_CHANNEL_14                0x1C000000U    /*!< DMA Channel 14 */
#define DMA_CHANNEL_15                0x1E000000U    /*!< DMA Channel 15 */
#endif /* DMA_SxCR_CHSEL_3 */
/**
  * @}
  */

/** @defgroup DMA_Data_transfer_direction DMA Data transfer direction
  * @brief    DMA data transfer direction 
  * @{
  */ 
#define DMA_PERIPH_TO_MEMORY          0x00000000U                 /*!< Peripheral to memory direction */
#define DMA_MEMORY_TO_PERIPH          ((uint32_t)DMA_SxCR_DIR_0)  /*!< Memory to peripheral direction */
#define DMA_MEMORY_TO_MEMORY          ((uint32_t)DMA_SxCR_DIR_1)  /*!< Memory to memory direction     */
/**
  * @}
  */
        
/** @defgroup DMA_Peripheral_incremented_mode DMA Peripheral incremented mode
  * @brief    DMA peripheral incremented mode 
  * @{
  */ 
#define DMA_PINC_ENABLE               ((uint32_t)DMA_SxCR_PINC)   /*!< Peripheral increment mode enable  */
#define DMA_PINC_DISABLE              0x00000000U                 /*!< Peripheral increment mode disable */
/**
  * @}
  */ 

/** @defgroup DMA_Memory_incremented_mode DMA Memory incremented mode
  * @brief    DMA memory incremented mode 
  * @{
  */ 
#define DMA_MINC_ENABLE               ((uint32_t)DMA_SxCR_MINC)   /*!< Memory increment mode enable  */
#define DMA_MINC_DISABLE              0x00000000U                 /*!< Memory increment mode disable */
/**
  * @}
  */

/** @defgroup DMA_Peripheral_data_size DMA Peripheral data size
  * @brief    DMA peripheral data size 
  * @{
  */ 
#define DMA_PDATAALIGN_BYTE           0x00000000U                  /*!< Peripheral data alignment: Byte     */
#define DMA_PDATAALIGN_HALFWORD       ((uint32_t)DMA_SxCR_PSIZE_0) /*!< Peripheral data alignment: HalfWord */
#define DMA_PDATAALIGN_WORD           ((uint32_t)DMA_SxCR_PSIZE_1) /*!< Peripheral data alignment: Word     */
/**
  * @}
  */ 

/** @defgroup DMA_Memory_data_size DMA Memory data size
  * @brief    DMA memory data size 
  * @{ 
  */
#define DMA_MDATAALIGN_BYTE           0x00000000U                  /*!< Memory data alignment: Byte     */
#define DMA_MDATAALIGN_HALFWORD       ((uint32_t)DMA_SxCR_MSIZE_0) /*!< Memory data alignment: HalfWord */
#define DMA_MDATAALIGN_WORD           ((uint32_t)DMA_SxCR_MSIZE_1) /*!< Memory data alignment: Word     */
/**
  * @}
  */

/** @defgroup DMA_mode DMA mode
  * @brief    DMA mode 
  * @{
  */ 
#define DMA_NORMAL                    0x00000000U                  /*!< Normal mode                  */
#define DMA_CIRCULAR                  ((uint32_t)DMA_SxCR_CIRC)    /*!< Circular mode                */
#define DMA_PFCTRL                    ((uint32_t)DMA_SxCR_PFCTRL)  /*!< Peripheral flow control mode */
/**
  * @}
  */

/** @defgroup DMA_Priority_level DMA Priority level
  * @brief    DMA priority levels 
  * @{
  */
#define DMA_PRIORITY_LOW              0x00000000U                 /*!< Priority level: Low       */
#define DMA_PRIORITY_MEDIUM           ((uint32_t)DMA_SxCR_PL_0)   /*!< Priority level: Medium    */
#define DMA_PRIORITY_HIGH             ((uint32_t)DMA_SxCR_PL_1)   /*!< Priority level: High      */
#define DMA_PRIORITY_VERY_HIGH        ((uint32_t)DMA_SxCR_PL)     /*!< Priority level: Very High */
/**
  * @}
  */ 

/** @defgroup DMA_FIFO_direct_mode DMA FIFO direct mode
  * @brief    DMA FIFO direct mode
  * @{
  */
#define DMA_FIFOMODE_DISABLE          0x00000000U                 /*!< FIFO mode disable */
#define DMA_FIFOMODE_ENABLE           ((uint32_t)DMA_SxFCR_DMDIS) /*!< FIFO mode enable  */
/**
  * @}
  */ 

/** @defgroup DMA_FIFO_threshold_level DMA FIFO threshold level
  * @brief    DMA FIFO level 
  * @{
  */
#define DMA_FIFO_THRESHOLD_1QUARTERFULL       0x00000000U                  /*!< FIFO threshold 1 quart full configuration  */
#define DMA_FIFO_THRESHOLD_HALFFULL           ((uint32_t)DMA_SxFCR_FTH_0)  /*!< FIFO threshold half full configuration     */
#define DMA_FIFO_THRESHOLD_3QUARTERSFULL      ((uint32_t)DMA_SxFCR_FTH_1)  /*!< FIFO threshold 3 quarts full configuration */
#define DMA_FIFO_THRESHOLD_FULL               ((uint32_t)DMA_SxFCR_FTH)    /*!< FIFO threshold full configuration          */
/**
  * @}
  */ 

/** @defgroup DMA_Memory_burst DMA Memory burst
  * @brief    DMA memory burst 
  * @{
  */ 
#define DMA_MBURST_SINGLE             0x00000000U
#define DMA_MBURST_INC4               ((uint32_t)DMA_SxCR_MBURST_0)  
#define DMA_MBURST_INC8               ((uint32_t)DMA_SxCR_MBURST_1)  
#define DMA_MBURST_INC16              ((uint32_t)DMA_SxCR_MBURST)  
/**
  * @}
  */ 

/** @defgroup DMA_Peripheral_burst DMA Peripheral burst
  * @brief    DMA peripheral burst 
  * @{
  */ 
#define DMA_PBURST_SINGLE             0x00000000U
#define DMA_PBURST_INC4               ((uint32_t)DMA_SxCR_PBURST_0)
#define DMA_PBURST_INC8               ((uint32_t)DMA_SxCR_PBURST_1)
#define DMA_PBURST_INC16              ((uint32_t)DMA_SxCR_PBURST)
/**
  * @}
  */

/** @defgroup DMA_interrupt_enable_definitions DMA interrupt enable definitions
  * @brief    DMA interrupts definition 
  * @{
  */
#define DMA_IT_TC                     ((uint32_t)DMA_SxCR_TCIE)
#define DMA_IT_HT                     ((uint32_t)DMA_SxCR_HTIE)
#define DMA_IT_TE                     ((uint32_t)DMA_SxCR_TEIE)
#define DMA_IT_DME                    ((uint32_t)DMA_SxCR_DMEIE)
#define DMA_IT_FE                     0x00000080U
/**
  * @}
  */

/** @defgroup DMA_flag_definitions DMA flag definitions
  * @brief    DMA flag definitions 
  * @{
  */ 
#define DMA_FLAG_FEIF0_4              0x00000001U
#define DMA_FLAG_DMEIF0_4             0x00000004U
#define DMA_FLAG_TEIF0_4              0x00000008U
#define DMA_FLAG_HTIF0_4              0x00000010U
#define DMA_FLAG_TCIF0_4              0x00000020U
#define DMA_FLAG_FEIF1_5              0x00000040U
#define DMA_FLAG_DMEIF1_5             0x00000100U
#define DMA_FLAG_TEIF1_5              0x00000200U
#define DMA_FLAG_HTIF1_5              0x00000400U
#define DMA_FLAG_TCIF1_5              0x00000800U
#define DMA_FLAG_FEIF2_6              0x00010000U
#define DMA_FLAG_DMEIF2_6             0x00040000U
#define DMA_FLAG_TEIF2_6              0x00080000U
#define DMA_FLAG_HTIF2_6              0x00100000U
#define DMA_FLAG_TCIF2_6              0x00200000U
#define DMA_FLAG_FEIF3_7              0x00400000U
#define DMA_FLAG_DMEIF3_7             0x01000000U
#define DMA_FLAG_TEIF3_7              0x02000000U
#define DMA_FLAG_HTIF3_7              0x04000000U
#define DMA_FLAG_TCIF3_7              0x08000000U
/**
  * @}
  */

/**
  * @}
  */
 
/* Exported macro ------------------------------------------------------------*/

/** @brief Reset DMA handle state
  * @param  __HANDLE__ specifies the DMA handle.
  * @retval None
  */
#define __HAL_DMA_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_DMA_STATE_RESET)

/**
  * @brief  Return the current DMA Stream FIFO filled level.
  * @param  __HANDLE__ DMA handle
  * @retval The FIFO filling state.
  *           - DMA_FIFOStatus_Less1QuarterFull: when FIFO is less than 1 quarter-full 
  *                                              and not empty.
  *           - DMA_FIFOStatus_1QuarterFull: if more than 1 quarter-full.
  *           - DMA_FIFOStatus_HalfFull: if more than 1 half-full.
  *           - DMA_FIFOStatus_3QuartersFull: if more than 3 quarters-full.
  *           - DMA_FIFOStatus_Empty: when FIFO is empty
  *           - DMA_FIFOStatus_Full: when FIFO is full
  */
#define __HAL_DMA_GET_FS(__HANDLE__)      (((__HANDLE__)->Instance->FCR & (DMA_SxFCR_FS)))

/**
  * @brief  Enable the specified DMA Stream.
  * @param  __HANDLE__ DMA handle
  * @retval None
  */
#define __HAL_DMA_ENABLE(__HANDLE__)      ((__HANDLE__)->Instance->CR |=  DMA_SxCR_EN)

/**
  * @brief  Disable the specified DMA Stream.
  * @param  __HANDLE__ DMA handle
  * @retval None
  */
#define __HAL_DMA_DISABLE(__HANDLE__)     ((__HANDLE__)->Instance->CR &=  ~DMA_SxCR_EN)

/* Interrupt & Flag management */

/**
  * @brief  Return the current DMA Stream transfer complete flag.
  * @param  __HANDLE__ DMA handle
  * @retval The specified transfer complete flag index.
  */
#define __HAL_DMA_GET_TC_FLAG_INDEX(__HANDLE__) \
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream0))? DMA_FLAG_TCIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream0))? DMA_FLAG_TCIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream4))? DMA_FLAG_TCIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream4))? DMA_FLAG_TCIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream1))? DMA_FLAG_TCIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream1))? DMA_FLAG_TCIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream5))? DMA_FLAG_TCIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream5))? DMA_FLAG_TCIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream2))? DMA_FLAG_TCIF2_6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream2))? DMA_FLAG_TCIF2_6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream6))? DMA_FLAG_TCIF2_6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream6))? DMA_FLAG_TCIF2_6 :\
   DMA_FLAG_TCIF3_7)

/**
  * @brief  Return the current DMA Stream half transfer complete flag.
  * @param  __HANDLE__ DMA handle
  * @retval The specified half transfer complete flag index.
  */      
#define __HAL_DMA_GET_HT_FLAG_INDEX(__HANDLE__)\
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream0))? DMA_FLAG_HTIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream0))? DMA_FLAG_HTIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream4))? DMA_FLAG_HTIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream4))? DMA_FLAG_HTIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream1))? DMA_FLAG_HTIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream1))? DMA_FLAG_HTIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream5))? DMA_FLAG_HTIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream5))? DMA_FLAG_HTIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream2))? DMA_FLAG_HTIF2_6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream2))? DMA_FLAG_HTIF2_6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream6))? DMA_FLAG_HTIF2_6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream6))? DMA_FLAG_HTIF2_6 :\
   DMA_FLAG_HTIF3_7)

/**
  * @brief  Return the current DMA Stream transfer error flag.
  * @param  __HANDLE__ DMA handle
  * @retval The specified transfer error flag index.
  */
#define __HAL_DMA_GET_TE_FLAG_INDEX(__HANDLE__)\
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream0))? DMA_FLAG_TEIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream0))? DMA_FLAG_TEIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream4))? DMA_FLAG_TEIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream4))? DMA_FLAG_TEIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream1))? DMA_FLAG_TEIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream1))? DMA_FLAG_TEIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream5))? DMA_FLAG_TEIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream5))? DMA_FLAG_TEIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream2))? DMA_FLAG_TEIF2_6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream2))? DMA_FLAG_TEIF2_6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream6))? DMA_FLAG_TEIF2_6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream6))? DMA_FLAG_TEIF2_6 :\
   DMA_FLAG_TEIF3_7)

/**
  * @brief  Return the current DMA Stream FIFO error flag.
  * @param  __HANDLE__ DMA handle
  * @retval The specified FIFO error flag index.
  */
#define __HAL_DMA_GET_FE_FLAG_INDEX(__HANDLE__)\
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream0))? DMA_FLAG_FEIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream0))? DMA_FLAG_FEIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream4))? DMA_FLAG_FEIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream4))? DMA_FLAG_FEIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream1))? DMA_FLAG_FEIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream1))? DMA_FLAG_FEIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream5))? DMA_FLAG_FEIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream5))? DMA_FLAG_FEIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream2))? DMA_FLAG_FEIF2_6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream2))? DMA_FLAG_FEIF2_6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream6))? DMA_FLAG_FEIF2_6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream6))? DMA_FLAG_FEIF2_6 :\
   DMA_FLAG_FEIF3_7)

/**
  * @brief  Return the current DMA Stream direct mode error flag.
  * @param  __HANDLE__ DMA handle
  * @retval The specified direct mode error flag index.
  */
#define __HAL_DMA_GET_DME_FLAG_INDEX(__HANDLE__)\
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream0))? DMA_FLAG_DMEIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream0))? DMA_FLAG_DMEIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream4))? DMA_FLAG_DMEIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream4))? DMA_FLAG_DMEIF0_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream1))? DMA_FLAG_DMEIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream1))? DMA_FLAG_DMEIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream5))? DMA_FLAG_DMEIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream5))? DMA_FLAG_DMEIF1_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream2))? DMA_FLAG_DMEIF2_6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream2))? DMA_FLAG_DMEIF2_6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Stream6))? DMA_FLAG_DMEIF2_6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Stream6))? DMA_FLAG_DMEIF2_6 :\
   DMA_FLAG_DMEIF3_7)

/**
  * @brief  Get the DMA Stream pending flags.
  * @param  __HANDLE__ DMA handle
  * @param  __FLAG__ Get the specified flag.
  *          This parameter can be any combination of the following values:
  *            @arg DMA_FLAG_TCIFx: Transfer complete flag.
  *            @arg DMA_FLAG_HTIFx: Half transfer complete flag.
  *            @arg DMA_FLAG_TEIFx: Transfer error flag.
  *            @arg DMA_FLAG_DMEIFx: Direct mode error flag.
  *            @arg DMA_FLAG_FEIFx: FIFO error flag.
  *         Where x can be 0_4, 1_5, 2_6 or 3_7 to select the DMA Stream flag.   
  * @retval The state of FLAG (SET or RESET).
  */
#define __HAL_DMA_GET_FLAG(__HANDLE__, __FLAG__)\
(((uint32_t)((__HANDLE__)->Instance) > (uint32_t)DMA2_Stream3)? (DMA2->HISR & (__FLAG__)) :\
 ((uint32_t)((__HANDLE__)->Instance) > (uint32_t)DMA1_Stream7)? (DMA2->LISR & (__FLAG__)) :\
 ((uint32_t)((__HANDLE__)->Instance) > (uint32_t)DMA1_Stream3)? (DMA1->HISR & (__FLAG__)) : (DMA1->LISR & (__FLAG__)))

/**
  * @brief  Clear the DMA Stream pending flags.
  * @param  __HANDLE__ DMA handle
  * @param  __FLAG__ specifies the flag to clear.
  *          This parameter can be any combination of the following values:
  *            @arg DMA_FLAG_TCIFx: Transfer complete flag.
  *            @arg DMA_FLAG_HTIFx: Half transfer complete flag.
  *            @arg DMA_FLAG_TEIFx: Transfer error flag.
  *            @arg DMA_FLAG_DMEIFx: Direct mode error flag.
  *            @arg DMA_FLAG_FEIFx: FIFO error flag.
  *         Where x can be 0_4, 1_5, 2_6 or 3_7 to select the DMA Stream flag.   
  * @retval None
  */
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) \
(((uint32_t)((__HANDLE__)->Instance) > (uint32_t)DMA2_Stream3)? (DMA2->HIFCR = (__FLAG__)) :\
 ((uint32_t)((__HANDLE__)->Instance) > (uint32_t)DMA1_Stream7)? (DMA2->LIFCR = (__FLAG__)) :\
 ((uint32_t)((__HANDLE__)->Instance) > (uint32_t)DMA1_Stream3)? (DMA1->HIFCR = (__FLAG__)) : (DMA1->LIFCR = (__FLAG__)))

/**
  * @brief  Enable the specified DMA Stream interrupts.
  * @param  __HANDLE__ DMA handle
  * @param  __INTERRUPT__ specifies the DMA interrupt sources to be enabled or disabled. 
  *        This parameter can be any combination of the following values:
  *           @arg DMA_IT_TC: Transfer complete interrupt mask.
  *           @arg DMA_IT_HT: Half transfer complete interrupt mask.
  *           @arg DMA_IT_TE: Transfer error interrupt mask.
  *           @arg DMA_IT_FE: FIFO error interrupt mask.
  *           @arg DMA_IT_DME: Direct mode error interrupt.
  * @retval None
  */
#define __HAL_DMA_ENABLE_IT(__HANDLE__, __INTERRUPT__)   (((__INTERRUPT__) != DMA_IT_FE)? \
((__HANDLE__)->Instance->CR |= (__INTERRUPT__)) : ((__HANDLE__)->Instance->FCR |= (__INTERRUPT__)))

/**
  * @brief  Disable the specified DMA Stream interrupts.
  * @param  __HANDLE__ DMA handle
  * @param  __INTERRUPT__ specifies the DMA interrupt sources to be enabled or disabled. 
  *         This parameter can be any combination of the following values:
  *            @arg DMA_IT_TC: Transfer complete interrupt mask.
  *            @arg DMA_IT_HT: Half transfer complete interrupt mask.
  *            @arg DMA_IT_TE: Transfer error interrupt mask.
  *            @arg DMA_IT_FE: FIFO error interrupt mask.
  *            @arg DMA_IT_DME: Direct mode error interrupt.
  * @retval None
  */
#define __HAL_DMA_DISABLE_IT(__HANDLE__, __INTERRUPT__)  (((__INTERRUPT__) != DMA_IT_FE)? \
((__HANDLE__)->Instance->CR &= ~(__INTERRUPT__)) : ((__HANDLE__)->Instance->FCR &= ~(__INTERRUPT__)))

/**
  * @brief  Check whether the specified DMA Stream interrupt is enabled or disabled.
  * @param  __HANDLE__ DMA handle
  * @param  __INTERRUPT__ specifies the DMA interrupt source to check.
  *         This parameter can be one of the following values:
  *            @arg DMA_IT_TC: Transfer complete interrupt mask.
  *            @arg DMA_IT_HT: Half transfer complete interrupt mask.
  *            @arg DMA_IT_TE: Transfer error interrupt mask.
  *            @arg DMA_IT_FE: FIFO error interrupt mask.
  *            @arg DMA_IT_DME: Direct mode error interrupt.
  * @retval The state of DMA_IT.
  */
#define __HAL_DMA_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__)  (((__INTERRUPT__) != DMA_IT_FE)? \
                                                        ((__HANDLE__)->Instance->CR & (__INTERRUPT__)) : \
                                                        ((__HANDLE__)->Instance->FCR & (__INTERRUPT__)))

/**
  * @brief  Writes the number of data units to be transferred on the DMA Stream.
  * @param  __HANDLE__ DMA handle
  * @param  __COUNTER__ Number of data units to be transferred (from 0 to 65535) 
  *          Number of data items depends only on the Peripheral data format.
  *            
  * @note   If Peripheral data format is Bytes: number of data units is equal 
  *         to total number of bytes to be transferred.
  *           
  * @note   If Peripheral data format is Half-Word: number of data units is  
  *         equal to total number of bytes to be transferred / 2.
  *           
  * @note   If Peripheral data format is Word: number of data units is equal 
  *         to total  number of bytes to be transferred / 4.
  *      
  * @retval The number of remaining data units in the current DMAy Streamx transfer.
  */
#define __HAL_DMA_SET_COUNTER(__HANDLE__, __COUNTER__) ((__HANDLE__)->Instance->NDTR = (uint16_t)(__COUNTER__))

/**
  * @brief  Returns the number of remaining data units in the current DMAy Streamx transfer.
  * @param  __HANDLE__ DMA handle
  *   
  * @retval The number of remaining data units in the current DMA Stream transfer.
  */
#define __HAL_DMA_GET_COUNTER(__HANDLE__) ((__HANDLE__)->Instance->NDTR)


/* Include DMA HAL Extension module */
// #include "stm32f4xx_hal_dma_ex.h"   

/* Exported functions --------------------------------------------------------*/

/** @defgroup DMA_Exported_Functions DMA Exported Functions
  * @brief    DMA Exported functions 
  * @{
  */

/** @defgroup DMA_Exported_Functions_Group1 Initialization and de-initialization functions
  * @brief   Initialization and de-initialization functions 
  * @{
  */
HAL_StatusTypeDef HAL_DMA_Init(DMA_HandleTypeDef *hdma); 
HAL_StatusTypeDef HAL_DMA_DeInit(DMA_HandleTypeDef *hdma);
/**
  * @}
  */

/** @defgroup DMA_Exported_Functions_Group2 I/O operation functions
  * @brief   I/O operation functions  
  * @{
  */
HAL_StatusTypeDef HAL_DMA_Start (DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength);
HAL_StatusTypeDef HAL_DMA_Start_IT(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength);
HAL_StatusTypeDef HAL_DMA_Abort(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_Abort_IT(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_PollForTransfer(DMA_HandleTypeDef *hdma, HAL_DMA_LevelCompleteTypeDef CompleteLevel, uint32_t Timeout);
void              HAL_DMA_IRQHandler(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_CleanCallbacks(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_RegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID, void (* pCallback)(DMA_HandleTypeDef *_hdma));
HAL_StatusTypeDef HAL_DMA_UnRegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID);

/**
  * @}
  */ 

/** @defgroup DMA_Exported_Functions_Group3 Peripheral State functions
  * @brief    Peripheral State functions 
  * @{
  */
HAL_DMA_StateTypeDef HAL_DMA_GetState(DMA_HandleTypeDef *hdma);
uint32_t             HAL_DMA_GetError(DMA_HandleTypeDef *hdma);
/**
  * @}
  */ 
/**
  * @}
  */ 
/* Private Constants -------------------------------------------------------------*/
/** @defgroup DMA_Private_Constants DMA Private Constants
  * @brief    DMA private defines and constants 
  * @{
  */
/**
  * @}
  */ 

/* Private macros ------------------------------------------------------------*/
/** @defgroup DMA_Private_Macros DMA Private Macros
  * @brief    DMA private macros 
  * @{
  */
#if defined (DMA_SxCR_CHSEL_3)
#define IS_DMA_CHANNEL(CHANNEL) (((CHANNEL) == DMA_CHANNEL_0) || \
                                 ((CHANNEL) == DMA_CHANNEL_1) || \
                                 ((CHANNEL) == DMA_CHANNEL_2) || \
                                 ((CHANNEL) == DMA_CHANNEL_3) || \
                                 ((CHANNEL) == DMA_CHANNEL_4) || \
                                 ((CHANNEL) == DMA_CHANNEL_5) || \
                                 ((CHANNEL) == DMA_CHANNEL_6) || \
                                 ((CHANNEL) == DMA_CHANNEL_7) || \
                                 ((CHANNEL) == DMA_CHANNEL_8) || \
                                 ((CHANNEL) == DMA_CHANNEL_9) || \
                                 ((CHANNEL) == DMA_CHANNEL_10)|| \
                                 ((CHANNEL) == DMA_CHANNEL_11)|| \
                                 ((CHANNEL) == DMA_CHANNEL_12)|| \
                                 ((CHANNEL) == DMA_CHANNEL_13)|| \
                                 ((CHANNEL) == DMA_CHANNEL_14)|| \
                                 ((CHANNEL) == DMA_CHANNEL_15))
#else
#define IS_DMA_CHANNEL(CHANNEL) (((CHANNEL) == DMA_CHANNEL_0) || \
                                 ((CHANNEL) == DMA_CHANNEL_1) || \
                                 ((CHANNEL) == DMA_CHANNEL_2) || \
                                 ((CHANNEL) == DMA_CHANNEL_3) || \
                                 ((CHANNEL) == DMA_CHANNEL_4) || \
                                 ((CHANNEL) == DMA_CHANNEL_5) || \
                                 ((CHANNEL) == DMA_CHANNEL_6) || \
                                 ((CHANNEL) == DMA_CHANNEL_7))
#endif /* DMA_SxCR_CHSEL_3 */

#define IS_DMA_DIRECTION(DIRECTION) (((DIRECTION) == DMA_PERIPH_TO_MEMORY ) || \
                                     ((DIRECTION) == DMA_MEMORY_TO_PERIPH)  || \
                                     ((DIRECTION) == DMA_MEMORY_TO_MEMORY)) 

#define IS_DMA_BUFFER_SIZE(SIZE) (((SIZE) >= 0x01U) && ((SIZE) < 0x10000U))

#define IS_DMA_PERIPHERAL_INC_STATE(STATE) (((STATE) == DMA_PINC_ENABLE) || \
                                            ((STATE) == DMA_PINC_DISABLE))

#define IS_DMA_MEMORY_INC_STATE(STATE) (((STATE) == DMA_MINC_ENABLE)  || \
                                        ((STATE) == DMA_MINC_DISABLE))

#define IS_DMA_PERIPHERAL_DATA_SIZE(SIZE) (((SIZE) == DMA_PDATAALIGN_BYTE)     || \
                                           ((SIZE) == DMA_PDATAALIGN_HALFWORD) || \
                                           ((SIZE) == DMA_PDATAALIGN_WORD))

#define IS_DMA_MEMORY_DATA_SIZE(SIZE) (((SIZE) == DMA_MDATAALIGN_BYTE)     || \
                                       ((SIZE) == DMA_MDATAALIGN_HALFWORD) || \
                                       ((SIZE) == DMA_MDATAALIGN_WORD ))

#define IS_DMA_MODE(MODE) (((MODE) == DMA_NORMAL )  || \
                           ((MODE) == DMA_CIRCULAR) || \
                           ((MODE) == DMA_PFCTRL)) 

#define IS_DMA_PRIORITY(PRIORITY) (((PRIORITY) == DMA_PRIORITY_LOW )   || \
                                   ((PRIORITY) == DMA_PRIORITY_MEDIUM) || \
                                   ((PRIORITY) == DMA_PRIORITY_HIGH)   || \
                                   ((PRIORITY) == DMA_PRIORITY_VERY_HIGH)) 

#define IS_DMA_FIFO_MODE_STATE(STATE) (((STATE) == DMA_FIFOMODE_DISABLE ) || \
                                       ((STATE) == DMA_FIFOMODE_ENABLE))

#define IS_DMA_FIFO_THRESHOLD(THRESHOLD) (((THRESHOLD) == DMA_FIFO_THRESHOLD_1QUARTERFULL ) || \
                                          ((THRESHOLD) == DMA_FIFO_THRESHOLD_HALFFULL)      || \
                                          ((THRESHOLD) == DMA_FIFO_THRESHOLD_3QUARTERSFULL) || \
                                          ((THRESHOLD) == DMA_FIFO_THRESHOLD_FULL))

#define IS_DMA_MEMORY_BURST(BURST) (((BURST) == DMA_MBURST_SINGLE) || \
                                    ((BURST) == DMA_MBURST_INC4)   || \
                                    ((BURST) == DMA_MBURST_INC8)   || \
                                    ((BURST) == DMA_MBURST_INC16))

#define IS_DMA_PERIPHERAL_BURST(BURST) (((BURST) == DMA_PBURST_SINGLE) || \
                                        ((BURST) == DMA_PBURST_INC4)   || \
                                        ((BURST) == DMA_PBURST_INC8)   || \
                                        ((BURST) == DMA_PBURST_INC16))
/**
  * @}
  */ 

/* Private functions ---------------------------------------------------------*/
/** @defgroup DMA_Private_Functions DMA Private Functions
  * @brief    DMA private  functions 
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

#ifdef __cplusplus
}
#endif

/******************************************************************************/
/*                                                                            */
/*                             DMA Controller                                 */
/*                                                                            */
/******************************************************************************/
/********************  Bits definition for DMA_SxCR register  *****************/
#define DMA_SxCR_CHSEL_Pos       (25U)                                         
#define DMA_SxCR_CHSEL_Msk       (0x7U << DMA_SxCR_CHSEL_Pos)                  /*!< 0x0E000000 */
#define DMA_SxCR_CHSEL           DMA_SxCR_CHSEL_Msk                            
#define DMA_SxCR_CHSEL_0         0x02000000U                                   
#define DMA_SxCR_CHSEL_1         0x04000000U                                   
#define DMA_SxCR_CHSEL_2         0x08000000U                                   
#define DMA_SxCR_MBURST_Pos      (23U)                                         
#define DMA_SxCR_MBURST_Msk      (0x3U << DMA_SxCR_MBURST_Pos)                 /*!< 0x01800000 */
#define DMA_SxCR_MBURST          DMA_SxCR_MBURST_Msk                           
#define DMA_SxCR_MBURST_0        (0x1U << DMA_SxCR_MBURST_Pos)                 /*!< 0x00800000 */
#define DMA_SxCR_MBURST_1        (0x2U << DMA_SxCR_MBURST_Pos)                 /*!< 0x01000000 */
#define DMA_SxCR_PBURST_Pos      (21U)                                         
#define DMA_SxCR_PBURST_Msk      (0x3U << DMA_SxCR_PBURST_Pos)                 /*!< 0x00600000 */
#define DMA_SxCR_PBURST          DMA_SxCR_PBURST_Msk                           
#define DMA_SxCR_PBURST_0        (0x1U << DMA_SxCR_PBURST_Pos)                 /*!< 0x00200000 */
#define DMA_SxCR_PBURST_1        (0x2U << DMA_SxCR_PBURST_Pos)                 /*!< 0x00400000 */
#define DMA_SxCR_CT_Pos          (19U)                                         
#define DMA_SxCR_CT_Msk          (0x1U << DMA_SxCR_CT_Pos)                     /*!< 0x00080000 */
#define DMA_SxCR_CT              DMA_SxCR_CT_Msk                               
#define DMA_SxCR_DBM_Pos         (18U)                                         
#define DMA_SxCR_DBM_Msk         (0x1U << DMA_SxCR_DBM_Pos)                    /*!< 0x00040000 */
#define DMA_SxCR_DBM             DMA_SxCR_DBM_Msk                              
#define DMA_SxCR_PL_Pos          (16U)                                         
#define DMA_SxCR_PL_Msk          (0x3U << DMA_SxCR_PL_Pos)                     /*!< 0x00030000 */
#define DMA_SxCR_PL              DMA_SxCR_PL_Msk                               
#define DMA_SxCR_PL_0            (0x1U << DMA_SxCR_PL_Pos)                     /*!< 0x00010000 */
#define DMA_SxCR_PL_1            (0x2U << DMA_SxCR_PL_Pos)                     /*!< 0x00020000 */
#define DMA_SxCR_PINCOS_Pos      (15U)                                         
#define DMA_SxCR_PINCOS_Msk      (0x1U << DMA_SxCR_PINCOS_Pos)                 /*!< 0x00008000 */
#define DMA_SxCR_PINCOS          DMA_SxCR_PINCOS_Msk                           
#define DMA_SxCR_MSIZE_Pos       (13U)                                         
#define DMA_SxCR_MSIZE_Msk       (0x3U << DMA_SxCR_MSIZE_Pos)                  /*!< 0x00006000 */
#define DMA_SxCR_MSIZE           DMA_SxCR_MSIZE_Msk                            
#define DMA_SxCR_MSIZE_0         (0x1U << DMA_SxCR_MSIZE_Pos)                  /*!< 0x00002000 */
#define DMA_SxCR_MSIZE_1         (0x2U << DMA_SxCR_MSIZE_Pos)                  /*!< 0x00004000 */
#define DMA_SxCR_PSIZE_Pos       (11U)                                         
#define DMA_SxCR_PSIZE_Msk       (0x3U << DMA_SxCR_PSIZE_Pos)                  /*!< 0x00001800 */
#define DMA_SxCR_PSIZE           DMA_SxCR_PSIZE_Msk                            
#define DMA_SxCR_PSIZE_0         (0x1U << DMA_SxCR_PSIZE_Pos)                  /*!< 0x00000800 */
#define DMA_SxCR_PSIZE_1         (0x2U << DMA_SxCR_PSIZE_Pos)                  /*!< 0x00001000 */
#define DMA_SxCR_MINC_Pos        (10U)                                         
#define DMA_SxCR_MINC_Msk        (0x1U << DMA_SxCR_MINC_Pos)                   /*!< 0x00000400 */
#define DMA_SxCR_MINC            DMA_SxCR_MINC_Msk                             
#define DMA_SxCR_PINC_Pos        (9U)                                          
#define DMA_SxCR_PINC_Msk        (0x1U << DMA_SxCR_PINC_Pos)                   /*!< 0x00000200 */
#define DMA_SxCR_PINC            DMA_SxCR_PINC_Msk                             
#define DMA_SxCR_CIRC_Pos        (8U)                                          
#define DMA_SxCR_CIRC_Msk        (0x1U << DMA_SxCR_CIRC_Pos)                   /*!< 0x00000100 */
#define DMA_SxCR_CIRC            DMA_SxCR_CIRC_Msk                             
#define DMA_SxCR_DIR_Pos         (6U)                                          
#define DMA_SxCR_DIR_Msk         (0x3U << DMA_SxCR_DIR_Pos)                    /*!< 0x000000C0 */
#define DMA_SxCR_DIR             DMA_SxCR_DIR_Msk                              
#define DMA_SxCR_DIR_0           (0x1U << DMA_SxCR_DIR_Pos)                    /*!< 0x00000040 */
#define DMA_SxCR_DIR_1           (0x2U << DMA_SxCR_DIR_Pos)                    /*!< 0x00000080 */
#define DMA_SxCR_PFCTRL_Pos      (5U)                                          
#define DMA_SxCR_PFCTRL_Msk      (0x1U << DMA_SxCR_PFCTRL_Pos)                 /*!< 0x00000020 */
#define DMA_SxCR_PFCTRL          DMA_SxCR_PFCTRL_Msk                           
#define DMA_SxCR_TCIE_Pos        (4U)                                          
#define DMA_SxCR_TCIE_Msk        (0x1U << DMA_SxCR_TCIE_Pos)                   /*!< 0x00000010 */
#define DMA_SxCR_TCIE            DMA_SxCR_TCIE_Msk                             
#define DMA_SxCR_HTIE_Pos        (3U)                                          
#define DMA_SxCR_HTIE_Msk        (0x1U << DMA_SxCR_HTIE_Pos)                   /*!< 0x00000008 */
#define DMA_SxCR_HTIE            DMA_SxCR_HTIE_Msk                             
#define DMA_SxCR_TEIE_Pos        (2U)                                          
#define DMA_SxCR_TEIE_Msk        (0x1U << DMA_SxCR_TEIE_Pos)                   /*!< 0x00000004 */
#define DMA_SxCR_TEIE            DMA_SxCR_TEIE_Msk                             
#define DMA_SxCR_DMEIE_Pos       (1U)                                          
#define DMA_SxCR_DMEIE_Msk       (0x1U << DMA_SxCR_DMEIE_Pos)                  /*!< 0x00000002 */
#define DMA_SxCR_DMEIE           DMA_SxCR_DMEIE_Msk                            
#define DMA_SxCR_EN_Pos          (0U)                                          
#define DMA_SxCR_EN_Msk          (0x1U << DMA_SxCR_EN_Pos)                     /*!< 0x00000001 */
#define DMA_SxCR_EN              DMA_SxCR_EN_Msk                               

/* Legacy defines */
#define DMA_SxCR_ACK_Pos         (20U)                                         
#define DMA_SxCR_ACK_Msk         (0x1U << DMA_SxCR_ACK_Pos)                    /*!< 0x00100000 */
#define DMA_SxCR_ACK             DMA_SxCR_ACK_Msk                              

/********************  Bits definition for DMA_SxCNDTR register  **************/
#define DMA_SxNDT_Pos            (0U)                                          
#define DMA_SxNDT_Msk            (0xFFFFU << DMA_SxNDT_Pos)                    /*!< 0x0000FFFF */
#define DMA_SxNDT                DMA_SxNDT_Msk                                 
#define DMA_SxNDT_0              (0x0001U << DMA_SxNDT_Pos)                    /*!< 0x00000001 */
#define DMA_SxNDT_1              (0x0002U << DMA_SxNDT_Pos)                    /*!< 0x00000002 */
#define DMA_SxNDT_2              (0x0004U << DMA_SxNDT_Pos)                    /*!< 0x00000004 */
#define DMA_SxNDT_3              (0x0008U << DMA_SxNDT_Pos)                    /*!< 0x00000008 */
#define DMA_SxNDT_4              (0x0010U << DMA_SxNDT_Pos)                    /*!< 0x00000010 */
#define DMA_SxNDT_5              (0x0020U << DMA_SxNDT_Pos)                    /*!< 0x00000020 */
#define DMA_SxNDT_6              (0x0040U << DMA_SxNDT_Pos)                    /*!< 0x00000040 */
#define DMA_SxNDT_7              (0x0080U << DMA_SxNDT_Pos)                    /*!< 0x00000080 */
#define DMA_SxNDT_8              (0x0100U << DMA_SxNDT_Pos)                    /*!< 0x00000100 */
#define DMA_SxNDT_9              (0x0200U << DMA_SxNDT_Pos)                    /*!< 0x00000200 */
#define DMA_SxNDT_10             (0x0400U << DMA_SxNDT_Pos)                    /*!< 0x00000400 */
#define DMA_SxNDT_11             (0x0800U << DMA_SxNDT_Pos)                    /*!< 0x00000800 */
#define DMA_SxNDT_12             (0x1000U << DMA_SxNDT_Pos)                    /*!< 0x00001000 */
#define DMA_SxNDT_13             (0x2000U << DMA_SxNDT_Pos)                    /*!< 0x00002000 */
#define DMA_SxNDT_14             (0x4000U << DMA_SxNDT_Pos)                    /*!< 0x00004000 */
#define DMA_SxNDT_15             (0x8000U << DMA_SxNDT_Pos)                    /*!< 0x00008000 */

/********************  Bits definition for DMA_SxFCR register  ****************/ 
#define DMA_SxFCR_FEIE_Pos       (7U)                                          
#define DMA_SxFCR_FEIE_Msk       (0x1U << DMA_SxFCR_FEIE_Pos)                  /*!< 0x00000080 */
#define DMA_SxFCR_FEIE           DMA_SxFCR_FEIE_Msk                            
#define DMA_SxFCR_FS_Pos         (3U)                                          
#define DMA_SxFCR_FS_Msk         (0x7U << DMA_SxFCR_FS_Pos)                    /*!< 0x00000038 */
#define DMA_SxFCR_FS             DMA_SxFCR_FS_Msk                              
#define DMA_SxFCR_FS_0           (0x1U << DMA_SxFCR_FS_Pos)                    /*!< 0x00000008 */
#define DMA_SxFCR_FS_1           (0x2U << DMA_SxFCR_FS_Pos)                    /*!< 0x00000010 */
#define DMA_SxFCR_FS_2           (0x4U << DMA_SxFCR_FS_Pos)                    /*!< 0x00000020 */
#define DMA_SxFCR_DMDIS_Pos      (2U)                                          
#define DMA_SxFCR_DMDIS_Msk      (0x1U << DMA_SxFCR_DMDIS_Pos)                 /*!< 0x00000004 */
#define DMA_SxFCR_DMDIS          DMA_SxFCR_DMDIS_Msk                           
#define DMA_SxFCR_FTH_Pos        (0U)                                          
#define DMA_SxFCR_FTH_Msk        (0x3U << DMA_SxFCR_FTH_Pos)                   /*!< 0x00000003 */
#define DMA_SxFCR_FTH            DMA_SxFCR_FTH_Msk                             
#define DMA_SxFCR_FTH_0          (0x1U << DMA_SxFCR_FTH_Pos)                   /*!< 0x00000001 */
#define DMA_SxFCR_FTH_1          (0x2U << DMA_SxFCR_FTH_Pos)                   /*!< 0x00000002 */

/********************  Bits definition for DMA_LISR register  *****************/ 
#define DMA_LISR_TCIF3_Pos       (27U)                                         
#define DMA_LISR_TCIF3_Msk       (0x1U << DMA_LISR_TCIF3_Pos)                  /*!< 0x08000000 */
#define DMA_LISR_TCIF3           DMA_LISR_TCIF3_Msk                            
#define DMA_LISR_HTIF3_Pos       (26U)                                         
#define DMA_LISR_HTIF3_Msk       (0x1U << DMA_LISR_HTIF3_Pos)                  /*!< 0x04000000 */
#define DMA_LISR_HTIF3           DMA_LISR_HTIF3_Msk                            
#define DMA_LISR_TEIF3_Pos       (25U)                                         
#define DMA_LISR_TEIF3_Msk       (0x1U << DMA_LISR_TEIF3_Pos)                  /*!< 0x02000000 */
#define DMA_LISR_TEIF3           DMA_LISR_TEIF3_Msk                            
#define DMA_LISR_DMEIF3_Pos      (24U)                                         
#define DMA_LISR_DMEIF3_Msk      (0x1U << DMA_LISR_DMEIF3_Pos)                 /*!< 0x01000000 */
#define DMA_LISR_DMEIF3          DMA_LISR_DMEIF3_Msk                           
#define DMA_LISR_FEIF3_Pos       (22U)                                         
#define DMA_LISR_FEIF3_Msk       (0x1U << DMA_LISR_FEIF3_Pos)                  /*!< 0x00400000 */
#define DMA_LISR_FEIF3           DMA_LISR_FEIF3_Msk                            
#define DMA_LISR_TCIF2_Pos       (21U)                                         
#define DMA_LISR_TCIF2_Msk       (0x1U << DMA_LISR_TCIF2_Pos)                  /*!< 0x00200000 */
#define DMA_LISR_TCIF2           DMA_LISR_TCIF2_Msk                            
#define DMA_LISR_HTIF2_Pos       (20U)                                         
#define DMA_LISR_HTIF2_Msk       (0x1U << DMA_LISR_HTIF2_Pos)                  /*!< 0x00100000 */
#define DMA_LISR_HTIF2           DMA_LISR_HTIF2_Msk                            
#define DMA_LISR_TEIF2_Pos       (19U)                                         
#define DMA_LISR_TEIF2_Msk       (0x1U << DMA_LISR_TEIF2_Pos)                  /*!< 0x00080000 */
#define DMA_LISR_TEIF2           DMA_LISR_TEIF2_Msk                            
#define DMA_LISR_DMEIF2_Pos      (18U)                                         
#define DMA_LISR_DMEIF2_Msk      (0x1U << DMA_LISR_DMEIF2_Pos)                 /*!< 0x00040000 */
#define DMA_LISR_DMEIF2          DMA_LISR_DMEIF2_Msk                           
#define DMA_LISR_FEIF2_Pos       (16U)                                         
#define DMA_LISR_FEIF2_Msk       (0x1U << DMA_LISR_FEIF2_Pos)                  /*!< 0x00010000 */
#define DMA_LISR_FEIF2           DMA_LISR_FEIF2_Msk                            
#define DMA_LISR_TCIF1_Pos       (11U)                                         
#define DMA_LISR_TCIF1_Msk       (0x1U << DMA_LISR_TCIF1_Pos)                  /*!< 0x00000800 */
#define DMA_LISR_TCIF1           DMA_LISR_TCIF1_Msk                            
#define DMA_LISR_HTIF1_Pos       (10U)                                         
#define DMA_LISR_HTIF1_Msk       (0x1U << DMA_LISR_HTIF1_Pos)                  /*!< 0x00000400 */
#define DMA_LISR_HTIF1           DMA_LISR_HTIF1_Msk                            
#define DMA_LISR_TEIF1_Pos       (9U)                                          
#define DMA_LISR_TEIF1_Msk       (0x1U << DMA_LISR_TEIF1_Pos)                  /*!< 0x00000200 */
#define DMA_LISR_TEIF1           DMA_LISR_TEIF1_Msk                            
#define DMA_LISR_DMEIF1_Pos      (8U)                                          
#define DMA_LISR_DMEIF1_Msk      (0x1U << DMA_LISR_DMEIF1_Pos)                 /*!< 0x00000100 */
#define DMA_LISR_DMEIF1          DMA_LISR_DMEIF1_Msk                           
#define DMA_LISR_FEIF1_Pos       (6U)                                          
#define DMA_LISR_FEIF1_Msk       (0x1U << DMA_LISR_FEIF1_Pos)                  /*!< 0x00000040 */
#define DMA_LISR_FEIF1           DMA_LISR_FEIF1_Msk                            
#define DMA_LISR_TCIF0_Pos       (5U)                                          
#define DMA_LISR_TCIF0_Msk       (0x1U << DMA_LISR_TCIF0_Pos)                  /*!< 0x00000020 */
#define DMA_LISR_TCIF0           DMA_LISR_TCIF0_Msk                            
#define DMA_LISR_HTIF0_Pos       (4U)                                          
#define DMA_LISR_HTIF0_Msk       (0x1U << DMA_LISR_HTIF0_Pos)                  /*!< 0x00000010 */
#define DMA_LISR_HTIF0           DMA_LISR_HTIF0_Msk                            
#define DMA_LISR_TEIF0_Pos       (3U)                                          
#define DMA_LISR_TEIF0_Msk       (0x1U << DMA_LISR_TEIF0_Pos)                  /*!< 0x00000008 */
#define DMA_LISR_TEIF0           DMA_LISR_TEIF0_Msk                            
#define DMA_LISR_DMEIF0_Pos      (2U)                                          
#define DMA_LISR_DMEIF0_Msk      (0x1U << DMA_LISR_DMEIF0_Pos)                 /*!< 0x00000004 */
#define DMA_LISR_DMEIF0          DMA_LISR_DMEIF0_Msk                           
#define DMA_LISR_FEIF0_Pos       (0U)                                          
#define DMA_LISR_FEIF0_Msk       (0x1U << DMA_LISR_FEIF0_Pos)                  /*!< 0x00000001 */
#define DMA_LISR_FEIF0           DMA_LISR_FEIF0_Msk                            

/********************  Bits definition for DMA_HISR register  *****************/ 
#define DMA_HISR_TCIF7_Pos       (27U)                                         
#define DMA_HISR_TCIF7_Msk       (0x1U << DMA_HISR_TCIF7_Pos)                  /*!< 0x08000000 */
#define DMA_HISR_TCIF7           DMA_HISR_TCIF7_Msk                            
#define DMA_HISR_HTIF7_Pos       (26U)                                         
#define DMA_HISR_HTIF7_Msk       (0x1U << DMA_HISR_HTIF7_Pos)                  /*!< 0x04000000 */
#define DMA_HISR_HTIF7           DMA_HISR_HTIF7_Msk                            
#define DMA_HISR_TEIF7_Pos       (25U)                                         
#define DMA_HISR_TEIF7_Msk       (0x1U << DMA_HISR_TEIF7_Pos)                  /*!< 0x02000000 */
#define DMA_HISR_TEIF7           DMA_HISR_TEIF7_Msk                            
#define DMA_HISR_DMEIF7_Pos      (24U)                                         
#define DMA_HISR_DMEIF7_Msk      (0x1U << DMA_HISR_DMEIF7_Pos)                 /*!< 0x01000000 */
#define DMA_HISR_DMEIF7          DMA_HISR_DMEIF7_Msk                           
#define DMA_HISR_FEIF7_Pos       (22U)                                         
#define DMA_HISR_FEIF7_Msk       (0x1U << DMA_HISR_FEIF7_Pos)                  /*!< 0x00400000 */
#define DMA_HISR_FEIF7           DMA_HISR_FEIF7_Msk                            
#define DMA_HISR_TCIF6_Pos       (21U)                                         
#define DMA_HISR_TCIF6_Msk       (0x1U << DMA_HISR_TCIF6_Pos)                  /*!< 0x00200000 */
#define DMA_HISR_TCIF6           DMA_HISR_TCIF6_Msk                            
#define DMA_HISR_HTIF6_Pos       (20U)                                         
#define DMA_HISR_HTIF6_Msk       (0x1U << DMA_HISR_HTIF6_Pos)                  /*!< 0x00100000 */
#define DMA_HISR_HTIF6           DMA_HISR_HTIF6_Msk                            
#define DMA_HISR_TEIF6_Pos       (19U)                                         
#define DMA_HISR_TEIF6_Msk       (0x1U << DMA_HISR_TEIF6_Pos)                  /*!< 0x00080000 */
#define DMA_HISR_TEIF6           DMA_HISR_TEIF6_Msk                            
#define DMA_HISR_DMEIF6_Pos      (18U)                                         
#define DMA_HISR_DMEIF6_Msk      (0x1U << DMA_HISR_DMEIF6_Pos)                 /*!< 0x00040000 */
#define DMA_HISR_DMEIF6          DMA_HISR_DMEIF6_Msk                           
#define DMA_HISR_FEIF6_Pos       (16U)                                         
#define DMA_HISR_FEIF6_Msk       (0x1U << DMA_HISR_FEIF6_Pos)                  /*!< 0x00010000 */
#define DMA_HISR_FEIF6           DMA_HISR_FEIF6_Msk                            
#define DMA_HISR_TCIF5_Pos       (11U)                                         
#define DMA_HISR_TCIF5_Msk       (0x1U << DMA_HISR_TCIF5_Pos)                  /*!< 0x00000800 */
#define DMA_HISR_TCIF5           DMA_HISR_TCIF5_Msk                            
#define DMA_HISR_HTIF5_Pos       (10U)                                         
#define DMA_HISR_HTIF5_Msk       (0x1U << DMA_HISR_HTIF5_Pos)                  /*!< 0x00000400 */
#define DMA_HISR_HTIF5           DMA_HISR_HTIF5_Msk                            
#define DMA_HISR_TEIF5_Pos       (9U)                                          
#define DMA_HISR_TEIF5_Msk       (0x1U << DMA_HISR_TEIF5_Pos)                  /*!< 0x00000200 */
#define DMA_HISR_TEIF5           DMA_HISR_TEIF5_Msk                            
#define DMA_HISR_DMEIF5_Pos      (8U)                                          
#define DMA_HISR_DMEIF5_Msk      (0x1U << DMA_HISR_DMEIF5_Pos)                 /*!< 0x00000100 */
#define DMA_HISR_DMEIF5          DMA_HISR_DMEIF5_Msk                           
#define DMA_HISR_FEIF5_Pos       (6U)                                          
#define DMA_HISR_FEIF5_Msk       (0x1U << DMA_HISR_FEIF5_Pos)                  /*!< 0x00000040 */
#define DMA_HISR_FEIF5           DMA_HISR_FEIF5_Msk                            
#define DMA_HISR_TCIF4_Pos       (5U)                                          
#define DMA_HISR_TCIF4_Msk       (0x1U << DMA_HISR_TCIF4_Pos)                  /*!< 0x00000020 */
#define DMA_HISR_TCIF4           DMA_HISR_TCIF4_Msk                            
#define DMA_HISR_HTIF4_Pos       (4U)                                          
#define DMA_HISR_HTIF4_Msk       (0x1U << DMA_HISR_HTIF4_Pos)                  /*!< 0x00000010 */
#define DMA_HISR_HTIF4           DMA_HISR_HTIF4_Msk                            
#define DMA_HISR_TEIF4_Pos       (3U)                                          
#define DMA_HISR_TEIF4_Msk       (0x1U << DMA_HISR_TEIF4_Pos)                  /*!< 0x00000008 */
#define DMA_HISR_TEIF4           DMA_HISR_TEIF4_Msk                            
#define DMA_HISR_DMEIF4_Pos      (2U)                                          
#define DMA_HISR_DMEIF4_Msk      (0x1U << DMA_HISR_DMEIF4_Pos)                 /*!< 0x00000004 */
#define DMA_HISR_DMEIF4          DMA_HISR_DMEIF4_Msk                           
#define DMA_HISR_FEIF4_Pos       (0U)                                          
#define DMA_HISR_FEIF4_Msk       (0x1U << DMA_HISR_FEIF4_Pos)                  /*!< 0x00000001 */
#define DMA_HISR_FEIF4           DMA_HISR_FEIF4_Msk                            

/********************  Bits definition for DMA_LIFCR register  ****************/ 
#define DMA_LIFCR_CTCIF3_Pos     (27U)                                         
#define DMA_LIFCR_CTCIF3_Msk     (0x1U << DMA_LIFCR_CTCIF3_Pos)                /*!< 0x08000000 */
#define DMA_LIFCR_CTCIF3         DMA_LIFCR_CTCIF3_Msk                          
#define DMA_LIFCR_CHTIF3_Pos     (26U)                                         
#define DMA_LIFCR_CHTIF3_Msk     (0x1U << DMA_LIFCR_CHTIF3_Pos)                /*!< 0x04000000 */
#define DMA_LIFCR_CHTIF3         DMA_LIFCR_CHTIF3_Msk                          
#define DMA_LIFCR_CTEIF3_Pos     (25U)                                         
#define DMA_LIFCR_CTEIF3_Msk     (0x1U << DMA_LIFCR_CTEIF3_Pos)                /*!< 0x02000000 */
#define DMA_LIFCR_CTEIF3         DMA_LIFCR_CTEIF3_Msk                          
#define DMA_LIFCR_CDMEIF3_Pos    (24U)                                         
#define DMA_LIFCR_CDMEIF3_Msk    (0x1U << DMA_LIFCR_CDMEIF3_Pos)               /*!< 0x01000000 */
#define DMA_LIFCR_CDMEIF3        DMA_LIFCR_CDMEIF3_Msk                         
#define DMA_LIFCR_CFEIF3_Pos     (22U)                                         
#define DMA_LIFCR_CFEIF3_Msk     (0x1U << DMA_LIFCR_CFEIF3_Pos)                /*!< 0x00400000 */
#define DMA_LIFCR_CFEIF3         DMA_LIFCR_CFEIF3_Msk                          
#define DMA_LIFCR_CTCIF2_Pos     (21U)                                         
#define DMA_LIFCR_CTCIF2_Msk     (0x1U << DMA_LIFCR_CTCIF2_Pos)                /*!< 0x00200000 */
#define DMA_LIFCR_CTCIF2         DMA_LIFCR_CTCIF2_Msk                          
#define DMA_LIFCR_CHTIF2_Pos     (20U)                                         
#define DMA_LIFCR_CHTIF2_Msk     (0x1U << DMA_LIFCR_CHTIF2_Pos)                /*!< 0x00100000 */
#define DMA_LIFCR_CHTIF2         DMA_LIFCR_CHTIF2_Msk                          
#define DMA_LIFCR_CTEIF2_Pos     (19U)                                         
#define DMA_LIFCR_CTEIF2_Msk     (0x1U << DMA_LIFCR_CTEIF2_Pos)                /*!< 0x00080000 */
#define DMA_LIFCR_CTEIF2         DMA_LIFCR_CTEIF2_Msk                          
#define DMA_LIFCR_CDMEIF2_Pos    (18U)                                         
#define DMA_LIFCR_CDMEIF2_Msk    (0x1U << DMA_LIFCR_CDMEIF2_Pos)               /*!< 0x00040000 */
#define DMA_LIFCR_CDMEIF2        DMA_LIFCR_CDMEIF2_Msk                         
#define DMA_LIFCR_CFEIF2_Pos     (16U)                                         
#define DMA_LIFCR_CFEIF2_Msk     (0x1U << DMA_LIFCR_CFEIF2_Pos)                /*!< 0x00010000 */
#define DMA_LIFCR_CFEIF2         DMA_LIFCR_CFEIF2_Msk                          
#define DMA_LIFCR_CTCIF1_Pos     (11U)                                         
#define DMA_LIFCR_CTCIF1_Msk     (0x1U << DMA_LIFCR_CTCIF1_Pos)                /*!< 0x00000800 */
#define DMA_LIFCR_CTCIF1         DMA_LIFCR_CTCIF1_Msk                          
#define DMA_LIFCR_CHTIF1_Pos     (10U)                                         
#define DMA_LIFCR_CHTIF1_Msk     (0x1U << DMA_LIFCR_CHTIF1_Pos)                /*!< 0x00000400 */
#define DMA_LIFCR_CHTIF1         DMA_LIFCR_CHTIF1_Msk                          
#define DMA_LIFCR_CTEIF1_Pos     (9U)                                          
#define DMA_LIFCR_CTEIF1_Msk     (0x1U << DMA_LIFCR_CTEIF1_Pos)                /*!< 0x00000200 */
#define DMA_LIFCR_CTEIF1         DMA_LIFCR_CTEIF1_Msk                          
#define DMA_LIFCR_CDMEIF1_Pos    (8U)                                          
#define DMA_LIFCR_CDMEIF1_Msk    (0x1U << DMA_LIFCR_CDMEIF1_Pos)               /*!< 0x00000100 */
#define DMA_LIFCR_CDMEIF1        DMA_LIFCR_CDMEIF1_Msk                         
#define DMA_LIFCR_CFEIF1_Pos     (6U)                                          
#define DMA_LIFCR_CFEIF1_Msk     (0x1U << DMA_LIFCR_CFEIF1_Pos)                /*!< 0x00000040 */
#define DMA_LIFCR_CFEIF1         DMA_LIFCR_CFEIF1_Msk                          
#define DMA_LIFCR_CTCIF0_Pos     (5U)                                          
#define DMA_LIFCR_CTCIF0_Msk     (0x1U << DMA_LIFCR_CTCIF0_Pos)                /*!< 0x00000020 */
#define DMA_LIFCR_CTCIF0         DMA_LIFCR_CTCIF0_Msk                          
#define DMA_LIFCR_CHTIF0_Pos     (4U)                                          
#define DMA_LIFCR_CHTIF0_Msk     (0x1U << DMA_LIFCR_CHTIF0_Pos)                /*!< 0x00000010 */
#define DMA_LIFCR_CHTIF0         DMA_LIFCR_CHTIF0_Msk                          
#define DMA_LIFCR_CTEIF0_Pos     (3U)                                          
#define DMA_LIFCR_CTEIF0_Msk     (0x1U << DMA_LIFCR_CTEIF0_Pos)                /*!< 0x00000008 */
#define DMA_LIFCR_CTEIF0         DMA_LIFCR_CTEIF0_Msk                          
#define DMA_LIFCR_CDMEIF0_Pos    (2U)                                          
#define DMA_LIFCR_CDMEIF0_Msk    (0x1U << DMA_LIFCR_CDMEIF0_Pos)               /*!< 0x00000004 */
#define DMA_LIFCR_CDMEIF0        DMA_LIFCR_CDMEIF0_Msk                         
#define DMA_LIFCR_CFEIF0_Pos     (0U)                                          
#define DMA_LIFCR_CFEIF0_Msk     (0x1U << DMA_LIFCR_CFEIF0_Pos)                /*!< 0x00000001 */
#define DMA_LIFCR_CFEIF0         DMA_LIFCR_CFEIF0_Msk                          

/********************  Bits definition for DMA_HIFCR  register  ****************/ 
#define DMA_HIFCR_CTCIF7_Pos     (27U)                                         
#define DMA_HIFCR_CTCIF7_Msk     (0x1U << DMA_HIFCR_CTCIF7_Pos)                /*!< 0x08000000 */
#define DMA_HIFCR_CTCIF7         DMA_HIFCR_CTCIF7_Msk                          
#define DMA_HIFCR_CHTIF7_Pos     (26U)                                         
#define DMA_HIFCR_CHTIF7_Msk     (0x1U << DMA_HIFCR_CHTIF7_Pos)                /*!< 0x04000000 */
#define DMA_HIFCR_CHTIF7         DMA_HIFCR_CHTIF7_Msk                          
#define DMA_HIFCR_CTEIF7_Pos     (25U)                                         
#define DMA_HIFCR_CTEIF7_Msk     (0x1U << DMA_HIFCR_CTEIF7_Pos)                /*!< 0x02000000 */
#define DMA_HIFCR_CTEIF7         DMA_HIFCR_CTEIF7_Msk                          
#define DMA_HIFCR_CDMEIF7_Pos    (24U)                                         
#define DMA_HIFCR_CDMEIF7_Msk    (0x1U << DMA_HIFCR_CDMEIF7_Pos)               /*!< 0x01000000 */
#define DMA_HIFCR_CDMEIF7        DMA_HIFCR_CDMEIF7_Msk                         
#define DMA_HIFCR_CFEIF7_Pos     (22U)                                         
#define DMA_HIFCR_CFEIF7_Msk     (0x1U << DMA_HIFCR_CFEIF7_Pos)                /*!< 0x00400000 */
#define DMA_HIFCR_CFEIF7         DMA_HIFCR_CFEIF7_Msk                          
#define DMA_HIFCR_CTCIF6_Pos     (21U)                                         
#define DMA_HIFCR_CTCIF6_Msk     (0x1U << DMA_HIFCR_CTCIF6_Pos)                /*!< 0x00200000 */
#define DMA_HIFCR_CTCIF6         DMA_HIFCR_CTCIF6_Msk                          
#define DMA_HIFCR_CHTIF6_Pos     (20U)                                         
#define DMA_HIFCR_CHTIF6_Msk     (0x1U << DMA_HIFCR_CHTIF6_Pos)                /*!< 0x00100000 */
#define DMA_HIFCR_CHTIF6         DMA_HIFCR_CHTIF6_Msk                          
#define DMA_HIFCR_CTEIF6_Pos     (19U)                                         
#define DMA_HIFCR_CTEIF6_Msk     (0x1U << DMA_HIFCR_CTEIF6_Pos)                /*!< 0x00080000 */
#define DMA_HIFCR_CTEIF6         DMA_HIFCR_CTEIF6_Msk                          
#define DMA_HIFCR_CDMEIF6_Pos    (18U)                                         
#define DMA_HIFCR_CDMEIF6_Msk    (0x1U << DMA_HIFCR_CDMEIF6_Pos)               /*!< 0x00040000 */
#define DMA_HIFCR_CDMEIF6        DMA_HIFCR_CDMEIF6_Msk                         
#define DMA_HIFCR_CFEIF6_Pos     (16U)                                         
#define DMA_HIFCR_CFEIF6_Msk     (0x1U << DMA_HIFCR_CFEIF6_Pos)                /*!< 0x00010000 */
#define DMA_HIFCR_CFEIF6         DMA_HIFCR_CFEIF6_Msk                          
#define DMA_HIFCR_CTCIF5_Pos     (11U)                                         
#define DMA_HIFCR_CTCIF5_Msk     (0x1U << DMA_HIFCR_CTCIF5_Pos)                /*!< 0x00000800 */
#define DMA_HIFCR_CTCIF5         DMA_HIFCR_CTCIF5_Msk                          
#define DMA_HIFCR_CHTIF5_Pos     (10U)                                         
#define DMA_HIFCR_CHTIF5_Msk     (0x1U << DMA_HIFCR_CHTIF5_Pos)                /*!< 0x00000400 */
#define DMA_HIFCR_CHTIF5         DMA_HIFCR_CHTIF5_Msk                          
#define DMA_HIFCR_CTEIF5_Pos     (9U)                                          
#define DMA_HIFCR_CTEIF5_Msk     (0x1U << DMA_HIFCR_CTEIF5_Pos)                /*!< 0x00000200 */
#define DMA_HIFCR_CTEIF5         DMA_HIFCR_CTEIF5_Msk                          
#define DMA_HIFCR_CDMEIF5_Pos    (8U)                                          
#define DMA_HIFCR_CDMEIF5_Msk    (0x1U << DMA_HIFCR_CDMEIF5_Pos)               /*!< 0x00000100 */
#define DMA_HIFCR_CDMEIF5        DMA_HIFCR_CDMEIF5_Msk                         
#define DMA_HIFCR_CFEIF5_Pos     (6U)                                          
#define DMA_HIFCR_CFEIF5_Msk     (0x1U << DMA_HIFCR_CFEIF5_Pos)                /*!< 0x00000040 */
#define DMA_HIFCR_CFEIF5         DMA_HIFCR_CFEIF5_Msk                          
#define DMA_HIFCR_CTCIF4_Pos     (5U)                                          
#define DMA_HIFCR_CTCIF4_Msk     (0x1U << DMA_HIFCR_CTCIF4_Pos)                /*!< 0x00000020 */
#define DMA_HIFCR_CTCIF4         DMA_HIFCR_CTCIF4_Msk                          
#define DMA_HIFCR_CHTIF4_Pos     (4U)                                          
#define DMA_HIFCR_CHTIF4_Msk     (0x1U << DMA_HIFCR_CHTIF4_Pos)                /*!< 0x00000010 */
#define DMA_HIFCR_CHTIF4         DMA_HIFCR_CHTIF4_Msk                          
#define DMA_HIFCR_CTEIF4_Pos     (3U)                                          
#define DMA_HIFCR_CTEIF4_Msk     (0x1U << DMA_HIFCR_CTEIF4_Pos)                /*!< 0x00000008 */
#define DMA_HIFCR_CTEIF4         DMA_HIFCR_CTEIF4_Msk                          
#define DMA_HIFCR_CDMEIF4_Pos    (2U)                                          
#define DMA_HIFCR_CDMEIF4_Msk    (0x1U << DMA_HIFCR_CDMEIF4_Pos)               /*!< 0x00000004 */
#define DMA_HIFCR_CDMEIF4        DMA_HIFCR_CDMEIF4_Msk                         
#define DMA_HIFCR_CFEIF4_Pos     (0U)                                          
#define DMA_HIFCR_CFEIF4_Msk     (0x1U << DMA_HIFCR_CFEIF4_Pos)                /*!< 0x00000001 */
#define DMA_HIFCR_CFEIF4         DMA_HIFCR_CFEIF4_Msk                          

/******************  Bit definition for DMA_SxPAR register  ********************/
#define DMA_SxPAR_PA_Pos         (0U)                                          
#define DMA_SxPAR_PA_Msk         (0xFFFFFFFFU << DMA_SxPAR_PA_Pos)             /*!< 0xFFFFFFFF */
#define DMA_SxPAR_PA             DMA_SxPAR_PA_Msk                              /*!< Peripheral Address */

/******************  Bit definition for DMA_SxM0AR register  ********************/
#define DMA_SxM0AR_M0A_Pos       (0U)                                          
#define DMA_SxM0AR_M0A_Msk       (0xFFFFFFFFU << DMA_SxM0AR_M0A_Pos)           /*!< 0xFFFFFFFF */
#define DMA_SxM0AR_M0A           DMA_SxM0AR_M0A_Msk                            /*!< Memory Address */

/******************  Bit definition for DMA_SxM1AR register  ********************/
#define DMA_SxM1AR_M1A_Pos       (0U)                                          
#define DMA_SxM1AR_M1A_Msk       (0xFFFFFFFFU << DMA_SxM1AR_M1A_Pos)           /*!< 0xFFFFFFFF */
#define DMA_SxM1AR_M1A           DMA_SxM1AR_M1A_Msk                            /*!< Memory Address */



#endif /* __STM32F4xx_HAL_DMA_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
