arrivalTime = [0, 1, 2, 3]; % Arrival time of each process
burstTime = [8, 6, 4, 2]; % Burst time of each process
quantum = 3; % Time quantum

[completionTimes, waitingTimes] = RoundRobin(arrivalTime, burstTime, quantum);

disp('Completion Times:');
disp(completionTimes);



disp('Waiting Times:');
disp(waitingTimes);
