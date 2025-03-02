//
// Created by adlercohen on 7/27/2022.
//

#include <stdio.h>
int main() {
    //Do While loop
    //The body of the loop is executed then the condition is evaluated
    //if the condition is true, it is executed again the loop terminates when condition is false
    int value = 0;

    do {
    //do block is always executed first before the condition which is outside the do block(while)
        printf("%d\n", value);
    //If the value is 5 [int value =5], 5 would be printed even though the statement is false
        value += 1;
    } while (value < 5);
}