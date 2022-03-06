//A01748931
#include <stdio.h>
double calcularPi(double iteraciones) {
  double numerador = 4;
  double denominador = 1; // A este lo vamos a ir aumentando de 2 en 2
  double pi = 0;
  int x = 0;
  // Recuerda que es alternar entre negativo y positivo; por eso la bandera.
  // Comenzamos en positivo
  int operador = 1;
  for (x; x < iteraciones; x++) {
    pi += operador * (numerador / denominador);
    denominador += 2; // El denominador aumenta de 2 en 2
    operador *= -1;   // Alternamos operador
  }
  return pi;
}
void main() {
    printf("La serie de Leibniz con 1000 iteraciones: %f \n",serieLeibniz(1));
    printf("La serie de Leibniz con 10000 iteraciones: %f \n",serieLeibniz(2));
    printf("La serie de Leibniz con 1000000 iteraciones: %f \n",serieLeibniz(3));
    return 0;
}

