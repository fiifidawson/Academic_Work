syms s I1 I2 I3 

A  = [(4*s + 4), -(4*s + 2), -2;
    -(4*s + 2), (4*s + 14), -(6*s + 4);
    -2, (6*s + 4), (6*s + 6 + (9/s))];
b = [V; 0; 0];

x = A\b;
pretty(x)

num = [96 192 224 72];
denum = [96 300 440 234];
sys = tf(num, denum);

step(sys)