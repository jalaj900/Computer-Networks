// search element in an array using pointers

#include <stdio.h>

#include <stdlib.h>
int main(void)

{

    int n, i, pos = -1, *a, element;

    printf("Enter size of array:");
    scanf("%d", &n);

    a = calloc(sizeof(int), n);
    printf("Enter %d Elements:", n);
    for (i = 0; i < n; i++)

    {

        scanf("%d", a + i);
    }

    printf("Enter a element to find:");
    scanf("%d", &element);

    for (i = 0; i < n; i++)

    {

        if (*(a + i) == element)
        {
            pos = i;
            break;
        }
    }

    printf("%d is in %d", element, pos);
    return 0;
}