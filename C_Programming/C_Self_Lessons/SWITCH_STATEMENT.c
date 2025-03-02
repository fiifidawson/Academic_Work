//
// Created by adlercohen on 5/12/2022.
//

//The switch statement in C is an alternate to if-else-if ladder statement which allows us to execute multiple
// operations for the different possibles values of a single variable called switch variable
#include <stdio.h>
int main(){

    int number;
    printf("Enter number between 1 to 7: ");
    scanf("%d", &number);

    switch(number){
        case 1:
            printf("Sunday");
            break;

        case 2:
            printf("Monday");
            break;

        case 3:
            printf("Tuesday");
            break;

        case 4:
            printf("Wednesday");
            break;

        case 5:
            printf("Thursday");
            break;

        case 6:
            printf("Friday");
            break;

        case 7:
            printf("Saturday");
            break;

        default:
            printf("Invalid number");


//    ALTERNATE WAY
//    switch (number) {
//        case 2:
//        case 3:
//        case 4:
//        case 5:
//        case 6:
//            printf("\nWeekday");
//            break;
//
//        case 1:
//        case 7:
//            printf("\nWeekend");
//             break;
//
//        default:
//             printf("Invalid Number");
//            }

    }

    return 0;
}