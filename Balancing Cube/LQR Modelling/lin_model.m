%%% Name: Ben Miller
%%% Student Number: c3328484

function [dx] = lin_model(in, p)

% state vector x = [d_alpha d_beta d_gamma alpha beta d_theta_A d_theta_B d_theta_c]

% output vector like y = [d_gamma alpha beta d_theta_A d_theta_B d_theta_C]

% State Variables
V_a = in(1);
V_b = in(2);
V_c = in(3);

u = [V_a;V_b;V_c];

d_alpha = in(4);
d_beta = in(5);
d_gamma = in(6);
alpha = in(7);
beta = in(8);
d_theta_A = in(9);
d_theta_B = in(10);
d_theta_C = in(11);
    

x=[d_alpha; d_beta; d_gamma; alpha; beta; d_theta_A; d_theta_B; d_theta_C];

A = p.A;
B = p.B;

%% Dynamics equations

dx  = A*x+B*u;

end