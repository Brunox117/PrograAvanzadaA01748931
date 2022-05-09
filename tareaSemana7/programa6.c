// Crea un programa que cambie las mayusculas por minusculas y las minusculas por mayusculas
// en un archivo. En el programa anterior esta el ejemplo para leer argumentos de la linea de
// comandos. Usa la-luna.txt
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

int main(void) {
    const char* filename = "la-luna.txt";
    const char* filename2 = "la-luna2.txt";

    FILE* input_file = fopen(filename, "r+");
    if (!input_file)
        exit(EXIT_FAILURE);
    FILE* input_file2 = fopen(filename2, "w+");//Con w+ creamos un archivo
    if (!input_file)
        exit(EXIT_FAILURE);
    do{
      int letra = fgetc(input_file);//Obtiene un caracter del archivo
      if(letra != EOF){ //Pregunta si el caracter es el final del archivo (-1)
        char x = (char)letra;
        if(x >= 'a' && x <= 'z')
            x = toupper(x);
        else if(x >= 'A' && x<= 'Z')
            x = tolower(x);
        fputc(x,input_file2);//escribimos el caracter en el archivo laluna2
      }
    }while(!feof(input_file));

    fclose(input_file);
    fclose(input_file2);
    exit(EXIT_SUCCESS);
}

// Usa file stdio.
