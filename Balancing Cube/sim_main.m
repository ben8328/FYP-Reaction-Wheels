%%% Name: Ben Miller
%%% Student Number: c3328484

close all
clear
clc

%% Cube Object Parameters
cube.l = 0.075; % Centroid distance;
cube.m = 1.2;

cube.I_x = cube.m*cube.l^2
cube.I_y = cube.m*cube.l^2
cube.I_z = cube.m*cube.l^2


%% DC Motor Object Parameters
motor.Kt = 0.0251;  % torque constant [Nm/s]
motor.Ra = 0.0464;    % armature resistance [Ohms]
motor.I_rw = 0.002;    % inertia of the x-axis reaction wheel [kg.sqm]
motor.b = 0.01;   % friction constant [Nms]

% Assume no Inductance (L) 

%% Define TransfoRation Matrix
R_y = [cos(-35.3*pi/180) 0 sin(-35.3*pi/180); 0 1 0; -sin(-35.3*pi/180) 0 cos(-35.3*pi/180)];
R_x = [1 0 0; 0 cos(45*pi/180) -sin(45*pi/180); 0 sin(45*pi/180) cos(45*pi/180)];

T_bf = R_y * R_x;


%% General Constants
g = 9.81;

%% Input Parameters
% Desired Cube Orientation
in.phi = 0*pi/180;
in.theta = 0*pi/180;
in.psi = 0*pi/180;

%% Simulation Parameters

sim.t = 15;

sim.rw_ic = [0; 0; 0];
sim.cube_ic_vel = [0; 0; 0];

% This is the offset from origin (Balance) This data will come from IMU
sim.cube_ic_pos = [5*pi/180; 0*pi/180; 0];  


