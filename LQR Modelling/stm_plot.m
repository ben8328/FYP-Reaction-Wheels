%%% Name: Ben Miller
%%% Student Number: c3328484

function sim_plot(sim_nl, stm_sim)

% state vector x = [d_alpha d_beta d_gamma alpha beta d_theta_A d_theta_B d_theta_c]


lin_t = sim_nl.t;
lin_d_alpha = sim_nl.x(:,1);
lin_d_beta = sim_nl.x(:,2);
lin_d_gamma = sim_nl.x(:,3);
lin_alpha = sim_nl.x(:,4);
lin_beta = sim_nl.x(:,5);
lin_d_theta_A = sim_nl.x(:,6);
lin_d_theta_B = sim_nl.x(:,7);
lin_d_theta_C = sim_nl.x(:,8);
lin_Va = sim_nl.u(:,1);
lin_Vb = sim_nl.u(:,2);
lin_Vc = sim_nl.u(:,3);

lin_t = stm_sim.t;
lin_d_alpha = stm_sim.x(:,1);
lin_d_beta = stm_sim.x(:,2);
lin_d_gamma = stm_sim.x(:,3);
lin_alpha = stm_sim.x(:,4);
lin_beta = stm_sim.x(:,5);
lin_d_theta_A = stm_sim.x(:,6);
lin_d_theta_B = stm_sim.x(:,7);
lin_d_theta_C = stm_sim.x(:,8);
lin_Va = stm_sim.u(:,1);
lin_Vb = stm_sim.u(:,2);
lin_Vc = stm_sim.u(:,3);

%% Voltage Inputs
%Compare
figure()

subplot(3,1,1)
plot(lin_t,lin_Va, "b")
hold on 
plot(lin_t,lin_Va, 'r--')
hold off
xlabel('Time [s]')
ylabel('Roll Input Voltage [V]')
legend('$V_A$ Non-Linear', '$V_A$ STM LIN ', 'Interpreter', 'latex');
grid on

subplot(3,1,2)
plot(lin_t,lin_Vb, "b")
hold on 
plot(lin_t,lin_Vb, 'r--')
hold off
xlabel('Time [s]')
ylabel('Pitch Input Voltage [V]')
legend('$V_B$ Non-Linear', '$V_B$ STM LIN ', 'Interpreter', 'latex');
grid on

subplot(3,1,3)
plot(lin_t,lin_Vc, "b")
hold on 
plot(lin_t,lin_Vc, 'r--')
hold off
xlabel('Time [s]')
ylabel('Yaw Input Voltage [V]')
legend('$V_C$ Non-Linear', '$V_C$ STM LIN ', 'Interpreter', 'latex');
grid on

sgtitle('Input Voltages' , 'FontSize', 12);

%% Cube Rates
figure()

subplot(3,1,1)
plot(lin_t,lin_d_alpha*180/pi, "b")
hold on 
plot(lin_t,lin_d_alpha*180/pi, 'r--')
hold off
xlabel('Time [s]')
ylabel('Roll Rate [deg/sec]')
legend({'$\dot \alpha$ Non-Linear', '$\dot \alpha$ STM LIN '}, 'Interpreter', 'latex');
grid on
grid minor

subplot(3,1,2)
plot(lin_t,lin_d_beta*180/pi, "b")
hold on 
plot(lin_t,lin_d_beta*180/pi, 'r--')
hold off
xlabel('Time [s]')
ylabel('Pitch Rate [deg/sec]')
legend({'$\dot \beta$ Non-Linear', '$\dot \beta$ STM LIN '}, 'Interpreter', 'latex');
grid on
grid minor

subplot(3,1,3)
plot(lin_t,lin_d_gamma*180/pi, "b")
hold on 
plot(lin_t,lin_d_gamma*180/pi, 'r--')
hold off
xlabel('Time [s]')
ylabel('Yaw Rate [deg/sec]')
legend({'$\dot \gamma$ Non-Linear', '$\dot \gamma$ STM LIN '}, 'Interpreter', 'latex');
grid on
grid minor

sgtitle('Cube Rates' , 'FontSize', 12);
%% State Outputs

figure()

subplot(3,2,1)
plot(lin_t,lin_d_gamma*180/pi, "b")
hold on 
plot(lin_t,lin_d_gamma*180/pi, 'r--')
hold off
xlabel('Time [s]')
ylabel('Yaw Rate [deg/sec]')
legend({'$\dot \gamma$ Non-Linear', '$\dot \gamma$ STM LIN '}, 'Interpreter', 'latex');
grid on
grid minor

subplot(3,2,2)
plot(lin_t,lin_alpha*180/pi, "b")
hold on 
plot(lin_t,lin_alpha*180/pi, 'r--')
hold off
xlabel('Time [s]')
ylabel('Roll Angle [deg]')
legend({'$\alpha$ Non-Linear', '$\alpha$ STM LIN '}, 'Interpreter', 'latex');
grid on
grid minor

subplot(3,2,3)
plot(lin_t,lin_beta*180/pi, "b")
hold on 
plot(lin_t,lin_beta*180/pi, 'r--')
hold off
xlabel('Time [s]')
ylabel('Pitch Angle [deg]')
legend({'$\beta$ Non-Linear', '$\beta$ STM LIN '}, 'Interpreter', 'latex');
grid on
grid minor

subplot(3,2,4)
plot(lin_t,lin_d_theta_A*180/pi, "b")
hold on 
plot(lin_t,lin_d_theta_A*180/pi, 'r--')
hold off
xlabel('Time [s]')
ylabel('Motor A Rate [deg/sec]')
legend({'$\dot \theta_A$ Non-Linear', '$\dot \theta_A$ STM LIN '}, 'Interpreter', 'latex');
grid on
grid minor

subplot(3,2,5)
plot(lin_t,lin_d_theta_B*180/pi, "b")
hold on 
plot(lin_t,lin_d_theta_B*180/pi, 'r--')
hold off
xlabel('Time [s]')
ylabel('Motor B Rate [deg/sec]')
legend({'$\dot \theta_B$ Non-Linear', '$\dot \theta_B$ STM LIN '}, 'Interpreter', 'latex');
grid on
grid minor

subplot(3,2,6)
plot(lin_t,lin_d_theta_C*180/pi, "b")
hold on 
plot(lin_t,lin_d_theta_C*180/pi, 'r--')
hold off
xlabel('Time [s]')
ylabel('Motor C Rate [deg/sec]')
legend({'$\dot \theta_C$ Non-Linear', '$\dot \theta_C$ STM LIN '}, 'Interpreter', 'latex');
grid on
grid minor

sgtitle('Output Vector' , 'FontSize', 12);
end