//
// Created by adlercohen on 7/7/2022.
//
#include <stdio.h>

int main()
{
    int num, binary, decimal = 0, base = 1, rem ;
    printf (" Enter a binary number with the combination of 0s and 1s \n");
    scanf (" %d", &num);

    binary = num;


    while ( num > 0)
    {
        rem = num % 10;
        decimal = decimal + rem * base;
        num = num / 10;
        base = base * 2;
    }

    printf (" The binary number is %d \t", binary);
    printf (" \n The decimal number is %d \t", decimal);
    printf (" \n The Octal number is %o \t", decimal);
    printf (" \n The Hexa number is %x \t", decimal);



    return 0;
}