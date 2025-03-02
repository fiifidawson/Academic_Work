//
// Created by adlercohen on 5/15/2022.
//
//STANDARD LIBRARY FUNCTION: are built in functions
/*Examples   Library
 * printf() = stdio.h
 * sqrt()   = math.h
 */

#include <stdio.h>
#include <math.h>

//main is also a function that executes the task
int main(){

    float result = sqrt(25);
    printf("Square root  is %lf", result);

    return 0;
}