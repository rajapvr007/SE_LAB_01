#include "student.h"
#include "grading.h"

float calculateCGPA(struct Student *s){
    int credit = 4;
    int totalCredits = 0;
    int totalGradePoints = 0;
    for (int i = 0; i < SUBJECTS; i++){
        int gp = gradeToPoint(s->subjects[i].grade);
        totalGradePoints += gp * credit;
        totalCredits += credit;
    }
    return (float)totalGradePoints/totalCredits;
    
}