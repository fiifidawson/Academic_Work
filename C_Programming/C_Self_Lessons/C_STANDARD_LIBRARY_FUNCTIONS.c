//
// Created by adlercohen on 5/17/2022.
//

#include <stdio.h>
// Math header file
#include <math.h>
int main(){

    int num = 25;
    //%.2lf means to decimal places
    printf("Square root %.2lf: ", sqrt(num));

    printf("\nCube root: %.2lf: ", cbrt(num));

    int a = 5;
    int b = 3;

    double result = pow(a, b);
    printf("\nPower: %.2lf", result);

    return 0;
}