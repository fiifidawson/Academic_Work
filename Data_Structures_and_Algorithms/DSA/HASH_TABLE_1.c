//
// Created by adlercohen on 1/15/2023.
//
#include <stdio.h>
#include <stdlib.h>

#define SIZE 20 // Define the size of the hash table

// Node structure to store key-value pairs
struct Node {
    int key;
    int value;
    struct Node* next; // pointer to the next node in case of collision
};

struct Node* hashTable[SIZE]; // Declare the hash table as an array of Node pointers

// Initialize the hash table
void init() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }
}

// Hash function to calculate the index of a key
int hashCode(int key) {
    return key % SIZE;
}

// Insert a key-value pair in the hash table
void insert(int key, int value) {
    int index = hashCode(key); // Get the index of the key
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node)); // Allocate memory for the new node
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[index]; // Insert the new node at the beginning of the list
    hashTable[index] = newNode;
}

// Search for a value in the hash table
int search(int key) {
    int index = hashCode(key); // Get the index of the key
    struct Node* current = hashTable[index]; // Start from the first node at the index
    while (current != NULL) {
        if (current->key == key) {
            return current->value; // Return the value if the key is found
        }
        current = current->next; // Move to the next node in case of collision
    }
    return -1; // Return -1 if the key is not found
}

int main() {
    init();
    insert(1, 10);
    insert(2, 20);
    insert(21, 210);
    insert(3, 30);
    insert(42, 420);
    printf("%d\n", search(21));
    printf("%d\n", search(1));
    printf("%d\n", search(3));
    printf("%d\n", search(42));
    printf("%d\n", search(7));
    return 0;
}
