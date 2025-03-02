//
// Created by adlercohen on 7/14/2022.
//
#include <stdio.h>

int main(){
    int days;
    printf("Enter the day in which the book was returned:");
    scanf("%d", &days);

    if( days <= 0){
        printf("Invalid Input!");
    } else if(days > 0 && days <= 5){
        printf("Your fine is 50 paisa");
    } else if(days > 5 && days <= 10){
        printf("Your fine is 1 rupee");
    } else if(days > 10 && days < 30){
        printf("Your fine is 5 rupees");
    } else if(days >= 30){
        printf("Your membership has been cancelled");
    } else{
        printf("Task ended");
    }

    return 0;
}