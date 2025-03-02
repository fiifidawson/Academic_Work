//
// Created by adlercohen on 6/24/2022.
//
// malloc() - memory allocation: is used to reserve a block of memory of the specified size

#include <stdio.h>
#include <malloc.h>

int main() {

    int n = 100;

    int* ptr;

    // int = 4 bytes
    // n * sizeof(int): is the memory required to store n number of integer values
    // Type casting (int*) is used so that the allocated memory is used to store
    // integer type data
    ptr = (int*) malloc(n * sizeof(int));
    // ptr variable stores the first byte of the allocated memory, and we can use the ptr
    // variable to access the remaining bytes
    printf("%d", *ptr);

    return 0;
}
