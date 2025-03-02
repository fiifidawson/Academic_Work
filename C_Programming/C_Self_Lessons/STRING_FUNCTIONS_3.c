//
// Created by adlercohen on 5/25/2022.
//

#include <stdio.h>
#include <string.h>

int main(){
    char text1[] = "abcd";
    char text2[] = "abcd";

    // [strcmp()] is used to compare two strings, it returns zero if both are equal but returns a random non-zero number
    // if their not equal
    int results = strcmp(text1, text2);
    printf("%d", results);

    return 0;
}