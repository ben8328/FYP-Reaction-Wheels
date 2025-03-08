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

%% Input Parameters
% in.cube = [0 0 0]; % [alpha beta gamma]
% in.rw = [0 0 0]; %  [phi theta psi]A, B, C

% Cube Orientation
in.phi = 45*pi/180;
in.theta = 45*pi/180;
in.psi = 0*pi/180;


%% Simulation Parameters

sim.t = 10;

sim.rw_ic = [0 0 0];
sim.cube_ic_vel = [0 0 0];
sim.cube_ic_pos = [0 0 0];  % Check this one


