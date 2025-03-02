//
// Created by adlercohen on 6/24/2022.
//
// Create a program that allocates dynamically changes the size of an array
/*Create a pointer array like this int* ages;
 * Allocate 4 spaces for the array using the malloc() function
 * Get 4 input values for the array.
 * Print the array elements using the pointer.
 * Resize the array to store 6 elements using realloc()
 * Assign 32 and 59 as the 5th and 6th elements.
 * ages[4] = 32;
 * ages[5] = 59;
 * Then finally Print all 6 array elements.
 */

#include <stdio.h>
#include <malloc.h>

int main() {

    int* ages;
    int n = 4;

    ages = (int*)malloc(n * sizeof(int));

    if(ages == NULL) {
        printf("Memory cannot be allocated");
        return 0;
    }

    printf("Enter input values:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", ages+i);
    }

    printf("Input Values are:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d\n", *(ages + i));
    }

    n = 6;

    ages[4] = 32;
    ages[5] = 49;

    ages = realloc(ages, n * sizeof(int));

    printf("After reallocation:\n");
    for(int i = 0; i < n; ++i) {
        printf("%d\n", *(ages+i));
    }

    free(ages);
    return 0;
}