//
// Created by adlercohen on 6/27/2022.
//
#include <stdio.h>

int main(){
    double marks;
    double avg_marks;

    for(int i = 0; i < 5; i++){
        printf("\nInput marks: ");
        scanf("%lf", &marks);

        if (marks < 0 || marks > 100) {
            printf("\nIncorrect input");
            break;
        }
        else
        {
            marks = marks + marks;
        }
    }
    printf("\n%lf", marks);

    return 0;
}