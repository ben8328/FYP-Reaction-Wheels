clear
clc
close all


%% NOTE:
% These values below are used from example

%% DC Motor Object
motor.Kt = 0.01;  % torque constant [Nm/s]
motor.Ke = 0.01;  % back-EMF constant []
motor.Ra = 1;    % armature resistance [Ohms]
motor.Jrw_x = 01;    % inertia of the x-axis reaction wheel [kg.sqm]
motor.Jrw_y = 01;    % inertia of the y-axis reaction wheel [kg.sqm]
motor.Jrw_z = 01;    % inertia of the z-axis reaction wheel [kg.sqm]
motor.b = 0.1;   % friction [Nms]

% motor.La = 0.5;  % [H]      %% ASSUME NO INDUCTANCE

%% Satellite Object
sat.J1 = 2.5;    % kg.sqm
sat.B = 1.17;    % Nms

sat.I_x = 10;   % kg*m^2
sat.I_y = 10;   % kg*m^2
sat.I_z = 10;    % kg*m^2


%% Transfer Functions
% (https://ctms.engin.umich.edu/CTMS/index.php?example=MotorSpeed&section=SystemModeling)
motor.tf_num = [motor.Kt/motor.Ra];
motor.tf_den = [motor.Jrw_x, motor.b + (motor.Ke*motor.Kt)/motor.Ra];




%% Stability Analysis
% Obtained from Transfer Functions
% M = tf(motor.tf_num, motor.tf_den)
% % S = tf(1, [2.5 1.17 0]);
% 
% % First find Poles
% motor_pole = pole(M)    % Both negative is Stable
% % sat_pole = pole(S)
% 
% % root Locus
% figure()
% rlocus(M)
% % figure()
% % rlocus(S)
% 
% % Bode Plot
% figure()
% margin(M)
% 
% % figure()
% % margin(S)
% 
% % Feedback loop
% figure()
% X_m = feedback(M,1)
% step(X_m)

% figure()
% X_s = feedback(S,1)
% step(X_s)

% NOTE: Slow response time is ok

%% simulation Data
time = 40;

% Desired Input Angles
phi_in = (45)*(pi/180)      % Roll Angle [Rads]
theta_in = (45)*(pi/180)    % Pitch Angle [Rads]
psi_in = (0)*(pi/180)       % Yaw Angle [Rads]
