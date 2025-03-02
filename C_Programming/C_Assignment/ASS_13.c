//
// Created by adlercohen on 7/6/2022.
//
#include <stdio.h>

int main(){
    int num1, num2, num3;

    printf("Enter first number:");
    scanf("%d", &num1);

    printf("\nEnter second number:");
    scanf("%d", &num2);

    printf("\nEnter third number:");
    scanf("%d", &num3);

    if(num1 > num2){
        printf("\nFirst number > Second number");
        if(num1 > num3){
            printf("\nFirst number > Third number");
        } else{ printf("\nFirst number < Third number");}
    }
    else if(num2 > num1){
        printf("\nSecond number > First number");
        if(num2 > num3){
            printf("\nSecond number > Third number");
        } else{ printf("\nThird number > second number");}
    } else if(num3 > num1){
        printf("\nThird number > First number");
        if(num3 > num2){
            printf("\nThird number > Second number");
        } else{ printf("\nThird number < Second number");}
    } else{ printf("Fist number = Second number = Third number");}
    return 0;
}