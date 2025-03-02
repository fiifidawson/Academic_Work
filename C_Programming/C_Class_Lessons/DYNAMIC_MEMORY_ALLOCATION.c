//
// Created by adlercohen on 8/18/2022.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *memory = malloc(8);
    printf("%X", memory);
    int *array = calloc(5, sizeof(int));
    printf("\n %d", array);
    memory = realloc(memory, 30);
    printf("\n %d", memory);
    free(memory);
    free(array);
//    printf("\n %d", memory);
//    printf("\n %d", array);


    return 0;
}