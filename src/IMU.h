#ifndef IMU_H
#define IMU_H

#include <stdint.h>

void IMU_init(void);
void IMU_read(void);
float get_accX(void);
float get_accY(void);
float get_accZ(void);
float get_gyroX(void);
float get_gyroY(void);
float get_gyroZ(void);
float get_pitch(void);
float get_roll(void);
void IMU_calibrate(void);

#endif