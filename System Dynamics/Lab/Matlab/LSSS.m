syms t
A = [0 1 0; 0 0 1; -2 -4 -5];
B = [0, 0, 1]';
D = 0
C = [1 0 0];
t = 0:0.01:20;
U = exp(-t);
X0 = [-1 0 0.5];


sys = ss(A, B, C, D);
[y] = lsim(sys, U, t, X0);
max(y)