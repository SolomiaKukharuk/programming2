#include <stdio.h>
#include <math.h>

double sum_sqrt(const double *arr,int n) {
    double sum =0;
    double *beg = arr;
    double *end = arr + n;
    for(beg <= end){
        double n_arr = *beg;
        sum+= pow(n_arr,2);
    }
}

void task_1(){
    unsigned n;
    printf("n =");
    scanf("%u",&n);
    double *arr;
    arr = (double*)malloc(arr*,sizeof(*arr));
    input_array(arr,n);
    double res = sum_sqrt(arr,n);
    printf("%lf",res);
    free(arr);
}

typedef struckt Stack{
    int data;
    Stack *addr;
} Stack;

void task_2(){
    Stack S;
    int x; int a[];
    int i = 0;
    S.add = NULL;
    S.data = 0;
    do{
        Stack t;
        scanf("%d",&x);
        t.data = x;
        t.addr = malloc(sizeof(Stack));
        S = t;
        t.addr = &S;
    }while(x!=0);
    Stack t1;
    while(S.addr != NULL){
        int x = S.data;
        t1 = *(S.addr);
    }
}
void output_vec(const double *arr, size_t n){
    for (size_t i = 0; i < n;i++){
        printf("%lf,",arr[i]);
    }
    printf("\n");
}

int input_vec(double *arr,size_t n){
    arr = malloc(n * sizeof(*arr));
    if (!arr){
        return 1;
    }
    for(size_t i = 0; i < n; i++){
        scanf("%lf",&arr[i]);
    }
    return 0;
}



int subt_vec(const double *ar1,const double *ar2, double *ar3, size_t n){
    if(ar1 == NULL || ar2 == NULL)
    {return 1;}
    ar3 = (double*)malloc(n * sizeof(*ar3);
    for (size_t i = 0;i<n;i++){
        ar[i] = ar1[i] - ar[i]
    }
    return 0;
}

void delete_vec(double *arr){
    if(arr){
        free(arr);}
}

void task_3(){
    size_t n;
    double *v1,*v2,*v3;
    printf ("n:");
    scanf("%zu",&n);
    input_vec(v1,n);
    input_vec(v2,n);
    subt_vec(v1,v2,v3,n);
    output_vec(v3,n);
    delete_vec(v1);
    delete_vec(v2);
    delete_vec(v3);
}
void output_mart2(const double **matr, size_t n){
    for (size_t i=0; i < n; i++){
        for (size_t j=0; j < n; j++){
            printf("%lf ", matr[i][j]);
        }
        printf("\n");
    }
}

void input_matr2(double **matr, size_t n){
    for(size_t i=0; i < n; i++){
        for (size_t j=0; j< n; j++){
            printf("matrix[%zu][%zu] = ", i, j);
            scanf("%lf", &matr[i][j]);
        }
    }
}

int create_matr2(double ***matr, size_t n){
    *matr = (double**)(calloc(n, sizeof **matr));
    if (!*matr){
        return 1;
    }
    for(size_t i=0; i < n; i++){
        (*matr)[i] = (double*)calloc(n, sizeof(double));
    }
    return 0;
}

void delete_matr2(double **matr, size_t n){
    if (matr != NULL) {
        free(matr);
    }
}

int mult_matr2(const double **matr1, const double **matr2, double **matr3, size_t n){
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            matr3[i][j] = 0;
            for (size_t k = 0; k < n; k++) {
                matr3[i][j] += matr1[i][k] * matr2[k][j];
            }
        }
    }
    return 0;
}

void task4_2(){
    size_t n;
    printf("n = ");
    scanf("%zu", &n);
    double **matr1, **matr2, **matr3;

    create_matr2(&matr1, n);
    create_matr2(&matr2, n);
    create_matr2(&matr3, n);

    input_matr2(matr1, n);
    input_matr2(matr2, n);

    mult_matr2((const double**)matr1, (const double**)matr2, matr3, n);
    printf("Resultant matrix: \n");
    output_mart2((const double**)matr3, n);

    delete_matr2(matr1, n);
    delete_matr2(matr2, n);
    delete_matr2(matr3, n);
}

// Функції для лінійного масиву

void output_mart1(const double *matr, size_t n){
    for (size_t i=0; i < n; i++){
        for (size_t j=0; j < n; j++){
            printf("%lf ", matr[i * n + j]);
        }
        printf("\n");
    }
}

void input_matr1(double *matr, size_t n){
    for (size_t i=0; i < n; i++){
        for (size_t j=0; j < n; j++){
            printf("matrix[%zu][%zu] = ", i, j);
            scanf("%lf", &matr[i * n + j]);
        }
    }
}

int create_matr1(double **matr, size_t n){
    *matr = (double*)(calloc(n*n, sizeof *matr));
    if (!matr){
        return 1;
    }
    return 0;
}

void delete_matr1(double *matr){
    if (matr != NULL) {
        free(matr);
    }
}

int mult_matr1(const double *matr1, const double *matr2, double **matr3, size_t n){
    if (matr1 == NULL || matr2 == NULL){
        return 1;
    }
    *matr3 = (double*)calloc(n * n, sizeof(double));
    if (!*matr3){
        return 1;
    }
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            (*matr3)[i * n + j] = 0;
            for (size_t k = 0; k < n; k++) {
                (*matr3)[i * n + j] += matr1[i * n + k] * matr2[k * n + j];
            }
        }
    }
    return 0;
}

void task4_1(){
    size_t n;
    printf("n = ");
    scanf("%zu", &n);
    double *matr1, *matr2, *matr3;

    create_matr1(&matr1, n);
    create_matr1(&matr2, n);
    create_matr1(&matr3, n);

    input_matr1(matr1, n);
    input_matr1(matr2, n);

    mult_matr1((const double*)matr1, (const double*)matr2, &matr3, n);
    printf("Resultant matrix: \n");
    output_mart1((const double*)matr3, n);

    delete_matr1(matr1);
    delete_matr1(matr2);
    delete_matr1(matr3);
}

int main(){
    int task;
    printf("task = ");
    scanf("%d", &task);

    if (task == 1){
        task1();
    }
    else if (task == 2){
        task2();
    }
    else if (task == 3){
        task3();
    }
    else if (task == 4){
        task4_2();
        task4_1();
    }
}