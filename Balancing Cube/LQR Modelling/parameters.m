%%% Name: Ben Miller
%%% Student Number: c3328484
function [params] = parameters()


%% DC Motor Object Parameters
params.Kt = 0.01;  % torque constant [Nm/s]
params.Ra = 1;    % armature resistance [Ohms]
params.rw_m = 0.500; % Mass of the RW disk;
params.rw_r = .2;   % Radius of the RW disk
params.I_rw = 0.5 *params.rw_m*params.rw_r^2;    % inertia of the x-axis reaction wheel [kg.sqm]
params.b = 0.1;   % friction constant [Nms]

% Assume no Inductance (L) 

%% Cube Object Parameters
params.I_x = 0.05;
params.I_y = 0.05;
params.I_z = 0.05;
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

% state vector x = [d_alpha d_beta d_gamma alpha beta d_theta_A d_theta_B d_theta_c]

% output vector like y = [d_gamma alpha beta d_theta_A d_theta_B d_theta_C]

% A matrix
params.A = [0, 0, 0, params.m*params.g*params.l/(params.I_y - params.I_rw), 0, (sqrt(6)/3)*(params.Kt^2/params.Ra)*(1/(params.I_y - params.I_rw)), -(sqrt(6)/6)*(params.Kt^2/params.Ra)*(1/(params.I_y - params.I_rw)), -(sqrt(6)/6)*(params.Kt^2/params.Ra)*(1/(params.I_y - params.I_rw));
            0, 0, 0, 0, params.m*params.g*params.l/(params.I_x - params.I_rw), 0, sqrt(2)*params.Kt^2/(2*params.Ra*(params.I_x - params.I_rw)), -sqrt(2)*params.Kt^2/(2*params.Ra*(params.I_x - params.I_rw));
            0, 0, 0, 0, 0, -params.Kt^2/(sqrt(3)*params.Ra*(params.I_z - params.I_rw)), -params.Kt^2/(sqrt(3)*params.Ra*(params.I_z - params.I_rw)), -params.Kt^2/(sqrt(3)*params.Ra*(params.I_z - params.I_rw));
            1, 0, 0, 0, 0, 0, 0, 0;
            0, 1, 0, 0, 0, 0, 0, 0;
            0, 0, 0, 0, 0, -params.Kt^2/(params.Ra*params.I_rw), 0, 0;
            0, 0, 0, 0, 0, 0, -params.Kt^2/(params.Ra*params.I_rw), 0;
            0, 0, 0, 0, 0, 0, 0, -params.Kt^2/(params.Ra*params.I_rw)];

% B matrix
params.B = [-sqrt(6)*params.Kt/(3*params.Ra*(params.I_y - params.I_rw)), sqrt(6)*params.Kt/(6*params.Ra*(params.I_y - params.I_rw)), sqrt(6)*params.Kt/(6*params.Ra*(params.I_y - params.I_rw));
            0, -sqrt(2)*params.Kt/(2*params.Ra*(params.I_x - params.I_rw)), sqrt(2)*params.Kt/(2*params.Ra*(params.I_x - params.I_rw));
            -params.Kt/(sqrt(3)*params.Ra*(params.I_z - params.I_rw)), -params.Kt/(sqrt(3)*params.Ra*(params.I_z - params.I_rw)), -sqrt(3)*params.Kt/(3*params.Ra*(params.I_z - params.I_rw));
            0, 0, 0;
            0, 0, 0;
            params.Kt/(params.Ra*params.I_rw), 0, 0;
            0, params.Kt/(params.Ra*params.I_rw), 0;
            0, 0, params.Kt/(params.Ra*params.I_rw)];

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