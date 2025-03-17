%% Load Parameters
%Inertia: kg*m^2
clear;
Ix = 0.014484;
Iy = Ix;
Iz = 0.004026;
Iw = 0.000189;
%Length: m
L = 0.108;
%mass: kg
m = 1.146;
%Moment constant of motor: N*m/A
Kt = 0.0251;
%Resistor: olm
Rm = 0.0464;
%Gravity constant: m/s^2
g = 9.81;
%% System Description

A = [0 0 0 m*g*L/(Iy-Iw) 0 sqrt(6).*Kt.^2/(3*Rm.*(Iy-Iw)) -sqrt(6).*Kt.^2/(3*Rm.*(Iy-Iw)) -sqrt(6).*Kt.^2/(3*Rm.*(Iy-Iw)); 0 0 0 0 m*g*L/(Ix-Iw) 0 sqrt(2).*Kt.^2/(2*Rm.*(Ix-Iw)) -sqrt(2).*Kt.^2/(2*Rm.*(Ix-Iw)); 0 0 0 0 0 -sqrt(3).*Kt.^2/(3*Rm.*(Iz-Iw)) -sqrt(3).*Kt.^2/(3*Rm.*(Iz-Iw)) -sqrt(3).*Kt.^2/(3*Rm.*(Iz-Iw));1 0 0 0 0 0 0 0 ; 0 1 0 0 0 0 0 0 ; 0 0 0 0 0 -Kt.^2/(Iw.*Rm) 0 0 ; 0 0 0 0 0 0 -Kt.^2/(Iw .*Rm) 0 ; 0 0 0 0 0 0 0 -Kt.^2/(Iw.*Rm) ];
B = [-sqrt(6).*Kt/(3.*Rm.*(Iy-Iw)) sqrt(6).*Kt/(6.*Rm.*(Iy-Iw)) sqrt(6).*Kt/(6.*Rm.*(Iy-Iw)) ;0 -sqrt(2).*Kt/(2.*Rm.*(Ix-Iw)) sqrt(2).*Kt/(2.*Rm.*(Ix-Iw)) ; -sqrt(3).*Kt/(3.*Rm.*(Iz-Iw)) -sqrt(3).*Kt/(3.*Rm.*(Iz-Iw)) -sqrt(3).*Kt/(3.*Rm.*(Iz-Iw));0 0 0;0 0 0;Kt/(Rm.*Iw) 0 0;0 Kt/(Rm.*Iw) 0;0 0 Kt/(Rm.*Iw)];

% Compute Controlability
C_AB = ctrb(A, B)

% check rank of matrix
if rank(C_AB) == 4
   COcheck = 1; % Controllable
   disp("System is Controllable")
else
   COcheck = 0; % Not Controllable
   disp("System is not Controllable")
end