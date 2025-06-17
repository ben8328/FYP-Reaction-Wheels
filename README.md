# Balancing Cube 
An embedded systems and control project featuring a reaction-wheel-based self-balancing cube. This cube maintains its balance on an edge or corner using three orthogonally mounted reaction wheels. The system implements an LQR controller running on an STM32F446RE microcontroller, with real-time state feedback from an MPU6050 IMU and motor encoders.

## Project Summary
This project demonstrates:

- Full modeling and simulation of a 3D reaction wheel cube using MATLAB/Simulink.
- LQR control law design based on a linearized state-space model.
- Real-time implementation of the controller in C on an STM32 microcontroller.
- Sensor fusion using IMU (MPU6050) and encoders to extract the state vector.
- Closed-loop feedback control of DC motors with reaction wheels.
- Real-time command interface and data logging over serial.

![Cube-final-hardware-int](https://github.com/user-attachments/assets/0ff3d103-3bd4-4a26-85df-27ede13589c4)


The goal is to build an autonomous, real-time feedback-controlled cube that demonstrates the effectiveness of control algorithms typically used in CubeSat Attitude Control Systems.

## Controller Design
- **Controller Type**: Linear Quadratic Regulator (LQR)
- **States**:
  - Angular rates and angles in two axes (pitch and roll)
  - Reaction wheel velocities
- **Inputs**: Motor torques to the 3 reaction wheels
- **State Feedback**: From IMU (angles, rates) and encoders (wheel speeds)
- **Implementation**:
  - Control loop runs at **200 Hz**
  - Executed from `ctrl_task()` in `main.c` using CMSIS-RTOS2

All controller gains (`K` matrix) were computed in MATLAB and hardcoded into `controller.c`.

## System Overview

![Balancing Cube System diagram](https://github.com/user-attachments/assets/95e8e0ee-25dc-4db7-9db3-da34c9f83093)



## Hardware Components
- **Microcontroller**: STM32F446RE (Nucleo board)
- **Sensors**: MPU6050 (I2C1, using `TM_I2C_PinsPack_2`)
- **Actuators**: 3 × DC motors with attached reaction wheels
- **Encoders**: Incremental rotary encoders (A/B phase)
- **Power**: 11.1V 3S LiPo battery (2200 mAh, 50C)
- **Custom PCB**: For clean routing and power distribution

## Getting Started

### Prerequisites
- VSCode with `Cortex-Debug`, `Arm Toolchain`, and `CMSIS` packs
- ST-Link USB driver
- Serial terminal (e.g., CoolTerm)
- GNU Make or CMake if using CLI build

### Setup

1. **Clone this repository**:
   `git clone https://github.com/ben8328/balancing_cube.git`

2.	Build the project:
Open with VSCode, select the appropriate build task (build), and flash using ST-Link or USB.

3.	Connect hardware:
- MPU6050 via I2C1
-	Motors via PWM + DIR GPIO
-	Encoders to interrupt-capable pins

## Command Parser 
- Use serial commands to test hardware setup:
<img width="450" alt="image" src="https://github.com/user-attachments/assets/d2cc02c8-77d6-4433-9ebc-d662990f4a40" />




##  Simulation & Validation
Before deploying to hardware, a full nonlinear Simulink model was used to validate the LQR control law under various initial conditions.
-	Compare nonlinear_model.slx vs. controller output from STM32.
-	Initial condition: `params.ic = [0; 0; 0; alpha0; beta0; 0; 0; 0]`
-	Logged output vectors: `[d_gamma, alpha, beta, d_theta_A, d_theta_B, d_theta_C]`

This allowed tuning of the K matrix prior to hardcoding into `controller.c`.
