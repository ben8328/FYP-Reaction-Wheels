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
% A matrix
params.A = [0, 0, 0, params.m*params.g*params.l/(params.Iy - params.Iw), 0, sqrt(6)*params.Kt^2/(3*params.Rm*(params.Iy - params.Iw)), -sqrt(6)*params.Kt^2/(3*params.Rm*(params.Iy - params.Iw)), -sqrt(6)*params.Kt^2/(3*params.Rm*(params.Iy - params.Iw));
            0, 0, 0, 0, params.m*params.g*params.l/(params.Ix - params.Iw), 0, sqrt(3)*params.Kt^2/(3*params.Rm*(params.Ix - params.Iw)), -sqrt(3)*params.Kt^2/(3*params.Rm*(params.Ix - params.Iw));
            0, 0, 0, 0, 0, -sqrt(3)*params.Kt^2/(3*params.Rm*(params.Iz - params.Iw)), -sqrt(3)*params.Kt^2/(3*params.Rm*(params.Iz - params.Iw)), -sqrt(3)*params.Kt^2/(3*params.Rm*(params.Iz - params.Iw));
            1, 0, 0, 0, 0, 0, 0, 0;
            0, 1, 0, 0, 0, 0, 0, 0;
            0, 0, 1, 0, 0, -params.Kt^2/(params.Rm*params.Iw), 0, 0;
            0, 0, 0, 0, 0, -params.Kt^2/(params.Rm*params.Iw), -params.Kt^2/(params.Rm*params.Iw), 0;
            0, 0, 0, 0, 0, -params.Kt^2/(params.Rm*params.Iw), 0, -params.Kt^2/(params.Rm*params.Iw)];

% B matrix
params.B = [sqrt(6)*params.Kt/(3*params.Rm*(params.Iy - params.Iw)), sqrt(6)*params.Kt/(6*params.Rm*(params.Iy - params.Iw)), sqrt(6)*params.Kt/(6*params.Rm*(params.Iy - params.Iw));
            0, sqrt(2)*params.Kt/(2*params.Rm*(params.Ix - params.Iw)), sqrt(2)*params.Kt/(2*params.Rm*(params.Ix - params.Iw));
            -sqrt(3)*params.Kt/(3*params.Rm*(params.Iz - params.Iw)), -sqrt(3)*params.Kt/(3*params.Rm*(params.Iz - params.Iw)), -sqrt(3)*params.Kt/(3*params.Rm*(params.Iz - params.Iw));
            0, 0, 0;
            0, 0, 0;
            params.Kt/(params.Rm*params.Iw), 0, 0;
            0, params.Kt/(params.Rm*params.Iw), 0;
            0, 0, params.Kt/(params.Rm*params.Iw)];

% C matrix
params.C = [0, 0, 1, 0, 0, 0, 0, 0;
            0, 0, 0, 1, 0, 0, 0, 0;
            0, 0, 0, 0, 1, 0, 0, 0;
            0, 0, 0, 0, 0, 1, 0, 0;
            0, 0, 0, 0, 0, 0, 1, 0;
            0, 0, 0, 0, 0, 0, 0, 1];

% D matrix
params.D = zeros(6, 3);

end