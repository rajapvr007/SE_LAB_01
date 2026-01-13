#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Subject{
    float minor, major,total;
    char grade[3];
};
struct Student{
    char id[50];
    char name[100];
    struct Subject subjects[5];
    float totalMarks, cpga, percentage;
    char grade[3];
    
    
};
void assignGrade(struct Subject *sub) {
    sub->total = sub->minor + sub->major;

    if (sub->total >= 90)
        strcpy(sub->grade, "O");
    else if (sub->total >= 85)
        strcpy(sub->grade, "A+");
    else if (sub->total >= 75)
        strcpy(sub->grade, "A");
    else if (sub->total >= 65)
        strcpy(sub->grade, "B+");
    else if (sub->total >= 60)
        strcpy(sub->grade, "B");
    else if (sub->total >= 55)
        strcpy(sub->grade, "C");
    else if (sub->total >= 50)
        strcpy(sub->grade, "D");
    else
        strcpy(sub->grade, "F");
}

int validateMinor(float minor){
    if( minor >= 0 && minor <= 40) return 1;
    else return 0;
}
int validateMajor(float major){
    if( major >= 0  && major <= 60) return 1;
    else return 0;
}
int validateTotalMarsk(float min, float maj){
    float total = min + maj;
    if (total >= 0.00 && total <= 100) return 1;
    return 0;
}
int main(){
    FILE *fin, *fout;
    struct Student s;
    fin =  fopen("input.txt", "r");
    fout = fopen("output.txt", "w");
    int n;
    fscanf(fin, "%d", &n);
    fscanf(fin,"%s %s", s.id, s.name);
    for (int i = 0; i < 5; i++){
        fscanf(fin,"%f %f", &s.subjects[i].minor, &s.subjects[i].major);
        float min = s.subjects[i].minor;
        float maj = s.subjects[i].major;
        if(!validateMinor(min) || !validateMajor(maj)){
            fprintf(fout,"Invalid marks of suject %d\n", i+1);
        }
        if(validateTotalMarsk(min,maj)){
            s.subjects[i].total = min + maj;
        }
        assignGrade(&s.subjects[i]);
        s.totalMarks += s.subjects[i].total;
    }

    fprintf(fout, "\n==================================\n");
        fprintf(fout, "Student ID   : %s\n", s.id);
        fprintf(fout, "Student Name : %s\n", s.name);
        fprintf(fout, "----------------------------------\n");
        fprintf(fout, "Sub  Minor  Major  Total  Grade\n");

        for (int i = 0; i < 5; i++) {
            fprintf(fout,
                "%3d  %5.1f  %5.1f  %5.1f   %s\n",
                i + 1,
                s.subjects[i].minor,
                s.subjects[i].major,
                s.subjects[i].total,
                s.subjects[i].grade);
        }

        fprintf(fout, "Total Marks : %.1f\n", s.totalMarks);
        fprintf(fout, "==================================\n");
    

    fclose(fin);
    fclose(fout);
    return 0;
}