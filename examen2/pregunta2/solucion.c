#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>

FILE *file;

void handler(int x){
    printf("Soy el padre mi PID es: %d\n",getpid());
}

int main () {
  int n;
  file = fopen("proceso.pid","w+");
  if (!fork()){
    fprintf(file, "%d", getpid());
    fflush(file);
    signal(SIGUSR1, handler);
    if(!fork()){
      if(!fork()){
        printf("soy el nieto mi PID es: %d y el de mi padre: %d\n", getpid(), getppid());
        sleep(3);
        file = fopen("proceso.pid","r");
        fscanf(file, "%d", &n);
        kill((pid_t)n,SIGUSR1);
      }
      wait(0);
    }
    wait(0);
  }
}

