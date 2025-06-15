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

u0 = -params.K * (params.iclin);
disp('Initial Control Input = ');
disp(u0);

% Check if inputs do not exceed their maximum values [Battery supply voltage 11.1V]
if abs(max(u0)) <= 11.1
    disp('Inputs within limits.');
else
    disp('Inputs exceed limits.');
end


%% Simulation of the nonlinear model with controller in STM32

% s = serialport('COM3', 921600, 'Timeout', 0.25); %Windows
s = serialport('/dev/cu.usbmodem21103', 921600, 'Timeout', 0.25);
% s = serialport('/dev/ttyACM0', 115200, 'Timeout', 0.25); %Linux

% Set serial update rate fast enough to emulate continuous time
T = 1/500;

lastwarn('');
try
    % Send init command to initialise/reset the controller
    writeline(s,'ctrl init')
    % Clear rx buffer to remove "Controller has initialised"
    readline(s);
    % Run simulation
    sim_stm.results=sim('PIL_lqr_lin');
    
catch me
    delete(s); clear s   % Close serialport connection and clear variable s
    rethrow(me);         % Pass to higher level error handler
end
delete(s); clear s       % Close serialport connection and clear variable s

% Note: If the serial object is not cleaned up before opening another connection,
%       Matlab will lose its handle to the previous serial object and lock the
%       port, requiring a session restart to release the resource.


%% Simulation Nonlinear Model

% simulate Linear LQR model
sim_lin.results = sim("lqr_lin");


% %% Voltage Input Check
% % Check if inputs do not exceed their maximum values [Battery supply voltage 11.1V]
% if abs(max(sim_stm.results.u(1))) <= 11.1 && abs(max(sim_stm.results.u(2))) <= 11.1 && abs(max(sim_stm.results.u(3))) <= 11.1
%     disp('Inputs within limits.');
% else
%     disp('Inputs exceed limits.');
% end

%% Compare STM results with Linearized Model
% Plot function
stm_plot(sim_lin.results, sim_stm.results)

