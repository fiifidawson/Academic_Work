%% A function to calculate: the percentage error and new error limit (15%)
 
%% Defining the primary function
function [percentage_error, new_error_limit] = errorAnalysis(R_val, Ac_val, Pc_val, r_err, ac_err, pc_err, Err_lim, n)

    [percentage_error, new_error_limit] = calculatePercentageErrorAndNewErrorLimit(R_val, Ac_val, Pc_val, r_err, ac_err, pc_err, Err_lim, n);
end

%% Local function to calculate the percentage error and new error limits
function [resultsPercentageError, resultsNewErrorLimit] = calculatePercentageErrorAndNewErrorLimit(R_val, Ac_val, Pc_val, r_err, ac_err, pc_err, Err_lim, n)
    % Define symbolic variables
    syms R_sym Ac_sym Pc_sym
    
    % Define the symbolic function L
    L_sym = (R_sym * Ac_sym) / Pc_sym;

    % Differentiating L with respect to each variable
    DL_DR_sym = diff(L_sym, R_sym);
    DL_DAc_sym = diff(L_sym, Ac_sym);
    DL_DPc_sym = diff(L_sym, Pc_sym);

    % Substitute the actual values into L and its derivatives
    L = double(subs(L_sym, [R_sym, Ac_sym, Pc_sym], [R_val, Ac_val, Pc_val]));

    result_R = double(subs(DL_DR_sym, [R_sym, Ac_sym, Pc_sym], [R_val, Ac_val, Pc_val]));
    result_Ac = double(subs(DL_DAc_sym, [R_sym, Ac_sym, Pc_sym], [R_val, Ac_val, Pc_val]));
    result_Pc = double(subs(DL_DPc_sym, [R_sym, Ac_sym, Pc_sym], [R_val, Ac_val, Pc_val]));

    % Calculate the allowable overall error N
    N = result_R * r_err + result_Ac * ac_err + abs(result_Pc) * pc_err;

    % Calculate the percentage error
    resultsPercentageError = (N / L) * 100;

    % Calculate the new error limits
    R_0_15 = (Err_lim * L) / (result_R * n);
    Ac_0_15 = (Err_lim * L) / (result_Ac * n);
    Pc_0_15 = (Err_lim * L) / (result_Pc * n);
    resultsNewErrorLimit = [R_0_15, Ac_0_15, Pc_0_15];
end
