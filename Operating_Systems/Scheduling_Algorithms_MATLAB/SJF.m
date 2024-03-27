function SJF(processes, burstTimes)
    % Sort processes based on burst times
    [burstTimes, idx] = sort(burstTimes);
    processes = processes(idx);
    
    n = length(processes);
    
    % Calculate completion times
    completionTimes = zeros(1, n);
    completionTimes(1) = burstTimes(1);
    for i = 2:n
        completionTimes(i) = completionTimes(i-1) + burstTimes(i);
    end
    
    % Calculate turnaround times
    turnaroundTimes = completionTimes;
    
    % Calculate waiting times
    waitingTimes = zeros(1, n);
    for i = 1:n
        waitingTimes(i) = turnaroundTimes(i) - burstTimes(i);
    end
    
    % Display results
    fprintf('Process\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n');
    for i = 1:n
        fprintf('%s\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n', processes{i}, burstTimes(i), completionTimes(i), turnaroundTimes(i), waitingTimes(i));
    end
    
    % Calculate average waiting time
    avgWaitingTime = mean(waitingTimes);
    fprintf('Average Waiting Time: %.2f\n', avgWaitingTime);
end


