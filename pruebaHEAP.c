#include <stdlib.h>
#include <stdio.h>
int main() {
    char c;
    char *ptr = malloc(1);
    printf("stack at %p", ptr);
    return 0;
}