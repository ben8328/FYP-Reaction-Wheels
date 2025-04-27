%%% Name: Ben Miller
%%% Student Number: c3328484

close all
clear
clc

% Declare Parameters
params = parameters();
%% Simulation Parameters
% state vector x = [d_alpha d_beta d_gamma alpha beta d_theta_A d_theta_B d_theta_c]
% output vector like y = [d_gamma alpha beta d_theta_A d_theta_B d_theta_C]

params.simtime = 20; % In seconds
params.u = [0; 0; 0];

% Initial conditions
params.x0 = [0; 0; 0; 5*pi/180; 3*pi/180; 0; 0; 0];

%% Open Loop Response
% Define SS Object
sys = ss(params.A, params.B, params.C, params.D);

% Check Step Response of Open-loop System
figure()
step(sys)
title('Open-loop Step Response')

%% Simulation Linear Model
% sim_lin.results = sim("pid_lin");
% 
% % Check if inputs do not exceed their maximum values [15V for now seems reasonable]
% if max(sim_lin.results.u(1)) <= 15 && max(sim_lin.results.u(2)) <= 15 && max(sim_lin.results.u(3)) <= 15
%     disp('Inputs within limits.');
% else
%     disp('Inputs exceed limits.');
% end
% 
% sim_plot(sim_nl.results, sim_lin.results)