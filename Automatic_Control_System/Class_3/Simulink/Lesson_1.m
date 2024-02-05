
R = 5;
L = 0.004;
VS = 10;

sys = tf(1, [L, R]);
step(VS * sys);