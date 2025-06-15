#include "stm32f4xx_hal.h"
#include "motor.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "cmsis_os2.h"
#include "uart.h"

// For Motor PWM
TIM_HandleTypeDef htim1;  // Global declaration for TIM1

// For Motor Encoders (TIM3, TIM4, TIM5)
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim4;
TIM_HandleTypeDef htim5;

volatile int32_t enc_count1 = 0;
volatile int32_t enc_count2 = 0;
volatile int32_t enc_count3 = 0;

static float prev_pos1 = 0.0f;
static float prev_pos2 = 0.0f;
static float prev_pos3 = 0.0f;

void motor_pwm_init(void) {
    /* Enable TIM1 clock */
    __HAL_RCC_TIM1_CLK_ENABLE();
    /* Enable GPIOA clock */
    __HAL_RCC_GPIOA_CLK_ENABLE();

    // __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    
    // PWM pins: PA8 (CH1), PA9 (CH2), PA10 (CH3)
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.Pin = GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF1_TIM1;

    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* Initialize PA0 for Motor 1 direction control */
    GPIO_InitStruct.Pin = M1_DIR_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(M1_DIR_GPIO_PORT, &GPIO_InitStruct);

    /* Initialize PC5 for Motor 2 direction control */
    GPIO_InitStruct.Pin = M2_DIR_PIN;
    HAL_GPIO_Init(M2_DIR_GPIO_PORT, &GPIO_InitStruct);

    /* Initialize PC6 for Motor 3 direction control */
    GPIO_InitStruct.Pin = M3_DIR_PIN;
    HAL_GPIO_Init(M3_DIR_GPIO_PORT, &GPIO_InitStruct);

    // Brake pin
    GPIO_InitStruct.Pin = BRAKE_PIN;
    HAL_GPIO_Init(BRAKE_GPIO_PORT, &GPIO_InitStruct);
    HAL_GPIO_WritePin(BRAKE_GPIO_PORT, BRAKE_PIN, GPIO_PIN_RESET); // Ensure brake is released on startup
    
    /* Initialize timer 1 for PA8 (CH1), PA9 (CH2), PA10 (CH3) to control motor enable pins */
    htim1.Instance = TIM1;
    htim1.Init.Prescaler = 0;       // 
    htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim1.Init.Period = TIMER_PERIOD-1;   // For PWM 20kHz
    htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    // htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

    if (HAL_TIM_PWM_Init(&htim1) != HAL_OK) {
        printf("Error: TIM1 PWM init failed\r\n");
        return;
    }

    /* Configure timer 1, channels for PA8 (CH1), PA9 (CH2), PA10 (CH3) */
    TIM_OC_InitTypeDef sConfigOC;
    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = 0;        // Start with 0% duty cycle
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;

    // Configure PWM Channel 1 for PA8 (Motor 1 Enable)
    if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, M1_PWM_CHANNEL) != HAL_OK)
    {
        // Handle error
        printf("Error: PWM channel configuration for TIM1 CH1 failed.\n");
        return;
    }
    // Configure PWM Channel 2 for PA9 (Motor 2 Enable)
    if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, M2_PWM_CHANNEL) != HAL_OK)
    {
        // Handle error
        printf("Error: PWM channel configuration for TIM1 CH2 failed.\n");
        return;
    }
    // Configure PWM Channel 3 for PA10 (Motor 3 Enable)
    if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, M3_PWM_CHANNEL) != HAL_OK)
    {
        // Handle error
        printf("Error: PWM channel configuration for TIM1 CH3 failed.\n");
        return;
    }

     /* Start PWM on TIM1 Channel 1 (PA8, ENA) and Channel 2 (PA9, ENB) */
    if (HAL_TIM_PWM_Start(&htim1, M1_PWM_CHANNEL) != HAL_OK)
    {
        printf("Error: Failed to start PWM on TIM1 CH1.\n");
        return;
    }
    if (HAL_TIM_PWM_Start(&htim1, M2_PWM_CHANNEL) != HAL_OK)
    {
        printf("Error: Failed to start PWM on TIM1 CH2.\n");
        return;
    }
    if (HAL_TIM_PWM_Start(&htim1, M3_PWM_CHANNEL) != HAL_OK)
    {
        printf("Error: Failed to start PWM on TIM1 CH3.\n");
        return;
    }
    else {
        (printf("Timer CH1, CH2 & CH3 Initialized\n"));
    }
}

