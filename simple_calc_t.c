#include <stdio.h>
#include <math.h>
// double pow(double x, double y);
int main() {

  char op;
  double first, second;
  printf("Enter an operator (+, -, *, /, #): ");
  scanf("%c", &op);

  printf("Enter two operands: ");
  scanf("%lf %lf", &first, &second);

  switch (op) {
    case '+':
      printf("%.1lf + %.1lf = %.1lf", first, second, first + second);
      break;
    case '-':
      printf("%.1lf - %.1lf = %.1lf", first, second, first - second);
      break;
    case '*':
      printf("%.1lf * %.1lf = %.1lf", first, second, first * second);
      break;
    case '/':
      printf("%.1lf / %.1lf = %.1lf", first, second, first / second);
      break;
    case '#':
        printf("let's see some power");

        {
            //int base, exp;
            long double result = 1.0;
            // printf("Enter a base number: ");

            //scanf("%d", &base);
            // printf("Enter an exponent: ");

            //scanf("%d", &exp);

            while (second != 0) {
                result *= first;
                --second;
            }
            printf("Answer = %.0Lf", result);

        break;
    // operator doesn't match any case constant
    default:
      printf("Error! operator is not correct");
       }
     }
  return 0;
}
