#include "data_logging.h"
#include "stm32f4xx_hal.h"
#include "cmsis_os2.h"
#include "uart.h"
#include "IMU.h"
#include "motor.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define LOG_FREQ_HZ 200.0f


uint16_t logCount = 0; // Variable to store the number of samples logged
static osTimerId_t logTimerID; // Timer attributes for data logging
static osTimerAttr_t logTimerAttr = {
    .name = "LogTimer"
}; 

/* Variable declarations*/
static void (*log_function)(void); // Function pointer for logging function

/* Function declarations */
void        logging_init(void);
static void log_pointer(void *argument);
static void log_imu(void);
static void log_encoders(void);




 static void log_pointer(void *argument)
 {
   UNUSED(argument);

   /* Call function pointed to by log_function*/
   (*log_function)();
 }



 void logging_init(void)
 {
    /* TODO: Initialise timer for use with pendulum data logging */
    logTimerID = osTimerNew(log_pointer, osTimerPeriodic, NULL, &logTimerAttr);

    //Error handling
    if (logTimerID == NULL) {
        printf("Error: Timer not created\n");
    }

 }

 void logging_stop(void)
 {
    /* TODO: Stop data logging timer */
        osTimerStop(logTimerID);
 }

 void imu_logging_start(void)
 {
    /* TODO: Change function pointer to the imu logging function (log_imu) */
        log_function = &log_imu;
    

    /* TODO: Reset the log counter */
        logCount = 0;

    /* TODO: Start data logging at 200Hz */
        osTimerStart(logTimerID, 5);  // 5 ms period => 200 Hz
 }

static void log_imu(void)
{
    /* Read IMU data */
    IMU_read();

    /* Compute angles in radians */
    float pitch = get_pitch();
    float roll = get_roll();

    /* Optionally convert to degrees for logging */
    float pitch_deg = pitch * (180.0f / M_PI);
    float roll_deg = roll * (180.0f / M_PI);

    /* Get raw accelerometer and gyroscope values */
    float ax = get_accX();
    float ay = get_accY();
    float az = get_accZ();

    float gx = get_gyroX();
    float gy = get_gyroY();
    float gz = get_gyroZ();

    /* Print time, angles, and sensor values */
    printf("Time: %.3f s, Pitch: %.2f, Roll: %.2f\n", logCount / LOG_FREQ_HZ, pitch_deg, roll_deg);
    printf("Accel [m/s^2] => X: %.2f, Y: %.2f, Z: %.2f\n", ax, ay, az);
    printf("Gyro [rad/s] => X: %.2f, Y: %.2f, Z: %.2f\n", gx, gy, gz);

    logCount++;
    // Log duration: 10000 samples / 200 Hz = 50 seconds
    if (logCount >= 10000)
    {
        logging_stop();
    }
}

void encoder_logging_start(void)
{
    log_function = &log_encoders;
    logCount = 0;
    osTimerStart(logTimerID, 5);  // 5 ms period => 200 Hz
}


static void log_encoders(void)
{
    float v1 = motor1_get_velocity();
    float v2 = motor2_get_velocity();
    float v3 = motor3_get_velocity();

    printf("[ENC] Time: %.3f s, Velocities (rad/s) => M1: %.3f | M2: %.3f | M3: %.3f\n",
       logCount / LOG_FREQ_HZ, v1, v2, v3);

    logCount++;

    // Log duration: 10000 samples / 200 Hz = 50 seconds
    if (logCount >= 10000) 
    {
        logging_stop();
    }
}

 