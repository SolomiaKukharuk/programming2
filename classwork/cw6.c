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
