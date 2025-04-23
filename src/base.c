#include "../include/base.h"

void initStack(Stack* stack) {
    stack->top = NULL;
    stack->size = 0;
}

void push(Stack* stack, Tenant tenant) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = tenant;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

void pop(Stack* stack, Tenant* tenant) {
    if (stack->top == NULL) return;

    StackNode* temp = stack->top;
    *tenant = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;
}

int isEmpty(const Stack* stack) {
    return stack->top == NULL;
}

void reverseStack(Stack* stack) {
    Stack temp = { NULL, 0 };
    Tenant tenant;

    while (!isEmpty(stack)) {
        pop(stack, &tenant);
        push(&temp, tenant);
    }

    *stack = temp;
}