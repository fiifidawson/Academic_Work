function [avg_waiting_time, avg_turnaround_time] = FCFS(processes)
    n = length(processes);
    
    % Sort processes by arrival time
    processes = sortrows(processes, 2);
    
    % Initialize completion time, waiting time, and turnaround time arrays
    completion_time = zeros(n, 1);
    waiting_time = zeros(n, 1);
    turnaround_time = zeros(n, 1);
    
    % Calculate completion time, waiting time, and turnaround time for each process
    completion_time(1) = processes(1, 2) + processes(1, 3);
    for i = 2:n
        completion_time(i) = completion_time(i - 1) + processes(i, 3);
    end
    
    for i = 1:n
        turnaround_time(i) = completion_time(i) - processes(i, 2);
        waiting_time(i) = turnaround_time(i) - processes(i, 3);
    end
    
    % Calculate average waiting time and average turnaround time
    avg_waiting_time = mean(waiting_time);
    avg_turnaround_time = mean(turnaround_time);
    
    % Display results
    disp('Process ID   Arrival Time   Burst Time   Completion Time   Waiting Time   Turnaround Time');
    for i = 1:n
        fprintf('%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n', i, processes(i, 2), processes(i, 3), completion_time(i), waiting_time(i), turnaround_time(i));
    end
    fprintf('\nAverage Waiting Time: %.2f\n', avg_waiting_time);
    fprintf('Average Turnaround Time: %.2f\n', avg_turnaround_time);
end

% Example usage:
% processes = [1 0 10; 2 1 4; 3 2 8]; % Example processes with format [Process ID, Arrival Time, Burst Time]
% [avg_waiting_time, avg_turnaround_time] = FCFS(processes);
