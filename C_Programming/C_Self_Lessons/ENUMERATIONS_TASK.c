//
// Created by adlercohen on 6/24/2022.
//
// Create an enum with enum constants Sunday, Monday, Tuesday, Wednesday
// Thursday, Friday, and Saturday
/*Inside the main function
 * Create two enum variables named weekend1 and weekend2
 * Assign values Sunday and Saturday to the variables respectively
 * Print the values of weekend1 and weekend2
 */

#include <stdio.h>

enum Weekdays{
    Sunday = 1,
    Monday = 2,
    Tuesday = 3,
    Wednesday = 4,
    Thursday = 5,
    Friday = 6,
    Saturday = 7
};

int main(){

    enum Weekdays weekend1 = Saturday;
    enum Weekdays weekend2 = Sunday;

    printf("Weekend 1: %d", weekend1);
    printf("\nWeekend 2: %d", weekend2);


    return 0;
}