//A01748931
#include<stdio.h>
#include<stdlib.h>

int main()
{
    char *p;
    int x = 0;
    while(1){
        x++;
        p = malloc(1024);
        printf("Iteracion %d el tamaño es: %ld",x,sizeof(p));
    }
}
