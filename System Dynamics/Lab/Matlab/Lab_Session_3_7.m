num = 8 
denum = [1 6 40]

sys = tf(num, denum);

u = 2 * exp(-2*t).*sin((pi/2)*t)
t = 0:0.01:10;
lsim(sys, u , t)
