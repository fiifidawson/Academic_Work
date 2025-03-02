//
// Created by adlercohen on 6/25/2022.
//
// Writing content to a file
#include <stdio.h>

int main(){

    FILE* fptr;

    // newFile.txt would be created and Mode (w: write)
    fptr = fopen("newFile.txt", "w");

   // fputs sends data to be written into the file
    fputs("This i seems so strange", fptr);
    fputs("\nAlders C journey", fptr);

    // If the file already exists, the previous content is overwritten

    fclose(fptr);

    return 0;
}