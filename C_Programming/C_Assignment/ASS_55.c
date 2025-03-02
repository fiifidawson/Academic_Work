//
// Created by adlercohen on 7/14/2022.
//
#include<stdio.h>
void factorial(int num1);

int main(){
    int num;

    printf("Enter a number to find factorial:");
    scanf("%d", &num);

    factorial(num);

    return 0;
}
void factorial(int num1) {
    int count, fact = 1;
    if (num1 == 0) {
        printf("\nFactorial of 0 = 1");
    } else {
        for (count = 1; count <= num1; count++) {
            fact = fact * count;
        }
        printf("\nfactorial of %d is %d\n", num1, fact);
    }
}
