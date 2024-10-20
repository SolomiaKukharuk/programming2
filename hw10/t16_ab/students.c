#include <stdio.h>
#include "students.h"

void input_students(Student *students, size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("Введіть інформацію про студента #%zu:\n", i + 1);
        printf("Прізвище: ");
        scanf("%s", students[i].surname);
        printf("Номер групи: ");
        scanf("%d", &students[i].group_number);
        printf("Оцінка 1: ");
        scanf("%d", &students[i].grade_1);
        printf("Оцінка 2: ");
        scanf("%d", &students[i].grade_2);
        printf("Оцінка 3: ");
        scanf("%d", &students[i].grade_3);
    }
}


void find_students_with_debts(const Student *students, size_t n) {
    printf("\nСтуденти, які мають заборгованості:\n");
    for (size_t i = 0; i < n; i++) {
        if (students[i].grade_1 < 50 || students[i].grade_2 < 50 || students[i].grade_3 < 50) {
            printf("%s (Група: %d)\n", students[i].surname, students[i].group_number);
        }
    }
}


void find_worst_subject(const Student *students, size_t n) {
    int total_grade_1 = 0, total_grade_2 = 0, total_grade_3 = 0;

    for (size_t i = 0; i < n; i++) {
        total_grade_1 += students[i].grade_1;
        total_grade_2 += students[i].grade_2;
        total_grade_3 += students[i].grade_3;
    }

    int avg_1 = total_grade_1 / n;
    int avg_2 = total_grade_2 / n;
    int avg_3 = total_grade_3 / n;

    printf("\nПредмет складений найгірше: ");
    if (avg_1 <= avg_2 && avg_1 <= avg_3) {
        printf("Предмет 1\n");
    } else if (avg_2 <= avg_1 && avg_2 <= avg_3) {
        printf("Предмет 2\n");
    } else {
        printf("Предмет 3\n");
    }
}
