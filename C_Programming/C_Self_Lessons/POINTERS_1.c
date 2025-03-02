//
// Created by adlercohen on 5/29/2022.
//
// Pointer Variable: Stores the memory address of the variable not the actual value

#include <stdio.h>

int main(){

    //Creating main variable
    int age = 25;

    printf("%p", &age);

    // Creating a pointer
    //ptr is pointer variable
    int* ptr = &age;

    printf("\n%p", ptr);

    return 0;
}