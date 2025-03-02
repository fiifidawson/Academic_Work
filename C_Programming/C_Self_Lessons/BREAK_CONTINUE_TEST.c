//
// Created by adlercohen on 5/14/2022.
//

#include <stdio.h>
int main(){
    //When the input is 0 or negative the loop breaks
    //When the input is an odd number, it skips it
    //When the input is an even number, it displays it
    while(1){
        int number;
        printf("Enter a number: ");
        scanf(" %d", &number);

        if(number <= 0){
            break;
        }
        else if (number % 2 == 1)
            continue;
        else{
        }
        printf("%d\n", number);
    }

    return 0;
}