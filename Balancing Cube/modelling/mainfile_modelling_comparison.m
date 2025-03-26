%%% Name: Ben Miller
%%% Student Number: c3328484

close all;
clear all;
clc

%% Non-Linear and linear model parameters

params = parameters();

% Simulation Parameters
params.ic = [40*pi/180; 90*pi/180; 0; 0];

params.simtime = 50; % In seconds


params.u = [0;0];

params.iclin = params.ic - params.xbar;


%% Simulation Nonlinear Model
sim_nl.results = sim("aero_modelling_nl");

%% Simulation Nonlinear Model
sim_lin.results = sim("aero_modelling_lin");



%% Animation Non-Linear
% aero_animation(params.simtime,sim_nl.results.x(:,1),sim_nl.results.x(:,2))