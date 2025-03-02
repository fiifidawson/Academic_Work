//
// Created by adlercohen on 8/18/2022.
//
#include <stdio.h>

int jumble(int x, int y){
    x = 2*x+y;
    return x;
}

int main(){
    int x = 2, y = 5;
    y = jumble(y,x);
    x = jumble(y,x);
    printf("%d\n", x);

    return 0;
}