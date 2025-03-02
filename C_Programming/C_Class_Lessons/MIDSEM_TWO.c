//
// Created by adlercohen on 8/26/2022.
//
//#include <stdio.h>
//int main(){

//    int input;
//    printf("Enter a number");
//    scanf("%d", &input);
//
//    (input > 0) ? printf("Number is positive") :(input < 0) ? printf("Number is Negative") : printf("Number is zero");
//    int b, i;
//
//    for (i=1; i <= 5; i++) {
//        for (b=1; b <= i; b++)
//            printf("%d",b);
//        printf("\n");
//    }
#include <stdio.h>
#include <math.h>


int main(){
    int n, r, bn, i;

    printf("Please enter the Octal Number:");
        scanf("%o",&n);
        printf("\nHexadecimal Number:%x",n);
        printf("\nDecimal Number:%d",n);
    while(n>0)
    {
        r=n%2;
        n=n/2;
        bn = bn + r*pow(10,i);
        i++;
    }
    printf("\nThe BINARY Number :%d",bn);
}




