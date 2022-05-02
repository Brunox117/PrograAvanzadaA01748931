// Escribe un programa que cuente la cantidad de lineas en un archivo. Usa la-luna.txt
#include<stdio.h>

int main(){

char ca;
int cont;

FILE *puntero;
puntero = fopen("la-luna.txt","r");

while(1){

      ca = fgetc(puntero);

      if(ca == '\n'){
          cont++;
      }
      if(ca == EOF){ 
          printf("%d",cont);
          break;
      }
  }
    return 0;
}
