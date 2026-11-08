

#include<stdio.h>

#define MAX 100

struct Student{
    int roll_no;
    char name[25];
    char course[10];
    float cgpa;
};

struct Student rec[MAX];
int student_count=0;
void addRecord(){
    if(student_count>MAX){
        printf("Record limit reached\n");
        return;
    }
    struct Student s;
    printf("Enter roll number: ");
    scanf("%d",&s.roll_no);
    printf("Enter name: ");
    scanf("%s",s.name);
    printf("Enter course: ");
    scanf("%s",s.course);
    printf("Enter CGPA: ");
    scanf("%f",&s.cgpa);
    rec[student_count]=s;
    student_count++;
}
void viewAll(){
    for(int i=0;i<student_count;i++){
        printf("Roll No: %d\n",rec[i].roll_no);
        printf("Name: %s\n",rec[i].name);
        printf("Course: %s\n",rec[i].course);
        printf("CGPA: %.2f\n\n",rec[i].cgpa);
    }
}
void searchRecord(){
    if(student_count==0){
        printf("No records found\n");
        return;
    }
    int roll_no;
    printf("Enter roll number to search: ");
    scanf("%d",&roll_no);
    for(int i=0;i<student_count;i++){
        if(rec[i].roll_no==roll_no){
            printf("Roll No: %d\n",rec[i].roll_no);
            printf("Name: %s\n",rec[i].name);
            printf("Course: %s\n",rec[i].course);
            printf("CGPA: %.2f\n\n",rec[i].cgpa);
            return;
        }
    }
    printf("Record not found\n");
}
void modifyRecord(){
    if(student_count==0){
        printf("No records found\n");
        return;
    }
    int roll_no;
    printf("Enter roll number to modify: ");
    scanf("%d",&roll_no);
    for(int i=0;i<student_count;i++){
        if(rec[i].roll_no==roll_no){
            printf("Enter new name: ");
            scanf("%s",rec[i].name);
            printf("Enter new course: ");
            scanf("%s",rec[i].course);
            printf("Enter new CGPA: ");
            scanf("%f",&rec[i].cgpa);
            printf("Record updated successfully\n");
            return;
        }
    }
    printf("Record not found\n");
}
void deleteRecord(){
    if(student_count==0){
        printf("No records found\n");
        return;
    }
    int roll_no;
    printf("Enter roll number to delete: ");
    scanf("%d",&roll_no);
    for(int i=0;i<student_count;i++){
        if(rec[i].roll_no==roll_no){
            for(int j=i;j<student_count-1;j++){
                rec[j]=rec[j+1];
            }
            student_count--;
            printf("Record deleted successfully\n");
            return;
        }
    }
    printf("Record not found\n");
}
void main() {
    while(1){
        int ch=-1;
        printf("Enter option\n");
        printf( "1. Add Record\n2. View All\n3. Search\n4. Modify\n5. Delete\n6.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                addRecord();
                break;
            case 2:
                viewAll();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                modifyRecord();
                break;
            case 5:
                deleteRecord();
                break;
            case 6:
                return;
            default:
                printf("Invalid option\n");
        }
    }
}