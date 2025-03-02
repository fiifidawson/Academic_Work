//
// Created by adlercohen on 6/25/2022.
//
// Define Function Macros


#include <stdio.h>
#include <math.h>

#define PI 3.1415
#define circleArea(r)(PI * pow(r, 2))

int main(){

    double radius = 12.4;

    double area = circleArea(radius);

    printf("%.2lf", area);

    return 0;
}