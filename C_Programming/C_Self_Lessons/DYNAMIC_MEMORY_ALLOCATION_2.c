//
// Created by adlercohen on 6/24/2022.
//
// free() function: is used to release the dynamically allocated memory
// free(ptr);

#include <stdio.h>
#include <malloc.h>

int main() {

    int n = 4;

    int* ptr;


    ptr = (int*) malloc(n * sizeof(int));

    if(ptr == NULL){
        printf("Memory cannot be allocated");
        return 0;
    }
    printf("Enter input values:\n");
    for(int i = 0; i < n; ++i){
        // ptr + i gives item limit of array
        scanf("%d", ptr + i);
    }
    printf("Input Values:\n");
    for (int i = 0; i < n; ++i) {
        // *(ptr + i) gives the value pointed by the ptr + i pointer
        printf("%d\n", *(ptr + i));

    }

    free(ptr);

    return 0;
}