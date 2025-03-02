//
// Created by adlercohen on 5/29/2022.
//
/*Create a program to change the value of a variable using a pointer
 * Get input value for a double variable salary
 * Assign the address of salary to a double pointer
 * Now ude the pointer to
 * print the value of salary
 * increase the salary by 2 times
 * print the new salary
 */

#include <stdio.h>

int main(){

    double salary;
    printf("Enter your salary:");
    scanf(" %lf", &salary);

    double* prt = &salary;

    printf("\nYour salary: %.2lf", *prt);

    double newSalary = *prt * 2;

    printf("\nYour double salary: %.2lf", newSalary);

    return 0;
}