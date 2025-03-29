%%% Name: Ben Miller
%%% Student Number: c3328484

close all
clear
clc

%% DC Motor Object Parameters
motor.Kt = 0.01;  % torque constant [Nm/s]
motor.Ra = 1;    % armature resistance [Ohms]
motor.I_rw = 01;    % inertia of the x-axis reaction wheel [kg.sqm]
motor.b = 0.1;   % friction constant [Nms]

% Assume no Inductance (L) 

%% Cube Object Parameters
cube.I_x = 0.01;
cube.I_y = 0.01;
cube.I_z = 0.01;
cube.l = 0.1; % Centroid distance;
cube.m = 1.0;

%% General Constants
g = 9.81;

%% Define TransfoRation Matrix
R_y = [cos(-35.3*pi/180) 0 sin(-35.3*pi/180); 0 1 0; -sin(-35.3*pi/180) 0 cos(-35.3*pi/180)];
R_x = [1 0 0; 0 cos(45*pi/180) -sin(45*pi/180); 0 sin(45*pi/180) cos(45*pi/180)];

T_bf = R_y * R_x;

%% Simulation Parameters

sim.t = 10;

sim.rw_ic = [0 0 0];
sim.cube_ic_vel = [0 0 0];
sim.cube_ic_pos = [0 0 0];  % Check this one

sim.ic_rates = [0; 0; 0; 0; 0; 0];  % [dd_alpha; dd_beta; dd_gamma; dd_theta_a; dd_theta_b; dd_theta_c]
sim.ic_pos = [0; 0; 0; 0; 0; 0];  % [d_alpha; d_beta; d_gamma; d_theta_a; d_theta_b; d_theta_c]


% Voltage input V_A V_B V_C
sim.input_v = [0; 0; 0];