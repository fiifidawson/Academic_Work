//
// Created by adlercohen on 7/14/2022.
//
#include<stdio.h>
void fibonacciSeries(int range)
{
    int input = 0, b = 1, c;
    while (input <= range)
    {
        printf("%d\t", input);
        c = input + b;
        input = b;
        b = c;
    }
}

int main()
{
    int range;

    printf("Enter range: ");
    scanf("%d", &range);

    printf("The fibonacci series is: \n");

    fibonacciSeries(range);

    return 0;
}