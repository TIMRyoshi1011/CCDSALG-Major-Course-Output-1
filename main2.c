// Author: Marcus Timothy V. Ramos
#include "graham_scan2.c" 

typedef char String[100];

int main(){
    int n;
    double x, y;
    Point points[MAX];
    String inputName;
    String outputName;
    struct Stack S;
    FILE *fastAlg;

    printf("Input Filename: ");
    scanf("%s", inputName);

    fastAlg = fopen(inputName, "r");

    if (fastAlg == NULL) {
        printf("\nFile Not Found!");
    }

    else {
        printf("Output Filename: ");
        scanf("%s", outputName);

        fscanf(fastAlg, "%d", &n);

        for(int i = 0; i < n && fscanf(fastAlg, "%lf %lf", &x, &y) == 2; i++) {
            points[i].x = x;
            points[i].y = y;
        }

        printf("\nElapsed Time:\n");
        convexHull(points, n, &S);

        fastAlg = fopen(outputName, "w");

        fprintf(fastAlg, "%d\n", S.top + 1);

        for (int i = 0; i <= S.top; i++) {
            Point p = toSortPoints(S.points[i]);
            fprintf(fastAlg, "%9lf %10lf\n", p.x, p.y);
        }

        printf("\nData successfully written to %s", outputName);
    }
    
    fclose(fastAlg);

    return 0;
}