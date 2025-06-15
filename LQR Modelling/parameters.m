%%% Name: Ben Miller
%%% Student Number: c3328484
function [params] = parameters()


%% DC Motor Object Parameters
params.Kt = 0.025/0.7;  % torque constant [Nm/s]    (Compute from Stall torque Value)
params.Ra = 1.0;    % armature resistance [Ohms]    (Approximate)
params.b = 0.1;   % friction constant [Nms]
% Assume no Inductance (L)

% --- Reaction Wheel Geometry (for hollow disk/ring) ---
params.rw_r_outer = 0.085;   % [m] Outer radius (R_outer), measured from center to outer edge
params.rw_r_inner = 0.065;   % [m] Inner radius (R_inner), measured from center to inner edge
rw_thickness    = 0.008;   % [m] Thickness of the wheel (not used in inertia but useful for volume/mass calc)

% --- Reaction Wheel Mass ---
rw_disk_mass = 0.050;      % [kg] Base mass of the disk (measure with scale if possible)
rw_bolt_mass = 0.015*4;    % [kg] Mass contribution from bolts (adjust as needed)
params.rw_m  = rw_disk_mass + rw_bolt_mass;  % [kg] Total reaction wheel mass

% --- Inertia Calculation for Hollow Disk/Ring ---
% I = 0.5 * m * (r_outer^2 + r_inner^2)
params.I_rw = 0.5 * params.rw_m * (params.rw_r_outer^2 + params.rw_r_inner^2);  % [kg·m^2] Inertia of ring

%Old
% params.rw_m = 0.050 + 0.015*8; % Mass of the RW disk;
% params.rw_r = .085;   % Radius of the RW disk
% params.I_rw = 0.5 *params.rw_m*params.rw_r^2;    % inertia of the x-axis reaction wheel [kg.sqm]



%% Cube Object Parameters
params.l = 0.20; % Centroid distance;   (Approximate)
params.m = 1.095 + rw_bolt_mass;                         % (Measured without bolt mass)
params.I_x = params.m*params.l^2;
params.I_y = params.m*params.l^2; 
params.I_z = params.m*params.l^2;

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

% dd_alpha = (p.m*p.g*p.l*sin(alpha)*cos(beta) - (sqrt(6)/6)*(p.Kt/p.Ra)*((2*V_a -V_b - V_c)-p.Kt*(2*d_theta_a - d_theta_b - d_theta_c)))/(p.I_y - p.I_rw);
% dd_beta = (p.m*p.g*p.l*sin(beta)*cos(alpha) - (sqrt(2)/2)*(p.Kt/p.Ra)*((V_b - V_c)-p.Kt*(d_theta_b-d_theta_c)))/(p.I_x - p.I_rw);
% dd_gamma = - ((1/sqrt(3))*(p.Kt/p.Ra)*((V_a + V_b + V_c)-p.Kt*(d_theta_a + d_theta_b + d_theta_c)))/(p.I_z - p.I_rw);
% 
% dd_theta_a = ((p.Kt/p.Ra)*(V_a - p.Kt*d_theta_a))/(p.I_rw);
% dd_theta_b = ((p.Kt/p.Ra)*(V_b - p.Kt*d_theta_b))/(p.I_rw);
% dd_theta_c = ((p.Kt/p.Ra)*(V_c - p.Kt*d_theta_c))/(p.I_rw);

% A matrix
% params.A = [0, 0, 0, params.m*params.g*params.l/(params.I_y - params.I_rw), 0, (sqrt(6)/6)*((params.Kt^2)/params.Ra)*2/(params.I_y - params.I_rw), -(sqrt(6)/6)*((params.Kt^2)/params.Ra)/(params.I_y - params.I_rw),-(sqrt(6)/6)*((params.Kt^2)/params.Ra)/(params.I_y - params.I_rw);
%             0, 0, 0, 0, params.m*params.g*params.l/(params.I_x - params.I_rw), 0, (sqrt(2)/2)*((params.Kt^2)/params.Ra)/(params.I_x - params.I_rw), -(sqrt(2)/2)*((params.Kt^2)/params.Ra)/(params.I_x - params.I_rw);
%             0, 0, 0, 0, 0, (1/sqrt(3))*((params.Kt^2)/params.Ra)/(params.I_z - params.I_rw), (1/sqrt(3))*((params.Kt^2)/params.Ra)/(params.I_z - params.I_rw), (1/sqrt(3))*((params.Kt^2)/params.Ra)/(params.I_z - params.I_rw);
%             1, 0, 0, 0, 0, 0, 0, 0;
%             0, 1, 0, 0, 0, 0, 0, 0;
%             0, 0, 0, 0, 0, -((params.Kt^2)/params.Ra)/(params.I_rw), 0, 0;
%             0, 0, 0, 0, 0, 0, -((params.Kt^2)/params.Ra)/(params.I_rw), 0;
%             0, 0, 0, 0, 0, 0, 0 -((params.Kt^2)/params.Ra)/(params.I_rw)];
% 
% % B matrix
% params.B = [-(sqrt(6)/6)*((params.Kt)/params.Ra)*2/(params.I_y - params.I_rw), (sqrt(6)/6)*((params.Kt)/params.Ra)/(params.I_y - params.I_rw), (sqrt(6)/6)*((params.Kt)/params.Ra)/(params.I_y - params.I_rw);
%             0 -(sqrt(2)/2)*((params.Kt)/params.Ra)/(params.I_x - params.I_rw), (sqrt(2)/2)*((params.Kt)/params.Ra)/(params.I_x - params.I_rw);
%             -(1/sqrt(3))*((params.Kt)/params.Ra)/(params.I_z - params.I_rw), -(1/sqrt(3))*((params.Kt)/params.Ra)/(params.I_z - params.I_rw), -(1/sqrt(3))*((params.Kt)/params.Ra)/(params.I_z - params.I_rw);
%             0, 0, 0;
%             0, 0, 0;
%             ((params.Kt)/params.Ra)/(params.I_rw), 0, 0;
%             0, ((params.Kt)/params.Ra)/(params.I_rw), 0;
%             0, 0, ((params.Kt)/params.Ra)/(params.I_rw)];



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
            -(1/sqrt(3))*((params.Kt)/params.Ra)/(params.I_z - params.I_rw), -(1/sqrt(3))*((params.Kt)/params.Ra)/(params.I_z - params.I_rw), -(1/sqrt(3))*((params.Kt)/params.Ra)/(params.I_z - params.I_rw);
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