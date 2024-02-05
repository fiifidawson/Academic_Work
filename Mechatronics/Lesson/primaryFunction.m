function [output, output2] = primaryFunction(input)
    % Primary function code
    output = localFunction(input);
    output2 = localFunction2(input);
end

function result = localFunction(x)
    % Local function code
    result = x^2;  % Example operation
end
function result1 = localFunction2(x)
    % Local function code
    result1 = x^3;  % Example operation
end




