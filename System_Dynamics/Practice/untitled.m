% A = [0 1; -5/2 -8];
% B = [0,0]';
% X = [0.3; -0.1];
% C = [1 1.5];
% D = 0
% 
% sys = ss(A, B, C, D)
% 
% initial(sys, X)
num = 2
denum = [0.6 12 28]

sys = tf(num, denum);

step(sys)