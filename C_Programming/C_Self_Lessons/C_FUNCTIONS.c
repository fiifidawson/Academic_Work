//
// Created by adlercohen on 5/15/2022.
//
//Function: is a group of related statements that perform a specific task
//by dividing a large program into smaller chunks

//returnType functionName(){
//                  }

#include <stdio.h>
// If you don't want to return any value from the
// function use void as the return type
void greet(){
    printf("Good Morning");
}

// Main body
int main(){

    // Calling the function
    greet();
    greet();
    printf("\nAfter Function Call");
    return 0;
}