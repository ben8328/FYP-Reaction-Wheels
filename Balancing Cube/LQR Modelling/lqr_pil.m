%%% Name: Ben Miller
%%% Student Number: c3328484

close all
clear
clc

%% Non-Linear and linear model parameters

% state vector x = [d_alpha d_beta d_gamma alpha beta d_theta_A d_theta_B d_theta_c]

% output vector like y = [d_gamma alpha beta d_theta_A d_theta_B d_theta_C]

% Define Parameters
params = parameters();

% Simulation Parameters
params.simtime = 10; % In seconds
params.u = [0; 0; 0];

% Initial Conditions of the Controller
params.ic = [0; 0; 0; 5*pi/180; 3*pi/180; 0; 0; 0];
params.xbar = [0; 0; 0; 0; 0; 0; 0; 0];        % Equilibrium Point
params.iclin = params.ic - params.xbar;

% Initial Conditions of the Observer
% params.icobs = [0;0;0;0];


params.ubar = [0; 0; 0];
params.ybar = params.C*params.xbar; % Output 

% Tuning states for smoother responses
q1 = 10;    % Roll rate
q2 = 2;    % Pitch rate
q3 = 1;    % Yaw rate
q4 = 20;   % Roll angle
q5 = 20;   % Pitch angle
q6 = 1;    % Motor A velocity
q7 = 1;    % Motor B velocity
q8 = 1;    % Motor C velocity

% Define an 8x8 Q matrix for state penalization
params.Q = diag([q1, q2, q3, q4, q5, q6, q7, q8]);

% Define the R matrix for input penalization 
params.R = diag([0.4, 1, 1]);  % More penalty on inputs

%% Controller Design
% Compute K (Gain of Controller) and Checks Controlability
[COcheck, params.K] = lqr_design(params.ic, params.A, params.B, params.Q, params.R);

u0 = -params.K * (params.iclin);
disp('Initial Control Input = ');
disp(u0);

%% Simulation of the nonlinear model with STM32 controller

% Create a serialport object at 921600 bps, 3 s timeout
s = serialport("/dev/tty.usbmodem21103", 921600, "Timeout", 3);
configureTerminator(s, "LF");
flush(s);                    % clear buffers

% Set serial update rate fast enough to emulate continuous time
T = 1/250;

lastwarn('');
try
    fopen(s);
    % Send reset/init cmd
    fprintf(s,"ctrl init\n");
    % Clear rx buffer to remove 'Hello World!'
    fscanf(s,"%s\n");
    % Run simulation
    STMsim_nl.results = sim('PIL_lqr_nl');
    
catch me
    fclose(s); delete(s); clear s   % Close serial connection and clean up
    rethrow(me);                     % Pass to higher level error handler
end
fclose(s); delete(s); clear s;       % Close serial connection and clean up

% Note: If the serial object is not cleaned up before opening another connection,
%       Matlab will lose its handle to the previous serial object and lock the
%       port, requiring a session restart to release the resource.

%% Simulation Nonlinear Model
sim_nl.results = sim("lqr_nl");

%% Check if STM inputs do not exceed their maximum values [15V for now seems reasonable]
if abs(max(STMsim_nl.results.u(1))) <= 15 && abs(max(STMsim_nl.results.u(2))) <= 15 && abs(max(STMsim_nl.results.u(3))) <= 15
    disp('Inputs within limits.');
else
    disp('Inputs exceed limits.');
end
% Check if NL inputs do not exceed their maximum values [15V for now seems reasonable]
if abs(max(sim_nl.results.u(1))) <= 15 && abs(max(sim_nl.results.u(2))) <= 15 && abs(max(sim_nl.results.u(3))) <= 15
    disp('Inputs within limits.');
else
    disp('Inputs exceed limits.');
end


%% Plot Results
sim_plot(sim_nl.results, STMsim_nl.results)

