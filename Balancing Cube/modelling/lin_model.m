%%% Name: Ben Miller
%%% Student Number: c3328484

function [dx] = aero_lin_model(in, p)

% State Variables
vp    = in(1);  
vy    = in(2);
x1    = in(3);    
x2    = in(4);  
x3    = in(5);
x4    = in(6);

x=[x1;x2;x3;x4];

%% Dynamics equations

dx  = p.A*x+p.B*[vp;vy];

end