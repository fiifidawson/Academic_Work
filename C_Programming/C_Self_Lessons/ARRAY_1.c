// assigning values to an array



#include <stdio.h>
int main() {


// Elements can less or equal to the number assigned
//array index identifies the position of a number in an array
    int age[5] = {1, 2, 3, 4, 5};
    printf("%d ", age[0]);
    printf("%d ", age[1]);
    printf("%d ", age[2]);
    printf("%d ", age[3]);
    printf("%d ", age[4]);

    // Assigning values individually
    int value[5];
    value[0] = 6;
    value[1] = 7;
    value[2] = 8;
    value[3] = 9;
    value[4] = 10;

    printf("%d %d %d %d %d", value[0], value[1], value[2], value[3], value[4]);

    // Taking input from the user
    int num[5];
    printf("Enter 5 numbers: ");
    scanf("%d", &num[0]);
    scanf("%d", &num[1]);
    scanf("%d", &num[2]);
    scanf("%d", &num[3]);
    scanf("%d", &num[4]);

    printf("\n%d %d %d %d %d", num[0], num[1], num[2], num[3], num[4]);


    return 0;
}