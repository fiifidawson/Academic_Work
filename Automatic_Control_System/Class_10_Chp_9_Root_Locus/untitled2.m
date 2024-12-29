sys_uc = zpk([], [-1 -2 -10], 1);
rlocus(sys_uc)
sgrid(0.174, 0)