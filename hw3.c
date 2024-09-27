#include <stdio.h>
#include <float.h>
#include <math.h>
int main(){
    int task_number;
    printf("number:");
    scanf("%d",&task_number);
    if (task_number == 3)
         {task_3();}
    else if (task_number == 23)
         {task_23();}
    }

void task_3(){
    double x,y,z,s1,s2,s3,m1,m2,m3,S,M;
    printf("x,y,z:");
    scanf("%lf,%lf,%lf",&x,&y,&z);
    s1 = x + y + z;
    s2 = x*y - x*z + z*y;
    s3 = x*y*z;
    S = s1 > s2 ? s1 : s2;
    S = S > s3 ? s3 : s3;
    m1 = x*y;
    m2 = x*z;
    m3 = y*z;
    M = m1 > m2 ? m2 : m1;
    M = m3 > M ? m3 : M;
    printf("%lf\n %lf",M,S);

}
void task_23(){
    double a, x;
    printf("a,x:");
    scanf("%lf,%lf",&a,&x);
    printf("softExponential(%.2lf, %.2lf) = %.6lf\n", a, x, soft_exponential(a, x));
    printf("derivative softExponential(%.2lf, %.2lf) = %.6lf\n", a, x, derivative_soft_exponential(a, x));
}

double soft_exponential(double a, double x) {
    if (a < 0) {
        return -(log(1 - a * (x + a))) / a;
    } else if (a == 0) {
        return x;
    } else {
        return (exp(a * x) - 1) / a;
    }
}
double derivative_soft_exponential(double a, double x){
     if (a < 0) {
            return -1/((a + x)*a - 1);
        } else if (a == 0) {
            return 1;
        } else {
            return exp(a*x);
        }
}
