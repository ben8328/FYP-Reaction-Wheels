%%% Name: Ben Miller
%%% Student Number: c3328484

function aero_plot(sim_nl, sim_lin)


nl_t = sim_nl.t;
nl_x1 = sim_nl.x(:,1);
nl_x2 = sim_nl.x(:,2);
nl_x3 = sim_nl.x(:,3);
nl_x4 = sim_nl.x(:,4);
nl_vp = sim_nl.u(:,1);
nl_vy = sim_nl.u(:,2);

lin_t = sim_lin.t;
lin_x1 = sim_lin.x(:,1);
lin_x2 = sim_lin.x(:,2);
lin_x3 = sim_lin.x(:,3);
lin_x4 = sim_lin.x(:,4);
lin_vp = sim_lin.u(:,1);
lin_vy = sim_lin.u(:,2);

figure(1)

subplot(5,1,1)
plot(nl_t,nl_x1*180/pi, "b")
hold on 
plot(lin_t,lin_x1*180/pi, 'r--')
hold off
xlabel('Time [s]')
ylabel('Pitch Angle [deg]')
legend('$x_1$ Non-Linear', '$x_1$ Linearised', 'Interpreter', 'latex');
% ylim([-60 120])
% xlim([0 14])
grid on
grid minor

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