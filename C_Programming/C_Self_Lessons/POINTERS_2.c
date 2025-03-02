//
// Created by adlercohen on 5/29/2022.
//
// Accessing Value using Pointer

#include <stdio.h>

int main(){

    int age = 25;

    // &age means ptr is taking the input of the age
    int* ptr = &age;

    // Format specifier for address %p
    printf("Address: %p\n", ptr);

    // Format specifier for value %d
    printf("Value: %d", *ptr);

    return 0;
}