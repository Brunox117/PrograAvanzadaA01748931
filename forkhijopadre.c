#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
void main(){
  pid_t pid_padre,pid_hijos;
  pid_padre=fork();
  if(pid_padre==0){
    for(int i=2;i>=1;i--){
      printf("Soy el hijo %d, Mi padre es= %d, Mi PID= %d\n",i,getppid(),getpid());
    }
    printf("Proceso PADRE = %d\n",getppid());
  }else{
    pid_hijos=wait();
  }
  exit(0);
}
