num = [1 8 0]
denum = [1 6 40]
sys = tf(num, denum)

%step(sys);

impulse(sys);


