//
// Created by adlercohen on 7/14/2022.
//
#include <stdio.h>

int main() {
    int num1 = 2, num2 = 3, sum, mul, div ;
    int *ptr1, *ptr2; ptr1 = &num1, ptr2 = &num2;

    sum = *ptr1 + *ptr2;
    mul = sum * (*ptr1);
    *ptr2 += 1;
    div = 9 + (*ptr1)/(*ptr2)- 30;

    printf("%d", sum);
    printf("\n%d", mul);
    printf("\n%d", *ptr2);
    printf("\n%d", div);


    return 0;
}