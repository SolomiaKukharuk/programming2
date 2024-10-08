#include <math.h>
#include <stdio.h>

#define SIZE1 5
#define SIZE2 4
#define SIZE3 10
#define SIZE4 5
#define SIZE5 50
#define SIZE6 20


void task1(){

    int mas[] = {1, 2, 3, 4, 5};
    double a;

    printf("a = ");
    scanf("%lf", &a);

    int cnt=0;
    for (int i=0; i < 5; i++){
        if (mas[i] < a){
            cnt++;
        }
    }
    printf("k = %d \n", cnt);

}

void task2(){

    int mas[] = {5, 112, 4, 3};

    for (int i=3; i >= 0; i--){
        printf("%d ", mas[i]);
    }
    printf("\n");

}

double summ(double arr[], int SIZE2){

    double sum=0.0;

    for (int i=0; i < SIZE2; i++){
        if (arr[i] > M_E){
            sum += arr[i];
        }
    }
    return sum;

}


double el_sum(double arr[SIZE3]) {
    double sum = 0;
    for (int i = 0; i < SIZE3; i++){
        if (arr[i] > M_E){
            sum +=arr[i];}
    return sum;
        }
    }

void task_3(){
    double a[SIZE3];
    for (int k = 0;k<SIZE3;k++){
        printf("a[%d] =",k);
        scanf("%lf",&a[k]);
    }
    printf("%lf",el_sum(a));
}

int input_arr(int a[SIZE]){
    for (int i = 0; i < 0;i++){
        printf("a[%d] = ",i);
        int r = scanf("%lf",&a[i])
        if (r != 1) return i;
    }
    return SIZE;
}
int maximum (double a[SIZE4]){
    int max = a[0];
    for(int i = 1;i<SIZE4;i++){
        if (a[i] > max){
            max = a[i];
        }
    }
    return max;
}
void task_4(){
    int a[SIZE4];
    int m = input_arr();
    if (m!=SIZE4){
        printf("Error");
        return; }
    printf("%d",max(a));
}

int input_arr1(int a[SIZE5],int n){
    for (int i = 0; i < SIZE5;i++){
        printf("a[%d] =",i);
        scanf("%lf",&a[i]);
        if (a[i] == 0) return i - 1;
    }
}

void odd_even(int a[],int n){
    int odd = 0,even =0;
    for (int i = 0; i < n;i++){
        if (a[i] % 2){
            odd ++;}
        else{even ++;}
    }
    printf("%d %d",odd,even);

}

void task_5(){
    int arr[SIZE5];
    input_arr(arr);
    odd_even(arr);
}
void input_vect(double v[],int n){
    for (int i=0; i < n; i++){
        printf("v[%d] = ", i);
        scanf("%lf", &v[i]);
    }
}

void outputvect(const double v[],int n){
    for (int i=0; i < n; i++){
        printf("%lf ", v[i]);
    }
    printf("\n");

}
void add_vect(const double v1[], const double v2[],double v3[]){

    for (int i=0; i < n; i ++){
        v3[i] = v1[i] + v2[i];
    }
}

double mult_vect(const double v1[],const double v2[],int n){
    double product=0.0;

    for (int i=0; i < n; i++){
        product += v1[i] * v2[i];
    }
    return product;
}

void task_6(){
    double vector1[SIZE6];
    double vector2[SIZE6];
    double vector3[SIZE6];
    int n;
    printf("n =");
    scanf("%d",&n);
    input_vector(vector1,n);
    input_vector(vector2,n);
    printf ("%lf\n %lf\n %lf\n",
    add_vect(vector1,vector2,vector3,n),mult_vect(vector1,vector2,n),outputvector(v3,n));
}
int main(){

    int task;
    printf("task = ");
    scanf("%d", &task);

    if (task == 1){
        task_1();
    }
    if (task == 2){
        task_2();
    }
    else if (task == 3){
        task_3();
    }
    else if (task == 4){
        task_4();
    }
    else if (task == 5){
        task_5();
    }
    else if (task == 6){
        task_6();
    }

}