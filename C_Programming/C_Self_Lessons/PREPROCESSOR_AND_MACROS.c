//
// Created by adlercohen on 6/25/2022.
//

// The C preprocessor is a macro processor that is used automatically by the C compiler to transform your program before
// actual compilation

// #Include Preprocessor is used to include extra header file in a program
// once you include a header file, you can use all the functions within that header file

#include <stdio.h>
#include <math.h>

int main(){

    int number = 125;

    double squareRoot = sqrt(number);
    printf("Square root: %.2lf\n", squareRoot);

    double cubeRoot = cbrt(number);
    printf("Cube root: %.2f", cubeRoot);

    return 0;
}