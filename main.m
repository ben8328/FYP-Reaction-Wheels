clear
clc
close all


%% NOTE:
% These values below are used from example

%% DC Motor Object
motor.K = 0.01;  % Nm/s
motor.Ra = 1;    % Ohms
motor.La = 0.5;  % H
motor.J = 01;    % kg.sqm
motor.b = 0.1;   % Nms

%% Satellite Object
sat.J1 = 2.5;    % kg.sqm
sat.B = 1.17;    % Nms

% %% Transfer Functions
% motor.tf_num = K;
% motor.tf_den = (J * s + b) * (Ra + La *s) + K^2;
% 
% sat.tf_num = 1;
% sat.tf_den = J * s^2 + B * s;

%% Stability Analysis
% Obtained from Transfer Functions
M = tf(10, [50 60 1001]);
S = tf(1, [2.5 1.17 0]);

% First find Poles
motor_pole = pole(M)    % Both negative is Stable
sat_pole = pole(S)

% root Locus
figure()
rlocus(M)
figure()
rlocus(S)

% Bode Plot
figure()
margin(M)

figure()
margin(S)

% Feedback loop
figure()
X_m = feedback(M,1)
step(X_m)

figure()
X_s = feedback(S,1)
step(X_s)

% Slow response time is ok
