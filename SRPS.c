// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// int countO = 0, countAplus = 0, countA = 0;
// int countBplus = 0, countB = 0, countC = 0, countF = 0;

// struct Subject{
//     float minor, major,total;
//     char grade[3];
// };
// struct Student{
//     char id[50];
//     char name[100];
//     struct Subject subjects[5];
//     float totalMarks, cgpa, percentage;
//     char grade[3];
// };
// void assignGrade(struct Subject *sub) {
//     sub->total = sub->minor + sub->major;

//     if (sub->total >= 90)
//         strcpy(sub->grade, "O");
//     else if (sub->total >= 85)
//         strcpy(sub->grade, "A+");
//     else if (sub->total >= 75)
//         strcpy(sub->grade, "A");
//     else if (sub->total >= 65)
//         strcpy(sub->grade, "B+");
//     else if (sub->total >= 60)
//         strcpy(sub->grade, "B");
//     else if (sub->total >= 55)
//         strcpy(sub->grade, "C");
//     else if (sub->total >= 50)
//         strcpy(sub->grade, "D");
//     else
//         strcpy(sub->grade, "F");
// }
// int validateStudentID(char id[]) {
//     for (int i = 0; id[i] != '\0'; i++) {
//         if (!((id[i] >= 'A' && id[i] <= 'Z') ||
//               (id[i] >= 'a' && id[i] <= 'z') ||
//               (id[i] >= '0' && id[i] <= '9'))) {
//             return 0;  
//         }
//     }
//     return 1;  
// }

// int validateName(char name[]) {
//     for (int i = 0; name[i] != '\0'; i++) {
//         if (!((name[i] >= 'A' && name[i] <= 'Z') ||
//               (name[i] >= 'a' && name[i] <= 'z'))) {
//             return 0;   
//         }
//     }
//     return 1;   
// }
// int validateMinor(float minor){
//     if( minor >= 0 && minor <= 40) return 1;
//     else return 0;
// }
// int validateMajor(float major){
//     if( major >= 0  && major <= 60) return 1;
//     else return 0;
// }
// int validateTotalMarsk(float min, float maj){
//     float total = min + maj;
//     if (total >= 0.00 && total <= 100) return 1;
//     return 0;
// }
// int gradeToPoint(char grade[]) {
//     if (strcmp(grade, "O") == 0) return 10;
//     else if (strcmp(grade, "A+") == 0) return 9;
//     else if (strcmp(grade, "A") == 0) return 8;
//     else if (strcmp(grade, "B+") == 0) return 7;
//     else if (strcmp(grade, "B") == 0) return 6;
//     else if (strcmp(grade, "C") == 0) return 5;
//     else if (strcmp(grade, "D") == 0) return 4;
//     else return 0;   
// }
// float calculateCGPA(struct Student *s) {
//     int credit = 4;
//     int totalCredits = 0;
//     int totalGradePoints = 0;

//     for (int i = 0; i < 5; i++) {
//         int gradePoint = gradeToPoint(s->subjects[i].grade);
//         totalGradePoints += gradePoint * credit;
//         totalCredits += credit;
//     }

//     return (float)totalGradePoints / totalCredits;
// }
// void calculateGrade(float cgpa){
//     if (cgpa >= 9.0)
//         countO++;
//     else if (cgpa >= 8.0)
//         countAplus++;
//     else if (cgpa >= 7.0)
//         countA++;
//     else if (cgpa >= 6.0)
//         countBplus++;
//     else if (cgpa >= 5.0)
//         countB++;
//     else if (cgpa >= 4.0)
//         countC++;
//     else
//         countF++;
// }

// int main(){
//     FILE *fin = fopen("input.txt", "r");
//     FILE *fout = fopen("output.txt", "w");
//     float average;
//     if (!fin || !fout) {
//         printf("File error\n");
//         return 1;
//     }
//     int n;
//     fscanf(fin, "%d", &n);
//     struct Student s[n];
//     for (int i = 0; i < n; i++){
//         s[i].totalMarks = 0;
        
