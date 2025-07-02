#include "stack.h"

void create(struct Stack *S) {
    S->top = -1;
}

int isFull(struct Stack *S) {
    return S->top == MAX - 1; 
}

int isEmpty(struct Stack *S) {
    return S->top == -1;
}

void push(struct Stack *S, double elem) {
    if (!isFull(S)) {
        (S->top)++;
        S->points[S->top] = elem; 
    }

    else
        printf("Stack Overflow, Cannot push %.1lf element\n", elem);
}

double pop(struct Stack *S) {
    if (!isEmpty(S)) {
        double temp = S->points[S->top];
        S->top--;
        return temp;
    }

    else {
        printf("Stack Underflow\n");
        return -1; 
    }
}

double top(struct Stack *S) {
    if (!isEmpty(S)) {
        return S->points[S->top]; 
    }

    else {
        printf("Stack is empty. No top element.\n");
        return -1; 
    }
}

double nextToTop(struct Stack *S) {
    if (S->top >= 1) {
        return S->points[S->top - 1];
    }
    
    else {
        printf("Not enough elements in the stack. No next-to-top element.\n");
        return -1; 
    }
}
