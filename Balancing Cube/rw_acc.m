function [dd_theta_A, dd_theta_B, dd_theta_C] = rw_acc(d_theta, vin, motor)
    %% Extract parameters
    Kt = motor(1);
    Ra = motor(2);
    b = motor(3);
    I_w = motor(4);

    d_theta_A = d_theta(1);
    d_theta_B = d_theta(2);
    d_theta_C = d_theta(3);

    V_A = vin(1);
    V_B = vin(2);
    V_C = vin(3);

    %% Caclulate Angular Rates of Reaction Wheels
    dd_theta_A = ((Kt/Ra) * (V_A - Kt * d_theta_A) - b * d_theta_A)/I_w;
    dd_theta_B = ((Kt/Ra) * (V_B - Kt * d_theta_B) - b * d_theta_B)/I_w;
    dd_theta_C = ((Kt/Ra) * (V_C - Kt * d_theta_C) - b * d_theta_C)/I_w;

end