#ifndef CONTROLLER_H
#define CONTROLLER_H

// Number of controller states (8) and outputs (3 inputs)
enum {
    CTRL_N_STATE  = 8,
    CTRL_N_OUTPUT = 3,
};

//Initialize the controller state to zero.
void    ctrl_init(void);

/* 
    Set all 8 state variables at once.
    state  Array of 8 floats representing current state.
*/ 
void    ctrl_set_state(const float state[CTRL_N_STATE]);

// Individual setters for each state variable
void    ctrl_set_x1(const float x1);
void    ctrl_set_x2(const float x2);
void    ctrl_set_x3(const float x3);
void    ctrl_set_x4(const float x4);
void    ctrl_set_x5(const float x5);
void    ctrl_set_x6(const float x6);
void    ctrl_set_x7(const float x7);
void    ctrl_set_x8(const float x8);

/*
    Retrieve a pointer to the internal state array.
    Pointer to float array of length CTRL_N_STATE.
*/
float * ctrl_get_state(void);

/*
    Compute the control outputs using LQR gains.
    Pointer to float array of length CTRL_N_OUTPUT (3 inputs).
*/
float * ctrl_run(void);

#endif
