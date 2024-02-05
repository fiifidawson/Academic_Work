c= 456400; % Vary the value of c
num = 1
denum = [1 c 10]
sys = tf(num, denum)

hold on;
step(sys, 10)

