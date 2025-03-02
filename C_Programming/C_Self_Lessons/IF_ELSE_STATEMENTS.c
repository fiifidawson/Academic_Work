//
// Created by adlercohen on 5/12/2022.
//

#include <stdio.h>

int main(){

    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    if(age >= 18){
        printf("You're eligible to vote");
    }
    else if(age < 0){
        printf("Incorrect age!");
    }
    else{
        printf("You are no eligible to vote.");
    }
    int a = 5;
    if (!(a % 2 == 0)){
        printf("\nInside if");

    }
    else{
        printf("Inside else");
    }

    return 0;
}