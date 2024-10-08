
//5_16k
#include <stdio.h>
#include <math.h>
int main(){
    task_12v();
    task_16k();
}
void task_12v(){
      int n;
      printf("Enter n:");
      scanf("%d",&n);
      pow_2 = 4;
      fact_k = 2;
      sum = 2/3; //calculated when k == 1
      for (int k = 2; k <= n; k++){
        double a1 = 1;
        double b1 = 1;
        double a_k = 3 * b1 + 2 * a1;
        double b_k = 2 * a1 + b1;
        sum += pow_2 / ((1 + a_k + b_k) * fact_k);
        a1 = a_k;
        b1 = b_k;
        pow_2 *= 2;
        fact_k *= k;
      }
      printf("The sum is %f\n",sum);
}

void task_16k(){
        double x, epsilon, sum = 1.0, term = 1.0;
        int n = 1;
        printf("Введіть значення x (|x| < 1): ");
        scanf("%lf", &x);
        if (fabs(x) >= 1) {
            printf("Помилка: |x| має бути менше 1.\n");
            return 1;
        }

        printf("Введіть значення epsilon (> 0): ");
        scanf("%lf", &epsilon);
        if (epsilon <= 0) {
            printf("Помилка: epsilon має бути більше 0.\n");
            return 1;
        }

        while (fabs(term) >= epsilon) {

            term *= (double)(1 - 2 * n) / (2 * n) * x;
            sum += term;
            n++;
        }
        printf("Наближене значення sqrt(1 + x): %.15f\n", sum);

}