//
// Created by adlercohen on 5/20/2022.
//
/*Create a program that computes the average marks of a student.
 * Create an array that stores the marks of 5 subjects
 * Compute the total marks by adding all the marks
 * Divide the total marks by total number of subjects
 * Print the average marks
 */

#include <stdio.h>

int main() {
    int i;
    double marks[5];
    printf("Enter marks:\n");

    for(i = 0; i < 5; i++) {
        scanf("%lf", &marks[i]);
    }

    double sum = 0;
    for(i = 0; i < 5; i++) {
        sum = marks[i] + sum;
    }

    double avg_marks = sum/5;
    printf("The average marks of a student: %.2lf", avg_marks);

    return 0;
}