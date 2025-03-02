//
// Created by adlercohen on 6/24/2022.
//
// Open a file
// FILE* fptr

#include <stdio.h>

int main(){

    FILE* fptr;

    // Filename and Mode (r: read)
    fptr = fopen("text", "r");

    if(fptr != NULL){
        printf("File open Successful");
    }
    else{
        printf("File Open Unsuccessful");
    }

    return 0;
}