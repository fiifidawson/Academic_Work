%% *NAME: Edem Fiifi Dawson*
%% *ROLL ID: 10211100348*
%% *COURSE: BSc computer Engineering*
%% *Question 1. a)*

a = input("Enter your vector a as [a b c]: ");
b = input("Enter your vector b as [a b c]: ");
dot_ab = dot(a,b);
norm_a = norm(a);
norm_b = norm(b);
angle = acosd(dot_ab/(norm_a*norm_b));
fprintf("The dot product of a and b is: %d", dot_ab)
fprintf("The angle is: %.2f degrees", angle)

%% *Question 2. a)*

figure;
[X,Y,Z] = sphere(50);
colormap(winter(10))
colorbar
radius = sqrt(36);
% Multiply the respective x,y,z coordinates by the radius(since radius = 1) 
X2 = X * radius;
Y2 = Y * radius;
Z2 = Z * radius;

% To include the x,y,z coordinates, to define the center of the 
% sphere add or subtract them respectively.
surf(X2-1,Y2-2 ,Z2-4)
shading flat;
title('$Center = (1, 2, 4) \quad radius = \sqrt{36} \ units$','Interpreter',"latex")
xlabel('X-axis'); ylabel('Y-Axis'); zlabel('Z-Axis');
grid on; grid minor;
axis equal