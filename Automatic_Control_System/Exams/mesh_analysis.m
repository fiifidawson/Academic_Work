%% First Session 1/17/2024
syms s I1 I2 I3 V(s)

A  = [(2*s + 2), -(2*s + 1), -1;
    -(2*s + 1), (9*s + 1), -4*s;
    -1, -4*s, (4*s + 1 + (1/s))];
b = [V(s); 0; 0];

x = A \ b;
pretty(x)