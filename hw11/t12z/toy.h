#ifndef TOY_H
#define TOY_H

#define MAX_NAME_LENGTH 50


typedef struct {
    char name[MAX_NAME_LENGTH];
    double price;
    int min_age;
    int max_age;
} Toy;


void read_toys_from_file(const char *filename, Toy **toys, size_t *count);
void find_constructors_by_price_and_age(Toy *toys, size_t count, double max_price, int min_age, const char *output_filename);

#endif
