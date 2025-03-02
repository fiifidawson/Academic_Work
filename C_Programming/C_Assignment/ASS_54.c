//
// Created by adlercohen on 7/14/2022.
//
#include <stdio.h>

int sumNumbers(int value1, int value2);
int subNumbers(int value1, int value2);
int multNumbers(int value1, int value2);
int divNumbers(int value1, int value2);

int main(){

    int results, input1, input2;
    printf("Enter first and second value:");
    scanf("%d \n %d", &input1, &input2);

    results = sumNumbers(input1, input2);
    printf("\nAnswer is %d", results);
    results = subNumbers(input1, input2);
    printf("\nAnswer is %d", results);
    results = multNumbers(input1, input2);
    printf("\nAnswer is %d", results);
    results = divNumbers(input1, input2);
    printf("\nAnswer is %d", results);

    return 0;
}
int sumNumbers( value1, value2){
    int sum = value1 + value2;
    return sum;
}
int subNumbers( value1, value2) {
    int sub = value1 - value2;
    return sub;
}
int multNumbers( value1, value2) {
    int mult = value1 * value2;
    return mult;
}
int divNumbers( value1, value2) {
    int div = value1 / value2;
    return div;
}