//
// Created by adlercohen on 12/11/2022.
//
#include <stdio.h>

#define MAX_SIZE 10  // Maximum size of the queue

// Declaration of the queue
int queue[MAX_SIZE];
int front = 0, rear = 0;

// Function to add an element to the queue
void enqueue(int value){
    if (rear == MAX_SIZE){
        printf("Queue is full\n");
        return;
    }
    queue[rear] = value;
    rear++;
}

// Function to remove an element from the queue
int dequeue(){
    if (front == rear){
        printf("Queue is empty\n");
        return -1;
    }
    int value = queue[front];
    front++;

    return value;
}

// Function to print the queue
void print_queue(){
    printf("Queue: ");
    for (int i = front; i < rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main function
int main(){
    // Adding elements to the queue
    int n;
    printf("Enter the number of elements to add to the queue: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++){
        int element;
        scanf("%d", &element);
        enqueue(element);
    }

    // Printing the queue
    print_queue();

    // Removing elements from the queue
    printf("Enter the number of elements to dequeue: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        printf("Dequeued: %d\n", dequeue());
    }

    // Printing the queue after removal
    print_queue();

    return 0;
}
