//
// Created by adlercohen on 6/11/2022.
//
// Collection of variables (can be of different types) under a single name

#include <stdio.h>

struct Person{
    double salary;
    int age;
};

int main(){

    //datatype VariableName
    struct Person person1;
    struct Person person2;

    person1.age = 25;
    person1.salary = 4321.79;
    printf("Age of person1: %d\n", person1.age);
    printf("Salary of person1: %.2lf", person1.salary);

    person2.age = 31;
    person2.salary = 2943.5;
    printf("\n");
    printf("\nAge of person2: %d\n", person2.age);
    printf("Salary of person2: %.2lf", person2.salary);


    return 0;
}
