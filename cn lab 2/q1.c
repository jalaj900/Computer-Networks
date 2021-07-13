//swap values using pointers

#include <stdio.h>

int main()
{
   int x, y, *a, *b, temp;

   printf("Enter the value 2 variables\n");
   scanf("%d %d", &x, &y);

   printf("Before Swapping  %d %d\n", x, y);

   a = &x;
   b = &y;

   temp = *b;
   *b = *a;
   *a = temp;

   printf("After Swapping  %d %d\n", x, y);
}