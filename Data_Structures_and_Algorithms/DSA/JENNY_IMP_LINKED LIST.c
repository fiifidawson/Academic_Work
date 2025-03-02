//
// Created by adlercohen on 1/9/2023.
//

#include <stdio.h>
#include <stdlib.h>

//Define the node
struct node{
    int data;//for the data
    struct node *next; //storing the address of the created node
};

//Function to create a new node
struct node *create_node(int data){
    //Allocate memory for the new node
    struct node *new_node = malloc(sizeof(struct node));

    //Setting data for new node
    new_node->data = data;
    new_node-> next = NULL;

    return new_node;
}

// Function to insert a node at the head of a list
void insert_at_head(struct node **head, int data){

    //creating a new node
    struct node *new_node = create_node(data);

    // If the list is empty, set the head to the new node
    if (*head == NULL){
        *head == new_node;
        return;
    }

    // Find the last node in the list
    struct node *temp = *head;
    while (temp->next != NULL){
        temp = temp->next;
    }

    //Set the next pointer of the last node to the new node
    temp->next = new_node;
}

// Function to print the list
void print_list(struct node *head) {
    printf("List: ");

    // Print each node's data
    while (head != NULL) {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");

}
