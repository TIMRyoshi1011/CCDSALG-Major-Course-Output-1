// Author: Marcus Timothy V. Ramos
#include "stack.h"

/*  create stack function
    @param S - pointer to the stack structure
*/
void create(struct Stack *S) {
    S->top = -1;
}

/*  checks if stack is full
    @param S - pointer to the stack structure
    @return 1 if full, 0 otherwise
*/
int isFull(struct Stack *S) {
    return S->top == MAX - 1; 
}
/* checks if stack is empty
    @param S - pointer to the stack structure
    @return 1 if empty, 0 otherwise
*/
int isEmpty(struct Stack *S) {
    return S->top == -1;
}
/*  push function in stack
    @param S - pointer to the stack structure
    @param elem - Points element to be pushed onto the stack
*/
void push(struct Stack *S, Points elem) {
    if (!isFull(S)) {
        (S->top)++;
        S->points[S->top] = elem; 
    }

    else
        printf("Stack Overflow\n");
}

/*  pop function in stack
    @param S - pointer to the stack structure
    @return Points element popped from the stack
*/
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

/*  top function in stack
    @param S - pointer to the stack structure
    @return Points element at the top of the stack
*/
Points top(struct Stack *S) {
    if (!isEmpty(S)) {
        return S->points[S->top]; 
    }

    else {
        return (Points){-1, -1}; 
    }
}

/*  nextToTop function in stack (returns the second element from the top)
    @param S - pointer to the stack structure
    @return Points element next to the top of the stack
*/
Points nextToTop(struct Stack *S) {
    if (S->top >= 1) {
        return S->points[S->top - 1];
    }
    
    else {
        return (Points){-1, -1}; 
    }
}
