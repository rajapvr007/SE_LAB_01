#include <stdio.h>
#include <limits.h>
#include "statistics.h"

/* Grade counters (module-level, low coupling) */
static int countO = 0, countAplus = 0, countA = 0;
static int countBplus = 0, countB = 0, countC = 0, countF = 0;

void initGradeCounters() {
    countO = countAplus = countA = 0;
    countBplus = countB = countC = countF = 0;
}

void updateGradeDistribution(float cgpa) {
    if (cgpa >= 9.0) countO++;
    else if (cgpa >= 8.0) countAplus++;
    else if (cgpa >= 7.0) countA++;
    else if (cgpa >= 6.0) countBplus++;
    else if (cgpa >= 5.0) countB++;
    else if (cgpa >= 4.0) countC++;
    else countF++;
}

void calculateClassStatistics(struct Student s[], int n,
                              float *avg, float *high, float *low) {
    float sum = 0;
    *high = -1;
    *low = 101;

    for (int i = 0; i < n; i++) {
        float percentage = (s[i].totalMarks / 500.0) * 100.0;
        sum += percentage;

        if (percentage > *high) *high = percentage;
        if (percentage < *low) *low = percentage;
    }
    *avg = sum / n;
}

void printStatistics(FILE *fout, float avg, float high, float low) {
    fprintf(fout, " Average percentage of Class : %.1f%%\n", avg);
    fprintf(fout, " Highest percentage of Class: %.1f%%\n", high);
    fprintf(fout, " Lowest percentage of Class : %.1f%%\n", low);
    fprintf(fout, "================================\n");
}

void printGradeDistribution(FILE *fout) {
    fprintf(fout, "\nGRADE DISTRIBUTION\n");
    fprintf(fout, "O  Grade  : %d students\n", countO);
    fprintf(fout, "A+ Grade  : %d students\n", countAplus);
    fprintf(fout, "A  Grade  : %d students\n", countA);
    fprintf(fout, "B+ Grade  : %d students\n", countBplus);
    fprintf(fout, "B  Grade  : %d students\n", countB);
    fprintf(fout, "C  Grade  : %d students\n", countC);
    fprintf(fout, "F  Grade  : %d students\n", countF);
    fprintf(fout, "================================\n");
}
