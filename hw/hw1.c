#include <stdio.h>
#include <math.h>
int main(){
  //1_12
  float a,b,c,T;
  a = 1 / (1 + (1/3));
  b = 1 / (7 + 1 / a);
  c = 1 / (4 + b);
  T = 365 + c;
  printf("T = %f\n",T);

  //1_16

    printf("x    | -1 - | - 2 - | - 3 - | - 4 -  | - 5 - |\n");
    printf("-----|-----|-----|-----|-----|-----|\n");

    // a
    printf("F(x) = e^(-x^2) |");
    for (int x = 1; x <= 5; x++) {
      double fx = exp(-pow(x, 2));
      printf(" %.2f |", fx);
    }
    printf("\n");
  //b
    printf("F(x) = sqrt(x)  |");
    for (int x = 1; x <= 5; x++) {
      if (x < 0) {
        printf(" NaN |");
      } else {
        double fx = sqrt(x);
        printf(" %.2f |", fx);
      }
    }
    printf("\n");
  }

