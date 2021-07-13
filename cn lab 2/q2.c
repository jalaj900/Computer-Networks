//input and print array using pointers

#include <stdio.h>
int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    int * p = arr;
    printf("Enter elements in array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (p+i));
    }

    printf("Array : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(p+i));
    }

}