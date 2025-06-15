#include "control_task.h"
#include "controller.h"
#include "motor.h"
#include "IMU.h"
#include "cmsis_os2.h"
#include <stdio.h>

#define CONTROL_TASK_PRIORITY osPriorityNormal
#define CONTROL_TASK_STACK_SIZE 512
#define CONTROL_TASK_PERIOD_MS 2   // 500 Hz

static void control_task_loop(void *argument);

void control_task_init(void) {
    osThreadNew(control_task_loop, NULL, 
                &(osThreadAttr_t){
                    .name = "ControlTask",
                    .priority = CONTROL_TASK_PRIORITY,
                    .stack_size = CONTROL_TASK_STACK_SIZE
                });
}

static void control_task_loop(void *argument) {
    (void)argument;
    // USER button on PC13, usually pulled up, pressed = LOW
    printf("Waiting for USER button press to start control loop...\n");
    // Configure GPIOC clock if not already done
    __HAL_RCC_GPIOC_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GPIO_PIN_13;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    // Wait for button press (active low)
    while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) != GPIO_PIN_RESET) {
        osDelay(10); // check every 10ms
    }
    printf("USER button pressed! Starting control loop...\n");

    // Optional: Wait for button release to avoid retriggering
    while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET) {
        osDelay(10);
    }

    uint32_t tick_start = osKernelGetTickCount();

    while (1) {
        float state[8];

        // 1- Read IMU angles and rates
        IMU_read();  // ensure data is up-to-date
        // --- Get accelerometer and gyro readings for debug ---
        float ax = get_accX();
        float ay = get_accY();
        float az = get_accZ();
        float gx = get_gyroX();
        float gy = get_gyroY();
        float gz = get_gyroZ();
        float alpha = get_pitch();
        float beta = get_roll();

        // --- Debug: Print raw IMU orientation and rates ---
        printf("Accel [m/s^2] => X: %.2f, Y: %.2f, Z: %.2f\n", ax, ay, az);
        printf("Gyro [rad/s] => X: %.2f, Y: %.2f, Z: %.2f\n", gx, gy, gz);

        // Assign state vector as normal (now using the same values, already computed above)
        state[0] = gy;      // d_alpha (roll rate)
        state[1] = gx;      // d_beta  (pitch rate)
        state[2] = gz;      // d_gamma (yaw rate)
        state[3] = alpha;   // alpha
        state[4] = beta;    // beta

        printf("Pitch: %.2f, Roll: %.2f\n", alpha, beta);


        // 2- Get motor angular velocities
        state[5] = motor1_get_velocity();  // d_theta_a
        state[6] = motor2_get_velocity();  // d_theta_b
        state[7] = motor3_get_velocity();  // d_theta_c

        // 3. Update controller state
        ctrl_set_state(state);

        // 4- Compute control input
        float* u = ctrl_run();

        // Debug: Print state vector and control input voltages
        printf("[CTRL] state = [");
        for (int i = 0; i < 8; ++i) {
            printf("% .3f%s", state[i], (i < 7) ? ", " : "");
        }
        printf("]\n");
        printf("[CTRL] u = [% .3f, % .3f, % .3f]\n", u[0], u[1], u[2]);

        // 5- Apply control voltages
        motor_set_voltage(u[0], u[1], u[2]);   // COMMENTED OUT for debugging

        // 6- Delay until next tick
        osDelayUntil(tick_start += CONTROL_TASK_PERIOD_MS);
    }
}