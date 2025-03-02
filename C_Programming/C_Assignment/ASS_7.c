//
// Created by adlercohen on 6/28/2022.
//
//#include<stdio.h>
//#include<conio.h>
//int main()
//{
//    int num, firstNumber, secondNumber, thirdNumber, fourthNumber, fifthNumber;
//    printf("Enter a five digit number : ");
//    scanf("%d", &num);
//
//    //Uses remainder and int to overturn trailing numbers
//    fifthNumber = num%10;
//    fourthNumber = (num/10) % 10;
//    thirdNumber = (num/100) % 10;
//    secondNumber = (num/1000) % 10;
//    firstNumber = (num/10000);
//
//    num = fifthNumber*10000 + fourthNumber*1000 + thirdNumber*100 + secondNumber*10 + firstNumber;
//    printf("\n%d", num);
//    getch();
//    return 0;
//}

#include<stdio.h>
int main()
{
    int n, reverse=0, rem;
    printf("Enter a number: ");
    scanf("%d", &n);
    while(n!=0)
    {
        rem=n%10;
        reverse=reverse*10+rem;
        n/=10;
    }
    printf("Reversed Number: %d",reverse);
    return 0;
}