//
// Created by adlercohen on 7/6/2022.
//
#include<stdio.h>

int main()
{
    int C, D, E;
    printf("Enter the value of C: ");
    scanf("%d", &C);

    printf("Enter the value of D: ");
    scanf("%d", &D);

    C = C+D; //c=30, d=20
    D = C-D; //d=10, c=30
    C = C-D; //c=20


    printf("\n The value of C: %d", C);
    printf("\n The value of D: %d", D);
    getchar();
    return 0;
}