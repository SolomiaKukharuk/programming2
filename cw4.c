#include <math.h>
#include <stdio.h>
#include <float.h>
void task_1() {
    double x,y;
    int n;
    printf("x:,n:");
    scanf ("%lf",&x);
    scanf(",%d",&n);
    y=x;
    for (int i = 0; i < n; i++){
        y = sin(i);
    }
    printf ("result %lf",y);

}
void task_2(){
    unsigned int n;
    printf("n =");
    scanf("%u",&n);
    //a
    for (int i = 1; i < n; i++){
        printf("%u * ",i);
    }
    printf("%u \n",n);
    //b
    for (int i = n; i > 1; i--){
        printf(" %u *",i);
    }
    printf("1\n");
}
void task_3(){
    double x;
    n = 3;
    for ( int i = n; i >= 0;i--){
        x += pow(x,i);
    }
    printf("%lf",x);
}
void task_4(){
    double x,y,power = 1;
    unsigned n,i,k;
    scanf("%lf %u",&x,&n);
    y = 0;
    for (i = 1; i <= n; i++){
        {power *= x; y+=power * i;}
    }
    printf("y = %lf",y);
}

void task_5(){
    unsigned int n;
    printf("n:");
    scanf("%u",&n);
    for (int i = n; i > 0; i -= 2)
    {m *= i;}
    printf("fact = %u",m);
}
void task_6(){
    //a
    unsigned int n;
    double res,res2;
    printf("n:");
    scanf("%u",&n);
    res = sqrt(2);
    for (int i = 0; i < n; i++){
        res = sqrt(2 + res);
    }
    printf("%lf \n",res);
    //b
    res1 = sqrt(3 * n);
    for (int i = n, i > 0,i--){
        res1 = sqrt(3 * (n -1) + res1 )
    }
    printf("%lf \n",res1);
}

void task_7(){
    double x,y,term = 1;
    unsigned n,i;
    scanf("%lf %u",&x,&n);
    y = 1;
    for (i = 1; i <= n; i++)
        {term *= (x/i); y += term;}
    printf("y = %lf",y);
}

void task8_9(){
    unsigned m,r,k,power;
    printf("m =");
    scanf("%u",&m);
    power = 1;
    k = 0;
    while (power <= m)
    {power *= 4; k++;}
    printf("k = %u",k - 1);
    power = 1; r = 0;
    do{power *= 2; r++;} while (power <= m);
    prinft ("r = %u",r);

}

void task_10(){
    float a = 1.f;
    do{a/=2;} while ( a + 1!= a);
    printf("%f",a * 2);
}

void task_11(){
    int i = 0;
    double sum = 0;
    eps = 2 * Dbl_Eps;
    do{
        printf("a[%d] = ,",i++)
        scanf(" %lf", &x);
        sum += x;
        }while(fabs(x) > eps);
}
void task_12(){

    unsigned int n;
    double subfact = 1;

    printf("n < 25 = ");
    scanf("%u", &n);

    for (int i=1; i <= n; i++){
        subfact = subfact * i + pow(-1, i);
    }
    printf("!%u = %.0f\n", n, subfact);

}


int main(){
    int task_number
    printf("number:");
    scanf("%d",&task_number);
    if (task_number == 1)
         {task_1();}
    else if (task_number == 2
         {task_2();}
    else if (task_number == 3)
        {task_3();}
    else if (task_number == 4)
        {task_4();}
    else if (task_number == 5)
        {task_5();}
    else if (task_number == 6)
        {task_6();}
    else if (task_number == 7)
        {task_7();}
    else if (task_number == 8)
        {task8_9();}
    else if (task_number == 9)
        {task8_9();}
    else if (task_number == 10)
        {task_10();}
    else if (task_number == 11)
        {task_11();}
    else if (task_number == 12)
        {task_12();}
