#include <stdio.h>
#include <float.h>
#include <math.h>
int main(){
    int task_number;
    printf("number:");
    scanf("%d",&task_number);
    if (task_number == 1)
         {task_1();}
    else if (task_number == 2)
         {task_2();}
    else if (task_number == 3)
         {task_3();}
    else if (task_number == 4)
         {task_4();}
    else if (task_number == 5)
         {task_5();}
	 else if (task_number == 8_a)
         {task8_a();}
    else if (task_number == 8_b)
         {task8_b);}
	 else if (task_number == 7)
         {task_7();}
    else if (task_number == 6)
         {task6_v();}
}
}
}

void task_1(){
    //a,b
    int a;
    printf("Enter a number1: ");
    scanf("%d",&a);
    int n;
    float s;
    s = 1;
    n = 2;
    while (s > a){
    s += 1.0/n;
    n++;
    }
    printf("s=%f\n",s);
}

void task_2(){
    //a
    unsigned long long F,F0,F1,f;
    F0 = 0;
    F1 = 1;
    size_t i,n,n1;
    int a;
    printf("Enter a our number2: ");
    scanf("%d",&a);

    /*for(i=0;i<n;i++){
    F = F0 + F1;
    F0 = F1;
    F1 = F;
    }*/
    //v на парі Ви сказали робити в, але в табличці б
    printf("%f",f);
    f = 0;
    for (n1 = 0; f < a;n1++){
    f = F0 + F1;
    F0 = F1;
    F1 = f;
    }
    printf("n1 = %zu\n",n1);
}

void task_3(){

}


void task_4(){
    double i,P,f;
    int n;
    P = 1;
    f = 1;
    printf("Enter a number3: ");
    scanf("%d",&n);
    for (i = 1; i <= n;){
    f = f/i;
    P = P*(1 + f);
    i++;
    }
    printf("%d",P);
}

void task_5(){
    int x1,x2,x3,xn;
    x1 = x2 = x3 = -99;
    xn = -1;
    while(xn < 0){
    xn = x3 + x1 + 100;
    x1 = x2;
    x2 = x3;
    x3 = xn;
    }
}

void task8_a() {
    double t,x,y,eps;
    int x;
    printf("x =");
    scanf("%lf",&x);
    do{printf"eps =");scanf("%lf"&eps);}
    while(eps = 0)
    t =1; i =1; y = t;
    while (t > eps){
        t *= (x/i);
        i++;
        y+=t;
    }
    printf("y = %lf,%lf",y,exp(x));

}

void task8_b(){
    double k,x,y,eps;
    int x;
    printf("x =");
    scanf("%lf",&x);
    do{printf"eps =");scanf("%lf"&eps);}
    while(eps = 0);
    k = -1 * (pow(x,3) / 3);
    i =2;y=t;
    while (k > eps){
        y+=k
        k *= (- x * x)/(2 * i + 1)
    }
    printf("y = %lf,%lf",y);
}
void task_7(){
	double n,k,i,a1,a2,b1,b2,b_k,a_k,s;
	printf("n: ");
	scanf("%lf",&n);
	a1=b1=0;
	a2=b2=1;
	if (n == 1){
		printf("2");}
	else if (n == 2){
		printf("6";)}
	else{
		double pow_2 = 2;
		s = 6;
		for (i = 3; i <= n; i++){
			b_k = a2 + b2;
			b1 = b2;
			b2 = b_k;
			a_k = a2/i + a1 * b_k;
			a1 = a2;
			a2 = a_k;
			pow_2 *= 2;
			s += pow_2 /(a_k * b_k);}
		printf("s = %lf\n",s);}
}

void task6_v(){

}
// y = 1 + 1/y