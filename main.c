#include <stdio.h>
struct Student {
    int id;
    char name[50];
    float cgpa;
};

void printStudentInfo(struct Student *students, int n) {
    printf("id\tname\tcgpa\n");
   FILE *fptr;
   fptr = fopen("student.txt", "w");
   if(fptr == NULL)
   {
       printf("Error!");
       exit(1);
   }
    fprintf(fptr,"id\tname\tcgpa\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%.2f\n", students[i].id, students[i].name, students[i].cgpa);
        fprintf(fptr,"%d\t%s\t%.2f\n", students[i].id, students[i].name, students[i].cgpa);
    }
     fclose(fptr);
}

int main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    for (int i = 0; i < n; i++) {
        printf("Enter name for student %d: ", i + 1);
        scanf("%s", students[i].name);
        students[i].id = i + 1;
        printf("Enter CGPA for student %d: ", i + 1);
        scanf("%f", &students[i].cgpa);
    }

    printStudentInfo(students, n);
    return 0;
}
