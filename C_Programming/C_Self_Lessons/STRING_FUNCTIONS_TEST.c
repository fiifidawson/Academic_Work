//
// Created by adlercohen on 5/25/2022.
//
/*Create a program to compare two strings and print the larger strings
 * Get two string input from the user using fgets()
 * Compare the length of both the strings using strlen()
 * Print the larger string
 */
#include <stdio.h>
#include <string.h>

int main(){
    char input1[20];
    char input2[20];

    printf("Enter a month: ");
    fgets(input1, sizeof (strlen(input1)), stdin);

    printf("\nEnter a month: ");
    fgets(input2, sizeof (strlen(input2)), stdin);

    if(strlen(input1) > strlen(input2)){
        printf("\nLongest Month Name: %s", input1);
    }
    else{
        printf("\nLongest Month Name: %s", input2);
    }

    return 0;
}