%%% Name: Ben Miller
%%% Student Number: c3328484

function [dx] = nl_model(in, p)
    % State Variables
    V_a = in(1);
    V_b = in(2);
    V_c = in(3);

    alpha = in(4);
    beta = in(5);
    gamma = in(6);
    d_theta_a = in(7);
    d_theta_b = in(8);
    d_theta_c = in(9);
    

    % State Space Equations
    dd_alpha = (p.m*p.g*p.l*sin(alpha)*cos(beta) - (sqrt(6)/6)*(p.Kt/p.Ra)*((2*V_a -V_b - V_c)-p.Kt*(2*d_theta_a - d_theta_b - d_theta_c)))/(p.I_y - p.I_rw);
    dd_beta = (p.m*p.g*p.l*sin(beta)*cos(alpha) - (sqrt(2)/2)*(p.Kt/p.Ra)*((V_b - V_c)-p.Kt*(d_theta_b-d_theta_c)))/(p.I_x - p.I_rw);
    dd_gamma = - ((sqrt(3)/3)*(p.Kt/p.Ra)*((V_a + V_b + V_c)-p.Kt*(d_theta_a + d_theta_b + d_theta_c)))/(p.I_z - p.I_rw);

    dd_theta_a = ((p.Kt/p.Ra)*(V_a - p.Kt*d_theta_a))/(p.I_rw);
    dd_theta_b = ((p.Kt/p.Ra)*(V_b - p.Kt*d_theta_b))/(p.I_rw);
    dd_theta_c = ((p.Kt/p.Ra)*(V_c - p.Kt*d_theta_c))/(p.I_rw);

    dx = [dd_alpha; dd_beta; dd_gamma; dd_theta_a; dd_theta_b; dd_theta_c];

end