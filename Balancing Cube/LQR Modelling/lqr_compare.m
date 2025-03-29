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
params.simtime = 30; % In seconds
params.u = 0;

% Initial Conditions of the Controller
params.ic = [0; 0; 0; 5*pi/180; 3*pi/180; 0; 0; 0];
params.xbar = [0; 0; 0; 0; 0; 0; 0; 0];        % Equilibrium Point
params.iclin = params.ic - params.xbar;

% Initial Conditions of the Observer
% params.icobs = [0;0;0;0];


params.ubar = [0; 0; 0];
params.ybar = params.C*params.xbar; % Output 

% Tuning states for smoother responses
q1 = 500;   % Penalize state 1 less for smoother roll rate
q2 = 0;   % Penalize state 2 less for smoother pitch reate
q3 = 0;   % Penalize state 3 less for smoother yaw rate
q4 = 0;   % roll position
q5 = 0;   % pitch postion
q6 = 2;   % Motor A velocity
q7 = 0;   % Motor B velocity
q8 = 0;   % Motor C velocity

% Define an 8x8 Q matrix for state penalization
params.Q = diag([q1, q2, q3, q4, q5, q6, q7, q8]);

% Define the R matrix for input penalization 
params.R = [0.01 0 0; 0 0.1 0; 0 0 0.1];  % More penalty on inputs

%% Controller Design
% Compute K (Gain of Controller) and Checks Controlability
[COcheck, params.K] = lqr_design(params.ic, params.A, params.B, params.Q, params.R);
%% Observer Design
% % Select eigenvalues for Observer
% params.obs_eig = [-10, -11, -12, -13];
% % Compute L (Gain of Observer) and Checks Observability
% [params.OBcheck,params.L] = aero_obs_design(params.A,params.C,params.obs_eig);

%% Simulation Nonlinear Model
sim_nl.results = sim("lqr_nl");

%% Simulation Nonlinear Model
sim_lin.results = sim("lqr_lin");

% Check if inputs do not exceed their maximum values [15V for now seems reasonable]
if max(sim_lin.results.u(1)) <= 15 && max(sim_lin.results.u(2)) <= 15 && max(sim_lin.results.u(3)) <= 15
    disp('Inputs within limits.');
else
    disp('Inputs exceed limits.');
end

sim_plot(sim_nl.results, sim_lin.results)

