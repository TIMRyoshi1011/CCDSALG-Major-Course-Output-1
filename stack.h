// Author: Marcus Timothy V. Ramos, S12

#include <stdio.h>
#include <stdlib.h>

#define MAX 32768

struct Stack {
    double points[MAX];
    int top;
};

void create(struct Stack *S);
int isFull(struct Stack *S);
int isEmpty(struct Stack *S);
void push(struct Stack *S, double elem);
double pop(struct Stack *S);
double top(struct Stack *S);
double nextToTop(struct Stack *S);
