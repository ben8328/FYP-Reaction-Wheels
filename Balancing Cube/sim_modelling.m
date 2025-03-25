%%% Name: Ben Miller
%%% Student Number: c3328484

close all
clear
clc

% Declare Parameters
params = parameters();

%% Simulation Parameters

sim.t = 10;

sim.rw_ic = [0 0 0];
sim.cube_ic_vel = [0 0 0];
sim.cube_ic_pos = [0 0 0];  % Check this one

sim.ic_rates = [0; 0; 0; 0; 0; 0];  % [dd_alpha; dd_beta; dd_gamma; dd_theta_a; dd_theta_b; dd_theta_c]
sim.ic_pos = [0; 0; 0; 0; 0; 0];  % [d_alpha; d_beta; d_gamma; d_theta_a; d_theta_b; d_theta_c]


% Voltage input V_A V_B V_C
sim.input_v = [0; 0; 0];


%% Simulation Nonlinear Model
% sim_nl.results = sim('nl_modelling');

%% Simulation Nonlinear Model
% sim_lin.results = sim("lin_modelling");    

aero_title = 'Plot'; % TODO: Add extra states
% aero_plot(sim_nl.results, sim_lin.results)