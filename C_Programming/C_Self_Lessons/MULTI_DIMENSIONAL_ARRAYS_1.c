//
// Created by adlercohen on 5/24/2022.
//
// ACCESSING ARRAY ELEMENTS

#include <stdio.h>
int main(){

    int arr[2][3] = {{0, 1, 2}, {3, 4, 5}};

    //accessing first array and first value of first array
    printf("%d\n", arr[0][0]);

    //accessing first array and second value of first array
    printf("%d\n", arr[0][1]);

    //accessing first array and third value of first array
    printf("%d\n", arr[0][2]);

    //accessing second array and first value of first array
    printf("%d\n", arr[1][0]);

    //accessing second array and second value of first array
    printf("%d\n", arr[1][1]);

    //accessing second array and third value of first array
    printf("%d\n", arr[1][2]);

    return 0;
}