//
// Created by adlercohen on 12/9/2022.
//
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

/* Function to delete a node in a linked list after the given node */
void deleteNodeAfter(struct Node *node){
    /* Check if the node is NULL or if the node has no next node */
    if (node == NULL || node->next == NULL)
        return;

    /* Store a pointer to the node after the given node */
    struct Node *temp = node->next;

    /* Set the next pointer of the given node to point to the node after the next node */
    node->next = temp->next;

    /* Free the memory occupied by the next node */
    free(temp);
}

/* Function to print the elements of a linked list */
void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

/* Function to create a linked list by reading values from the user */
struct Node *createList(void)
{
    struct Node *head = NULL;
    struct Node *tail = NULL;

    int data;

    printf("Enter values for the linked list (enter -1 to stop):\n");

    while (1)
    {
        scanf("%d", &data);

        if (data == -1)
            break;

        struct Node *newNode = malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

int main(void){
    /* Create the linked list by reading values from the user */
    struct Node *head = createList();

    /* Print the linked list before deleting the node */
    printf("Original list: ");
    printList(head);

    /* Read the position of the node after which a node should be deleted */
    int position;
    printf("Enter the position of the node after which you want to delete a node: ");
    scanf("%d", &position);

    /* Get a pointer to the node at the given position */
    struct Node *node = head;
    int i;
    for (i = 0; i < position; i++)
    {
        if (node == NULL)
        {
            printf("Invalid position!\n");
            return 0;
        }

        node = node->next;
    }

    /* Delete the node after the node at the given position */
    deleteNodeAfter(node);

    /* Print the linked list after deleting the node */
    printf("Modified list: ");
    printList(head);

    return 0;
}
