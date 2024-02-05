%% A function to calculate: the percentage error and new error limit (15%)
 
%% Defining the primary function
function [percentage_error, new_error_limit] = measurementResults(R_val, Ac_val, Pc_val, r_err, ac_err, pc_err, Err_lim, n)
    % Calculate percentage error
    percentage_error = calculatePercentageError(R_val, Ac_val, Pc_val, r_err, ac_err, pc_err);
    
    % Calculate new error limit (15%)
    new_error_limit = calculateNewErrorLimit(R_val, Ac_val, Pc_val, Err_lim, n);
end

%% Local function to calculate the percentage error
function resultsPercentageError = calculatePercentageError(R_val, Ac_val, Pc_val, r_err, ac_err, pc_err)
    % Defining the symbolic variables and function
    syms R_sym Ac_sym Pc_sym
    L_sym = (R_sym * Ac_sym) / Pc_sym;
    
    % Differentiating L with respect to each variable
    DL_DR_sym = diff(L_sym, R_sym);
    DL_DAc_sym = diff(L_sym, Ac_sym);
    DL_DPc_sym = diff(L_sym, Pc_sym);
    
    % Substituting the actual values into L and its derivatives
    L = double(subs(L_sym, [R_sym, Ac_sym, Pc_sym], [R_val, Ac_val, Pc_val]));

    result_R = double(subs(DL_DR_sym, [R_sym, Ac_sym, Pc_sym], [R_val, Ac_val, Pc_val]));
    result_Ac = double(subs(DL_DAc_sym, [R_sym, Ac_sym, Pc_sym], [R_val, Ac_val, Pc_val]));
    result_Pc = double(subs(DL_DPc_sym, [R_sym, Ac_sym, Pc_sym], [R_val, Ac_val, Pc_val]));
    
    % Calculating allowable overall error N and percentage error
    N = result_R * r_err + result_Ac * ac_err + abs(result_Pc) * pc_err;
    resultsPercentageError = (N / L) * 100;
end

%% Local function to calculate new error limits (15%)
function resultsNewErrorLimit = calculateNewErrorLimit(R_val, Ac_val, Pc_val, Err_lim, n)
    % Recalculate L for new error limit calculation
    L = (R_val * Ac_val) / Pc_val; 

    % Calculate new error limits
    R_0_15 = (Err_lim * L) / (result_R * n);
    Ac_0_15 = (Err_lim * L) / (result_Ac * n);
    Pc_0_15 = (Err_lim * L) / (result_Pc * n);
    resultsNewErrorLimit = [R_0_15, Ac_0_15, Pc_0_15];
end
