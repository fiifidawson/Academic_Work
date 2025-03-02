//
// Created by adlercohen on 5/10/2022.
//

#include <stdio.h>
int main(){

    int age;

    //$Represents the memory address of the variable
    printf("Enter age: ");
    scanf("%d", &age);
    printf("Age = %d", age);

    //Taking double inputs
    double number;
    char alphabet;

    printf("\n>>Enter double integer: ");
    scanf("%lf", &number);

    printf("\n>>Enter character input: ");
    scanf("\n%c", &alphabet);

    printf("Number: %lf", number);
    printf("\nCharacter: %c", alphabet);

    //Taking multiple inputs using a single scanf function
    double value;
    char character;

    printf("Enter input values: ");
    scanf("%lf %c", &value, &character);

    printf("\nValue: %lf", value);
    printf("\nCharacter: %c", character);

    return 0;
}