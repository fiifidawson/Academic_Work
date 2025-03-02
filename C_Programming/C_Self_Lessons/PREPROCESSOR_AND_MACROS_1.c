//
// Created by adlercohen on 6/25/2022.
//
// Define Preprocessor
// #define is used to define macros
//Macro: a piece of code that is give a name
// eg. #define PI 3.1415 [PI is the Macro]

#include <stdio.h>
#include <math.h>

#define PI 3.1415

int main(){

    double radius = 12.4;

    double area = PI * pow(radius, 2);

    printf("%.2lf", area);

    return 0;
}