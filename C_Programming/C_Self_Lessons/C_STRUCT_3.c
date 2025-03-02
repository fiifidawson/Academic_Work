//
// Created by adlercohen on 6/24/2022.
//
// A program to perform calculation of complex numbers

#include <stdio.h>

typedef struct Complex{
    double real;
    double imagine;
} complex;

int main(){

    complex c1 = {.real =21.87, .imagine = 30};
    complex c2 = {.real = 13.34, .imagine = 112.23};

    complex sum;

    sum.real = c1.real + c2.real;
    sum.imagine = c1.imagine + c2.imagine;

    printf("Result is %.2lf + %.2lfi", sum.real, sum.imagine);

    return 0;
}