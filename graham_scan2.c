// Author: Marcus Timothy V. Ramos
#include "sort2.c"
#include "stack.c"
#include <time.h>

/*  Function to calculate the direction of the turn using cross product
    @param a - first point
    @param b - second point
    @param c - third point
    @return positive if counter-clockwise, negative if clockwise, zero if collinear
*/
double getDirection(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

/*  Function to convert Point from sort.h to Points from stack.h structure
    @param srt - Point from the structure from sort.h
    @return stk - Points from the structure from stack.h
*/
Points toStackPoints(Point srt) {
    Points stk;
    stk.a = srt.x;
    stk.b = srt.y;
    return stk;
}

/*  Function to convert Points from stack.h structure to Point from sort.h structure 
    @param stk - Points from the structure from stack.h
    @return srt - Point from the structure from sort.h
*/
Point toSortPoints(Points stk) {
    Point srt;
    srt.x = stk.a;
    srt.y = stk.b;
    return srt;
}

/*  Function to compute the convex hull of a set of points using Graham's scan algorithm
    @param points - array of points that were inputted
    @param n - number of elements in the array
    @param S - pointer to the stack structure to hold the convex hull points
*/
void convexHull(Point points[], int n, struct Stack *S) {
    clock_t start; 
    clock_t end;  

    start = clock(); 

    if (n < 3) {
        printf("Convex hull not possible if n < 3.\n");
    }

    else {

        sortPoints(points, n);

        create(S);
        push(S, toStackPoints(points[0]));
        push(S, toStackPoints(points[1]));
        push(S, toStackPoints(points[2]));

        for (int i = 3; i < n; i++) {
            while (!isEmpty(S)) {
                Point top1 = toSortPoints(top(S));
                Point top2 = toSortPoints(nextToTop(S));
                if (getDirection(top2, top1, points[i]) > 0) 
                    break; 
                pop(S); 
            }
            push(S, toStackPoints(points[i]));
        }
    }
    end = clock(); 
    printf("%6d %15lf\n", n, (double)(end - start)); 
}
