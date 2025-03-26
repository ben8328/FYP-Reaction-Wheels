%%% Name: Ben Miller
%%% Student Number: c3328484

function [COcheck,K] = aero_lqr_design(x_ic,A,B,Q,R)

    % Compute Gain of the Controller
    K = lqr(A,B,Q,R);

    %% the aero system has 4 states, therefore a rank of 4 is required for it to be controllable
    % Compute Controlability
    C_AB = ctrb(A, B);

    % check rank of matrix
    if rank(C_AB) == length(x_ic)
       COcheck = 1; % Controllable
       disp("System is Controllable")
    else
       COcheck = 0; % Not Controllable
       disp("System is not Controllable [check states]")
    end

    

end