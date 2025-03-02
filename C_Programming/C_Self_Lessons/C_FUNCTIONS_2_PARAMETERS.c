//
// Created by adlercohen on 5/15/2022.
//

#include <stdio.h>

//Parameter: is a value accepted by the function
void addNumbers(int number1, int number2){
    int add = number1 + number2;
    printf("The sum of %d and %d is %d\n", number1,number2, add);
}
int main(){

    //calling the function
    addNumbers(5, 6);
    return 0;
}