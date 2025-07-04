#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

double polarAngle(Point p0, Point p);
Point anchorPoint(Point *points, int n);
int compare(const void *a, const void *b, void *p0);
void merge(Point *points, int left, int mid, int right, Point anchor);
void mergeSort(Point *points, int left, int right, Point anchor);
void sortPoints(Point *points, int n);
