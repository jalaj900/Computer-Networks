//copy one array to another using pointer

#include <stdio.h>
int main()
{
    int a[5], b[5];
    int *p1 = a;
    int *p2 = b;

    printf("Enter array elements: ");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", (p1 + i));
    }

    p1 = a;
    for (int i = 0; i < 5; i++)
    {
        *(p2++) = *(p1++);
    }

    p2 = b;
    printf("Final array elements after copying: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(p2 + i));
    }
}
