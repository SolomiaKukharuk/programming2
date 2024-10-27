//Варіанту з не було в 11му номері,тому робила 'є',так
// як воно найближче до з
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "toy.h"


void read_toys_from_file(const char *filename, Toy **toys, size_t *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open file for reading.\n");
        exit(1);
    }

    size_t size = 0;
    *toys = NULL;
    Toy toy;


    while (fscanf(file, "%s %lf %d %d", toy.name, &toy.price, &toy.min_age, &toy.max_age) == 4) {
        *toys = realloc(*toys, (size + 1) * sizeof(Toy));
        (*toys)[size] = toy;
        size++;
    }
    *count = size;

    fclose(file);
}


void find_constructors_by_price_and_age(Toy *toys, size_t count, double max_price, int min_age, const char *output_filename) {
    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        printf("Failed to open file for writing.\n");
        exit(1);
    }

    int found = 0;
    for (size_t i = 0; i < count; i++) {

        if (strcmp(toys[i].name, "constructor") == 0 &&
            toys[i].price <= max_price &&
            toys[i].min_age <= min_age && toys[i].max_age >= 12) {


            fwrite(&toys[i], sizeof(Toy), 1, output_file);
            printf("Name: %s, Price: %.2f, Age: %d-%d\n",
                   toys[i].name, toys[i].price, toys[i].min_age, toys[i].max_age);
            found = 1;
        }
    }


    if (!found) {
        const char *message = "Constructor matching the conditions not found.\n";
        fwrite(message, sizeof(char), strlen(message), output_file);
        printf("%s", message);
    }

    fclose(output_file);
}
