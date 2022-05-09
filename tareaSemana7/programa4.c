#include <stdio.h>
#include <stdlib.h>

// Crear un programa que reciba como parametros dos archivos y los compare
// Usar file i/o

void usage(char *arg) {
	fprintf(stderr, "Debes ejecutar %s con 2 argumentos\n", arg);
	exit(0);
}

int main (int argc, char *argv) {
	if (argc < 3) usage(argv[0]);
	// Si el programa se ejecuta como ./programa4 archivo1.txt archivo2.txt
	// argv[1] contiene archivo1.txt y argv[2] contiene archivo2.txt
	const char* filename = argv[1];
    const char* filename2 = argv[2];

    FILE* input_file = fopen(filename, "r+");
    if (!input_file)
        exit(EXIT_FAILURE);
    FILE* input_file2 = fopen(filename2, "w+");//Con w+ creamos un archivo
    if (!input_file)
        exit(EXIT_FAILURE);
    do{
      int letra = fgetc(input_file);//Obtiene un caracter del archivo
      int letra2 = fgetc(input_file2);
			printf("%d %d\n",letra,letra2 );
      }while(!feof(input_file));

    fclose(input_file);
    fclose(input_file2);
    exit(EXIT_SUCCESS);
}
