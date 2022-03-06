//A01748931
#include <stdio.h>
long double serieLeibniz(int iterations) {
    int signo = 1;
    int denominador = 1;
    long double pi = 0;
    for (int i = 0; i < iterations; i++) {
        pi = pi + signo * (4/denominador);
        signo = signo * -1;
        denominador += 2;
    }
    return pi;
}
void main() {
    printf("La serie de Leibniz con 1000 iteraciones: %lf \n",serieLeibniz(1000));
    printf("La serie de Leibniz con 10000 iteraciones: %lf \n",serieLeibniz(10000));
    printf("La serie de Leibniz con 1000000 iteraciones: %lf \n",serieLeibniz(1000000));
    return 0;
}

