#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct { // Points structure to hold coordinates for the stack
    double x;
    double y;
} Point;

// Function prototypes for bubble sorting operations
double polarAngle(Point p0, Point p);
Point anchorPoint(Point points[], int n);
void bubbleSort(Point points[], int n);
