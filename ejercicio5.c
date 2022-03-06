//A01748931
#include <stdio.h>
long double serieLeibniz(int iteraciones) {
    int signo = 1;
    int denominador = 1;
    long double pi = 0;
    for (int i = 0; i < iterations; i++) {
        pi += signo * (4/denominador);
        signo *= -1;
        denominador += 2;
    }
    return pi;
}
void main() {
    printf("La serie de Leibniz con 1000 iteraciones: %LF \n",serieLeibniz(1000));
    printf("La serie de Leibniz con 10000 iteraciones: %LF \n",serieLeibniz(10000));
    printf("La serie de Leibniz con 1000000 iteraciones: %LF \n",serieLeibniz(1000000));
    return 0;
}

