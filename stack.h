// Author: Marcus Timothy V. Ramos, S12
#include <stdio.h>
#include <stdlib.h>

#define MAX 32768

typedef struct { // Points structure to hold coordinates for the stack
    double a;
    double b;
} Points;

struct Stack { // Stack structure to hold Points and the top index
    Points points[MAX];
    int top;
};

// Function prototypes for stack operations
void create(struct Stack *S);
int isFull(struct Stack *S);
int isEmpty(struct Stack *S);
void push(struct Stack *S, Points elem);
Points pop(struct Stack *S);
Points top(struct Stack *S);
Points nextToTop(struct Stack *S);
