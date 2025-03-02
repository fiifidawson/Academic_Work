//
// Created by adlercohen on 6/28/2022.
//
#include <stdio.h>

int main(){
    double temperatureFahrenheit;
    printf("Enter temperature in Fahrenheit: ");
    scanf(" %lf", &temperatureFahrenheit);

    double temperatureCelsius;

    temperatureCelsius = (0.5555556) * (temperatureFahrenheit - 32);

    printf("\nThe temperature from Fahrenheit: %.1lf to Celsius is %.1lf", temperatureFahrenheit, temperatureCelsius);

    return 0;
}