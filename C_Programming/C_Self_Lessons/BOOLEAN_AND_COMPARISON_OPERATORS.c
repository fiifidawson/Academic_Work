//
// Created by adlercohen on 5/11/2022.
//
//To use boolean, you need to import it, i.e #include <stdbool.h>
//The format specifier for boolean by %d
//True = 1
//False = 0


/*COMPARISON OPERATORS
 > Greater than
 <Less than
 == Equal to
 >= Greater than ot equal to
 <= Less than or equal to
 != Not equal to
*/
/* LOGICAL OPERATORS
 && - AND
 || - 0R
 ! - NOT
 */

#include <stdio.h>
#include <stdbool.h>

int main(){
    bool value1 = true;
    bool value2 = false;
    printf("True: %d", value1);
    printf("\nFalse: %d", value2);


    //Comparison and Logical Operators
    //> Greater than
    printf("\n>>GREATER THAN");
    bool case1 = (12 > 4);
    printf("\nTrue: %d", case1);
    bool case2 = (5 > 9);
    printf("\nFalse: %d", case2);
    //Same for all operators

    //Logical Operators
    //AND
    int age = 18;
    double height = 6.3;
    bool result = (age >= 18) && (height < 6.0);
    printf("\n>>LOGICAL AND OPERATOR");
    printf("\nAnd Operator: %d", result);

    //OR
    int age1 = 18;
    double height1 = 6.3;
    bool result1 = (age1 >= 18) || (height1 < 6.0);
    printf("\n>>LOGICAL OR OPERATOR");
    printf("\nOR Operator: %d", result1);

    //NOT
    int age2 = 18;
    bool result2 = age2 <= 5;
    printf("\n>>LOGICAL AND OPERATOR");
    printf("\nAnd Operator: %d", result2);


    return 0;
}