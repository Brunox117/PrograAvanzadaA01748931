#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
	int linea,x;
	char data[51][80];
	srandom(getpid());
	//random()%51
	FILE * archivo = fopen("sayings.txt","r");
	x=51;
	while(x>0){
		fgets(data[linea],80,archivo);
		linea++;
		x--;
	}
	printf("%s\n",data[random()%51]);
 exit(0);
}
