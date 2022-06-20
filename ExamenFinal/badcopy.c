#include <stdio.h>

char buffer[4096];

int main(int argc, char *argv[]) {
    FILE *fin, *fout;

    if(argc < 3) {
        printf("Faltan parametros\n");
        return -1;
    }

    fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "wb");
    while(1) {
        fgets(buffer, 4096, fin);
        if(feof(fin)) break;
        fputs(buffer, fout);
    }
}
