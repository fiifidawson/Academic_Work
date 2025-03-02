//
// Created by adlercohen on 1/10/2023.
//
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Inserts a new node with the given data value between the two nodes prev and next
// in a linked list.
void insert_node(struct node *prev, struct node *next) {
    // Allocate memory for the new node
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        // Error: memory allocation failed
        return;
    }

    // Get the data value for the new node from the user
    printf("Enter data value for new node: ");
    scanf("%d", &new_node->data);

    // Set the next pointer of the new node to point to the node next
    new_node->next = next;

    // Set the next pointer of the node prev to point to the new node
    prev->next = new_node;
}

int main(void) {
    // ...
    return 0;
}




