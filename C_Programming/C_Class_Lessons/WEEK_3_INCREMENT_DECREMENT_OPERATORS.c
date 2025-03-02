//
// Created by adlercohen on 6/21/2022.
//
#include <stdio.h>
int main() {
    int a = 2, b, c, d, e, f;

    b = a++;
    c = ++a + --b;
    d = a++ + b-- + ++c;
    e = ++a + --b + c++ + d--;
    f = a++ + b-- + ++c + --d + e++;

    printf("\n a = %d \n b = %d \n c = %d \n d = %d \n e = %d \n f = %d", a, b, c, d, e, f);

    return 0;
}