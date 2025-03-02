//
// Created by adlercohen on 5/19/2022.
//
// A function that calls itself

#include <stdio.h>

int sum(int n);

int main(){
    int number, result;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    result = sum(number);

    printf("sum = %d", result);

    return 0;
}

// Function
int sum(int n){
    if (n != 0){
        // sum() function calls itself
        return n + sum(n - 1);
    }
    else{
        return n;
    }
}