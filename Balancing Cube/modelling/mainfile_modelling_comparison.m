%%% Name: Ben Miller
%%% Student Number: c3328484

close all;
clear all;
clc

%% Non-Linear and linear model parameters

aero_p = aero_parameters();

% Simulation Parameters
aero_p.ic = [40*pi/180; 90*pi/180; 0; 0];

aero_p.simtime = 50; % In seconds


aero_p.u = [0;0];

aero_p.xbar = aero_p.xbar_a;
aero_p.iclin = aero_p.ic - aero_p.xbar;

aero_p.ubar = aero_p.ubar_a;
aero_p.A = aero_p.A_a;
aero_p.B = aero_p.B_a;

%% Simulation Nonlinear Model
sim_nl.results = sim("aero_modelling_nl");

%% Simulation Nonlinear Model
sim_lin.results = sim("aero_modelling_lin");

aero_title = 'Plot';
aero_plot(sim_nl.results, sim_lin.results)


%% Animation Non-Linear
% aero_animation(aero_p.simtime,sim_nl.results.x(:,1),sim_nl.results.x(:,2))