#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_NUM 100

int is_power_of_three(int num) {
    if (num < 1) return 0;
    while (num % 3 == 0) {
        num /= 3;
    }
    return num == 1;
}

int is_even(int num){
  if (num < 1) return 0;
  while (num % 2 == 0) {
    num /= 2;
  }
  return num == 1;

}



void print_file_content(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("failed to open file");
        return;
    }

    char line[256]; // buffer for reading lines
    printf("content of %s:\n", filename);
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line); // print each line
    }
    fclose(file);
}

int main() {
    FILE *fileF, *fileG;
    int numbers[MAX_NUM];
    int count = 0;

    fileF = fopen("F.txt", "w");
    if (fileF == NULL) {
        perror("failed to create file F");
        return 1;
    }

    printf("enter integers (0 to finish):\n");
    while (1) {
        int num;
        scanf("%d", &num);
        if (num == 0) break;
        numbers[count++] = num; // store the number in the array
        fprintf(fileF, "%d\n", num);
    }
    fclose(fileF);
    fileG = fopen("G.txt", "w");
    if (fileG == NULL) {
        perror("failed to create file G");
        return 1;
    }
    //(a)
    fprintf(fileG, "numbers that are even:\n");
    int found_even = 0; // flag to check if any even number is found
    for (int i = 0; i < count; i++) {
        if (is_even(numbers[i])) {
            fprintf(fileG, "%d\n", numbers[i]);
            found_even = 1;
        }
    }
    if (!found_even) {
        fprintf(fileG, "None\n"); // if none found, indicate that
    }

    // (b): write powers of 3 to file G
    fprintf(fileG, "numbers that are powers of 3:\n");
    int found_power_of_three = 0; // flag to check if any power of 3 is found
    for (int i = 0; i < count; i++) {
        if (is_power_of_three(numbers[i])) {
            fprintf(fileG, "%d\n", numbers[i]);
            found_power_of_three = 1;
        }
    }
    if (!found_power_of_three) {
        fprintf(fileG, "None\n"); // if none found, indicate that
    }
