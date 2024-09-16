#include<stdio.h>
#include<math.h>

//2_1
int main() {
    double x, res;
    printf("x = ");
    scanf("%lf", &x);
    res = cos(x);
    printf("cos(%.3lf) = %.6lf", x, res);
}

//2_2
int main() {
    double a, b, c;
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    if (a>0 && b>0)
    {
        c = sqrt(a*a + b*b);
        printf("c = %.3lf", c);
    }
    else {
        printf("Incorrectly entered values!");
    }

    //2_3
    int main() {
        double a, b, c;
        double p, S;
        printf("Enter value a, b, c = ");
        scanf("%lf %lf %lf", &a, &b, &c);
        if ((a < b+c) && (b < a+c) && (c < a+b))
        {
            p = (a + b + c) / 2;
            S = sqrt(p * (p-a)*(p-b)*(p-b));
            printf("S = %.3lf", S);
        }
        else {
            printf("This triangle does not exist");
        }
    }

    //2_4 в
    double horner(double x) {
        double y = (((((x + 5) * x + 10) * x + 10) * x + 5) * x + 1);
        return y;
    }

    int main() {
        double x;
        printf("Введіть значення x: ");
        scanf("%lf", &x);
        double result = horner(x);
        printf("Значення многочлена: %.2lf\n", result);


    }


    //2_5
    double RosenBrock2d(double x, double y) {
        double t1 = pow(x, 2) - y;
        double t2 = x - 1;
        double z = 100 * pow(t1, 2) + pow(t2, 2);
        return z;
    }

    int main() {
        printf("%lf\n", RosenBrock2d(0,1));
        printf("%lf\n", RosenBrock2d(2,4));
        printf("%lf\n", RosenBrock2d(1,0));
    }

    //2_6
    double area(double a, double b, double c)
    {
        double p = (a+b+c)/2;
        double S = sqrt((p * (p-a)*(p-b)*(p-c)));
        return S;
    }

    double lenth(double x1, double x2, double y1, double y2)
    {
        double l = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
        return l;
    }


    int main() {
        double Ax, Ay, Bx, By, Cx, Cy;
        double AB, BC, CA;
        double S;

        printf("Enter A(x,y), B(x,y), C(x,y)\n");
        scanf("%lf %lf %lf %lf %lf %lf", &Ax, &Ay, &Bx, &By, &Cx, &Cy);
        printf("%lf %lf, %lf %lf, %lf %lf\n", Ax, Ay, Bx, By, Cx, Cy);

        AB = lenth(Ax, Bx, Ay, By);
        BC = lenth(Bx, Cx, By, Cy);
        CA = lenth(Cx, Ax, Cy, Ay);

        if ((AB < BC+CA) && (BC < AB+CA) && (CA < AB+BC))
        {
            S = area(AB, BC, CA);
            printf("AB = %.3lf, BC = %.3lf, CA = %.3lf\n", AB, BC, CA);
            printf("S = %.6lf", S);
        }
        else {
            printf("This triangle does not exist");
        }
    }
