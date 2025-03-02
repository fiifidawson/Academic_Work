//
// Created by adlercohen on 5/12/2022.
//

#include <stdio.h>
int main(){

    char operator;
    printf("Choose an operator ['+', '-', '*', '/']: ");
    scanf("%c", &operator);

    double number1, number2;
    printf("\nEnter first value: ");
    scanf(" %lf", &number1);

    printf("\nEnter second value: ");
    scanf(" %lf", &number2);

    double result;

    switch (operator) {
        case '+':
            result = number1 + number2;
            printf("%lf", &result);
            break;
        case '-':
            result = number1 - number2;
            printf("%lf", &result);
            break;
        case '*':
            result = number1 * number2;
            printf("%lf", &result);
            break;
        case '/':
            result = number1 / number2;
            printf("%lf", &result);
            break;
        default:
            printf("Invalid Input");

    }


    return 0;
}