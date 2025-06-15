#include "tm_stm32_mpu6050.h"
#include <math.h>
#include "IMU.h"
#include <stdint.h>
#include <stdlib.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/* Variable declarations */
TM_MPU6050_t IMU_datastruct;

// Use calibrateIMU to get the calibration offsets and enter here
static float offset_ax = -72.60f, offset_ay = -56.74f, offset_az = 7.30f;
static float offset_gx = -314.94f, offset_gy = 207.81f, offset_gz = -260.99f;

/* Function defintions */
void IMU_init(void)
{
    /* TODO: Initialise IMU with AD0 LOW, accelleration sensitivity +-4g, gyroscope +-250 deg/s */
    TM_MPU6050_Result_t result = TM_MPU6050_Init(&IMU_datastruct, TM_MPU6050_Device_0, TM_MPU6050_Accelerometer_4G, TM_MPU6050_Gyroscope_250s);



    if (result == TM_MPU6050_Result_Ok) {
        printf("IMU initialized successfully.\n");
    } 
    else if (result == TM_MPU6050_Result_DeviceNotConnected) {
        printf("Error: MPU6050 not connected.\n");
    } 
    else {
        printf("Error: MPU6050 initialization failed with unknown error.\n");
    }
}

void IMU_read(void)
{
    /* TODO: Read all IMU values */
    TM_MPU6050_ReadAll(&IMU_datastruct);
}

float get_accX(void)
{
    /* Convert raw accelerometer Z reading to g (4g sensitivity -> 1g = 8192) */
    float accX_ms2 = (IMU_datastruct.Accelerometer_X - offset_ax) * 9.81 / 8192;

    /* Return the Z acceleration in m/s^2 */
    return accX_ms2;
}

float get_accY(void)
{
    /* TODO: Convert accelleration reading to ms^-2 */
    /* Convert raw accelerometer reading to g */
    float accY_ms2 = (IMU_datastruct.Accelerometer_Y - offset_ay) * 9.81 / 8192;  // For 4g -> 1g = 8192 (32768/4) (Scaled)

    /* TODO: return the Y acceleration */
    return accY_ms2;
}

float get_accZ(void)
{
    /* Convert raw accelerometer Z reading to g (4g sensitivity -> 1g = 8192) */
    float accZ_ms2 = (IMU_datastruct.Accelerometer_Z - offset_az) * 9.81 / 8192;

    /* Return the Z acceleration in m/s^2 */
    return accZ_ms2;
}

// d_beta state (Pitch Rate)
float get_gyroX(void)
{
    /* Convert degrees per second to radians per second */
    float gyroX_rads = ((IMU_datastruct.Gyroscope_X - offset_gx) * (M_PI / 180)) / 131.072; // For 250 sensetivity -> 1rad = 131.072 (32768/250) (Scaled)

    /* Return the X angular velocity in radians per second */
    return gyroX_rads;
}

// d_alpha (Roll Rate)
float get_gyroY(void)
{
    /* Convert degrees per second to radians per second */
    float gyroY_rads = ((IMU_datastruct.Gyroscope_Y - offset_gy) * (M_PI / 180)) / 131.072; // For 250 sensetivity -> 1rad = 131.072 (32768/250) (Scaled)

    /* Return the y angular velocity in radians per second */
    return gyroY_rads;
}

// d_gamma state (Yaw Rate)
float get_gyroZ(void)
{
    /* Convert degrees per second to radians per second */
    float gyroZ_rads = ((IMU_datastruct.Gyroscope_Z - offset_gz) * (M_PI / 180)) / 131.072; // For 250 sensetivity -> 1rad = 131.072 (32768/250) (Scaled)

    /* Return the Z angular velocity in radians per second */

    printf("Raw Accel [raw] => X: %.2d, Y: %.2d, Z: %.2d\n",
    IMU_datastruct.Accelerometer_X,
    IMU_datastruct.Accelerometer_Y,
    IMU_datastruct.Accelerometer_Z);

    return gyroZ_rads;
}

// alpha state (Roll Angle) (about y-axis)
float get_roll(void) {
    float ax = get_accX();
    float ay = get_accY();
    float az = get_accZ();
    // Roll is about y-axis: use ax for numerator
    return atan2f(-ax, sqrtf(ay * ay + az * az));
}

// beta state (Pitch Angle) (about x-axis)
float get_pitch(void) {
    float ax = get_accX();
    float ay = get_accY();
    float az = get_accZ();
    // Pitch is about x-axis: use ay for numerator
    return -atan2f(ay, sqrtf(ax * ax + az * az));
}



void IMU_calibrate(void) {
    // Average N samples for better noise rejection
    const int samples = 100;
    float sum_ax = 0, sum_ay = 0, sum_az = 0;
    float sum_gx = 0, sum_gy = 0, sum_gz = 0;

    for (int i = 0; i < samples; ++i) {
        IMU_read();
        sum_ax += IMU_datastruct.Accelerometer_X;
        sum_ay += IMU_datastruct.Accelerometer_Y;
        sum_az += IMU_datastruct.Accelerometer_Z;
        sum_gx += IMU_datastruct.Gyroscope_X;
        sum_gy += IMU_datastruct.Gyroscope_Y;
        sum_gz += IMU_datastruct.Gyroscope_Z;
        HAL_Delay(10);
    }

    float avg_ax = sum_ax / samples;
    float avg_ay = sum_ay / samples;
    float avg_az = sum_az / samples;
    float avg_gx = sum_gx / samples;
    float avg_gy = sum_gy / samples;
    float avg_gz = sum_gz / samples;

    // Use *measured* expected gravity values for this orientation!
    float expected_ax = 6774.0f;
    float expected_ay = -156.0f;
    float expected_az = 5360.0f;

    offset_ax = avg_ax - expected_ax;
    offset_ay = avg_ay - expected_ay;
    offset_az = avg_az - expected_az;

    // Gyro offsets
    offset_gx = avg_gx;
    offset_gy = avg_gy;
    offset_gz = avg_gz;

    printf("IMU calibration complete (M1 face, custom expected raw values).\n");
    printf("Accelerometer Offsets -> ax: %.2f, ay: %.2f, az: %.2f\n", offset_ax, offset_ay, offset_az);
    printf("Gyroscope Offsets -> gx: %.2f, gy: %.2f, gz: %.2f\n", offset_gx, offset_gy, offset_gz);
    printf("Expected gravity [raw]: ax=%.2f, ay=%.2f, az=%.2f\n", expected_ax, expected_ay, expected_az);
}