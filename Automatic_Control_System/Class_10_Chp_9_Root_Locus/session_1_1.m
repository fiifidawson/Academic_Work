% Uncompensated System
sys_uc = zpk([], [-1 -3 -10], 1);
rlocus(sys_c)
sgrid (0.5, 0)


% Compensated System
sys_c = zpk(-0.2, [0 -1 -3 -10], 1);
rlocus(sys_c)
sgrid (0.5, 0)

% step(feedback(73.1*sys_uc, 1))
% 
% hold on
% 
% step(feedback(159*sys_c, 1))