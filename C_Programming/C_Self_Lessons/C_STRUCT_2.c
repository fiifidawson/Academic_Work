//
// Created by adlercohen on 6/21/2022.
//
// typedef in Struct

#include <stdio.h>

typedef struct Person{
    double salary;
    int age;
}person; // Used as an alias to struct

int main(){

    person person1;

    person1.age = 24;
    person1.salary = 324232.2;
    printf("Age of person1: %d\n", person1.age);
    printf("Salary of person1: %.2lf\n", person1.salary);

    return 0;
}
