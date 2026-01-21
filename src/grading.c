#include "string.h"
#include "grading.h"


void assignGrade(struct Subject *sub){
    sub->total = sub->minor + sub->major;

    if (sub->total >= 90) strcpy(sub->grade, "O");
    else if (sub->total >= 85) strcpy(sub->grade, "A+");
    else if (sub->total >= 75) strcpy(sub->grade, "A");
    else if (sub->total >= 65) strcpy(sub->grade, "B+");
    else if (sub->total >= 60) strcpy(sub->grade, "B");
    else if (sub->total >= 55) strcpy(sub->grade, "C");
    else if (sub->total >= 50) strcpy(sub->grade, "D");
    else strcpy(sub->grade, "F");
}
int gradeToPoint(char grade[]) {
    if (strcmp(grade, "O") == 0) return 10;
    if (strcmp(grade, "A+") == 0) return 9;
    if (strcmp(grade, "A") == 0) return 8;
    if (strcmp(grade, "B+") == 0) return 7;
    if (strcmp(grade, "B") == 0) return 6;
    if (strcmp(grade, "C") == 0) return 5;
    if (strcmp(grade, "D") == 0) return 4;
    return 0;
}