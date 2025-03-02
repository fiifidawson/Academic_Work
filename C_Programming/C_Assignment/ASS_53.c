//
// Created by adlercohen on 7/14/2022.
//
#include <stdio.h>

int sumNumbers(int value1, int value2);

int main(){

    int results, input1, input2;
    printf("Enter first value:");
    scanf("%d", &input1);

    printf("\nEnter second value:");
    scanf("%d", &input2);

    results = sumNumbers(input1, input2);
    printf("Answer is %d", results);

    return 0;
}
int sumNumbers( value1, value2){
    int sum = value1 + value2;
    return sum;
}