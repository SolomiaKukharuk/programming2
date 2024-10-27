#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int find_max_in_group(int *arr, size_t start, size_t end) {
    int max_value = INT_MIN;
    for (size_t i = start; i < end; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }
    return max_value;
}


void process_file(const char *input_file, const char *output_file, size_t n) {
    FILE *f_in = fopen(input_file, "r");
    FILE *f_out = fopen(output_file, "w");

    if (!f_in || !f_out) {
        printf("Не вдалося відкрити файли.\n");
        return;
    }


    int *components = NULL;
    size_t size = 0;
    int temp;
    while (fscanf(f_in, "%d", &temp) == 1) {
        components = realloc(components, (size + 1) * sizeof(int));
        components[size] = temp;
        size++;
    }


    size_t groups = size / n;
    size_t remainder = size % n;


    for (size_t i = 0; i < groups; i++) {
        int max_value = find_max_in_group(components, i * n, (i + 1) * n);
        fprintf(f_out, "%d\n", max_value);
    }


    if (remainder > 0) {
        int max_value = find_max_in_group(components, groups * n, size);
        fprintf(f_out, "%d\n", max_value);
    }


    free(components);
    fclose(f_in);
    fclose(f_out);
}

int main() {
    size_t n;
    printf("Enter the number of groups (n): ");
    scanf("%zu", &n);

    const char *input_file = "F.txt";
    const char *output_file = "G.txt";

    process_file(input_file, output_file, n);

    printf("File G has been succesfully created\n");
    return 0;
}
