//
// Created by adlercohen on 8/29/2022.
//
#include <stdio.h>
#include <math.h>

int main(){
    int n, r, bn, i = 0;
    printf("Please enter the Octal Number:");
    scanf("%o",&n);
    printf("\nHexadecimal Number:%x",n);
    printf("\nDecimal Number:%d",n);

while(n>0){
    r = n%2;
    n = n/2;
    bn = bn + r * pow(10,i);
    i++;
    }
    printf("\nThe BINARY Number :%d",bn);
    return 0;
}
