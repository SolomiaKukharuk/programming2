#ifndef STUDENTS_H
#define STUDENTS_H


typedef struct {
    char surname[50];
    int group_number;
    int grade_1;
    int grade_2;
    int grade_3;
} Student;


void input_students(Student *students, size_t n);
void find_students_with_debts(const Student *students, size_t n);
void find_worst_subject(const Student *students, size_t n);

#endif
