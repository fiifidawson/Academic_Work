//
// Created by adlercohen on 12/11/2022.
//
#include <stdio.h>
#include <stdlib.h>

// Define a node struct
struct node {
    int data;
    struct node *next;
};

// Function to create a new node and return a pointer to it
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the list
void appendNode(struct node** head, int data) {
    // Create a new node
    struct node* newNode = createNode(data);

    // If the list is empty, set the new node as the head of the list
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Otherwise, traverse the list to find the last node
    struct node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Append the new node to the end of the list
    current->next = newNode;
}

// Function to print the list
void printList(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create an empty list
    struct node* head = NULL;

    // Prompt the user to enter some data to add to the list
    printf("Enter some numbers to add to the list (enter -1 to stop):\n");

    int data;
    scanf("%d", &data);
    while (data != -1) {
        // Add the data to the list
        appendNode(&head, data);

        // Prompt the user for more data
        scanf("%d", &data);
    }

    // Print the list
    printf("The list contains: ");
    printList(head);

    return 0;
}
