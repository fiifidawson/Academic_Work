//
// Created by adlercohen on 6/11/2022.
//

#include <stdio.h>

int* addNumbers(int* num1, int* num2, int* sum){

    *sum = *num1 + *num2;

    return sum;
}

int main(){

    int number1 = 32;
    int number2 = 18;
    int sum;

    int* result = addNumbers(&number1, &number2, &sum);

    printf("Results: %d", *result);

    return 0;
}