//         fscanf(fin,"%s %s", s[i].id, s[i].name);
//         if (!validateStudentID(s[i].id)) {
//         fprintf(fout, "Invalid Student ID (must be alphanumeric)\n");
//         return 0;
//         }

//         if (!validateName(s[i].name)) {
//         fprintf(fout, "Invalid Name (only alphabets allowed)\n");
//         return 0;
//         }
//         for (int j = 0; j < 5; j++){
//             fscanf(fin,"%f %f", &s[i].subjects[j].minor, &s[i].subjects[j].major);
//             float min = s[i].subjects[j].minor;
//             float maj = s[i].subjects[j].major;
//             if(!validateMinor(min) || !validateMajor(maj)){
//                 fprintf(fout,"Invalid marks for Student %s subject %d\n",s[i].id, j+1);
//                 s[i].subjects[j].total = 0;
//                 strcpy(s[i].subjects[j].grade, "NA");
//                 continue;
//             }
//             s[i].subjects[j].total = s[i].subjects[j].minor + s[i].subjects[j].major;
//             assignGrade(&s[i].subjects[j]);
//             s[i].totalMarks += s[i].subjects[j].total;
//         }
//     }
//     float totalSumPercentage, highestPercentage = INT_MIN, lowestPercentage = INT_MAX,percentage;
//         for (int i = 0; i < n; i++) {
//         fprintf(fout, "\n==================================\n");
//         fprintf(fout, "Student ID   : %s\n", s[i].id);
//         fprintf(fout, "Student Name : %s\n", s[i].name);
//         fprintf(fout, "----------------------------------\n");
//         fprintf(fout, "Subject  Minor  Major  Total  Grade\n");

//         for (int j = 0; j < 5; j++) {
//             fprintf(fout,
//                 "%3d  %5.1f  %5.1f  %5.1f   %s\n",
//                 j + 1,
//                 s[i].subjects[j].minor,
//                 s[i].subjects[j].major,
//                 s[i].subjects[j].total,
//                 s[i].subjects[j].grade);
//         }
//         percentage = (s[i].totalMarks / 500.0) * 100.0;
//         if (percentage > highestPercentage)
//             highestPercentage = percentage;

//         if (percentage < lowestPercentage)
//             lowestPercentage = percentage;

//         totalSumPercentage += percentage;
//         s[i].cgpa = calculateCGPA(&s[i]);

//         calculateGrade(s[i].cgpa);

//         fprintf(fout, "----------------------------------\n");
//         fprintf(fout, "Total Marks : %.1f\n",s[i].totalMarks);
//         fprintf(fout, "Percentage  : %.1f%%\n",percentage);
//         fprintf(fout, "CGPA        : %.1f\n", s[i].cgpa);
//         fprintf(fout, "==================================\n");
//     }
//     fprintf(fout," Average percentage of Class : %.1f%%\n", totalSumPercentage/n);
//     fprintf(fout," Highest percentage of Class: %.1f%%\n", highestPercentage);
//     fprintf(fout," Lowest percentage of Class: %.1f%%\n", lowestPercentage);
//     fprintf(fout, "================================\n");
    

//     fprintf(fout, "\nGRADE DISTRIBUTION      \n");
//     fprintf(fout, "O  Grade  : %d students\n", countO);
//     fprintf(fout, "A+ Grade  : %d students\n", countAplus);
//     fprintf(fout, "A  Grade  : %d students\n", countA);
//     fprintf(fout, "B+ Grade  : %d students\n", countBplus);
//     fprintf(fout, "B  Grade  : %d students\n", countB);
//     fprintf(fout, "C  Grade  : %d students\n", countC);
//     fprintf(fout, "F  Grade  : %d students\n", countF);
//     fprintf(fout, "================================\n");

//     fclose(fin);
//     fclose(fout);
//     return 0;
// }