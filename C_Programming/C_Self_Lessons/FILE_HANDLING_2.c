//
// Created by adlercohen on 6/25/2022.
//
#include <stdio.h>

int main(){

    FILE* fptr;

    // Filename and Mode (r: read)
    fptr = fopen("text", "r");

    char content[1000];

    if(fptr != NULL){
        // Reading all the content in a file, use while loop
        while (fgets(content, 1000, fptr))
            printf("%s", content);
    }
    else{
        printf("File Open Unsuccessful");
    }

    return 0;
}