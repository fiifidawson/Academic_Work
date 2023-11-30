num = [1 8 0]
denum = [1 6 40]
sys = tf(num, denum)

figure1(step(sys));

figure2(impulse(sys));


