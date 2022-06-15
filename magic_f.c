#include<stdio.h>

int main()
{
  int radius; //dist from outside to center of the circle
 printf("please enter a radius in cm\n");
  scanf("%i", &radius); // address of operatir


   double area= 3.14159 *(radius *radius);

  printf("The area of a circe with %i cm radius is %f cm_square\n", radius, area);
  return 0;
}
