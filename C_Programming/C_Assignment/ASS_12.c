//
// Created by adlercohen on 7/6/2022.
//
#include <stdio.h>

int main(){
    int num1, num2;
    printf("Enter first number:");
    scanf("%d", &num1);

    printf("\nEnter second number:");
    scanf("%d", &num2);

    if(num1 > num2){
        printf("\nFirst number > Second number");
    }
    else if(num2 > num1){
        printf("\nSecond number > First number");
    }
    else{
        printf("First number = Second number");
    }
    return 0;
}