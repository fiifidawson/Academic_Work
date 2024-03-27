function [completionTimes, waitingTimes] = RoundRobin(arrivalTime, burstTime, quantum)
    % Initialize variables
    n = length(arrivalTime); % Number of processes
    remainingTime = burstTime; % Initialize remaining burst time
    currentTime = 0; % Initialize current time
    readyQueue = []; % Initialize queue for ready processes
    completionTimes = zeros(1, n); % Initialize array to store completion times
    waitingTimes = zeros(1, n); % Initialize array to store waiting times
    
    while any(remainingTime > 0) % Continue until all processes are completed
        % Add arriving processes to the ready queue
        for i = 1:n
            if arrivalTime(i) <= currentTime && remainingTime(i) > 0
                readyQueue = [readyQueue, i]; % Add process to ready queue
            end
        end
        
        if isempty(readyQueue) % No process in ready queue
            currentTime = currentTime + 1; % Increment time
        else
            process = readyQueue(1); % Get first process in ready queue
            readyQueue(1) = []; % Remove process from ready queue
            
            if remainingTime(process) <= quantum
                % Process completes within quantum time
                currentTime = currentTime + remainingTime(process);
                completionTimes(process) = currentTime; % Store completion time
                remainingTime(process) = 0; % Update remaining burst time
            else
                % Process still has remaining burst time
                currentTime = currentTime + quantum;
                remainingTime(process) = remainingTime(process) - quantum; % Update remaining burst time
                readyQueue = [readyQueue, process]; % Add process back to ready queue
            end
        end
    end
    
    % Calculate waiting times
    for i = 1:n
        waitingTimes(i) = completionTimes(i) - arrivalTime(i) - burstTime(i);
    end
end
