#include <stdio.h>
#include "student.h"
#include "fileio.h"
#include "statistics.h"

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");

    int n;
    fscanf(fin, "%d", &n);

    struct Student s[n];

    readStudents(fin, s, n);

    initGradeCounters();

    for (int i = 0; i < n; i++) {
        s[i].cgpa = calculateCGPA(&s[i]);
        updateGradeDistribution(s[i].cgpa);
    }

    writeResults(fout, s, n);

    float avg, high, low;
    calculateClassStatistics(s, n, &avg, &high, &low);
    printStatistics(fout, avg, high, low);
    printGradeDistribution(fout);

    fclose(fin);
    fclose(fout);
    return 0;
}
