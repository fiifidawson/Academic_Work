//
// Created by adlercohen on 7/7/2022.
//
#include <stdio.h>
#include <math.h>

int main() {
    int i = 0, r, n = 0, q;
    double bn = 0;
    printf("Please Enter the number in Decimal: ");
    scanf("%d", &n);
    printf("\nThe Hexadecimal: %x", n);
    printf("\nThe octal number: %o", n);

    while (n > 0) {
        r = n % 2;
        n = n / 2;
        bn = bn + r * pow(10, i);
        i++;
    }
    printf("\nThe Binary Number: %d", (int)bn);

    return 0;
}