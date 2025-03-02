//
// Created by adlercohen on 7/6/2022.
//
#include <stdio.h>

int main() {

    int n, reverse = 0, remainder;

    printf("Enter an integer: ");
    scanf("%d", &n);

    while (n != 0) {
        remainder = n % 10;
        reverse = reverse * 10 + remainder;
        n /= 10;
    }
    printf("Reversed number = %d", reverse);

    if(n == reverse){
        printf("\nNumbers are the same");
    } else{
        printf("\nNumbers are not the same");
    }

    return 0;
}