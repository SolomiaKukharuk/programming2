#include <stdio.h>
void task_1(){
    unsigned char n;
    scanf("%hhu",&n);
    unsigned long long m = 1 << n;
    printf("%llu",m);
}
void task_2(){
    unsigned k;
    int n;
    printf("n =");
    scanf("%d",&n);
    printf("%d", n | (1<<k));
}

void task_3(){
    unsigned j;
    int m;
    printf("m =");
    scanf("%d",&m);
    printf("%d", m &~(1<<j);

}

void task_4(){
    unsigned n,m;
    scanf("%u",&n);
    b1 = n&0xFF;
    b2 = (n >> 8)&0xFF;
    b3 = (n>>16)&0xFF;
    b4 = n >>24;
    m = (b1 << 24) | (b3 << 16) | (b2 << 8) | b4;
    printf("%x\n",m);
    printf("%u\n",m);
}

void task5() {

    unsigned long long n;
    unsigned max_count=0, count=0; 

    printf("n = ");
    scanf("%llu", &n);

    while (n) {
        if (n & 1) {
            count++;
            if (count > max_count) {
                max_count = count;
            }
        } else {
            count = 0;
        }
        n >>= 1;
    }

    printf("max ones count = %u \n", max_count);

}

void task6_a(){

    unsigned char x;
    unsigned long long y;

    printf("x = ");
    scanf("%hhu", &x);
    for (int i=1; i < 33; i++){
        y = ((i & (i - 1)) > 0);
        printf("i = %d, y = %llu\n", i, y);
        if (!(i & (i - 1))) printf("%u \n", i);
    } 

}

void task6_b(){

    unsigned char x;
    unsigned long long y;

    printf("x = ");
    scanf("%hhu", &x);
    for (int i=1; i < 33; i++){
        y = i & (-i);
        printf("i = %d, y = %llu\n", i, y);

        int count = 0;
        int temp = i;
        while (temp % 2 == 0){
            temp /= 2;
            count++;
        }
        printf("count = %d \n", count);
    }

}

void task7() {

    unsigned value = 0x12345678;

    unsigned b1 = value & 0xFF;          // 0x78       
    unsigned b2 = (value >> 8) & 0xFF;   // 0x56
    unsigned b3 = (value >> 16) & 0xFF;  // 0x34
    unsigned b4 = (value >> 24) & 0xFF;  // 0x12

    if (b1 == 0x78 && b2 == 0x56 && b3 == 0x34 && b4 == 0x12){
        printf("Little-endian \n");
    }
    else if (b1 == 0x12 && b2 == 0x34 && b3 == 0x56 && b4 == 0x78){
        printf("Big-endian \n");
    }
    else if (b1 == 0x34 && b2 == 0x12 && b3 == 0x78 && b4 == 0x56){
        printf("Big-endian \n");
    }
    else{
        printf("Unknown architecture \n");
    }

}

void task27(){

    unsigned long long n, m; // 64 біт
    int i=0;

    printf("n = ");
    scanf("%llu", &n);

    printf("m = ");
    scanf("%llu", &m);

    unsigned long long p = n^m;

    while(i < 64){
        if (p & (1<<i)) printf("%d \n", i);
        i++;
    }

}

int main(){

    int task;
    printf("task = ");
    scanf("%d", &task);

    if (task == 1){
        task1();
    }
    else if (task == 2){
        task2();
    }
    else if (task == 3){
        task3();
    }
    else if (task == 4){
        task4();
    }
    else if (task == 5){
        task5();
    }
    else if (task == 6){
        task6_a();
        task6_b();
    }
    else if (task == 7){
        task7();
    }
    else if (task == 27){
        task27();
    }

}