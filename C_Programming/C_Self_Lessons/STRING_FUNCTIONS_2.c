//
// Created by adlercohen on 5/25/2022.
//
#include <stdio.h>
#include <string.h>

int main(){
    char text1[] = "Hey, ";
    char text2[] = "How are you?";

    // [strcat] is used to join two strings together(concatenation)
    strcat(text1, text2);
    printf("%s", text1);

    return 0;
}