void motor_encoder_init(void) {
    // Enable clocks for timers
    __HAL_RCC_TIM3_CLK_ENABLE();
    __HAL_RCC_TIM4_CLK_ENABLE();
    __HAL_RCC_TIM5_CLK_ENABLE();

    // Enable GPIO clocks
    __HAL_RCC_GPIOA_CLK_ENABLE(); // For TIM3 (PA6, PA7)
    __HAL_RCC_GPIOB_CLK_ENABLE(); // For TIM4 (PB6, PB7) and TIM5 (PB12, PB13)

    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // --- Motor 1 Encoder Pins (TIM3: PA6 CH1, PA7 CH2) ---
    GPIO_InitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    htim3.Instance = TIM3;
    htim3.Init.Prescaler = 0;
    htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim3.Init.Period = 0xFFFF;
    htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim3.Init.RepetitionCounter = 0;
    HAL_TIM_Encoder_Init(&htim3, &(TIM_Encoder_InitTypeDef){
        .EncoderMode = TIM_ENCODERMODE_TI12,
        .IC1Polarity = TIM_ICPOLARITY_RISING,
        .IC1Selection = TIM_ICSELECTION_DIRECTTI,
        .IC1Prescaler = TIM_ICPSC_DIV1,
        .IC1Filter = 0,
        .IC2Polarity = TIM_ICPOLARITY_RISING,
        .IC2Selection = TIM_ICSELECTION_DIRECTTI,
        .IC2Prescaler = TIM_ICPSC_DIV1,
        .IC2Filter = 0
    });
    HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);

    // --- Motor 2 Encoder Pins (TIM5: PA0 CH1, PA1 CH2) ---
    GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF2_TIM5;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    htim5.Instance = TIM5;
    htim5.Init.Prescaler = 0;
    htim5.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim5.Init.Period = 0xFFFF;
    htim5.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim5.Init.RepetitionCounter = 0;
    HAL_TIM_Encoder_Init(&htim5, &(TIM_Encoder_InitTypeDef){
        .EncoderMode = TIM_ENCODERMODE_TI12,
        .IC1Polarity = TIM_ICPOLARITY_RISING,
        .IC1Selection = TIM_ICSELECTION_DIRECTTI,
        .IC1Prescaler = TIM_ICPSC_DIV1,
        .IC1Filter = 0,
        .IC2Polarity = TIM_ICPOLARITY_RISING,
        .IC2Selection = TIM_ICSELECTION_DIRECTTI,
        .IC2Prescaler = TIM_ICPSC_DIV1,
        .IC2Filter = 0
    });
    HAL_TIM_Encoder_Start(&htim5, TIM_CHANNEL_ALL);

    // --- Motor 3 Encoder Pins (TIM4: PB6 CH1, PB7 CH2) ---
    GPIO_InitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_7;
    GPIO_InitStruct.Alternate = GPIO_AF2_TIM4;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    htim4.Instance = TIM4;
    htim4.Init.Prescaler = 0;
    htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim4.Init.Period = 0xFFFF;
    htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim4.Init.RepetitionCounter = 0;
    HAL_TIM_Encoder_Init(&htim4, &(TIM_Encoder_InitTypeDef){
        .EncoderMode = TIM_ENCODERMODE_TI12,
        .IC1Polarity = TIM_ICPOLARITY_RISING,
        .IC1Selection = TIM_ICSELECTION_DIRECTTI,
        .IC1Prescaler = TIM_ICPSC_DIV1,
        .IC1Filter = 0,
        .IC2Polarity = TIM_ICPOLARITY_RISING,
        .IC2Selection = TIM_ICSELECTION_DIRECTTI,
        .IC2Prescaler = TIM_ICPSC_DIV1,
        .IC2Filter = 0
    });
    HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_ALL);

    printf("\nMotor Encoders Initialized (Timer Mode + GPIO AF Config)\n");
}

