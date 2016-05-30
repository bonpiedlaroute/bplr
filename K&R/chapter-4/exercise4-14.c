#include <stdio.h>

#define swap(t,x,y) {t temp = x; \
                     x = y; \
                     y = temp;}

int main(int argc, char *argv[])
{
    int a = 4, b = 15;

    printf("a : %d; b : %d\n",a,b);

    swap(int, a, b);

    printf("a : %d; b : %d\n",a,b);

    return 0;
} 
