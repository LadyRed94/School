#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

int **genRandomMatrix(int n, int max) {
    int i, j;
    int **mat = malloc(n * sizeof(int *));

    for (i = 0; i < n; i++) {
        mat[i] = malloc(n * sizeof(int));

        for (j = 0; j < n; j++) {
            mat[i][j] = 1 + rand() % max;
        }
    }

    return mat;
}

void free_all(int **mat, int n) {
    int i;

    for (i = 0; i < n; i++) {
        free(mat[i]);
    }

    free(mat);
}

float averageMat_v1(int **mat, int n) {
    int i, j, total = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            // Note indexing: [i][j]
            total += mat[i][j];
        }
    }

    return (float) total / (n * n);
}

float averageMat_v2(int **mat, int n) {
    int i, j, total = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            // Note indexing: [j][i]
            total += mat[j][i];
        }
    }

    return (float) total / (n * n);
}

int main(int argc, char **argv) {
    int i, n;
    int **matrix;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <n>\n", argv[0]);
        fprintf(stderr, "where <n> is the dimension of the matrix\n");
        return 1;
    }

    n = strtol(argv[1], NULL, 10);
    srand(time(NULL));
    matrix = genRandomMatrix(n, 100);


    printf("%ld : first row clock\n", clock());
    averageMat_v1(matrix, n);
    printf("%ld : second row clock\n", clock());
    printf("\n");
    printf("%ld : first col clock\n", clock());
    averageMat_v2(matrix, n);
    printf("%ld : second col clock\n", clock());
    printf("\n");
    //printf("%ld       %f\n%ld\n", clock(), averageMat_v1(matrix, n), clock());
    printf("\n");
    //printf("%ld       %f\n%ld\n", clock(), averageMat_v2(matrix, n), clock());
    //printf("%ld\n", clock());
    //averageMat_v2(n, 100);
    //printf("%d\n", **matrix);
    //printf("%ld\n", clock());

    free_all(matrix, n);
    return 0;
}
