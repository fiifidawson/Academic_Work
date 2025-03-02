//
// Created by adlercohen on 6/25/2022.
//
// Closing the file
#include <stdio.h>

int main(){

    FILE* fptr;

    // Filename and Mode (r: read)
    fptr = fopen("text", "r");

    char content[1000];

    if(fptr != NULL){
        // fgets reads content of the file, 1000 is the size of the file fptr is the pointer used to read the file
        // fgets can only read the first content at a time
        fgets(content, 1000, fptr);
        printf("%s", content);
    }
    else{
        printf("File Open Unsuccessful");
    }
    // The close function
    fclose(fptr);

    return 0;
}