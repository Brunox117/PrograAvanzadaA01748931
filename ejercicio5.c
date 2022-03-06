//A01748931
#include <stdio.h>
double serieLeibniz(double iteraciones) {
  double numerador = 4;
  double denominador = 1; 
  double pi = 0;
  int x = 0;
  int operador = 1;
  for (x; x < iteraciones; x++) {
    pi += operador * (numerador / denominador);
    denominador += 2; 
    operador *= -1;   
  }
  return pi;
}
void main() {
    printf("Leibniz 1000: %f \n",serieLeibniz(1000));
    printf("Leibniz 10000: %f \n",serieLeibniz(10000));
    printf("Leibniz 1000000: %f \n",serieLeibniz(100000));
    return 0;
}

