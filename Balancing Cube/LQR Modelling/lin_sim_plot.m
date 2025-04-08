%%% Name: Ben Miller
%%% Student Number: c3328484

function sim_plot(sim_lin)

% state vector x = [d_alpha d_beta d_gamma alpha beta d_theta_A d_theta_B d_theta_c]


lin_t = sim_lin.t;
lin_d_alpha = sim_lin.x(:,1);
lin_d_beta = sim_lin.x(:,2);
lin_d_gamma = sim_lin.x(:,3);
lin_alpha = sim_lin.x(:,4);
lin_beta = sim_lin.x(:,1);
lin_d_theta_A = sim_lin.x(:,2);
lin_d_theta_B = sim_lin.x(:,3);
lin_d_theta_C = sim_lin.x(:,4);
lin_Va = sim_lin.u(:,1);
lin_Vb = sim_lin.u(:,2);
lin_Vc = sim_lin.u(:,3);

%% Voltage Inputs
%Compare
figure()

subplot(3,1,1)
hold on 
plot(lin_t,lin_Va, 'b')
hold off
xlabel('Time [s]')
ylabel('Roll Input Voltage [V]')
legend('$V_A$ Linearised', 'Interpreter', 'latex');
grid on

subplot(3,1,2)
hold on 
plot(lin_t,lin_Vb, 'b')
hold off
xlabel('Time [s]')
ylabel('Pitch Input Voltage [V]')
legend('$V_B$ Linearised', 'Interpreter', 'latex');
grid on

subplot(3,1,3)
hold on 
plot(lin_t,lin_Vc, 'b')
hold off
xlabel('Time [s]')
ylabel('Yaw Input Voltage [V]')
legend('$V_C$ Linearised', 'Interpreter', 'latex');
grid on

sgtitle('Input Voltages' , 'FontSize', 12);

%% Cube Rates
figure()

subplot(3,1,1)
hold on 
plot(lin_t,lin_d_alpha*180/pi, 'b')
hold off
xlabel('Time [s]')
ylabel('Roll Rate [deg/sec]')
legend({'$\dot \alpha$ Linearised'}, 'Interpreter', 'latex');
grid on
grid minor

subplot(3,1,2)
hold on 
plot(lin_t,lin_d_beta*180/pi, 'b')
hold off
xlabel('Time [s]')
ylabel('Pitch Rate [deg/sec]')
legend({'$\dot \beta$ Linearised'}, 'Interpreter', 'latex');
grid on
grid minor

subplot(3,1,3)
hold on 
plot(lin_t,lin_d_gamma*180/pi, 'b')
hold off
xlabel('Time [s]')
ylabel('Yaw Rate [deg/sec]')
legend({'$\dot \alpha$ Linearised'}, 'Interpreter', 'latex');
grid on
grid minor

sgtitle('Cube Rates' , 'FontSize', 12);
%% State Outputs

figure()

subplot(3,2,1)
hold on 
plot(lin_t,lin_d_gamma*180/pi, 'b')
hold off
xlabel('Time [s]')
ylabel('Yaw Rate [deg/sec]')
legend({'$\dot \gamma$ Linearised'}, 'Interpreter', 'latex');
grid on
grid minor

subplot(3,2,2)
hold on 
plot(lin_t,lin_alpha*180/pi, 'b')
hold off
xlabel('Time [s]')
ylabel('Roll Angle [deg]')
legend({'$\alpha$ Linearised'}, 'Interpreter', 'latex');
grid on
grid minor

subplot(3,2,3)
hold on 
plot(lin_t,lin_beta*180/pi, 'b')
hold off
xlabel('Time [s]')
ylabel('Pitch Angle [deg]')
legend({'$\beta$ Linearised'}, 'Interpreter', 'latex');
grid on
grid minor

subplot(3,2,4)
hold on 
plot(lin_t,lin_d_theta_A*180/pi, 'b')
hold off
xlabel('Time [s]')
ylabel('RW_A Rate [deg/sec]')
legend({'$\dot \theta_A$ Linearised'}, 'Interpreter', 'latex');
grid on
grid minor

subplot(3,2,5)
hold on 
plot(lin_t,lin_d_theta_B*180/pi, 'b')
hold off
xlabel('Time [s]')
ylabel('RW_B Rate [deg/sec]')
legend({'$\dot \theta_B$ Linearised'}, 'Interpreter', 'latex');
grid on
grid minor

subplot(3,2,6)
hold on 
plot(lin_t,lin_d_theta_C*180/pi, 'b')
hold off
xlabel('Time [s]')
ylabel('RW_C Rate [deg/sec]')
legend({'$\dot \theta_C$ Linearised'}, 'Interpreter', 'latex');
grid on
grid minor

sgtitle('Output Vector' , 'FontSize', 12);
end