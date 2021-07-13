//calculate monthly pay

#include <stdio.h>
struct employee
{
    char name[50];
    int gross_salary;
} e[100];

void display(struct employee *e, int n)
{
    for (int j = 0; j < n; j++)
    {

        printf("%s\n", e[j].name);
        printf("%d\n", e[j].gross_salary);
    }
}
int main()
{
    int n;
    printf(" enter no. of employees\n");
    scanf(" %d", &n);
    printf(" enter the details of %d employees\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("enter name\n");
        scanf("%s", e[i].name);
        int basic_pay, da;
        printf("Enter the basic pay of the employee");
        scanf("%d", &basic_pay);
        da = 0.52 * basic_pay;
        e[i].gross_salary = basic_pay + da;
    }
    display(e, n);
}