%%% Name: Ben Miller
%%% Student Number: c3328484

close all
clear
clc

% Declare Parameters
params = parameters();


%% State Space Modeling

% Initial conditions
x0 = [5*pi/180; 0; 0; 0; 0; 0; 0; 0];

% Define SS Object
sys = ss(params.A, params.B, params.C, params.D);

% Check Step Response of Open-loop System
figure;
step(sys)
title('Open-loop Step Response')

%% Linear Quadratic Regulator (LQR)
% Tuning states
q1 = 10;  % Penalize state 1 more
q2 = 1;   % Penalize state 2 less
q3 = 1;
q4 = 1;
q5 = 1;
q6 = 1;
q7 = 1;
q8 = 1;

% Controller
% Define an 8x8 Q matrix for state penalization
Q = diag([q1, q2, q3, q4, q5, q6, q7, q8]);

% Define the R matrix for input penalization
R = [1 0 0; 0 1 0; 0 0 1];

% LQR gain matrix
K = lqr(params.A, params.B, Q, R);

% Closed-loop A matrix
Acl = params.A - params.B*K;

% Create closed-loop system
syscl = ss(Acl, params.B, params.C, params.D);

% Step response of Closed-loop System
figure;
step(syscl)
title('Closed-loop Step Response')

% Run response to initial condition
t = 0:0.01:10;
[y, t, x] = initial(syscl, x0, t);

%% Plot Results for Each State
figure;
state_labels = {'\alpha (Roll Angle)', '\beta (Pitch Angle)', '\gamma (Yaw Angle)', ...
                '\dot{\theta}_A (Motor A Angular Velocity)', '\dot{\theta}_B (Motor B Angular Velocity)', ...
                '\dot{\theta}_C (Motor C Angular Velocity)', '\theta_A (Motor A Angular Position)', ...
                '\theta_B (Motor B Angular Position)'};

for i = 1:size(x, 2)
    subplot(4, 2, i)
    plot(t, x(:, i)*180/pi, 'LineWidth', 1.5)
    xlabel('Time [s]')
    ylabel(state_labels{i}, 'Interpreter', 'latex')
    title(['State ' num2str(i) ': ' state_labels{i}])
    grid on
end
sgtitle('State Responses to Initial Conditions')
