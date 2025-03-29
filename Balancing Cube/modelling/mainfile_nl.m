%%% Name: Ben Miller
%%% Student Number: c3328484

close all;
clear all;
clc

%% Non-Linear and linear model parameters

params = parameters();



% Simulation Parameters
params.ic_rates = [0; 0; 0; 0; 0; 0];  % [dd_alpha; dd_beta; dd_gamma; dd_theta_a; dd_theta_b; dd_theta_c]
params.ic_vel = [5*pi/180; 0; 0; 0; 0; 0];  % [d_alpha; d_beta; d_gamma; d_theta_a; d_theta_b; d_theta_c]

% Voltage input V_A V_B V_C
params.u = [0; 0; 0];

sim_nl.t = 10;    % In Seconds

%% Simulation Nonlinear Model
sim_nl.results = sim("modelling_nl");

%% Plot Results

% Extract Data
nl_t = sim_nl.results.t;
nl_x1 = sim_nl.results.x(:,1);
nl_x2 = sim_nl.results.x(:,2);
nl_x3 = sim_nl.results.x(:,3);
nl_x4 = sim_nl.results.x(:,4);
nl_x5 = sim_nl.results.x(:,5);
nl_x6 = sim_nl.results.x(:,6);

nl_va = sim_nl.results.u(:,1);
nl_vb = sim_nl.results.u(:,2);
nl_vc = sim_nl.results.u(:,3);

figure(1)

subplot(3,1,1)
plot(nl_t,nl_x1*180/pi, "b")
hold on 
% plot(lin_t,lin_x1*180/pi, 'r--')
hold off
xlabel('Time [s]')
ylabel('\alpha Angle [deg]')
legend({'$\alpha$ Non-Linear'}, 'Interpreter', 'latex');
grid on
grid minor

subplot(3,1,2)
plot(nl_t,nl_x2*180/pi, "b")
hold on 
% plot(lin_t,lin_x1*180/pi, 'r--')
hold off
xlabel('Time [s]')
ylabel('\beta Angle [deg]')
legend({'$\beta$ Non-Linear'}, 'Interpreter', 'latex');
grid on
grid minor

subplot(3,1,3)
plot(nl_t,nl_x3*180/pi, "b")
hold on 
% plot(lin_t,lin_x1*180/pi, 'r--')
hold off
xlabel('Time [s]')
ylabel('\gamma Angle [deg]')
legend({'$\gamma$ Non-Linear'}, 'Interpreter', 'latex');
grid on
grid minor