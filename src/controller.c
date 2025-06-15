#include <stddef.h>
#include "controller.h"
#include "stm32f4xx_hal.h"

// Number of states and outputs (3 inputs)
#ifndef CTRL_N_STATE
#define CTRL_N_STATE 8
#endif
#ifndef CTRL_N_INPUT
#define CTRL_N_INPUT 3
#endif

static float _ctrl_state[CTRL_N_STATE];
static float _ctrl_output[CTRL_N_OUTPUT];

/* Continuous LQR gain matrix K (3 inputs × 8 states) */
static const float K[CTRL_N_INPUT][CTRL_N_STATE] = {
    // Voltage Input 1 gains
    { -52.2989f,  -0.0000f,  -0.1826f, -368.8009f,  -0.0000f,  -0.1429f,   0.2110f,  0.2110f },
    // Voltage Input 2 gains
    {  26.1495f, -45.2922f,  -0.1826f,  184.4005f, -319.3910f,  0.2110f,  -0.1429f,  0.2110f },
    // Voltage Input 3 gains
    {  26.1495f,  45.2922f,  -0.1826f,  184.4005f,  319.3910f,  0.2110f,   0.2110f, -0.1429f }
};

void ctrl_init(void)
{
    for (size_t i = 0; i < CTRL_N_STATE; ++i) {
        _ctrl_state[i] = 0.0f;
    }
}
    
void ctrl_set_state(const float state[CTRL_N_STATE])
{
    for (size_t i = 0; i < CTRL_N_STATE; ++i) {
        _ctrl_state[i] = state[i];
    }
}

// update state vector elements
void ctrl_set_x1(const float x1) { _ctrl_state[0] = x1; }       // d_alpha
void ctrl_set_x2(const float x2) { _ctrl_state[1] = x2; }       // d_beta
void ctrl_set_x3(const float x3) { _ctrl_state[2] = x3; }       // d_gamma
void ctrl_set_x4(const float x4) { _ctrl_state[3] = x4; }       // alpha
void ctrl_set_x5(const float x5) { _ctrl_state[4] = x5; }       // beta
void ctrl_set_x6(const float x6) { _ctrl_state[5] = x6; }       // d_theta_a
void ctrl_set_x7(const float x7) { _ctrl_state[6] = x7; }       // d_theta_b
void ctrl_set_x8(const float x8) { _ctrl_state[7] = x8; }       // d_theta_c

float * ctrl_get_state(void)
{
    return _ctrl_state;
}

float * ctrl_run(void)
{
    // Manually expanded control outputs u = -K * x
    _ctrl_output[0] = (
        K[0][0]*_ctrl_state[0] + K[0][1]*_ctrl_state[1] + K[0][2]*_ctrl_state[2] + K[0][3]*_ctrl_state[3] +
        K[0][4]*_ctrl_state[4] + K[0][5]*_ctrl_state[5] + K[0][6]*_ctrl_state[6] + K[0][7]*_ctrl_state[7]
    );

    _ctrl_output[1] = (
        K[1][0]*_ctrl_state[0] + K[1][1]*_ctrl_state[1] + K[1][2]*_ctrl_state[2] + K[1][3]*_ctrl_state[3] +
        K[1][4]*_ctrl_state[4] + K[1][5]*_ctrl_state[5] + K[1][6]*_ctrl_state[6] + K[1][7]*_ctrl_state[7]
    );

    _ctrl_output[2] = (
        K[2][0]*_ctrl_state[0] + K[2][1]*_ctrl_state[1] + K[2][2]*_ctrl_state[2] + K[2][3]*_ctrl_state[3] +
        K[2][4]*_ctrl_state[4] + K[2][5]*_ctrl_state[5] + K[2][6]*_ctrl_state[6] + K[2][7]*_ctrl_state[7]
    );

    return _ctrl_output;
}
