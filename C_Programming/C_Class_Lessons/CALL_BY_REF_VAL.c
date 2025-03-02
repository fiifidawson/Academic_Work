//
// Created by adlercohen on 7/14/2022.
//
#include <stdio.h>
void swap_call_val(int, int);
void swap_call_ref(int *, int *);

int main() {
    int a = 1, b = 2, c = 3, d = 4;
    printf("\n In main(), a = %d and b = %d", a, b);
    swap_call_val(a, b);
    printf("\n In main(), a = %d and b = %d", a, b);
    printf("\n\n In main(), c = %d and d = %d", c, d);
    swap_call_ref(&c, &d);
    printf("\n In main(), c = %d and d = %d", c, d);
}
    void swap_call_val(int a, int b) {
        int temp;
        temp = a;
        a = b;
        b = temp;
        printf("\n In function (Call By Value Method) – a = %d and b = %d", a, b);
    }

    void swap_call_ref(int *c, int *d) {
        int temp;
        temp = *c;
        *c = *d;
        *d = temp;
        printf("\n In function (Call By Reference Method) – c = %d and d = %d", *c, *d);
    }
