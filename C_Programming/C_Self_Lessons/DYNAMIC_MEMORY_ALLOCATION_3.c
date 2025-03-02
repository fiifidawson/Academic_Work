//
// Created by adlercohen on 6/24/2022.
//
// realloc() function:
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
    printf("Allocated Memory\n");
    for(int i = 0; i < n; ++i){
        printf("%p\n", ptr + i);
    }

    n = 6;

    ptr = realloc(ptr, n * sizeof (int ));
    printf("Newly Allocated Memory\n");
    for(int i = 0; i < n; ++i){
        printf("%p\n", ptr + i);
    }

    free(ptr);

    return 0;
}