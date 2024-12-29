%% Q1
A1 = [-24 1 0;-191 0 1;-504 1 0]
B1 = [0 1 6]'
C1 = [1 0 0]
D1 = 0
J1 = [-1+4j -1-4j -8]
L1 = [acker(A1',C1',J1)]'
%% Ans E

%%Q2
%% Uncompensated
sys = zpk(-0.18,[0 -0.02 -2 -5],1)
f = figure;
rlocus(sys)
sgrid(0.2,0)
%% Ans C

%%Q3
G1 = tf(1,conv([1 5],[1 7]))
H = tf([1 -2 6],[1 2 10])
T = G1/(1+(G1*H))
rlocus(T)
%sisotool(Ge)

%%Q4
G2 = tf(1,conv([1 5],conv([1 7],[1 10])))
rlocus(G2)
%Ans:F

%%Q5
G3 = tf([1 3],conv([1 0],conv([1 5],conv([1 7],[1 10]))))
rlocus(G3)
%%Ans: G

%%Q6
G4 = tf(1,conv([1 5],conv([1 8],[1 17])))
sisotool(G4)
%Ans:D

%%Q7
G5 = tf([40 48 500000],[1 5.6 62000 0])
Km = 10
driveinfo = stepinfo(out.d,out.tout)
%% Ans = F 

%%Q8
A_7 = [0 1; -7 -5]
B_7 = [0 1]'
C_7 = [1 0]
D_7 = 0;
K = [80 30]
L = [38 1219]'
%Ans: D