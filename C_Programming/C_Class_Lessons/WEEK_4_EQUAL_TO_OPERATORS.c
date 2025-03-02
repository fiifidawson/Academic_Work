//
// Created by adlercohen on 6/23/2022.
//

#include <stdio.h>
int main(){
#include<stdio.h>
    int a,b;

        printf("Please Enter the values of A:");
        scanf("%d",&a);
        printf("Please Enter the values of B:");
        scanf("%d",&b);
        printf("\n a/=b:%d",a/=b);
        getchar();
        printf("\n a*=b:%d",a*=b);
        getchar();
        printf("\na+=b:%d",a+=b);
        getchar();
        printf("\na-=b:%d",a-=b);
        getchar();
        printf("\n  a&=b:%d",a&=b);
        getchar();
        printf("\na^=b:%d",a^=b);
        getchar();
        printf("\na<<=b:%d",a<<=b);
        getchar();
        printf("\na>>=b:%d",a>>=b);
        getchar();

    return 0;
}