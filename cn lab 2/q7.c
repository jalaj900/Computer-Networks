//add two distance in feet and inches using pointers
#include <stdio.h>

struct Distance
{
  int feet;
  float inch;
} first_Dist, second_Dist, sum;
int main()
{
  printf("Enter feet and inch for the first distance: ");
  scanf("%d %f", &first_Dist.feet, &first_Dist.inch);

  printf("Enter feet and inch for the second distance: ");
  scanf("%d %f", &second_Dist.feet, &second_Dist.inch);

  sum.feet = first_Dist.feet + second_Dist.feet;
  sum.inch = first_Dist.inch + second_Dist.inch;

  while (sum.inch >= 12)
  {
    sum.inch = sum.inch - 12;
    sum.feet++;
  }

  printf("\nSum is %d feet, %.1f inches: ", sum.feet, sum.inch);
  return 0;
}