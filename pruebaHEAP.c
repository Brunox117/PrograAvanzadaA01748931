#include <stdlib.h>
#include <stdio.h>
int main() {
    char c;
    char *ptr = malloc(1);
    printf("stack at %p, heap at %p\n", &c, ptr);
    printf("Prueba commit");
    return 0;
}