// Author: Marcus Timothy V. Ramos
#include "sort.c"
#include "stack.c"
#include <time.h>
print
double getDirection(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

Points toStackPoints(Point srt) {
    Points stk;
    stk.a = srt.x;
    stk.b = srt.y;
    return stk;
}

Point toSortPoints(Points stk) {
    Point srt;
    srt.x = stk.a;
    srt.y = stk.b;
    return srt;
}

void convexHull(Point points[], int n, struct Stack *S) {
    clock_t start; 
    clock_t end;  

    start = clock();  

    if (n < 3) {
        printf("Convex hull not possible if n < 3.\n");
    }

    else {
        
        bubbleSort(points, n);

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
    printf("%6ld %15lf\n", (long int)n, (double)(end - start)); 
}
