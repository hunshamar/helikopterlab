% FOR HELICOPTER NR 3-10
% This file contains the initialization for the helicopter assignment in
% the course TTK4115. Run this file before you execute QuaRC_ -> Build 
% to build the file heli_q8.mdl.

% Oppdatert høsten 2006 av Jostein Bakkeheim
% Oppdatert høsten 2008 av Arnfinn Aas Eielsen
% Oppdatert høsten 2009 av Jonathan Ronen
% Updated fall 2010, Dominik Breu
% Updated fall 2013, Mark Haring
% Updated spring 2015, Mark Haring


%%%%%%%%%%% Calibration of the encoder and the hardware for the specific
%%%%%%%%%%% helicopter
Joystick_gain_x = 1;
Joystick_gain_y = -1;


%%%%%%%%%%% Physical constants
g = 9.81; % gravitational constant [m/s^2]
l_c = 0.46; % distance elevation axis to counterweight [m]
l_h = 0.66; % distance elevation axis to helicopter head [m]
l_p = 0.175; % distance pitch axis to motor [m]
m_c = 1.92; % Counterweigh  | t mass [kg]
m_p = 0.72; % Motor mass [kg]

%% LQR-controller %%
K_1  = 4;
K_2 = 0.45;
A = [0 1 0 0 0; 0 0 0 0 0; 0 0 0 0 0; 1 0 0 0 0; 0 0 1 0 0];
B = [0 0; 0 K_1; K_2 0; 0 0; 0 0];
C = [1 0 0 0 0;0 0 0 0 1];
Q = [120 0 0 0 0; 0 60 0 0 0; 0 0 70 0 0; 0 0 0 800 0; 0 0 0 0 100];
R = [1 0; 0 0.3];

K = lqr(A,B,Q,R);
disp(K);

%state estimation

K_3 = 0.5;

A_L =  [0 1 0 0 0 0; 
        0 0 0 0 0 0;
        0 0 0 1 0 0;
        0 0 0 0 0 0;
        0 0 0 0 0 1;
      K_3 0 0 0 0 0];
  
 C_L = [1 0 0 0 0 0;
        0 0 1 0 0 0;
        0 0 0 0 1 0];
    
B_L = [0 0; 0 K_1; 0 0; K_2 0; 0 0; 0 0];


    

Ob_m = obsv(A_L,C_L);






sys_poles = eig(A-B*K);
max_eigen = max(sys_poles); 
max_eigen = max_eigen * 3;
magnitude = (sqrt(real(max_eigen)^2 + sqrt(imag(max_eigen)^2)));
a = [-170; -190; -150; -210; -240; -120]; %angles for the poles
poles = zeros(6,1); %Empty matrix to fill with poles

for j = 1:6
    [re, im] = pol2cart(a(j,1)*pi/180, magnitude);
    re = round(re);
    im = round(im);
    poles(j,1) = re + im*i;
end

L = (place(A_L',C_L',poles))';


