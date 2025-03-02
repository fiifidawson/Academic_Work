//
// Created by adlercohen on 6/25/2022.
//
//Create a program to find the square root of a number using the sqrt() function
// and macro together
/*Include the math.h header file
 * Define a macro function squareRoot(n)
 * Inside the main function, use the squareRoot() macro to compute the square root
 */



#include <stdio.h>
#include <math.h>

#define squareRoot(n)(sqrt(n))

int main(){

    double radius = 12;

    double area;
    area = squareRoot(radius);

    printf("%.2lf", area);

    return 0;
}