//
// Created by adlercohen on 5/14/2022.
//

#include <stdio.h>
int main(){

    //Break in for
    for(int i = 1; i <= 5; i++){
        if(i ==3){
            break;
        }
        printf("%d\n", i);
    }

    //True = 1
    while (1){
        int input;
        printf("\nEnter a number: ");
        scanf("%d", &input);

        if(input < 0){
            break;
        }
        printf("%d\n", input);

    }
    //Continue Statement: Skips the current iteration of the loop
    for(int c = 1; c <= 5; c++){
        if(c ==3){
            continue;
        }
        printf("%d\n", c);
    }

    return 0;
}