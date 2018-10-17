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
Q = [120 0 0 0 0; 0 100 0 0 0; 0 0 80 0 0; 0 0 0 800 0; 0 0 0 0 200];
R = [1 0; 0 0.3];




K = lqr(A,B,Q,R);
disp(K);
P = eye(2);
disp(P);

%state estimation

K_3 = 4;

A_L =  [0 1 0 0 0 0; 
        0 0 0 0 0 0;
        0 0 0 1 0 0;
        0 0 0 0 0 0;
        0 0 0 0 0 1;
      K_3 0 0 0 0 0];
  
  C_L = [1 0 0 0 0 0;
         0 0 1 0 0 0;
         0 0 0 0 1 0];

%   C_L = [0 0 1 0 0 0;
%          0 0 0 0 1 0];

B_L = [0 0; 0 K_1; 0 0; K_2 0; 0 0; 0 0];


    

Ob_m = obsv(A_L,C_L);

sys_poles =eig(A-B*K);

le = max(sys_poles);
magn = sqrt(real(le)^2 + sqrt(imag(le)^2));
magn = 3*magn;

e1 = [-170.0 magn];
e2 = [-190.0 magn];
e3 = [-150.0 magn];
e4 = [-210.0 magn];
e5 = [-240.0 magn];
e6 = [-120.0 magn];

a = [e1; e2; e3; e4; e5; e6];

poles = zeros(6,1);

for j = 1:6
    
    [re, im] = pol2cart(a(j,1)*pi/180, a(j,2));
    
    re = round(re);
    im = round(im);
  
    poles(j,1) = re + im*sqrt(-1);
end
 
L = (place(A_L',C_L',poles))';


% le = max(sys_poles);
% magn = sqrt(real(le)^2 + sqrt(imag(le)^2));
% magn = 5*magn;
% 
% e1 = [-182.0 magn];
% e2 = [-178.0 magn];
% e3 = [-184.0 magn];
% e4 = [-176.0 magn];
% e5 = [-174.0 magn];
% e6 = [-186.0 magn];
% 
% a = [e1; e2; e3; e4; e5; e6];
% 
% poles = zeros(6,1);
% 
% for j = 1:6
%     
%     [re, im] = pol2cart(a(j,1)*pi/180, a(j,2));
%     
%     re = round(re);
%     im = round(im);
%   
%     poles(j,1) = re + im*sqrt(-1);
% end
%  
% L = (place(A_L',C_L',poles))';
% 


