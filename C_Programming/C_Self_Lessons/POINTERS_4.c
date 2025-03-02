//
// Created by adlercohen on 5/29/2022.
//
// Mistakes in pointers

#include <stdio.h>

int main(){

    int number;

    int* ptr;

    // [wrong] Pointer which can only store memory address, number is not a memory address
    ptr = number; // Invalid

    // [wrong] *ptr gives the value stored in the ptr location however &number gives the memory address
    *ptr = &number; // Invalid

    // [right] both ptr and &number represent memory address
    ptr = &number; // Valid

    // [right] both *ptr and number represent value stored in the memory location
    *ptr = number;
    return 0;
}