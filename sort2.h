// Author: Marcus Timothy V. Ramos
// Author: Keann Colin T. Lusong
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct { // Points structure to hold coordinates for the stack
    double x;
    double y;
} Point;

// Function prototypes for merge sorting operations
double polarAngle(Point p0, Point p);
Point anchorPoint(Point points[], int n);
void merge(Point points[], int left, int mid, int right, Point anchor);
void mergeSort(Point points[], int left, int right, Point anchor);
void sortPoints(Point points[], int n);
