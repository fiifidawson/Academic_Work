//
// Created by adlercohen on 6/24/2022.
//
// In C, dynamic memory is allocated from the heap using some standard library functions.
// The two key dynamic memory functions are malloc() and free()

#include <stdio.h>

int main() {

    int var = 32;

    // pointer variable ptr stores memory address of var variable
    int* ptr = &var;

    // Memory address
    printf("Memory address: %d", ptr);

    // Value of variable
    printf("\nValue of variable: %d", *ptr);

    return 0;
}
