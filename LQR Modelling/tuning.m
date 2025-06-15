function [best_Q, best_R, best_K] = tuning(params)

    q_vals = [0.1, 1, 10, 50];
    r_vals = [0.1, 1, 10];
    
    best_cost = inf;
    best_Q = [];
    best_R = [];
    best_K = [];

    for q1 = q_vals
        for q4 = q_vals
            for r1 = r_vals
                try
                    Q = diag([q1, q1, 1, q4, q4, 1, 1, 1]);
                    R = diag([r1, r1, r1]);

                    % Check controllability
                    CO = ctrb(params.A, params.B);
                    if rank(CO) < size(params.A, 1)
                        disp('System is not Controllable [check states]');
                        continue;
                    end

                    [~, gain] = lqr_design(params.iclin, params.A, params.B, Q, R)

                    % Simulate system
                    params.K = gain;
                    simin = Simulink.SimulationInput('lqr_lin');
                    simin = simin.setVariable('params', params);
                    sim_out = sim(simin);

                    % Cost function: squared error of output
                    y_data = sim_out.y;
                    cost = sum(y_data(:).^2);

                    if cost < best_cost
                        best_cost = cost;
                        best_Q = Q;
                        best_R = R;
                        best_K = gain;
                    end
                catch ME
                    warning("Skipping a failed config: %s", ME.message);
                    continue;
                end
            end
        end
    end

    if isempty(best_Q)
        error("No controllable configuration found. Check A and B matrices.");
    end

    fprintf("Best cost: %.4f\n", best_cost);
    disp("Best Q matrix:");
    disp(best_Q);
    disp("Best R matrix:");
    disp(best_R);
    disp("Best K matrix:");
    disp(best_K);
end