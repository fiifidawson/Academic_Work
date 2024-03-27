% Example usage:
processes = [1 0 10; 2 1 4; 3 2 8]; % Example processes with format [Process ID, Arrival Time, Burst Time]
[avg_waiting_time, avg_turnaround_time] = FCFS(processes);