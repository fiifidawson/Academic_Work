% num = [2 3] 
% denum = [1.5 10 40]
% 
% sys = tf(num, denum);
% 
% % u = 2 * exp(-2*t).*sin((pi/2)*t)
% % t = 0:0.01:10;
% % lsim(sys, u , t)
% 
% % step(20*sys)
% num = [15 17] 
% denum = [5 2 3]
% 
% sys = tf(num, denum);
% 
% % u = 2 * exp(-2*t).*sin((pi/2)*t)
% % t = 0:0.01:10;
% % lsim(sys, u , t)
% 
% impulse(sys)
syms s;
A = [0 1 0;-1 -1 1;-4 -0.6 -1.2];
B= [0 0;1 0;0 2];
C = [1 0 0;0 1 1];
D = 0;
sys = ss(A, B, C, D)

% step(sys)
% step(10*sys)
% impulse(sys)
% eig(A)



G = C*inv(s*eye(2) - A) * B + D

[n, d] = ss2tf(A, B, C, D, 2)