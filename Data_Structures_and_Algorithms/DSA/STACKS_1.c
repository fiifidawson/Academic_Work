#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = 0;

void push(int value) {
    if (top == MAX_SIZE ) {
        printf("Error: Stack overflow\n");
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed to stack\n", value);
    }
}

void pop() {
    if (top == -1) {
        printf("Error: Stack underflow\n");
    } else {
        printf("%d popped from stack\n", stack[top]);
        top--;
    }
}

void peek() {
    if (top == 0) {
        printf("Error: Stack is empty\n");
    } else {
        printf("Top element is %d\n", stack[top]);
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to be pushed: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
