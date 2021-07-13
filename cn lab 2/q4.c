//swap two arrays using pointers

#include <stdio.h>
int main()
{
    int a[5], b[5];
    int *p1 = a;
    int *p2 = b;

    printf("Enter 1st array elements: ");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", (p1 + i));
    }

    printf("Enter 2nd array elements: ");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", (p2 + i));
    }

    p1 = a;
    p2 = b;

    for (int i = 0; i < 5; i++)
    {
        *(p1 + i) += *(p2 + i);
        *(p2 + i) = *(p1 + i) - *(p2 + i);
        *(p1 + i) -= *(p2 + i);
    }

    printf("\n1st Array elements: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(p1 + i));
    }

    printf("\n2nd Array elements: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(p2 + i));
    }
}