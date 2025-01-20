#include <stdint.h>
#include <stdio.h>
#include <math.h>

void task1(){
   int a,b,c,num;
   unsigned number;
   printf("number = ");
   scanf("%u",&number);
   if (number >= 100 && number <= 999){
       a = number % 10;
       b = (number / 10) % 10;
       c = number / 100;
       num = a * 100 + 10 * b + c;
       //a
      printf("%d,%d,%d\n",a,b,c);
       //b
       printf("%d\n",a + b + c);
       //c
       printf("%d\n",num);


    }
}

void task2(){
   int a,b,c,num;
   unsigned number;
   printf("number = ");
   scanf("%u",&number);
   if (number >= 100 && number <= 999){
       a = number % 10;
       b = (number / 10) % 10;
       c = number / 100;
   }
    if (a!=b && b!=c && a != c){
        printf("%d\n", a * 100 + b * 10 + c);
        printf("%d\n", a * 100 + c * 10 + b);
        printf("%d\n", b * 100 + a * 10 + c);
        printf("%d\n", b * 100 + c * 10 + a);
        printf("%d\n", c * 100 + b * 10 + a);
        printf("%d\n", c * 100 + c * 10 + b);
    }

}

void task3(){
    long long a,b,c,product;
    printf("a,b,c =");
    scanf("%lld",&a);
    scanf(",%lld",&b);
    scanf(",%lld",&c);
    product = a * b * c;
    printf("%lld\n",&product);

}

void task7_a() {
        double a, b, c;
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    printf("c = ");
    scanf("%lf", &c);

    if (a == 0) {
        printf("a == 0\n");

    double D, x1, x2;
    D = b * b - 4 * a * c;
    if (D > 0) {
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);
        printf("x1 = %.2lf, x2 = %.2lf\n", x1, x2);
    } else if (D == 0) {
        x1 = -b / (2 * a);
        printf("x = %.2lf\n", x1);
    } else {
        printf("x doesn't exist\n");
    }
}
}


void task5(){
    int a,b;
    printf("a,b =");
    scanf("%d,%d",&a,&b);
    if (a > b){
        printf("bigger = (%d)",&a);
    }else{
        printf("bigger = (%d)",&b);
    }
}

uint16_t mult(uint8_t x, uint8_t y){
    uint16_t z = x * y;
    return z;
}
void task4(){
    uint8_t x,y;
    uint16_t z;
    printf("x y:");
    scanf("%C %C",&x,&y);
    z = mult(x,y);
    printf("z = %u\n",z);

}

void task6(){
    int a,b,c,M;
    a = abs(a);
    b = abs(b);
    c = abs(c);
    printf("a,b,c:");
    scanf("%d,%d,%d",&a,&b,&c);
    M = a > b?a:b;
    M > c? M : c;



}

void task7_b() {
    double a, b, c;
    printf("Введіть коефіцієнти a, b, c для рівняння ax^4 + bx^2 + c = 0:\n");
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    printf("c = ");
    scanf("%lf", &c);
    if (a == 0) {
        printf("Це не рівняння 4-го ступеня (a не може дорівнювати 0)\n");
    } else {

       double D, z1, z2, x1, x2, x3, x4;
       D = b * b - 4 * a * c;
       if (D < 0) {
        printf("Рівняння не має дійсних розв'язків\n");
    } else {

        z1 = (-b + sqrt(D)) / (2 * a);
        z2 = (-b - sqrt(D)) / (2 * a);

        if (z1 >= 0) {
            x1 = sqrt(z1);
            x2 = -sqrt(z1);
            printf("Розв'язки: x1 = %.2lf, x2 = %.2lf\n", x1, x2);
        } else {
            printf("z1 = %.2lf не має дійсних коренів\n", z1);
        }

        if (z2 >= 0) {
            x3 = sqrt(z2);
            x4 = -sqrt(z2);
            printf("Розв'язки: x3 = %.2lf, x4 = %.2lf\n", x3, x4);
        } else {
            printf("z2 = %.2lf не має дійсних коренів\n", z2);
        }
    }
    }
}

int main() {
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7_a();
    task7_b();
}