float motor1_get_position_radians(void) {
    int32_t count = -__HAL_TIM_GET_COUNTER(&htim3);
    enc_count1 = ((count % MOTOR_CPR) + MOTOR_CPR) % MOTOR_CPR;
    
    return (MOTOR_2PI * enc_count1) / MOTOR_CPR;
}

float motor2_get_position_radians(void) {
    int32_t count = -__HAL_TIM_GET_COUNTER(&htim5);
    enc_count2 = ((count % MOTOR_CPR) + MOTOR_CPR) % MOTOR_CPR;
    return (MOTOR_2PI * enc_count2) / MOTOR_CPR;
}

float motor3_get_position_radians(void) {
    int32_t count = -__HAL_TIM_GET_COUNTER(&htim4);
    enc_count3 = ((count % MOTOR_CPR) + MOTOR_CPR) % MOTOR_CPR;
    return (MOTOR_2PI * enc_count3) / MOTOR_CPR;
}

float motor1_get_velocity(void) {
    float pos = motor1_get_position_radians();
    float vel = (pos - prev_pos1) * 200.0f;  // 200Hz sample rate
    prev_pos1 = pos;
    return vel;
}

float motor2_get_velocity(void) {
    float pos = motor2_get_position_radians();
    float vel = (pos - prev_pos2) * 200.0f;
    prev_pos2 = pos;
    return vel;
}

float motor3_get_velocity(void) {
    float pos = motor3_get_position_radians();
    float vel = (pos - prev_pos3) * 200.0f;
    prev_pos3 = pos;
    return vel;
}

/*PWM Control of voltage input for Motor 1*/
void motor1_set_V(float voltage_motor1) {
    float dutyCycle_motor1;
    // Motor 1 direction control (PA0)
    if (voltage_motor1 > 0)
    {
        HAL_GPIO_WritePin(M1_DIR_GPIO_PORT, M1_DIR_PIN, GPIO_PIN_RESET);   // CW = LOW
        
    }
    else if (voltage_motor1 < 0)
    {
        HAL_GPIO_WritePin(M1_DIR_GPIO_PORT, M1_DIR_PIN, GPIO_PIN_SET); // CCW = HIGH
        voltage_motor1 = -voltage_motor1;
    }
    else
    {
        HAL_GPIO_WritePin(M1_DIR_GPIO_PORT, M1_DIR_PIN, GPIO_PIN_RESET);
    }

    // Clamp voltage to maximum tested supply voltage
    if (voltage_motor1 > MOTOR_SAFETY_VOLTAGE) voltage_motor1 = MOTOR_SAFETY_VOLTAGE;

    // Calculate duty cycle based on motor voltage vs supply voltage
    dutyCycle_motor1 = (voltage_motor1 / MOTOR_SUPPLY_VOLTAGE) * TIMER_PERIOD;

    // Clamp to valid range
    if (dutyCycle_motor1 > TIMER_PERIOD)
        dutyCycle_motor1 = TIMER_PERIOD;

    // Set PWM duty cycle for Motor 1 (PA8)
    __HAL_TIM_SET_COMPARE(&htim1, M1_PWM_CHANNEL, dutyCycle_motor1); 
    printf("\nTimer Channel 1 set to duty cycle: %f\n" , dutyCycle_motor1/TIMER_PERIOD *100.0f);
}

