//
// Created by adlercohen on 6/21/2022.
//
#include<stdio.h>

int main(){
    int a,b,c,d,e,f,g,h,i;
    printf("Please Enter the values of A:");
    scanf("%d",&a);
    printf("\nPlease Enter the values of B:");
    scanf("%d",&b);
    c = a^b;
    d = a|b;
    e = a<<2;
    f = b>>2;
    g = ~a;
    h = a&b;
    i = ~b;
    printf("\nA ^ B:%d",c);
    getchar();
    printf("\nA | B:%d",d);
    getchar();
    printf("\nA<<2+:%d",e);
    getchar();
    printf("\nB>>2:%d",f);
    getchar();
    printf("\n~A:%d",g);
    getchar();
    printf("\nA&B:%d",h);
    getchar();
    printf("\n~B:%d",i);
    getchar();

    return 0;
}