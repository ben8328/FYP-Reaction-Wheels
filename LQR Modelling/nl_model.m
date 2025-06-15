%%% Name: Ben Miller
%%% Student Number: c3328484

function [dx] = nl_model(in, p)

% state vector x = [d_alpha d_beta d_gamma alpha beta d_theta_A d_theta_B d_theta_c]

% output vector like y = [d_gamma alpha beta d_theta_A d_theta_B d_theta_C]


    % State Variables
    V_a = in(1);
    V_b = in(2);
    V_c = in(3);

    

    d_alpha = in(4);
    d_beta = in(5);
    d_gamma = in(6);
    alpha = in(7);
    beta = in(8);
    d_theta_a = in(9);
    d_theta_b = in(10);
    d_theta_c = in(11);
    
    % State Space Equations (Simplified Model) (from research paper [chen2017])
    % dd_alpha = (p.m*p.g*p.l*sin(alpha)*cos(beta))/(p.I_rw - p.I_y) + (sqrt(6)/6)*(p.Kt/p.Ra)*(V_b + V_c -2*V_a + p.Kt*(2*d_theta_a - d_theta_b-d_theta_c))/(p.I_rw - p.I_y);
    % dd_beta = -(p.m*p.g*p.l*sin(beta)*cos(alpha))/(p.I_rw - p.I_x) + (sqrt(2)/2)*(p.Kt/p.Ra)*((V_b - V_c) - p.Kt*(d_theta_b - d_theta_c))/(p.I_rw - p.I_x);
    % dd_gamma = (1/sqrt(3))*(p.Kt/p.Ra)*((V_a + V_b + V_c)-p.Kt*(d_theta_a + d_theta_b + d_theta_c))/(p.I_rw - p.I_z);
    % 
    % dd_theta_a = ((p.Kt/p.Ra)*(V_a - p.Kt*d_theta_a))/(p.I_rw);
    % dd_theta_b = ((p.Kt/p.Ra)*(V_b - p.Kt*d_theta_b))/(p.I_rw);
    % dd_theta_c = ((p.Kt/p.Ra)*(V_c - p.Kt*d_theta_c))/(p.I_rw);

    % State Space Equations (Simplified Model)
    dd_alpha = (p.m*p.g*p.l*sin(alpha)*cos(beta) - (sqrt(6)/6)*(p.Kt/p.Ra)*((2*V_a -V_b - V_c)-p.Kt*(2*d_theta_a - d_theta_b - d_theta_c)))/(p.I_y - p.I_rw);
    dd_beta = (p.m*p.g*p.l*sin(beta)*cos(alpha) - (sqrt(2)/2)*(p.Kt/p.Ra)*((V_b - V_c)-p.Kt*(d_theta_b-d_theta_c)))/(p.I_x - p.I_rw);
    dd_gamma = - ((1/sqrt(3))*(p.Kt/p.Ra)*((V_a + V_b + V_c)-p.Kt*(d_theta_a + d_theta_b + d_theta_c)))/(p.I_z - p.I_rw);

    dd_theta_a = ((p.Kt/p.Ra)*(V_a - p.Kt*d_theta_a))/(p.I_rw);
    dd_theta_b = ((p.Kt/p.Ra)*(V_b - p.Kt*d_theta_b))/(p.I_rw);
    dd_theta_c = ((p.Kt/p.Ra)*(V_c - p.Kt*d_theta_c))/(p.I_rw);

    dx = [dd_alpha; dd_beta; dd_gamma; d_alpha; d_beta; dd_theta_a; dd_theta_b; dd_theta_c];

end