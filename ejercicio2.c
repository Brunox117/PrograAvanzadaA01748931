#include <stdio.h>
int main()
{
    unsigned long long x = 19;
    int i = 0;
    for (i = 0; i < 30; i++ ){
      printf("y << 61 = %lld\n", x << i);
    } 
    return 0;
}