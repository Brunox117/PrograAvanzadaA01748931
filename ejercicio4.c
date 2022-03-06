//A01748931
#include <stdio.h>
int x;
int y = 10;
int main()
{
    int x2;
    int y2 = 10;
    int arr[10];
    printf("global sin inicializar %d\n", sizeof(x));
    printf("global inicializada %d\n", sizeof(y));
    printf("stack sin inicializar %d\n", sizeof(x2));
    printf("stack inicializado %d\n", sizeof(y2));
    printf("array %lu\n", sizeof(arr));
    return 0;
}