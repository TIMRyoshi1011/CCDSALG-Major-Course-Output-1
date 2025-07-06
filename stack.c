// Author: Marcus Timothy V. Ramos
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

void push(struct Stack *S, Points elem) {
    if (!isFull(S)) {
        (S->top)++;
        S->points[S->top] = elem; 
    }

    else
        printf("Stack Overflow\n");
}

Points pop(struct Stack *S) {
    if (!isEmpty(S)) {
        Points temp = S->points[S->top];
        S->top--;
        return temp;
    }

    else {
        printf("Stack Underflow\n");
        return (Points){-1, -1}; 
    }
}

Points top(struct Stack *S) {
    if (!isEmpty(S)) {
        return S->points[S->top]; 
    }

    else {
        return (Points){-1, -1}; 
    }
}

Points nextToTop(struct Stack *S) {
    if (S->top >= 1) {
        return S->points[S->top - 1];
    }
    
    else {
        return (Points){-1, -1}; 
    }
}
