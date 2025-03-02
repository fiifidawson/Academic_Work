//
// Created by adlercohen on 5/11/2022.
//

/*DATA TYPE HIERARCHY
 Long double
 double
 float
 long
 int
 short
 char
 */

#include <stdio.h>
int main(){

    // Implicit Type Data Conversion: 'automatic type conversion'. It is done by the compiler on its own, without any
    // external trigger from the user. It generally takes place when in an expression more than one data type is present
    double d = 12.45;
    int i = 45;
    int results = d + i;
    printf("Implicit Conversion: %d", results);



    // Explicit Data Type Conversion:
    double a = 5.67;
    int b = 9;
    double result = (int)a + b;
    printf("\nExplicit conversion: %lf", result);


    return 0;
}