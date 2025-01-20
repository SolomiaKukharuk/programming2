#include <stdio.h>
#include <math.h>
int main(){
    //1.1

    int sum = 2 + 31;
    int mult_sub = 45 * 54 - 11;
    int div_int = 15 / 4;
    double div_float = 15.0 / 4;
    int mod = 67 % 5;
    double complex_expr = (2 * 45.1 + 3.2) / 2;


    printf("2 + 31 = %d\n", sum);
    printf("45 * 54 - 11 = %d\n", mult_sub);
    printf("15 / 4 = %d\n", div_int);
    printf("15.0 / 4 = %.2f\n", div_float);
    printf("67 %% 5 = %d\n", mod);
    printf("(2 * 45.1 + 3.2) / 2 = %.2f\n", complex_expr);

    //1.2
    float a = 1e-4f;
    double b = 24.33e5;
    long double pi = M_PI;
    long double e = M_E;
    float sqrt_5 = sqrt(5);
    double ln100 = log(100);


    printf("a = %.2f\n", a);
    printf("b = %.2lf\n", b);
    printf("pi = %.2Lf\n", pi);
    printf("e = %.2Lf\n", e);
    printf("sqrt(5) = %.2f\n", sqrt_5);
    printf("ln(100) = %.2lf\n", ln100);

    //1.3
    char a;
    printf("Введіть цифру: ");
    scanf("%c", &a);
    printf("(%c\n", a)
    printf("- %c - %c - %c\n", a, a, a);
    printf("%c | %c | %c\n", a, a, a);
    printf("- %c - %c - %c\n", a, a, a);





  // 1.4
    double m1,m2,r1;
    const double y = 6.673E-11;
    double F;
    printf("m1 =");
    scanf ("%lf",&m1);
    printf("m2 =");
    scanf("%lf",&m2);
    printf("r =");
    scanf("%lf",&r1);
    F = y * ((m1*m2)/(r1*r1));
    printf("F = %le", F);


   //1.5(b)

     double x3,x_3;
     printf ("x = ");
     scanf("%lf",&x3);
     x_3 = x3 * x3 * x3 ;
     x_3 *= x_3;
     printf("(%g))^6 = %g",x3,x_3);

    //1.6

        double C,F1;
        printf("Temperature C° = ");
        scanf("%lf",&C);
        F = ((9 * C) / 5) + 32;
        printf ("F = (%g)",F1);

      //1.7


        double x,z,d;
        int c,f,r;
        printf("x = ");
        scanf("%lf",&x);
        c = ceil(x);//округлення зверху
        f = floor(x);//округлення знизу
        r = round(x);
        z = (int) x;
        d = fabs(x - z);
        printf("%lf,%lf,%lf",x,z,d);
        printf(",%d,%d,%d",c,f,r);

        //1.8

        double c1,y,mul,diff1,diff2
        printf("c = ")
        scanf("%lf",%c1)
        printf("y = ")
        scanf("%lf",%y)
        mul = c1 * y
        diff1 = c1 - y
        diff2 = y - c1
        printf("mul = (%g), c - y =(%g), y - c = (%g)", mul, diif1,diff2)

  //1.9

      double a,b,mid,midg;
      printf("a b = ");
      scanf("%lf",&a);
      scanf(" %lf",&b);
      mid = (a + b) / 2;
      midg = 2 / ((1/a) + (1/b));
      printf("mid = %g, midg = %g",mid,midg);

}
