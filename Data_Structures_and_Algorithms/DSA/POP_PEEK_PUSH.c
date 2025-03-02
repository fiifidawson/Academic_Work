//
// Created by adlercohen on 11/30/2022.
//
///Write an algorithm or a in program in C to implement POP, & PEEK operations in stack.
//#include <stdio.h>
//
//#define MAX 5 // Altering this value changes size of stack created
//
//int st[MAX], top=-1;
//int pop(int str[]);
//int peek(int st[]);
//int push(int str[]);
//int display(int st[]);
//
//int main(int argc, char *argv[]){
//    int val, option;
//    do{
//        printf("\n *****MAIN MENU*****");
//        printf("\n 1. POP");
//        printf("\n 2. PEEK");
//        printf("\n 3. EXIT");
//        printf("\n Enter your option: ");
//        scanf("%d", &option);
//        switch(option)
//        {
//            case 1:
//                printf("\n The value stored at top of stack is: %d", val);
//                break;
//            case 2:
//                display(st);
//                break;
//        }
//    }while(option != 3);
//    return 0;
//}
//int push(int str[], int val)
//{
//    if(top == MAX-1){
//        printf("\n STACK OVERFLOW");
//    }
//    else{
//        top++;
//        str[top] = val;
//    }
//}
//int pop(int str[]){
//    int val;
//    if(top == -1){
//        printf("\n STACK UNDERFLOW");
//        return -1;
//    }else{
//        val = str[top];
//        top--;
//        return val;
//    }
//}
//int display(int st[]){
//    int i;
//    if(top ==  -1)
//        printf("\n STACK IS EMPTY");
//    else{
//        for(i=top;i>=0;i--)
//            printf("\n %d",st[i]);
//        printf("\n"); // Added for formatting purposes
//    }
//}
//int peek(int st[]){
//    if(top == -1){
//        printf("\n STACK IS EMPTY");
//        return -1;
//    }
//    else
//        return (st[top]);
//}
//
// Created by adlercohen on 10/26/2022.
//
#include<stdio.h>

#include<stdlib.h>

#define Size 4

int Top=-1, inp_array[Size];
void Push();
void Pop();
void show();

int main()
{
    int choice;

    while(1)
    {
        printf("\nOperations performed by Stack");
        printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.End");
        printf("\n\nEnter the choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: Push();
                break;
            case 2: Pop();
                break;
            case 3: show();
                break;
            case 4: exit(0);

            default: printf("\nInvalid choice!!");
        }
    }
}

void Push()
{
    int x;

    if(Top==Size-1){
        printf("\nOverflow!!");
    }
    else
    {
        printf("\nEnter element to be inserted to the stack:");
        scanf("%d",&x);
        Top=Top+1;
        inp_array[Top]=x;
    }
}

void Pop()
{
    if(Top==-1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nPopped element:  %d",inp_array[Top]);
        Top=Top-1;
    }
}

void show()
{


    if(Top==-1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nElements present in the stack: \n");
        for(int i=Top;i>=0;--i)
            printf("%d\n",inp_array[i]);
    }
}