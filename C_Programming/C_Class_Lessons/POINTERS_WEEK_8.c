//
// Created by adlercohen on 7/14/2022.
//
//#include<stdio.h>
//int main()
//{
//    int x=10;
//    char ch = 'A';
//    void *gp;
//    gp = &x;
//    printf("\n Generic pointer points to the integer value = %d", *(int*)gp);
//    gp = &ch;
//    printf("\n Generic pointer now points to the character= %c", *(char*)gp);
//    return 0;
//}
#include <stdio.h>
int main(){
    int value = 1, input;
    printf("Enter number");
    scanf("%d", &input);

    for (int i = 1; i < 13; ++i) {
        int product = value * 2;
        printf("\n%d x %d = %d", input,value, product);
        value++;

    }
    return 0;
}