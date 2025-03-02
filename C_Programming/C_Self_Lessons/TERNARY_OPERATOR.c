//
// Created by adlercohen on 5/12/2022.
//
//Can be used to replace if statements

#include <stdio.h>
int main(){

    int age = 56;

    //Condition    If True               : If False
    (age >= 18) ? printf("You can vote") : printf("You cannot vote");

     char operator = '+';
     int num1 = 8;
     int num2 = 7;

    int result = (operator == '+') ? (num1 + num2) : (num1 - num2);
    printf("%d", result);

    return 0;
}