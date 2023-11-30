A = [0 1;-2 -3];
b= [0 1;1 0];
B = [0 1;1 0];
C = [1 0];
D = [0 0];
sys = ss(A, B, C, D)

step(sys)
step(10*sys)
impulse(sys)
eig(A)

syms s;

G = C*inv(s*eye(2) - 2) * B + D

[n, d] = ss2tf(A, B, C, D, 2)