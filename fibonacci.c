/*
Made by: Youssof Soliman
Fibonacci sequence programe
Last edited: 15/6/2022
*/

#include <stdio.h>

void fibonacci()
{
  long n, n1 = 0, n2 = 1, nextN = 0; // First two numbers are always 0 and 1

  printf("Enter desired terms: ");
  scanf("%ld", &n);
  printf("Sequence: \n");

  for (int i = 1; i <= n; ++i)
  {
    if (i == 1)
    {
      printf("%ld, ", n1);
      continue;
    }
    if (i == 2)
    {
      printf("%ld, ", n2);
      continue;
    }
    nextN = n1 + n2;
    n1 = n2; // Responsible for making the second number become the first number so that it moves along
    n2 = nextN;

    printf("%ld, ", nextN);
  }
}

int main()
{
  fibonacci();
  return 0;
}