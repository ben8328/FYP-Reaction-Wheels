%%% Name: Ben Miller
%%% Student Number: c3328484

function [params] = parameters()

%% DC Motor Object Parameters
params.Kt = 0.01;  % torque constant [Nm/s]
params.Ra = 1;    % armature resistance [Ohms]
params.I_rw = 01;    % inertia of the x-axis reaction wheel [kg.sqm]
params.b = 0.1;   % friction constant [Nms]

% Assume no Inductance (L) 

%% Cube Object Parameters
params.I_x = 0.01;
params.I_y = 0.01;
params.I_z = 0.01;
params.l = 0.1; % Centroid distance;
params.m = 1.0;

%% Equilibrium Points
params.xbar = []; % Check "Balancing Cube Dynamics" notes
%% Input Voltages
params.ubar = [0;0;0];

%% General Constants
params.g = 9.81;

%% Define TransfoRation Matrix
R_y = [cos(-35.3*pi/180) 0 sin(-35.3*pi/180); 0 1 0; -sin(-35.3*pi/180) 0 cos(-35.3*pi/180)];
R_x = [1 0 0; 0 cos(45*pi/180) -sin(45*pi/180); 0 sin(45*pi/180) cos(45*pi/180)];

params.T_bf = R_y * R_x;


%% Linearied Matrics 






end