//A01748931
#include <stdio.h>

int y; //Variable Global
int x = 10; //Variable globar con valor inicial del
char arr[20]; //Arreglo
int main() {
    int w = 1; //Variable en Stack
    char nombre[20];
    printf("Size of Global Variable: %lu\n", sizeof(y));
    printf("Size of Global Variable w/InitialValue: %lu\n", sizeof(x));
    printf("Size of Stack Variable: %lu\n", sizeof(w));
    printf("Size of Global Array: %lu\n", sizeof(arr));
    printf("Size of Stack Array: %lu\n", sizeof(nombre));
    return 0;
}