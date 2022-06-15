#include<stdio.h>

int main()
{
  printf("The number of eggs for today is:\n");
  int eggs;
  scanf("%i", &eggs);

   double dozen= (double) eggs / 12.0;

    printf(" You have %f dozen eggs.\n", dozen);
  return 0;
}
