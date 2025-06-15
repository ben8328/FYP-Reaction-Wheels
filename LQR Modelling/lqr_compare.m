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
params.ic = [0; 0; 0; 7*pi/180; 5*pi/180; 0; 0; 0];
params.xbar = [0; 0; 0; 0; 0; 0; 0; 0];        % Equilibrium Point
params.iclin = params.ic - params.xbar;

% Initial Conditions of the Observer
% params.icobs = [0;0;0;0];

params.ubar = [0; 0; 0];
params.ybar = params.C*params.xbar; % Output 

% Compute Controlability
C_AB = ctrb(params.A, params.B);

% check rank of matrix
if rank(C_AB) == length(params.iclin)
   COcheck = 1; % Controllable
   disp("System is Controllable")
else
   COcheck = 0; % Not Controllable
   disp("Rank:")
   disp(rank(C_AB))
   error("System is not Controllable [check states] Check A and B matrices.");
end

% find best cost functions
[params.Q, params.R, params.K] = tuning(params);

%% Controller Design
% Compute K (Gain of Controller) and Checks Controlability
% [COcheck, params.K] = lqr_design(params.iclin, params.A, params.B, params.Q, params.R);

% Control Matrix K
disp('Controller Matrix K: ');
disp(params.K);

% u0 = -params.K * (params.iclin);
% disp('Initial Control Input = ');
% disp(u0);
% 
% % Check if inputs do not exceed their maximum values [Battery supply voltage 11.1V]
% if abs(max(u0)) <= 11.1
%     disp('Inputs within limits.');
% else
%     disp('Inputs exceed limits.');
% end


%% Simulation Nonlinear Model

%TODO: This is wrong because it uses LIN K parameter
sim_nl.results = sim("lqr_nl");

%% Simulation Nonlinear Model
sim_lin.results = sim("lqr_lin");

% % Check if inputs do not exceed their maximum values [Battery supply voltage 11.1V]
% if abs(max(sim_lin.results.u(1))) <= 11.1 && abs(max(sim_lin.results.u(2))) <= 11.1 && abs(max(sim_lin.results.u(3))) <= 11.1
%     disp('Inputs within limits.');
% else
%     disp('Inputs exceed limits.');
% end

sim_plot(sim_nl.results, sim_lin.results)

