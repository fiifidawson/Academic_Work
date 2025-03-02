//
// Created by adlercohen on 5/11/2022.
//

/*ARITHMETIC OPERATORS
+ Addition
- Subtraction
* Multiplication
/ Division
% Remainder
++ Increment(increments by 1)
-- Decrement(decrements by 1)
 */

#include <stdio.h>
int main(){
    //Addition Operator
    int x = 12;
    int result = x + 3;
    printf("\nAddition of Integers: %d", result);

    //Division of Integers
    int u = 12;
    int output = u / 8;
    printf("\nInteger Division: %d", output);

    //Division of double
    double d = 12;
    double outcome = d / 8;
    printf("\nDouble Division: %.2lf", outcome);

    //Increment
    int i = 19;
    printf("\nIncrement of a number: %d", ++i);

    //Decrement
    int m = 19;
    printf("\nDecrement of a number: %d", --m);

    return 0;
}

