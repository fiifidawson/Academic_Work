//
// Created by adlercohen on 6/24/2022.
//
/* Create a program to find the difference between three complex numbers
 * Perform the subtraction between complex numbers by subtracting the real
 * part of one complex number from the other complex numbers and same for
 * the imaginary part too
 */

#include <stdio.h>

typedef struct Complex{
    double real;
    double imaginary;
} complex;

int main(){

    double input1_real, input2_real, input3_real, input1_imaginary, input2_imaginary, input3_imaginary;
    // First imaginary number
    printf("First complex number");
    printf("\nEnter real number: ");
    scanf(" %lf", &input1_real);
    printf("Enter imaginary number:");
    scanf(" %lf", &input1_imaginary);
    printf("Complex number 1: %.2flf + %.2lfi", input1_real, input1_imaginary);

    printf("\n");
    printf("\n");

    // Second imaginary number
    printf("Second complex number");
    printf("\nEnter real number: ");
    scanf(" %lf", &input2_real);
    printf("Enter imaginary number:");
    scanf(" %lf", &input2_imaginary);
    printf("Complex number 2: %.2flf + %.2lfi", input2_real, input2_imaginary);

    printf("\n");
    printf("\n");

    // Third imaginary number
    printf("Third complex number");
    printf("\nEnter real number: ");
    scanf(" %lf", &input3_real);
    printf("Enter imaginary number:");
    scanf(" %lf", &input3_imaginary);
    printf("Complex number 3: %.2flf + %.2lfi", input3_real, input3_imaginary);

    printf("\n");
    printf("\n");

    complex c1 = {.real = input1_real, .imaginary = input2_imaginary};
    complex c2 = {.real = input2_real, .imaginary = input2_imaginary};
    complex c3 = {.real = input3_real, .imaginary = input3_imaginary};

    complex difference;

    difference.real = c1.real - c2.real - c3.real;
    difference.imaginary = c1.imaginary - c2.imaginary - c3.imaginary;

    printf("Result is %.2lf + %.2lfi", difference.real, difference.imaginary);

    return 0;
}