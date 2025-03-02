//
// Created by adlercohen on 6/21/2022.
//
#include <stdio.h>

struct Person{
    double salary;
    int age;
};

int main(){

    // Alt way of storing variables
    struct Person person1 = {.age = 25, .salary = 1234.54};
    struct Person person2 = {.age = 31, .salary = 67499.46};

    printf("Age of person1: %d\n", person1.age);
    printf("Salary of person1: %.2lf", person1.salary);

    printf("\n");
    printf("\nAge of person2: %d\n", person2.age);
    printf("Salary of person2: %.2lf", person2.salary);


    return 0;
}