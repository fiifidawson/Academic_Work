//
// Created by adlercohen on 7/6/2022.
//
#include <stdio.h>
#include <ctype.h>

int main(){

    double num1, num2, addition, subtraction, multiplication, division;
    char operation;
    printf("\nChoose an operation to perform"
           "\nA - Addition"
           "\nS - Subtraction"
           "\nM - Multiplication"
           "\nD - Division");

    printf("\nOperation: ");
    scanf("%s", &operation);

    printf("\nEnter first number:");
    scanf("%lf", &num1);

    printf("\nEnter second number:");
    scanf("%lf", &num2);

    if(toupper(operation) == 'A'){
        addition = num1 + num2;
        printf("\n%.2lf + %.2lf = %.2lf", num1, num2, addition);
    }
    else if(toupper(operation) == 'S'){
        subtraction = num1 - num2;
        printf("\n%.2lf - %.2lf = %.2lf", num1, num2, subtraction);
    }
    else if(toupper(operation) == 'M'){
        multiplication = num1 * num2;
        printf("\n%.2lf x %.2lf = %.2lf", num1, num2, multiplication);
    }
    else if(toupper(operation) == 'D'){
        division = num1 / num2;
        printf("\n%.2lf % %.2lf = %.2lf", num1, num2, division);
    }
    else{
        printf("\nIncorrect operation!");
    }

    return 0;
}