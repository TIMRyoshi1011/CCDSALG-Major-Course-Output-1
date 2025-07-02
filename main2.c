// Author: Marcus Timothy V. Ramos, S12 

#include "stack.h"
// insert headers (for fast algo) here

typedef char String[100];

int main(){
    int n;
    double x, y;
    double points[MAX][2];
    String inputName;
    String outputName;
    FILE *grScan;

    printf("Input Filename: ");
    scanf("%s", inputName);

    grScan = fopen(inputName, "r");

    if (grScan == NULL) {
        printf("\nFile Not Found!");
    }

    else {
        printf("Output Filename: ");
        scanf("%s", outputName);

        fscanf(grScan, "%d", &n);

        for(int i = 0; i < n && fscanf(grScan, "%lf %lf", &x, &y) == 2; i++) {
            points[i][0] = x;
            points[i][1] = y;
        }

        // insert graham scan (fast) algorithm here

        grScan = fopen(outputName, "w");

        // insert code to write the output to the file

        printf("\nData successfully written to %s", outputName);
    }
    
    fclose(grScan);

    return 0;
}
