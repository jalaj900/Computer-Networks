// name of student with highest marks

#include <stdio.h>

#include <string.h>

typedef char st[10];

int main()

{

    st studname[10];

    int marks[10];

    int i;
    int n = 5;
    int imaxpos = 1;

    for (i = 1; i <= n; i++)

    {

        printf("Enter name of %d : ", i);

        scanf("%s", studname[i]);
    }

    for (i = 1; i <= n; i++)

    {

        printf("Enter marks of %d : ", i);

        scanf("%d", &marks[i]);
    }

    for (i = 2; i <= n; i++)

    {

        if (marks[i] > marks[imaxpos])

        {

            imaxpos = i;
        }
    }

    printf("The largest marks=%d\nObtained by student : %d Name: %s\n", marks[imaxpos], imaxpos, studname[imaxpos]);

    return (0);
}