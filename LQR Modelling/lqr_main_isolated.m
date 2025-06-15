%%% Name: Ben Miller
%%% Student Number: c3328484

close all
clear
clc

% Define Parameters
params = parameters();

% Simulation Parameters
params.simtime = 10; % In seconds
params.u = [0; 0; 0];

% Initial Conditions of the Controller
params.ic = [0; 0; 0; 5*pi/180; 3*pi/180; 0; 0; 0];
params.xbar = [0; 0; 0; 0; 0; 0; 0; 0];        % Equilibrium Point
params.iclin = params.ic - params.xbar;

%% State Space Modeling

% Define state-space system
sys = ss(params.A, params.B, params.C, params.D);

% Define labels for outputs and inputs
output_labels = {'$\dot{\gamma}$', '$\alpha$', '$\beta$', ...
                 '$\dot{\theta}_A$', '$\dot{\theta}_B$', '$\dot{\theta}_C$'};
input_labels = {'Motor A Voltage', 'Motor B Voltage', 'Motor C Voltage'};

% Get step response data
[y, t] = step(sys);

% Dimensions
[numOutputs, numInputs] = size(params.D);

% Plot
figure()
for i = 1:numOutputs
    for j = 1:numInputs
        subplot(numOutputs, numInputs, (i-1)*numInputs + j)
        plot(t, squeeze(y(:, i, j)), 'b', 'LineWidth', 1.2)
        xlabel('Time (s)')
        ylabel(output_labels{i}, 'Interpreter', 'latex')
        title(['Input: ', input_labels{j}], 'Interpreter', 'latex')
        grid on
    end
end

sgtitle('Open-loop Step Response', 'FontWeight', 'bold')

%% Linear Quadratic Regulator (LQR)

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

% state vector x = [d_alpha d_beta d_gamma alpha beta d_theta_A d_theta_B d_theta_c]

% output vector like y = [d_gamma alpha beta d_theta_A d_theta_B d_theta_C]

% Initial conditions
params.iclin = [0; 0; 0; 5*pi/180; 3*pi/180; 0; 0; 0];
params.simtime = 10; % In seconds

% find best cost functions
[Q, R, K] = tuning(params);

% Closed-loop A matrix
Acl = params.A - params.B*K;

% Create closed-loop system
syscl = ss(Acl, params.B, params.C, params.D);

% Step response of Closed-loop System
% Define labels for outputs and inputs
output_labels = {'$\dot{\gamma}$', '$\alpha$', '$\beta$', ...
                 '$\dot{\theta}_A$', '$\dot{\theta}_B$', '$\dot{\theta}_C$'};
input_labels = {'Motor A Voltage', 'Motor B Voltage', 'Motor C Voltage'};

% Get step response data
[y, t] = step(syscl);

% Dimensions
[numOutputs, numInputs] = size(params.D);

% Plot
figure()
for i = 1:numOutputs
    for j = 1:numInputs
        subplot(numOutputs, numInputs, (i-1)*numInputs + j)
        plot(t, squeeze(y(:, i, j)), 'b', 'LineWidth', 1.2)
        xlabel('Time (s)')
        ylabel(output_labels{i}, 'Interpreter', 'latex')
        title(['Input: ', input_labels{j}], 'Interpreter', 'latex')
        grid on
    end
end

sgtitle('Closed-loop Step Response', 'FontWeight', 'bold')

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
