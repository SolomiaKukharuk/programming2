#include <stdio.h>
#include <math.h>
double sigmweight(double x){
    return x * (1 / (1 + exp(-x)));
}
double sigmweight_derivative(double x){
    return x*exp(-x)/pow((exp(-x) + 1),2) + 1/(exp(-x) + 1);
}
int task2_17z(){
    printf("f(3) = %.3lf \n", sigmweight(3));
    printf("f'(4) = %.3lf \n", sigmweight_derivative(4));
    printf("f(0) = %.3lf \n", sigmweight(0));
    printf("f'(6) = %.3lf \n", sigmweight_derivative(6));
    printf("f(0) = %.3lf \n", sigmweight(45));
    printf("f'(6) = %.3lf \n", sigmweight_derivative(3.2));

}

double poly_b(double x,double y){
    double result_b = x * x * y * y + pow(x,3) * pow(y,3) + pow(x,4) * pow(y,4);
    return result_b;
}

double poly_v(double x,double y){
    double result_v = x + y + x * x + y * y + pow(x,3) + pow(y,3) + pow(x,4) + pow(y,4);
    return result_v;
}


int task2_15(){
    double x,y;
    printf("x: ");
    scanf("%lf",&x);
    printf("y: ");
    scanf("%lf",&y);
    double result_b = poly_b(x,y);
    double result_v = poly_v(x,y);
    printf("b : %.2lf, v : %.2lf", result_b, result_v);
}

int main() {
    task2_15();
    task2_17z();
}