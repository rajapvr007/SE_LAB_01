#ifndef STUDENT_H
#define STUDENT_H

#define SUBJECTS 5

struct Subject {
    float minor, major, total;
    char grade[3];
};

struct Student {
    char id[50];
    char name[100];
    struct Subject subjects[SUBJECTS];
    float totalMarks,cgpa;
};

float calculateCGPA(struct Student *s);
#endif