//Archivo de pruebas
#include<stdio.h>
#include<stdlib.h>

int main()
{
    for (int i=0; i<10000000; i++)
    {
       int *ptr = (int *)malloc(sizeof(int));
    }
    return 0;
}
