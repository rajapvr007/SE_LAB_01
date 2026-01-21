#include<stdio.h>
#include<string.h>
#include "fileio.h"
#include "validation.h"
#include "grading.h"

void readStudents(FILE *fin, struct Student s[], int n){
    for (int i = 0; i < n; i++){
        s[i].totalMarks = 0;
        fscanf(fin, "%s %s",s[i].id,s[i].name);

        for (int j = 0; j < SUBJECTS; j++){
            fscanf(fin, "%f %f",
                    &s[i].subjects[j].minor,
                    &s[i].subjects[j].major);
            if(!validateMinor(s[i].subjects[j].minor) ||
                !validateMajor(s[i].subjects[j].major)){
                strcpy(s[i].subjects[j].grade, "NA");
                s[i].subjects[j].total = 0;
                continue;
                }
            assignGrade(&s[i].subjects[j]);
            s[i].totalMarks += s[i].subjects[j].total;
        }
        
        
    }   
    
}   
void writeResults(FILE *fout, struct Student s[], int n){
    for (int i = 0; i < n; i++){
        fprintf(fout, "\nStudent ID    : %s",s[i].id);
        fprintf(fout, "\nStudent Name  : %s\n",s[i].name);
        fprintf(fout, "Sub  Minor   Major   Total   Grade\n");

        for (int j = 0; j < SUBJECTS; j++){
            fprintf(fout, "%d   %.1f    %.1f    %.1f    %s\n",
                j+1,
                s[i].subjects[j].minor,
                s[i].subjects[j].major,
                s[i].subjects[j].total,
                s[i].subjects[j].grade);
        }
        fprintf(fout, "Toal Marks: %.1f\n", s[i].totalMarks);
        fprintf(fout, "CGPA      : %.2f\n", s[i].cgpa);
        fprintf(fout, "-------------------------------\n");
        
    }
    
}