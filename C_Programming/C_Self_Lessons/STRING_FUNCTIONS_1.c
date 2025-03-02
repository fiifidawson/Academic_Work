//
// Created by adlercohen on 5/25/2022.
//
#include <stdio.h>
#include <string.h>

int main(){
    char food[] = "Pizza";

    // strlen() function is used here so that the length of the best food string is the same as the food string
    char bestFood[strlen(food)];

    //used to copy one string to another
    //It takes two values
    //Destination: Copy to, Source: From where you want to copy
    strcpy(bestFood, food);
    printf("%s", bestFood);

    return 0;
}