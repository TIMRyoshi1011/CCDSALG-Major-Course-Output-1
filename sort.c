// Author: Marcus Timothy V. Ramos
// Author: Byron David C. Hung
#include "sort.h"

/*  function to calculate the polar angle using atan2
    @param p0 - the reference point
    @param p - the point to calculate the angle to
    @return the polar angle in radians
*/ 
double polarAngle(Point p0, Point p) {
    return atan2(p.y - p0.y, p.x - p0.x);
}

/*  function to find the anchor point 
    @param points - array of points
    @param n - number of points in the array
    @return anchor point
*/
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

/*  bubble sort algotithm
    @param points - array of points to be sorted
    @param n - number of elements in the array
*/
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