function [dd_alpha, dd_beta, dd_gamma] = cube_acc(ref, d_theta, vin, motor, cube)
    %% Extract parameters
    alpha = ref(1);
    beta = ref(2);

    Kt = motor(1);
    Ra = motor(2);
    b = motor(3);
    I_w = motor(4);

    I_x = cube(1);
    I_y = cube(2);
    I_z = cube(3);
    l = cube(4);
    m = cube(5);

    d_theta_A = d_theta(1);
    d_theta_B = d_theta(2);
    d_theta_C = d_theta(3);

    V_A = vin(1);
    V_B = vin(2);
    V_C = vin(3);

    %% Define TransfoRaation Matrix
    R_y = [cos(beta) 0 sin(beta); 0 1 0; -sin(beta) 0 cos(beta)];
    R_x = [1 0 0; 0 cos(alpha) -sin(alpha); 0 sin(alpha) cos(alpha)];
    
    T_bf = R_y * R_x;

    %% Caclulate Angular Rates of Reaction Wheels
    dd_alpha = (m*g*l*sin(alpha)*cos(beta) - T_bf * ((Kt/Ra)*((2*V_A - V_B - V_C) - Kt*(2*d_theta_A - d_theta_B - d_theta_C) - b*(2*d_theta_A - d_theta_B - d_theta_C)))) * (I_y - I_w);
    dd_beta = (m*g*l*sin(beta)*cos(alpha) - T_bf * ((Kt/Ra)*((V_B - V_C) -Kt*(d_theta_B - d_theta_C) - b*(d_theta_B - d_theta_C)))) *(I_x - I_w);
    dd_gamma = T_bf * ((Kt/Ra)*((V_A - V_B - V_C) - Kt*(d_theta_A - d_theta_B - d_theta_C) - b*(d_theta_A - d_theta_B - d_theta_C))) * (I_z - I_w);


end