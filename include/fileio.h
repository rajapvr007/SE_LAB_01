#ifndef FILEIO_H
#define FILEIO_H

#include "student.h"
void readStudents(FILE *fin, struct Student s[], int n);
void writeResults(FILE *fin, struct Student s[], int n);
#endif 