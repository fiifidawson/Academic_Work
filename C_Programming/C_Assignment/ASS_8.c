//
// Created by adlercohen on 6/29/2022.
//
#include <stdio.h>

int main(){

    int input, a, b, sum; //a: first digit, b:second digit
    printf("Enter a 4 digit number: ");
    scanf("%d", &input);

    a = (input / 1000) % 10;
    sum = a;

    b = input % 10;
    sum = sum + b;


    printf("\n%d", sum);

    return 0;
}