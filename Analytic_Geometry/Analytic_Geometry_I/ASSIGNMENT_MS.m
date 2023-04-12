%% 
% *ASSIGNMENT*
% 
% Name: Marian E.M Segbaya
% 
% Roll Number: 10211100324.
% 
% 
% 
% *QUESTION 11*

syms x
y11 = piecewise(x<0, x + 3, x >= 0, -x + 3 )
y = limit(y11)
fplot(y11)
%% 
% 
% 
% *QUESTION 12*

syms x
y12 = piecewise( x< 2, x, x >= 2, x + 1)
y = limit(y12, 2)
fplot(y12)

%% 
% *QUESTION 13*

syms x
y13 = piecewise(x< 2, x^2 -2* x, x > 2, x^2 - 6*x + 8)
% The function f(x) = 1 when x = 2 is for the second function in the in piecewise function f(x) a point ( 2, 1) on the graph when
% plotted.
y = limit ( y13, 2)
fplot(y13)