// Author: Marcus Timothy V. Ramos
#include "graham_scan1.c" 

typedef char String[100];

int main(){
    int n;
    double x, y;
    Point points[MAX];
    String inputName;
    String outputName;
    struct Stack S;
    FILE *slowAlg;

    printf("Input Filename: ");
    scanf("%s", inputName);

    slowAlg = fopen(inputName, "r");

    if (slowAlg == NULL) {
        printf("\nFile Not Found!");
    }

    else {
        printf("Output Filename: ");
        scanf("%s", outputName);

        fscanf(slowAlg, "%d", &n);

        for(int i = 0; i < n && fscanf(slowAlg, "%lf %lf", &x, &y) == 2; i++) {
            points[i].x = x;
            points[i].y = y;
        }

        printf("\nElapsed Time:\n");
        convexHull(points, n, &S);

        slowAlg = fopen(outputName, "w");

        fprintf(slowAlg, "%d\n", S.top + 1);

        for (int i = 0; i <= S.top; i++) {
            Point p = toSortPoints(S.points[i]);
            fprintf(slowAlg, "%9lf %10lf\n", p.x, p.y);
        }

        printf("\nData successfully written to %s", outputName);
    }
    
    fclose(slowAlg);

    return 0;
}
