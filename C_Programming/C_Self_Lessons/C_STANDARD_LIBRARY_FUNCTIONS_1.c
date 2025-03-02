//
// Created by adlercohen on 5/18/2022.
//

// ctype Header File: Character type

#include <stdio.h>
#include <ctype.h>

int main(){

    char alpha = 'l';
    // Making a character capital
    char upper = toupper(alpha);
    printf("%c", upper);

    // Making character lower case
    char lower = tolower(upper);
    printf("\n%c", lower);
    return 0;
}