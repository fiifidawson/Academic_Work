//
// Created by adlercohen on 5/15/2022.
//
// FUNCTION PROTOTYPE: It is the declaration of a function. It provides
//information about the function name and return type but not the body
//Function prototype provides information about the function to the compiler
#include <stdio.h>

// The function prototypes are used to tell the compiler about the number of arguments and about the required datatypes
// of a function parameter, it also tells about the return type of the function
int addNumbers(int number1, int number);

int main(){

    int result = addNumbers(5, 7);
    printf("Result = %d", result);
    return 0;
}

int addNumbers(int number1, int number2){
    int sum = number1 + number2;
    return sum;
}