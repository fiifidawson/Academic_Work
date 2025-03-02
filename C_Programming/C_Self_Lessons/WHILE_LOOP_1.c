//
// Created by adlercohen on 7/27/2022.
//

#include <stdio.h>
int main(){
//Multiplication Table
    int number;
        printf("\nEnter the number: ");
        scanf("%d", &number);

    int limit = 1;

    while(limit <= 10){
        int product = number * limit;
        //Representing multiple variables in one print statement
        printf("\n%d x %d = %d", number, limit, product);
        limit += 1 ;
    }
    return 0;
}