//
// Created by adlercohen on 6/1/2022.
//
#include <stdio.h>

void findSquare(int *number) {

    // [value pointed by the number pointer] * itself
    int square = *number * *number;
    *number = square;
}

int main(){

    int number = 21;

    findSquare(&number);

    printf("Square is: %d", number);

    return 0;
}