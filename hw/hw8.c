#include <stdio.h>
#include <stdlib.h>

double** allocate_matrix(int n, int m) {
    double **matrix = malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        matrix[i] = malloc(m * sizeof(double));
    }
    return matrix;
}

void free_matrix(double **matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void input_matrix(double **matrix, int n, int m) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
}

void output_matrix(double **matrix, int n, int m) {
    printf("Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

void move_max_to_end(double **matrix, int n, int m) {
    for (int j = 0; j < m; j++) {
        double max = matrix[0][j];
        int max_row = 0;
        for (int i = 1; i < n; i++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
                max_row = i;
            }
        }
        if (max_row != n - 1) {
            matrix[max_row][j] = matrix[n - 1][j];
            matrix[n - 1][j] = max;
        }
    }
}

int main(){
//8_14
    int n, m;
    printf("Enter the number of rows (n): ");
    scanf("%d", &n);
    printf("Enter the number of columns (m): ");
    scanf("%d", &m);
    double **matrix = allocate_matrix(n, m);
    input_matrix(matrix, n, m);
    output_matrix(matrix, n, m);
    move_max_to_end(matrix, n, m);
    printf("Modified matrix:\n");
    output_matrix(matrix, n, m);
    free_matrix(matrix, n);

    return 0;
}
