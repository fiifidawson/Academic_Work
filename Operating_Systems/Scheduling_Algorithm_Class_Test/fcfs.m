function fcfs()
t1=0;
t2=0;
t3=0;
n=4;                    %no of processes
btime=[ 100 40 80 20];       %burst time
atime=[2 6 10 16]; %arrival time
wtime=zeros(1,n);       %waiting time
tatime=zeros(1,n);      %turn around time
cotime=zeros(1,n);      %completion time
for i=2:1:n
   wtime(i)=btime(i-1)+wtime(i-1);  %waiting time will be sum of burst time of previous process and waiting time of previous process
   t1=t1+wtime(i);                  %calculating total time
end
for i=1:1:n
    tatime(i)=btime(i)+wtime(i);    %turn around time=burst time +wait time
    t2=t2+tatime(i);                %total turn around time
end

%%completion time start%%
for i=1:1:n
    cotime(i)=tatime(i)+atime(i);    %completion time= turn around time+arrival time
    t3=t3+cotime(i);                %total completion time
end
%%completion time end%%

disp('Process   Burst time  Waiting time    Turn Around time    Completion time'); %displaying final values
for i=1:1:n
    fprintf('P%d\t\t\t%d\t\t\t%d\t\t\t\t%d\t\t\t\t\t%d\n',(i-2+1),btime(i),wtime(i),tatime(i), cotime(i));
end
fprintf('Average waiting time: %f\n',(t1/n));
fprintf('Average turn around time: %f\n',(t2/n));
fprintf('Average completion time: %f\n',(t3/n));