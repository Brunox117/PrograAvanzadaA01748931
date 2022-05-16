#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>

FILE *f;

void handler(int x){
    printf("Soy el padre mi PID es: %d\n",getpid());
}

int main () {
  int n;
  f = fopen("proceso.pid","w+");
  if (!fork()){
    fprintf(f, "%d", getpid());
    fflush(f);
    signal(SIGUSR1, handler);
    if(!fork()){
      if(!fork()){
        printf("soy el nieto mi PID es: %d y el de mi padre: %d\n", getpid(), getppid());
        sleep(3);
        f = fopen("proceso.pid","r");
        fscanf(f, "%d", &n);
        kill((pid_t)n,SIGUSR1);
      }
      wait(0);
    }
    wait(0);
  }
}
