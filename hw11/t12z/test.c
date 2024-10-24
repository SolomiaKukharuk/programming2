#include <stdio.h>
#include "toy.h"

int main() {
    Toy *toys = NULL;
    size_t count = 0;
    double max_price;
    int min_age;


    read_toys_from_file("toys.txt", &toys, &count);


    printf("Enter the maximum price (Y) for the constructor: ");
    scanf("%lf", &max_price);
    printf("Enter the minimum age (x): ");
    scanf("%d", &min_age);


    find_constructors_by_price_and_age(toys, count, max_price, min_age, "result.bin");


    free(toys);
    return 0;
}
