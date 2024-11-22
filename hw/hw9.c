#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double calculate_mean(double *arr, size_t n) {
    double sum = 0.0;
    for (size_t i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

double calculate_variance(double *arr, size_t n, double mean) {
    double variance = 0.0;
    for (size_t i = 0; i < n; i++) {
        variance += (arr[i] - mean) * (arr[i] - mean);
    }
    return variance / n;
}

int input_vector(double **arr, size_t n) {
    *arr = malloc(n * sizeof(**arr));
    if (!(*arr)) {
        return 1;
    }
    for (size_t i = 0; i < n; i++) {
        printf("Введіть елемент %zu: ", i + 1);
        scanf("%lf", &(*arr)[i]);
    }
    return 0;
}

void task_8() {
    size_t n;
    double *vector;
    char choice;

    printf("Введіть розмірність вектора: ");
    scanf("%zu", &n);
    input_vector(&vector, n)
    double mean = calculate_mean(vector, n);
    printf("Середнє арифметичне: %.6lf\n", mean);
    double variance = calculate_variance(vector, n, mean);
    printf("Дисперсія: %.6lf\n", variance);
    free(vector);

}




double** create_matrix(size_t rows, size_t cols) {
    double** matrix = malloc(rows * sizeof(double*));
    if (!matrix) {
        printf("Помилка виділення пам'яті!\n");
        exit(1);
    }

    for (size_t i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(double));
        if (!matrix[i]) {
            printf("Помилка виділення пам'яті!\n");
            exit(1);
        }
    }
    return matrix;
}


void fill_matrix_random(double** matrix, size_t rows, size_t cols) {
    srand(time(NULL));
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}


void fill_matrix_from_console(double** matrix, size_t rows, size_t cols) {
    printf("Введіть елементи матриці (%zux%zu):\n", rows, cols);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            printf("matrix[%zu][%zu] = ", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }
}


void print_matrix(double** matrix, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            printf("%.2lf\t", matrix[i][j]);
        }
        printf("\n");
    }
}


size_t find_column_with_max_sum(double** matrix, size_t rows, size_t cols) {
    double max_sum = -1;
    size_t max_col = 0;

    for (size_t j = 0; j < cols; j++) {
        double sum = 0;
        for (size_t i = 0; i < rows; i++) {
            sum += matrix[i][j];
        }

        if (sum > max_sum) {
            max_sum = sum;
            max_col = j;
        }
    }

    return max_col;
}

double** add_column(double** matrix, size_t* rows, size_t* cols, size_t max_col) {
    *cols += 1;
    matrix = realloc(matrix, (*rows) * sizeof(double*));

    for (size_t i = 0; i < *rows; i++) {
        matrix[i] = realloc(matrix[i], (*cols) * sizeof(double));

        for (size_t j = *cols - 1; j > max_col + 1; j--) {
            matrix[i][j] = matrix[i][j - 1];
        }

        matrix[i][max_col + 1] = 0;
    }

    return matrix;
}

void free_matrix(double** matrix, size_t rows) {
    for (size_t i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void task_9ch {
    size_t n, m;
    int choice;
    printf("Введіть кількість рядків (N): ");
    scanf("%zu", &n);
    printf("Введіть кількість стовпців (M): ");
    scanf("%zu", &m);
    double** matrix = create_matrix(n, m);
    printf("Оберіть спосіб заповнення матриці:\n");
    printf("1. Випадкові числа\n");
    printf("2. Ввести з консолі\n");
    scanf("%d", &choice);

    if (choice == 1) {
        fill_matrix_random(matrix, n, m);
    } else if (choice == 2) {
        fill_matrix_from_console(matrix, n, m);
    } else {
        printf("Невірний вибір!\n");
        free_matrix(matrix, n);
        return 1;
    }

    printf("Початкова матриця:\n");
    print_matrix(matrix, n, m);
    size_t max_col = find_column_with_max_sum(matrix, n, m);
    printf("Найбільша сума елементів у стовпці %zu\n", max_col + 1);
    matrix = add_column(matrix, &n, &m, max_col);
    printf("Матриця після додавання стовпця:\n");
    print_matrix(matrix, n, m);

    free_matrix(matrix, n);
}

int main(){
    task_8();
    task_9ch();
}