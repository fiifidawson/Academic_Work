//
// Created by adlercohen on 6/1/2022.
//
//POINTERS AND FUNCTIONS

#include <stdio.h>

// Takes pointer as an argument
void findValue(int* num){

    *num = 39;
}

int main(){

    int number = 21;

    // Since our function is a pointer value that stores the memory address, address of the number variable is passed
    findValue(&number);

    printf("Number: %d", number);

    return 0;
}