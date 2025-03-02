//
// Created by adlercohen on 6/11/2022.
//
// Create a program to find the multiplication of two numbers using a function and pointers
int* multiplyNumbers(int* num1, int* num2, int* product){

    *product = *num1 * *num2;

    return product;

}

#include <stdio.h>

int main(){
    int number1 = 5;
    int number2 = 2;
    int multiply;

    int* results = multiplyNumbers(&number1, &number2, &multiply);

    printf("Answer: %d", *results);

    return 0;
}