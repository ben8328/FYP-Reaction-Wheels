%%% Name: Ben Miller
%%% Student Number: c3328484

close all
clear
clc

% Declare Parameters
params = parameters();


%% State Space Modeling

% Define SS Object
sys = ss(params.A, params.B, params.C, params.D);

% Check Step Response of Open-loop System
figure()
step(sys)
title('Open-loop Step Response')

%% Linear Quadratic Regulator (LQR)

% state vector x = [d_alpha d_beta d_gamma alpha beta d_theta_A d_theta_B d_theta_c]

% output vector like y = [d_gamma alpha beta d_theta_A d_theta_B d_theta_C]

% Initial conditions
x0 = [0; 0; 0; 5*pi/180; 3*pi/180; 0; 0; 0];

% Tuning states for smoother responses
q1 = 1.2;   % Roll rate
q2 = 2;   % Pitch reate
q3 = 2;   % Yaw rate
q4 = 140;   % roll position
q5 = 160;   % pitch postion
q6 = 10;   % Motor A velocity
q7 = 10;   % Motor B velocity
q8 = 10;   % Motor C velocity

% Define an 8x8 Q matrix for state penalization
Q = diag([q1, q2, q3, q4, q5, q6, q7, q8]);

% Define the R matrix for input penalization 
R = diag([0.0001, 0.0001, 0.001]);  % More penalty on inputs

% LQR gain matrix
K = lqr(params.A, params.B, Q, R);

% Closed-loop A matrix
Acl = params.A - params.B*K;

% Create closed-loop system
syscl = ss(Acl, params.B, params.C, params.D);

% Step response of Closed-loop System
figure()
step(syscl)
title('Closed-loop Step Response')

% Run response to initial condition
t = 0:0.01:30;
[y, t, x] = initial(syscl, x0, t);

%% Plot Results for Each State
figure;

% Declare output states
% output vector like y = [d_gamma alpha beta d_theta_A d_theta_B d_theta_C]

state_labels = {'d\alpha (Roll Rate)', 'd\beta (Pitch Rate)', 'd\gamma (Yaw Rate)', '\alpha (Roll Angle)', '\beta (Pitch Angle)','d\theta_A (Motor A Angular Velocity)', 'd\theta_B (Motor B Angular Velocity)', 'd\theta_C (Motor C Angular Velocity)'};

for i = 1:size(x, 2)
    subplot(4, 2, i)
    plot(t, x(:, i)*180/pi, 'LineWidth', 1.5)
    xlabel('Time [s]')
    ylabel(state_labels{i})
    title(['State ' num2str(i) ': ' state_labels{i}])
    grid on
end
sgtitle('State Responses to Initial Conditions')
