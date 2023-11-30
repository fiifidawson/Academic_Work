%lab 3
num = 1;
den = [1 2 20];
sys = tf(num,den);

step(10*sys);
% a = impulse(sys);
t = 0:0.01:10;
u = 2*exp(-4*t);
lsim(sys, u , t)