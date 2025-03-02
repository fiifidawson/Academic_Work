//
// Created by adlercohen on 5/17/2022.
//
//-Local and Global Variable Scope

//LOCAL VARIABLE SCOPE
//  it exists only within the block that it is declared in. Once that block ends, the variable is destroyed and its
//  values lost . A local variable of the same name declared elsewhere is a different variable

//GLOBAL VARIABLE
// hold their values throughout the lifetime of your program and they can be accessed inside any of the functions
// defined for the program. A global variable can be accessed by any function. That is, a global variable is available
// for use throughout your entire program after its declaration
#include <stdio.h>

// To make it a global variable
// int result;
void addNumbers(int number1, int number2){
    // result = number1 + number2;
    int result = number1 + number2;
    printf("Result: %d", result);
}
int main(){

    addNumbers(5, 6);

    return 0;
}