#include <stdio.h>
int count_ones(unsigned int x) {
    int count = 0;
    while (x) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}


int count_matching_bits(unsigned int a, unsigned int b) {
    unsigned int xnor = ~(a ^ b);
    return count_ones(xnor);
}


void task_15() {
    unsigned int m, n, num;
    int i;
    printf("Enter two natural 32-bit numbers m and n:\n");
    scanf("%u %u", &m, &n);

    unsigned int common_ones = count_ones(m & n);
    printf("Number of common units: %u\n", common_ones);

    unsigned int matching_bits = count_matching_bits(m, n);
    printf("Number of matching bits: %u\n", matching_bits);
}

int changing_bits(unsigned n){
    int n_bits = sizeof(n) * 8;
    while ((n >> (n_bits - 1)) == 0 && n_bits > 0){n_bits--;}
    int last_8_bits = n & 0xFF;
    int first_8_bits;
    if (n_bits < 8){
      first_8_bits = last_8_bits;}
    else{
     firts_8_bits = n >> (n_bits - 8)
    }
    int middle_bits = n & ~(0xFF | (0xFF << (n_bits - 8)));
    unsigned changed;
    changed = (last_8_bits << (n_bits - 8)) | middle_bits | first_8_bits;
    return changed;
}

void task_10(){
    unsigned n;
    printf("Enter natural n:");
    scanf("%u", &n);
    n_changed = changing_bits(n);
    printf("Number of changed bits: %f\n", n_changed);
    printf("Number of changing bits: %x\n", n_changed);


}