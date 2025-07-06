// Author: Marcus Timothy V. Ramos
// Author: Keann Colin T. Lusong
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

void merge(Point points[], int left, int mid, int right, Point anchor) {

    int i, j, k;

    int lSize = mid - left + 1;
    int rSize = right - mid;

    Point *L = (Point *)malloc(lSize * sizeof(Point));
    Point *R = (Point *)malloc(rSize * sizeof(Point));

    for (i = 0; i < lSize; i++) {
        L[i] = points[left + i];
    }
    for (j = 0; j < rSize; j++) {
        R[j] = points[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < lSize && j < rSize) {
        if (polarAngle(anchor, L[i]) <= polarAngle(anchor, R[j])) {
            points[k] = L[i];
            i++;
        } 
        
        else {
            points[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < lSize) {
        points[k] = L[i];
        i++;
        k++;
    }

    while (j < rSize) {
        points[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Point points[], int left, int right, Point anchor) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(points, left, mid, anchor);
        mergeSort(points, mid + 1, right, anchor);

        merge(points, left, mid, right, anchor);
    }
}

void sortPoints(Point points[], int n) {
    Point anchor = anchorPoint(points, n);
    mergeSort(points, 0, n - 1, anchor);
}