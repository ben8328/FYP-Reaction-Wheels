%%% Name: Ben Miller
%%% Student Number: c3328484

function sim_plot(sim_nl, sim_lin)

% state vector x = [d_alpha d_beta d_gamma alpha beta d_theta_A d_theta_B d_theta_c]


nl_t = sim_nl.t;
nl_d_alpha = sim_nl.x(:,1);
nl_d_beta = sim_nl.x(:,2);
nl_d_gamma = sim_nl.x(:,3);
nl_alpha = sim_nl.x(:,4);
nl_beta = sim_nl.x(:,5);
nl_d_theta_A = sim_nl.x(:,6);
nl_d_theta_B = sim_nl.x(:,7);
nl_d_theta_C = sim_nl.x(:,8);
nl_Va = sim_nl.u(:,1);
nl_Vb = sim_nl.u(:,2);
nl_Vc = sim_nl.u(:,3);

lin_t = sim_lin.t;
lin_d_alpha = sim_lin.x(:,1);
lin_d_beta = sim_lin.x(:,2);
lin_d_gamma = sim_lin.x(:,3);
lin_alpha = sim_lin.x(:,4);
lin_beta = sim_lin.x(:,5);
lin_d_theta_A = sim_lin.x(:,6);
lin_d_theta_B = sim_lin.x(:,7);
lin_d_theta_C = sim_lin.x(:,8);
lin_Va = sim_lin.u(:,1);
lin_Vb = sim_lin.u(:,2);
lin_Vc = sim_lin.u(:,3);

%% Voltage Inputs
%Compare
figure()

subplot(3,1,1)
plot(nl_t,nl_Va, "b")
hold on 
plot(lin_t,lin_Va, 'r--')
hold off
xlabel('Time [s]')
ylabel('Roll Input Voltage [V]')
legend('$V_A$ Non-Linear', '$V_A$ Linearised', 'Interpreter', 'latex');
grid on

subplot(3,1,2)
plot(nl_t,nl_Vb, "b")
hold on 
plot(lin_t,lin_Vb, 'r--')
hold off
xlabel('Time [s]')
ylabel('Pitch Input Voltage [V]')
legend('$V_B$ Non-Linear', '$V_B$ Linearised', 'Interpreter', 'latex');
grid on

subplot(3,1,3)
plot(nl_t,nl_Vc, "b")
hold on 
plot(lin_t,lin_Vc, 'r--')
hold off
xlabel('Time [s]')
ylabel('Pitch Input Voltage [V]')
legend('$V_C$ Non-Linear', '$V_C$ Linearised', 'Interpreter', 'latex');
grid on

sgtitle('Input Voltages' , 'FontSize', 12);

%% Cube Rates
figure()

subplot(3,1,1)
plot(nl_t,nl_d_alpha*180/pi, "b")
hold on 
plot(lin_t,lin_d_alpha*180/pi, 'r--')
hold off
xlabel('Time [s]')
ylabel('Roll Rate [deg/sec]')
legend({'$\dot \alpha$ Non-Linear', '$\dot \alpha$ Linearised'}, 'Interpreter', 'latex');
grid on
grid minor

subplot(3,1,2)
plot(nl_t,nl_d_beta*180/pi, "b")
hold on 
plot(lin_t,lin_d_beta*180/pi, 'r--')
hold off
xlabel('Time [s]')
ylabel('Pitch Rate [deg/sec]')
legend({'$\dot \beta$ Non-Linear', '$\dot \beta$ Linearised'}, 'Interpreter', 'latex');
grid on
grid minor

subplot(3,1,3)
plot(nl_t,nl_d_gamma*180/pi, "b")
hold on 
plot(lin_t,lin_d_gamma*180/pi, 'r--')
hold off
xlabel('Time [s]')
ylabel('Yaw Rate [deg/sec]')
legend({'$\dot \gamma$ Non-Linear', '$\dot \gamma$ Linearised'}, 'Interpreter', 'latex');
grid on
grid minor

sgtitle('Cube Rates' , 'FontSize', 12);
%% State Outputs

figure()

subplot(3,2,1)
plot(nl_t,nl_d_gamma*180/pi, "b")
hold on 
plot(lin_t,lin_d_gamma*180/pi, 'r--')
hold off
xlabel('Time [s]')
ylabel('Yaw Rate [deg/sec]')
legend({'$\dot \gamma$ Non-Linear', '$\dot \gamma$ Linearised'}, 'Interpreter', 'latex');
grid on
grid minor

subplot(3,2,2)
plot(nl_t,nl_alpha*180/pi, "b")
hold on 
plot(lin_t,lin_alpha*180/pi, 'r--')
hold off
xlabel('Time [s]')
ylabel('Roll Angle [deg]')
legend({'$\alpha$ Non-Linear', '$\alpha$ Linearised'}, 'Interpreter', 'latex');
grid on
grid minor

subplot(3,2,3)
plot(nl_t,nl_beta*180/pi, "b")
hold on 
plot(lin_t,lin_beta*180/pi, 'r--')
hold off
xlabel('Time [s]')
ylabel('Pitch Angle [deg]')
legend({'$\beta$ Non-Linear', '$\beta$ Linearised'}, 'Interpreter', 'latex');
grid on
grid minor

subplot(3,2,4)
plot(nl_t,nl_d_theta_A*180/pi, "b")
hold on 
plot(lin_t,lin_d_theta_A*180/pi, 'r--')
hold off
xlabel('Time [s]')
ylabel('RW_A Rate [deg/sec]')
legend({'$\dot \theta_A$ Non-Linear', '$\dot \theta_A$ Linearised'}, 'Interpreter', 'latex');
grid on
grid minor

subplot(3,2,5)
plot(nl_t,nl_d_theta_B*180/pi, "b")
hold on 
plot(lin_t,lin_d_theta_B*180/pi, 'r--')
hold off
xlabel('Time [s]')
ylabel('RW_B Rate [deg/sec]')
legend({'$\dot \theta_B$ Non-Linear', '$\dot \theta_B$ Linearised'}, 'Interpreter', 'latex');
grid on
grid minor

subplot(3,2,6)
plot(nl_t,nl_d_theta_C*180/pi, "b")
hold on 
plot(lin_t,lin_d_theta_C*180/pi, 'r--')
hold off
xlabel('Time [s]')
ylabel('RW_C Rate [deg/sec]')
legend({'$\dot \theta_C$ Non-Linear', '$\dot \theta_C$ Linearised'}, 'Interpreter', 'latex');
grid on
grid minor

sgtitle('Output Vector' , 'FontSize', 12);
end