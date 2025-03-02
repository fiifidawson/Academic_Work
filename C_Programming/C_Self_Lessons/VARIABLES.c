//A variable is name given to a memory location inside a computer where data is stored

//Basic structure of C programming
#include <stdio.h>

int main(){
    // VARIABLE SAMPLE ONE
    // You need to specify your data type in C
    int age = 25;

    printf("learning the language of the gods!\n");

    // In printing variables, format specifiers are used eg. "%d"
    printf("Age: %d", age);

    //Assigning new value to variables
    age = 19;
    printf("\nNew Age: %d", age);



    //VARIABLE SAMPLE TWO
    //Two variables can be assigned to the same value
    int FirstNumber = 33;
    printf("\nFirst number: %d", FirstNumber);

    int SecondNumber = FirstNumber;
    printf("\nSecond number: ", SecondNumber);

    //Two variables can be used to represent the same value
    //int variable1, variable2 = 30;

    return 0;
}

//Camel Case: myAge, firstWord