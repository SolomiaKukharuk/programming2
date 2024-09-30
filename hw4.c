#include <stdio.h>

void task_18e(){
    int k,x;
    double x_k,k_fact;
    printf("k,x =");
    scanf("%d,%d",&k,x);
    x_k = (- 1 * x * x) / 2;
    k_fact = 2;
    for (int i = 2; i <=k;i++){
    k_fact += 2*i;
    x_k *= ((-1)*x*x*x) / k_fact;
    }
    printf("x_k = ",x_k);
}




void findDecimalPeriod(int n, int m) {
    int remainder = n % m;
    int slow = remainder, fast = remainder;
    int position = 0, period_start = -1, period_length = 0;
    printf("%d / %d = 0.", n, m);

        slow *= 10;
        printf("%d", slow / m);
        slow %= m;
        fast *= 10;
        fast = (fast % m) * 10;
        printf("%d", (fast / m));
        fast %= m;
        position++;
        if (slow == fast) {
            period_start = position;
            break;
        }
    } while (slow != 0);

    if (slow == 0) {
        printf("\nЦей дріб має кінцеве десяткове представлення.\n");
    } else {

        int temp = slow;
        do {
            temp *= 10;
            temp %= m;
            period_length++;
        } while (temp != slow);

        printf("\nПеріод починається на позиції %d і має довжину %d.\n", period_start, period_length);
    }
}

void task_25() {
    int n, m;
    printf("n,m: ");
    scanf("%d,%d", &n, &m);

    findDecimalPeriod(n, m);

}

