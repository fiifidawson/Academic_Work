//
// Created by adlercohen on 5/10/2022.
//


//Data types

/*                    | format specifier
int         (4 bytes) | %d for printing
double      (8 bytes) | %lf for printing
float       (4 bytes) | %f for printing
char        (1 byte)  | %c for printing
 */


#include <stdio.h>
int main(){
    int age = 10;
    printf("\n>>Integer Data Type");
    printf("\nAge = %d", age);

    double number = 12.23;
    //Default decimals place is 6. to change the number of decimal places
    //printf("%.2lf", number);
    printf("\n>>Double Data Type");
    printf("\n%lf", number);

    float number1 = 12.6f;
    printf("\n>>Float Data TYpe");
    printf("\n%f", number1);

    //Using double and float to store exponential numbers
    double number2 = 5.5e6;
    printf("\n>>Exponential of Double Data Type");
    printf("\n%lf", number2);
    //It's advisable to use double in storing floating point numbers because of
    // their precision


    //Characters are stored as integers
    char character = 'z';
    printf("\n>> Character Data Type");
    printf("\n%c",character);
    //To determine its integer value
    printf("\n>>Integer Value of Data TYpe");
    printf("\n%d", character);



    //Determining the size of an operator
    int unit;
    double value;
    //%zu is used in printing size of a Data Type
    printf("\nPrinting the size of Data Types");
    printf("\nint size = %zu", sizeof(unit));
    printf("\ndouble size = %zu", sizeof(value));


 return 0;
}