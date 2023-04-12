%% *NAME: Edem Fiifi Dawson*
%% *ROLL ID: 10211100348*
%% *COURSE: BSc computer Engineering*
% 
%% *Question 1*
%  *a. i)*

a = input("Enter your vector a as [a b c]: ");
b = input("Enter your vector b as [a b c]: ");
dot_ab = dot(a,b);
norm_a = norm(a);
norm_b = norm(b);
angle = acosd(dot_ab/(norm_a*norm_b));
fprintf("The dot product of a and b is: %d", dot_ab)
fprintf("The angle is: %.2f degrees", angle)
%% 
% *a. ii)*

F = [4 0 -3];
A1 = [1 -3 4];
B1 = [2 -2 5];

A1B1 = B1 - A1

Moment1 = cross(A1B1, F)
Magnitude1 = norm(Moment1)
%% *Question 2*
% *b. ii)*

F1 = [2 1 -3];
F2 = [2 -2 1];
FT = F1 + F2

A = [4 0 1];
B = [-1 3 -2];

AB = B - A

Moment = cross(AB,FT)
%% *Question 3*
% *a. ii)*

t = -3:4

x = t.^2 - 3;
y = 2.*t - 1;


title('A Graph of x plotted against y')

plot(x,y,"red", "LineWidth",3)

grid on

xlim([-3.8 12.0])
ylim([-6.2 6.0])
title("A Graph of x plotted against y")

xlabel("t^2 - 3")
ylabel("2t - 1")

%% 
% *b. ii)*

syms x y z

y.*sin(x) + z.*cos(x)

f = @(x,y,z) y.*sin(x) + z.*cos(x)

w = integral3(f,0,pi,0,1,-1,1)

fprintf("%.2f", w)