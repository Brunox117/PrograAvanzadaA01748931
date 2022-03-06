#include <stdio.h>
int main(){
  unsigned long long int var = 1;
  int i;
  int x;
  for (i = 0; i < 30; i++ ){
      x = (var << i );
      printf(x);
  } 
}