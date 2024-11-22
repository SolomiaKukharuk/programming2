#include <stdio.h>
#include "students.h"

int main() {
    size_t n;
    printf("Введіть кількість студентів: ");
    scanf("%zu", &n);

    Student *students = (Student *)malloc(n * sizeof(Student));
    input_students(students, n);
    find_students_with_debts(students, n);
    find_worst_subject(students, n);

    free(students);
    return 0;
}

