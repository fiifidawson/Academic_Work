%%
syms t %%Initalize your variables using this 

%% MATLAB 
laplace(); %% to find the laplace of an expression or equation 
ilaplace(); %% for the inverse laplace of the expression

[r,p,k] = residue(a,b); %% Use residue for partial fraction expansion
    OR
partfrac() 

sys=tf(); %% Use to find the transfer funtion of the equation 
step(sys); %% Show the step response for the transfer function 
impulse(sys); %% Show the impulse response of the transfer function 
plot(t,y) %% Where t is the time interval and y is the equation 
lsim(sys,u,t) %% Simulate the time response 
tfdata(sys) %% Shows the num and den of a transfer function 
ss(a,b,c,d) %% Creates the continuous-time state-space model

%% SIMULINK
%Transfer function block
%Use To Workspace block to bring to Matlab (change to array) 
% Use display and scope
% In step block, change step time to 0, keep as 0 unless otherwise
% instructed.
% If t is given in the question stop time is changed not step time.
stepinfo(out.y,out.tout) % To get the step information from the simulink model
%% Blocks in Simulink
% Gain block: Simple increment by value in the block 
% integrator: for derivatives (y'' -> [int block]-> y')
% Summer: basic addition{ [-|+|-] will return - on top and bottom with + in middle}
% Add block can be used to avoid over apperance of summer
% product(or use divide block): multiplicationof two expression or equation for single output use
    %ex: 2*exp(3*t) + ln(3*t) will require a product block 
% Derivative blocks are used when the equation has some dynamics but no
% denominator ex: 5s+7 