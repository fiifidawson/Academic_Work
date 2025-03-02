//
// Created by adlercohen on 8/27/2022.
//
#include<stdio.h>
int evenodd(int); //FUNCTION DECLARATION
int main()
{
    int num, flag;
    printf("\n Enter the number : ");
    scanf("%d", &num);
    flag = evenodd(num); //FUNCTION CALL
    if (flag == 1)
        printf("\n %d is EVEN", num);
    else
        printf("\n %d is ODD", num);
}
int evenodd(int a) // FUNCTION HEADER
{
// FUNCTION BODY
    if(a%2 == 0) return 1;
    else return 0;
}
