A1 = [0 1; -10 -6];
B1 = [0 1]';
C1 = [1 0];
D1 = [0];

sys1 = ss(A, B, C, D);
sys2 = ss(A1, B1, C1, D1);

% Create a figure window
figure;

% Plot the step response of sys1 in the first subplot
subplot(2, 1, 1); % Divides the figure into 2 rows and 1 column, and selects the 1st subplot
step(sys1);
title('Step Response of sys1'); % Optional: Add a title

% Plot the step response of sys2 in the second subplot
subplot(2, 1, 2); % Selects the 2nd subplot in the same figure
step(sys2);
title('Step Response of sys2'); % Optional: Add a ti