//
// Created by adlercohen on 5/29/2022.
//
// Change Value using Pointers

#include <stdio.h>

int main(){

    int age = 25;

    int *ptr = &age;

    // Assigning a new value
    *ptr = 31;

    printf("%d", age);

    return 0;
}