//
// Created by adlercohen on 6/28/2022.
//
#include<stdio.h>

int main()
    {
        int input, sum = 0 , m;
        printf("Enter a five digit number:");
        scanf("%d",&input);

        while(input > 0){
            m = input % 10;
            sum = sum + m;
            input = input / 10;
        }
        printf("Sum is = %d",sum);

        return 0;
    }
