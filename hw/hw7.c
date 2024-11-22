
//710a
#include <stdio.h>
#include <stdlib.h>


int input_arr_odd(double **arr, size_t n, size_t *filled) {
    *arr = malloc(n * sizeof(**arr));
    if (!(*arr)) {
        return 1;
    }
    *filled = 0;
    for (size_t i = 0; i < n; i++) {
        double d;
        scanf("%lf", &d);
        if ((int)d % 2 != 0) {
            (*arr)[*filled] = d;
            (*filled)++;
        }
    }
    return 0;
}


void output_a(const double *arr, size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("%lf, ", arr[i]);
    }
    printf("\n");
}

double minimum(const double *arr,size_t n){
    double min = arr[0];
    for (int i = 1; i < n; i++){
        if (min > arr[i]){min = arr[i];}}
    return min;
}

void task_8g() {
    unsigned n;
    double *a = NULL;
    size_t filled = 0;
    printf("n = ");
    scanf("%u", &n);
    input_arr_odd(&a,n,&filled);
    output_a(a, filled);
    printf("%lf", minimum(a,filled));
    free(a);}


int input_arr_mul(double **arr, size_t n) {
    *arr = malloc(n * sizeof(**arr));
    if (!(*arr)) {
        return 1;
    }
    for (size_t i = 0; i < n; i++) {
        double d;
        scanf("%lf", &d);
        (*arr)[i] = (i + 1) * d;
    }
    return 0;
}


void task_10a() {
    unsigned n;
    double *a = NULL;
    printf("n = ");
    scanf("%u", &n);
    input_arr_mul(&a, n)
    output_a(a, n);
    printf("%lf\n", minimum(a, n));

    free(a);
}

int main() {
    task_10a();
    task_8g();
}
