#include "sort.h"

double polarAngle(Point p0, Point p) {
    return atan2(p.y - p0.y, p.x - p0.x);
}

Point anchorPoint(Point points[], int n) {
    int i;
    Point anchor = points[0];
    for (i = 1; i < n; i++) {
        if (points[i].y < anchor.y || (points[i].y == anchor.y && points[i].x < anchor.x)) {
            anchor = points[i];
        }
    }
    return anchor;
}

void bubbleSort(Point points[], int n) {
    int i, j;
    Point anchor = anchorPoint(points, n); 
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            if (polarAngle(anchor, points[j]) > polarAngle(anchor, points[j + 1])) {
                Point temp = points[j];
                points[j] = points[j+1];
                points[j+1] = temp;
            }
        }
    }
}
