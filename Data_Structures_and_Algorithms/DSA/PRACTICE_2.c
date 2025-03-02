//
// Created by adlercohen on 12/10/2022.
//
#include <stdio.h>

//Write a program for performing all arithmetic
//operation using switch case

int main() {

    int number_1, number_2, arithmetic_operation, answer;

    // Take first number
    printf("Enter your first number:");
    scanf("%d", &number_1);

    printf("\n");

    // Take second number
    printf("Enter your first number:");
    scanf("%d", &number_2);

    // Choose arithmetic operation
    // Update it to include more
    printf("\n******Choose an arithmetic operation:********");
    printf("\n 1. Add(+)");
    printf("\n 2. Subtract(-)");
    printf("\n 3. Multiply(x)");
    printf("\n 4. Divide(%)");

    printf("\n Enter your option: ");
    scanf("%d", &arithmetic_operation);

    switch(arithmetic_operation)
    {
        case 1:
            answer = number_1 + number_2;
            printf("%d", answer);
            break;
        case 2:
            answer = number_1 - number_2;
            printf("%d", answer);
            break;
        case 3:
            answer = number_1 * number_2;
            printf("%d", answer);
            break;
        case 4:
            answer = number_1 / number_2;
            printf("%d", answer);
            break;
        default:
            printf("Invalid Input");
    }
    

    return 0;
}