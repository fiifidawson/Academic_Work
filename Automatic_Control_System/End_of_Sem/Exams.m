% sys = tf([1 0.18],[1 7.02 10.14 10.2 0])
% sisotool(sys)


% Question 2
% num = [1 0.18]
% den = conv([1 0.02], conv([1 0], conv([1 2], [1 5])))
% sys = tf(num, den)
% sisotool(sys)

% sys1 = zpk([],[-5 -7 -10],1)
% sisotool(sys1)

sys = zpk(-0.18,[0 -0.02 -2 -5],1)
f = figure;
rlocus(sys)
sgrid(0.2,0)
%% Ans C

