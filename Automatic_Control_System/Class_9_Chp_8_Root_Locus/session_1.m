% sys = tf(1, [1 5]);
% rlocus(sys)
% grid on

% sys = tf(1, [1 10 4]);
% rlocus(sys)
% grid on

% sys = zpk([-3 -4], [-1 -2], 1);
% rlocus(sys)
% grid on

% sys = tf([1 4], conv([1 1], [1 10 4]))
% rlocus(sys)
% grid on

% sys = tf([1 -4 20], conv([1 2], [1 4]))
% rlocus(sys)
% sgrid(0.8, 0)


% sys1 = tf([1 4],[1 2 20]);
% sys2 = tf(2, [1 7]);
% sys = sys1 * sys2;
% rlocus(sys)
% sgrid

% sys = tf(2.3,[0.1 1 2.3])
% rlocus(sys)
% grid on
