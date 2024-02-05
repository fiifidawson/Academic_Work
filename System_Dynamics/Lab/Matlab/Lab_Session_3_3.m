%lab 3
num = 1;
den = [7 8 80];
sys = tf(num,den);

step(10*sys);
% a = impulse(sys);
t = 0:0.01:10;
u = 2*sin(((pi)/2)*t) + t.*exp(-2*t);
lsim(sys, u , t)