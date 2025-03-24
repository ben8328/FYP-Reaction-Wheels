%%% Name: Ben Miller
%%% Student Number: c3328484

function [dx] = lin_model(in, A, B)

% State Variables
V_a = in(1);
V_b = in(2);
V_c = in(3);

u = [V_a;V_b;V_c];

alpha = in(4);
beta = in(5);
gamma = in(6);
d_theta_a = in(7);
d_theta_b = in(8);
d_theta_c = in(9);

x=[alpha;beta;gamma;d_theta_a;d_theta_b;d_theta_c];

%% Dynamics equations

dx  = A*x+B*u;

end