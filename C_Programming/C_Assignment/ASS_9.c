//
// Created by adlercohen on 6/30/2022.
//
#include <stdio.h>

int main(){
    double interest, principal, rate, years;
    printf("Enter principal: ");
    scanf("%lf", &principal);

    printf("Enter Number of years: ");
    scanf("%lf", &years);

    printf("Enter rate: ");
    scanf("%lf", &rate);

    interest = (principal * rate * years) / 100;

    printf("The interest is  GHS %.2lf", interest);

    return 0;
}