/*PWM Control of voltage input for Motor 2*/
void motor2_set_V(float voltage_motor2) {
    float dutyCycle_motor2;
    // Motor 2 direction control (PC5)
    if (voltage_motor2 > 0)
    {
        HAL_GPIO_WritePin(M2_DIR_GPIO_PORT, M2_DIR_PIN, GPIO_PIN_RESET);   // CW = LOW
        
    }
    else if (voltage_motor2 < 0)
    {
        HAL_GPIO_WritePin(M2_DIR_GPIO_PORT, M2_DIR_PIN, GPIO_PIN_SET); // CCW = HIGH
        voltage_motor2 = -voltage_motor2;
    }
    else
    {
        HAL_GPIO_WritePin(M2_DIR_GPIO_PORT, M2_DIR_PIN, GPIO_PIN_RESET);
    }

    // Clamp voltage to maximum tested supply voltage
    if (voltage_motor2 > MOTOR_SAFETY_VOLTAGE) voltage_motor2 = MOTOR_SAFETY_VOLTAGE;

    // Calculate duty cycle based on motor voltage vs supply voltage
    dutyCycle_motor2 = (voltage_motor2 / MOTOR_SUPPLY_VOLTAGE) * TIMER_PERIOD;

    // Clamp to valid range
    if (dutyCycle_motor2 > TIMER_PERIOD)
        dutyCycle_motor2 = TIMER_PERIOD;

    // Set PWM duty cycle for Motor 2 (PA9)
    __HAL_TIM_SET_COMPARE(&htim1, M2_PWM_CHANNEL, dutyCycle_motor2); 
    printf("\nTimer Channel 2 set to duty cycle: %f\n" , dutyCycle_motor2/TIMER_PERIOD *100.0f);
}

/*PWM Control of voltage input for Motor 3*/
void motor3_set_V(float voltage_motor3) {
    float dutyCycle_motor3;
    // Motor 3 direction control (PC6)
    if (voltage_motor3 > 0)
    {
        HAL_GPIO_WritePin(M3_DIR_GPIO_PORT, M3_DIR_PIN, GPIO_PIN_RESET);   // CW = LOW
        
    }
    else if (voltage_motor3 < 0)
    {
        HAL_GPIO_WritePin(M3_DIR_GPIO_PORT, M3_DIR_PIN, GPIO_PIN_SET); // CCW = HIGH
        voltage_motor3 = -voltage_motor3;
    }
    else
    {
        HAL_GPIO_WritePin(M3_DIR_GPIO_PORT, M3_DIR_PIN, GPIO_PIN_RESET);
    }

    // Clamp voltage to maximum tested supply voltage
    if (voltage_motor3 > MOTOR_SAFETY_VOLTAGE) voltage_motor3 = MOTOR_SAFETY_VOLTAGE;
    
    // Calculate duty cycle based on motor voltage vs supply voltage
    dutyCycle_motor3 = (voltage_motor3 / MOTOR_SUPPLY_VOLTAGE) * TIMER_PERIOD;

    // Clamp to valid range
    if (dutyCycle_motor3 > TIMER_PERIOD)
        dutyCycle_motor3 = TIMER_PERIOD;

    // Set PWM duty cycle for Motor 3 (PA10)
    __HAL_TIM_SET_COMPARE(&htim1, M3_PWM_CHANNEL, dutyCycle_motor3); 
    printf("\nTimer Channel 3 set to duty cycle: %f\n" , dutyCycle_motor3/TIMER_PERIOD *100.0f);
}

void motor_set_voltage(float voltage_motor1, float voltage_motor2, float voltage_motor3)
{
    motor1_set_V(voltage_motor1);
    motor2_set_V(voltage_motor2);
    motor3_set_V(voltage_motor3);
}


// --- FreeRTOS task for periodic velocity logging ---
void motor_velocity_logging_task(void *argument) {
    UNUSED(argument);
    while (1) {
        float v1 = motor1_get_velocity();
        float v2 = motor2_get_velocity();
        float v3 = motor3_get_velocity();
        printf("[LOG] Velocities (rad/s) => M1: %.3f | M2: %.3f | M3: %.3f\n", v1, v2, v3);
        osDelay(100); // log every 100ms
    }
}




