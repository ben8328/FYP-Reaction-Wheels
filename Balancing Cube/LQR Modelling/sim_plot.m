%%% Name: Ben Miller
%%% Student Number: c3328484

function sim_plot(sim_nl, sim_lin)

% state vector x = [d_alpha d_beta d_gamma alpha beta d_theta_A d_theta_B d_theta_c]


nl_t = sim_nl.t;
nl_d_alpha = sim_nl.x(:,1);
nl_d_beta = sim_nl.x(:,2);
nl_d_gamma = sim_nl.x(:,3);
nl_alpha = sim_nl.x(:,4);
nl_beta = sim_nl.x(:,1);
nl_d_theta_A = sim_nl.x(:,2);
nl_d_theta_B = sim_nl.x(:,3);
nl_d_theta_c = sim_nl.x(:,4);
nl_Va = sim_nl.u(:,1);
nl_Vb = sim_nl.u(:,2);
nl_Vc = sim_nl.u(:,3);

lin_t = sim_lin.t;
lin_d_alpha = sim_lin.x(:,1);
lin_d_beta = sim_lin.x(:,2);
lin_d_gamma = sim_lin.x(:,3);
lin_alpha = sim_lin.x(:,4);
lin_beta = sim_lin.x(:,1);
lin_d_theta_A = sim_lin.x(:,2);
lin_d_theta_B = sim_lin.x(:,3);
lin_d_theta_c = sim_lin.x(:,4);
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

% States

subplot(5,1,2)
plot(nl_t,nl_x2*180/pi, "b")
hold on 
plot(lin_t,lin_x2*180/pi, 'r--')
hold off
xlabel('Time [s]')
ylabel('Yaw Angle [deg]')
legend({'$x_2$ Non-Linear', '$x_2$ Linearised'}, 'Interpreter', 'latex');
% ylim([-60 120])
% xlim([0 14])
grid on
grid minor

subplot(5,1,3)
plot(nl_t,nl_x3*180/pi, "b")
hold on 
plot(lin_t,lin_x3*180/pi, 'r--')
hold off
xlabel('Time [s]')
ylabel('Pitch Rate [deg/s]')
legend({'$x_3$ Non-Linear', '$x_3$ Linearised'}, 'Interpreter', 'latex');
% ylim([-60 120])
% xlim([0 14])
grid on
grid minor

subplot(5,1,4)
plot(nl_t,nl_x4*180/pi, "b")
hold on 
plot(lin_t,lin_x4*180/pi, 'r--')
hold off
xlabel('Time [s]')
ylabel('Yaw rate [deg/s]')
legend({'$x_4$ Non-Linear', '$x_4$ Linearised'}, 'Interpreter', 'latex');
% ylim([min(lin_x4*180/pi) max(lin_x4*180/pi)])
% xlim([0 14])
grid on
grid minor

subplot(5,1,5)
plot(nl_t,nl_vp, "b")
hold on 
plot(nl_t,nl_vy, "g")
plot(lin_t,lin_vp, "r--")
plot(lin_t,lin_vy, "k--")
hold off
xlabel('Time [s]')
ylabel('Input Voltage [V]')
legend("V_p Non-Linear", "V_y Non-Linear", "V_p Linearised", "V_y Linearised")
% ylim([-60 120])
% xlim([0 14])
grid on
grid minor

% Plot title
% sgtitle(plot_title , 'FontSize', 8);
end