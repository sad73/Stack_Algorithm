#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_CAPACITY 100  // You can change this to any size you want

// Structure definition for Stack
typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;

// Function to initialize the stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (int*)malloc(sizeof(int) * capacity);
    return stack;
}

// Check if the stack is full
bool isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Push an element onto the stack
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->data[++stack->top] = value;
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;  // Error value
    }
    return stack->data[stack->top--];
}

// Peek at the top element of the stack
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is Empty\n");
        return -1;
    }
    return stack->data[stack->top];
}

// Free stack memory
void destroyStack(Stack* stack) {
    free(stack->data);
    free(stack);
}

// Example usage
int main() {
    Stack* myStack = createStack(STACK_CAPACITY);

    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);

    printf("Top element: %d\n", peek(myStack));

    printf("Popped: %d\n", pop(myStack));
    printf("Popped: %d\n", pop(myStack));

    destroyStack(myStack);
    return 0;
}
