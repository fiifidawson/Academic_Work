//
// Created by adlercohen on 7/28/2022.
//
//#include <stdio.h>
//void sum (int*, int*, int*);
//int main()
//{
//    int num1, num2, total;
//    printf("\n Enter the first number : ");
//    scanf("%d", &num1);
//    printf("\n Enter the second number : ");
//    scanf("%d", &num2);
//    sum(&num1, &num2, &total);
//    printf("\n Total = %d", total);
//    return 0;
//}
//void sum (int *a, int *b, int *t)
//{
//    *t = *a + *b;
//}
#include <stdio.h>

int main()
{
    int m=5;
    if(m<3) printf("%d", m+1);
    else if(m<5) printf("%d",m+2);
    else if(m<7) printf("%d",m+3);
    else printf("%d",m+4);
}
