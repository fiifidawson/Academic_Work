//
// Created by adlercohen on 7/6/2022.
//
#include <stdio.h>

int main(){

    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    if(number % 2 == 0){
        printf("Number is an even integer");
    }
    else{
        printf("Number is an odd integer");
    }
    return 0;
}