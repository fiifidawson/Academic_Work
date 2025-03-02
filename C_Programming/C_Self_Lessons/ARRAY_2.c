//
// Created by adlercohen on 5/20/2022.
//

#include <stdio.h>
int main(){

    //changing the value in an array
    int value[5];
    value[0] = 6;
    value[1] = 7;
    value[2] = 8;
    value[3] = 9;
    value[4] = 10;

    value[3] =50000;

    printf("%d %d %d %d %d", value[0], value[1], value[2], value[3], value[4]);

    // For loops in array
    int age[5];

    for(int i = 0; i < 5; ++i){
        scanf("\n%d ", &age[i]);
    }
    for(int i = 0; i < 5; ++i) {
        printf("\n%d ", age[i]);
    }

    return 0;
}