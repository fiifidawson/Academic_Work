//
// Created by adlercohen on 5/29/2022.
//
// Change array elements using pointers

#include <stdio.h>

int main(){

    int numbers[5] = {1, 3, 5, 7, 9};

    *numbers = 2;
    // Represents the last value, 9
    *(numbers + 4) = 11;

    printf("First Element: %d\n", *numbers);
    printf("Second Element: %d\n", *(numbers + 4));

    return 0;
}