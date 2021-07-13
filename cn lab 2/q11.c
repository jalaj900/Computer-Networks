//name and branch of student using pointers

#include <stdio.h>
typedef struct student
{
    char name[50];
    char branch[4];
} student;

student input_details(student *s)
{
    printf("Enter student's name: ");
    gets(s->name);

    printf("Enter student's branch: ");
    gets(s->branch);
}

void display_details(student *p)
{
    printf("\nName: %s", p->name);
    printf("\nBranch: %s", p->branch);
}

int main()
{
    student p;
    student *s = &p;
    input_details(s);
    display_details(s);
}