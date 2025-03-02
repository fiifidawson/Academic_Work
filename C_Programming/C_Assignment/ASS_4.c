//
// Created by adlercohen on 6/28/2022.
//
#include <stdio.h>
#include <math.h>
#define PI 3.14

int main(){

    double length, breadth, radius, recArea, recParam, circArea, circParam;

    printf("Enter length of rectangle: ");
    scanf("%lf", &length);

    printf("\nEnter breadth of rectangle: ");
    scanf("%lf", &breadth);

    if(length > 0 && breadth > 0){
        recParam = 2 * (length + breadth);
        printf("\nParameter of rectangle is %.2lf", recParam);

        recArea = length * breadth;
        printf("\nArea of rectangle is %.2lf", recArea);
    }
    else{
        printf("\n");
        printf("Length, breadth cannot be negative or 0!");
    }

    printf("\n");
    printf("\n");

    printf("\nEnter radius of circle: ");
    scanf("%lf", &radius);

    if(radius <= 0){
        printf("Radius cannot be negative or zero! ");
    }
    else{
        circParam = 2 * PI * radius;
        printf("\nCircumference of the circle is %.2lf", circParam);

        circArea = PI * pow(radius, 2);
        printf("\nArea of the circle is %.2lf", circArea);
    }

    return 0;
}