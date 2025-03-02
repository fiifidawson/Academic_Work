//
// Created by adlercohen on 1/3/2023.
//
#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node *create_node(int data) {
    // Allocate memory for the new node
    struct node *new_node = malloc(sizeof(struct node));

    // Set the data of the new node
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

// Function to insert a new node at the head of the list
void insert_at_head(struct node **head, int data) {
    // Create a new node
    struct node *new_node = create_node(data);

    // Set the next pointer of the new node to the current head
    new_node->next = *head;

    // Set the head to the new node
    *head = new_node;
}

// Function to insert a new node at the tail of the list
void insert_at_tail(struct node **head, int data) {
    // Create a new node
    struct node *new_node = create_node(data);

    // If the list is empty, set the head to the new node
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    // Find the last node in the list
    struct node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Set the next pointer of the last node to the new node
    temp->next = new_node;
}

// Function to print the list
void print_list(struct node *head) {
    printf("List: ");

    // Print each node's data
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

int main(void) {
    // Create an empty list
    struct node *head = NULL;

    char input[10];
    int data;

    while (1) {
        // Print menu
        printf("Enter a command (i/d/p/q):\n");
        printf("  (i)nsert at head\n");
        printf("  (d)elete from head\n");
        printf("  (p)rint list\n");
        printf("  (q)uit\n");

        scanf("%s", input);

        if (input[0] == 'i') {
            printf("Enter a number to insert: ");
            scanf("%d", &data);
            insert_at_head(&head, data);
        } else if (input[0] == 'd') {
            if (head == NULL) {
                printf("Error: list is empty\n");
            } else {
                struct node *temp = head;
                head = head->next;
                free(temp);
            }
        } else if (input[0] == 'p') {
            print_list(head);
        } else if (input[0] == 'q') {
            break;
        } else {
            printf("Invalid input\n");
        }
    }

    return 0;
}
