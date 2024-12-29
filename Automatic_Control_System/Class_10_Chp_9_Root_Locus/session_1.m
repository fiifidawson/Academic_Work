% sys = zpk([], [-1 -2 -10], 1)
% rlocus(sys)
% sgrid (0.174, 0)

% Uncompensated System
sys_uc = zpk([], [-1 -2 -10], 1);
rlocus(sys)
sgrid (0.174, 0)

% Compensated System
figure(2);
sys_c = zpk(-0.1, [0 -1 -2 -10], 1);
rlocus(sys_c)
sgrid (0.174, 0)

step(feedback(165*sys_uc, 1))

hold on

step(feedback(159*sys_u=c, 1))