syms s
Kpot = 0.318;
K = 23;% Finding K
K1 = 100;
a = 100;
Km = 2.083;
am = 1.71;
Kg = 0.1;

num = K*Kpot*K1*Km*Kg;
% t = conv(5,conv(1, (1 + am)))
denum = [1 (a+am) (am*a)  K*Kpot*K1*Km*Kg];

sys = tf(num, denum);

step(0.5 * sys)

% maximum overshoot = 5.14%
% Settling Time = 4.87s