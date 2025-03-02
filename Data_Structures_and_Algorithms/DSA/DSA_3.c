//
// Created by adlercohen on 10/22/2022.
//
/// Creating and implementing a linked list

#include <stdio.h>
#include <stdlib.h>

//Creating a node
//Defining a node
struct node{
    //Contains two parts, data type and pointer
    //Data type of current node
    int data;
    //Pointer would store address of next node
    struct node *next;
};

int main() {
// Creating a "Head" pointer
    //*head is storing the address of node:when creating a new node, the address of that node would be stored in *newnode.
    struct node *head, *newnode, *temp;

    head = 0;// Assuming head has no value

    //malloc returns a pointer to the starting address of the memory block
    //The address returned by malloc would be stored in newnode
    //malloc returns void pointer, so it would be typecasted
    newnode = (struct node*)malloc(sizeof(struct node));//How much to be allocated.

    printf("Enter data");
    scanf("%d", &newnode -> data);//how to access members of a list using pointer

    newnode -> next = 0;

    if(head == 0){
        head = temp = newnode;}
    else{
        temp -> next = newnode;
        temp = newnode;
    }
    int choice;
    printf("\nDo you want to continue(0,1) ?");
    scanf("%d", &choice);

    while (choice){
        newnode = (struct node*)malloc(sizeof(struct node));
    }
    temp = head;
    while (temp != 0){
        printf("%d", temp->data);
        temp = temp -> next;
    }


}