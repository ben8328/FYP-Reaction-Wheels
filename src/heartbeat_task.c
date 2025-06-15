#include <stdint.h>

#include "stm32f4xx_hal.h"
#include "cmsis_os2.h"
#include "heartbeat_task.h"

static void _heartbeat_update(void *arg);

static TIM_HandleTypeDef   _htim2;

static osThreadId_t _heartbeatThreadID;
static osThreadAttr_t _heartbeatThreadAttr = 
{
    .name = "heartbeat",
    .priority = osPriorityIdle,
    .stack_size = 128
};

static uint8_t _is_running = 0;
static uint8_t _is_init = 0;

void heartbeat_task_init(void)
{
    if (!_is_init)
    {
        /* Enable peripheral clocks */
        __HAL_RCC_GPIOA_CLK_ENABLE();
        __HAL_RCC_TIM2_CLK_ENABLE();

        /* Configure PA5 in output pushpull mode */
        GPIO_InitTypeDef  GPIO_InitStructure;
        GPIO_InitStructure.Pin = GPIO_PIN_5;
        GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStructure.Pull = GPIO_PULLUP;
        GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_LOW;
        GPIO_InitStructure.Alternate = GPIO_AF1_TIM2;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);

        /* Configure Timer2 to generate single PWM output on GPIOA5 */
        /* Set timer, prescaler, mode, period and clkdiv */
        _htim2.Instance = TIM2;
        _htim2.Init.Prescaler = 1;
        _htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
        _htim2.Init.Period = 0xFFFF;
        _htim2.Init.ClockDivision = 0;

        TIM_OC_InitTypeDef  _sConfigPWM;
        _sConfigPWM.OCMode = TIM_OCMODE_PWM1;
        _sConfigPWM.Pulse = 0;
        _sConfigPWM.OCPolarity = TIM_OCPOLARITY_HIGH;
        _sConfigPWM.OCFastMode = TIM_OCFAST_DISABLE;

        HAL_TIM_PWM_Init(&_htim2);
        HAL_TIM_PWM_ConfigChannel(&_htim2, &_sConfigPWM, TIM_CHANNEL_1);

        /* Enable clock for Timer2 */
        HAL_TIM_PWM_Start(&_htim2, TIM_CHANNEL_1);

        // CMSIS-RTOS API v2 Timer Documentation: https://www.keil.com/pack/doc/CMSIS/RTOS2/html/group__CMSIS__RTOS__TimerMgmt.html
        _heartbeatThreadID = osThreadNew(_heartbeat_update, NULL, &_heartbeatThreadAttr);   // Create the thread in the OS scheduler. 
        // Note: The thread starts automatically when osThreadNew is called
        _is_running = 1;
        _is_init = 1;
    }
}

void heartbeat_task_start(void)
{
    if (!_is_running)
    {
        osThreadResume(_heartbeatThreadID);
        _is_running = 1;
    }
}

void heartbeat_task_stop(void)
{
    if (_is_running)
    {
        osThreadSuspend(_heartbeatThreadID);
        _is_running = 0;
    }
}

uint8_t heartbeat_task_is_running(void)
{
    return _is_running;
}

void _heartbeat_update(void *arg)
{
    UNUSED(arg); 
    while(1)
    {
        for (int i = 0; i <= 127; i++)
        {
            __HAL_TIM_SET_COMPARE(&_htim2, TIM_CHANNEL_1, i*512);
            osDelay(1);
        }
        for (int i = 127; i >= 0; i--)
        {
            __HAL_TIM_SET_COMPARE(&_htim2, TIM_CHANNEL_1, i*512);
            osDelay(1);
        }
        for (int i = 0; i <= 127; i++)
        {
            __HAL_TIM_SET_COMPARE(&_htim2, TIM_CHANNEL_1, i*512);
            osDelay(1);
        }
        for (int i = 127; i >= 0; i--)
        {
            __HAL_TIM_SET_COMPARE(&_htim2, TIM_CHANNEL_1, i*512);
            osDelay(1);
        }
        osDelay(256);
    }
}

void heartbeat_task_deinit(void)
{
    _is_init = 0;
    _is_running = 0;
}