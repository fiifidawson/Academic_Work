% sys = zpk(-3,[-2 , -8], 16)
% step(sys)
num4 = conv(16, [1 3])
denum4 = conv([1 2], [1 8])

% sys = tf(num4, denum4)

% applying a unit step
step(sys) 
grid on

% K is the gain
[z3, p3, K3] = tf2zp(num4, denum4)

% DC gain
DCGAIN3 = dcgain(num4, denum4)