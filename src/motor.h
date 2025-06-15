/* motor.h */
#ifndef MOTOR_H
#define MOTOR_H

#include <stdint.h>
#include <stdbool.h>
#include "stm32f4xx_hal.h"

// Motor 1 pins (Nidec 24H)
#define M1_PWM_TIM          htim1        // PWM timer instance
#define M1_PWM_CHANNEL      TIM_CHANNEL_1 // PA8
// #define M1_DIR_GPIO_PORT    GPIOA         // PA0
// #define M1_DIR_PIN          GPIO_PIN_0    // Direction pin

//Temporary move for M2 Encoder function
#define M1_DIR_GPIO_PORT    GPIOC
#define M1_DIR_PIN          GPIO_PIN_8

#define M1_ENCA_GPIO_PORT   GPIOA         // PA6
#define M1_ENCA_PIN         GPIO_PIN_6    // Encoder A
#define M1_ENCB_GPIO_PORT   GPIOA         // PA7
#define M1_ENCB_PIN         GPIO_PIN_7    // Encoder B

// Motor 2 pins
#define M2_PWM_TIM          htim1        // TIM1 CH2 -> PA9
#define M2_PWM_CHANNEL      TIM_CHANNEL_2
#define M2_DIR_GPIO_PORT    GPIOC        // PC5
#define M2_DIR_PIN          GPIO_PIN_5
#define M2_ENCA_GPIO_PORT   GPIOB        // PB4
#define M2_ENCA_PIN         GPIO_PIN_4
#define M2_ENCB_GPIO_PORT   GPIOB        // PB5
#define M2_ENCB_PIN         GPIO_PIN_5

// Motor 3 pins
#define M3_PWM_TIM          htim1        // TIM1 CH3 -> PA10
#define M3_PWM_CHANNEL      TIM_CHANNEL_3
#define M3_DIR_GPIO_PORT    GPIOC        // PC6
#define M3_DIR_PIN          GPIO_PIN_6
#define M3_ENCA_GPIO_PORT   GPIOB        // PB6
#define M3_ENCA_PIN         GPIO_PIN_6
#define M3_ENCB_GPIO_PORT   GPIOB        // PB7
#define M3_ENCB_PIN         GPIO_PIN_7

// Common brake pin (all motors)
#define BRAKE_GPIO_PORT     GPIOC        // PC0
#define BRAKE_PIN           GPIO_PIN_0

#define MOTOR_SUPPLY_VOLTAGE 11.1f
#define MOTOR_SAFETY_VOLTAGE 10.8f
// #define MOTOR_SAFETY_VOLTAGE 5.0f  // for safe closed-loop testing
#define TIMER_PERIOD 4200

// Encoder counts
extern volatile int32_t enc_count1;
extern volatile int32_t enc_count2;
extern volatile int32_t enc_count3;

// Timer handles for encoders (defined in motor.c)
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim5;

// Pulse count to radians conversion
#define MOTOR_CPR           400      // 100-line Dual-Channel (reading rise and fall of signal therefore 400 counts per revolution)
#define MOTOR_2PI           6.28318530718f

// Initialize PWM for all three motors
void motor_pwm_init(void);
void motor_encoder_init(void);

void EXTI9_5_IRQHandler(void);
void EXTI15_10_IRQHandler(void);

// Get wheel rotation in radians
float motor1_get_velocity(void);
float motor2_get_velocity(void);
float motor3_get_velocity(void);

// Set motor voltages (speed -127 to 127)
void motor_set_speed(int16_t speed1, int16_t speed2, int16_t speed3);

void motor_set_voltage(float voltage1, float voltage2, float voltage3);

// FreeRTOS task to periodically log motor velocities
void motor_velocity_logging_task(void *argument);

#endif // MOTOR_H