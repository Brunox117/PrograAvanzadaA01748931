#include <stdio.h>
int main()
{
    unsigned long long x = 1;
    int i = 0;
    for (i = 0; i < 30; i++ ){
      printf("x << %d = %lld\n",i, x << i);
    } 
    return 0;
}