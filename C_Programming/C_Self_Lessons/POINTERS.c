//
// Created by adlercohen on 5/29/2022.
//
//Pointer: it stores the memory address of the variable's value
// It allows the user to work directly with computer language

#include <stdio.h>
int main(){

    int age = 25;

    // accessing memory address where age variable is stored
    printf("%p", &age);

    return 0;
}