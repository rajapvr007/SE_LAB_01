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
int validateStudentID(char id[]) {
    for (int i = 0; id[i] != '\0'; i++) {
        if (!((id[i] >= 'A' && id[i] <= 'Z') ||
              (id[i] >= 'a' && id[i] <= 'z') ||
              (id[i] >= '0' && id[i] <= '9'))) {
            return 0;  
        }
    }
    return 1;  
}

int validateName(char name[]) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (!((name[i] >= 'A' && name[i] <= 'Z') ||
              (name[i] >= 'a' && name[i] <= 'z'))) {
            return 0;   
        }
    }
    return 1;   
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
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    float average;
    if (!fin || !fout) {
        printf("File error\n");
        return 1;
    }
    int n;
    fscanf(fin, "%d", &n);
    struct Student s[n];
    for (int i = 0; i < n; i++){
        s[i].totalMarks = 0;
        
        fscanf(fin,"%s %s", s[i].id, s[i].name);
        if (!validateStudentID(s[i].id)) {
        fprintf(fout, "Invalid Student ID (must be alphanumeric)\n");
        return 0;
        }

        if (!validateName(s[i].name)) {
        fprintf(fout, "Invalid Name (only alphabets allowed)\n");
        return 0;
        }
        for (int j = 0; j < 5; j++){
            fscanf(fin,"%f %f", &s[i].subjects[j].minor, &s[i].subjects[j].major);
            float min = s[i].subjects[j].minor;
            float maj = s[i].subjects[j].major;
            if(!validateMinor(min) || !validateMajor(maj)){
                fprintf(fout,"Invalid marks for Student %s subject %d\n",s[i].id, j+1);
                s[i].subjects[j].total = 0;
                strcpy(s[i].subjects[j].grade, "NA");
                continue;
            }
            s[i].subjects[j].total = s[i].subjects[j].minor + s[i].subjects[j].major;
            assignGrade(&s[i].subjects[j]);
            s[i].totalMarks += s[i].subjects[j].total;
        }
    }
    float totalSumPercentage, highestPercentage = INT_MIN, lowestPercentage = INT_MAX,percentage;
    for (int i = 0; i < n; i++) {
        fprintf(fout, "\n==================================\n");
        fprintf(fout, "Student ID   : %s\n", s[i].id);
        fprintf(fout, "Student Name : %s\n", s[i].name);
        fprintf(fout, "----------------------------------\n");
        fprintf(fout, "Sub  Minor  Major  Total  Grade\n");

        for (int j = 0; j < 5; j++) {
            fprintf(fout,
                "%3d  %5.1f  %5.1f  %5.1f   %s\n",
                j + 1,
                s[i].subjects[j].minor,
                s[i].subjects[j].major,
                s[i].subjects[j].total,
                s[i].subjects[j].grade);
        }
        //find the percentage and class lowest and highest percentage
        percentage = (s[i].totalMarks / 500.0) * 100.0;
        if (percentage > highestPercentage)
            highestPercentage = percentage;

        if (percentage < lowestPercentage)
            lowestPercentage = percentage;

        totalSumPercentage += percentage;
        fprintf(fout, "----------------------------------\n");
        fprintf(fout, "Total Marks : %.1f\n",
                s[i].totalMarks);
                fprintf(fout, "Percentage : %.1f%%\n",percentage);
        fprintf(fout, "==================================\n");
    }
    fprintf(fout,"Class Average percentage : %.1f%%\n", totalSumPercentage/n);
    fprintf(fout,"Class Highest percentage : %.1f%%\n", highestPercentage);
    fprintf(fout,"Class lowest percentage : %.1f%%\n", lowestPercentage);
    fclose(fin);
    fclose(fout);
    return 0;
}