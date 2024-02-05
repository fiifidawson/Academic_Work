
% Values
R_val = 90;
Ac_val = 7.85 * 10^-7;
Pc_val = 49 * 10^-8;

% Error margins
r_err = 9;
ac_err = 7.85 * 10^(-8);
pc_err = 4.9 * 10^(-8);

% 15% error limit
Err_lim = 0.15;
n = 3;

% Call the function
[percentage_error, new_error_limit] = results(R_val, Ac_val, Pc_val, r_err, ac_err, pc_err, Err_lim, n);

% Display the percentage error
disp(['Percentage error: ', num2str(percentage_error), '%']);

% Labels for new error limits
new_error_limit_labels = {'R', 'Ac', 'Pc'};

% Display the new error limits with labels and formatted values
disp('New error limits 15%:');
for i = 1:length(new_error_limit)
    fprintf('%s: %.10f\n', new_error_limit_labels{i}, new_error_limit(i));
end
