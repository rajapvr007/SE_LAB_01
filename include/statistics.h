#ifndef STATISTICS_H
#define STATISTICS_H

#include "student.h"

void initGradeCounters();
void updateGradeDistribution(float cgpa);
void calculateClassStatistics(struct Student s[], int n,
                              float *avg, float *high, float *low);
void printStatistics(FILE *fout, float avg, float high, float low);
void printGradeDistribution(FILE *fout);

#endif
