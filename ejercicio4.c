//A01748931
#include <stdio.h>
int x;
int y = 10;
int main()
{
    int x2;
    int y2 = 10;
    int arr[10];
    printf("global sin inicializar %lu\n", sizeof(x));
    printf("global inicializada %lu\n", sizeof(y));
    printf("stack sin inicializar %lu\n", sizeof(x2));
    printf("stack inicializado %lu\n", sizeof(y2));
    printf("array %lu\n", sizeof(arr));
    return 0;
}