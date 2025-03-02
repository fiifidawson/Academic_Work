//
// Created by adlercohen on 5/15/2022.
//
#include <stdio.h>

int addNumbers(int number1, int number2){
    int sum = number1 + number2;
    return sum;
}

int main(){

    int result = addNumbers(5, 7);
    printf("Result = %d", result);
    return 0;
}