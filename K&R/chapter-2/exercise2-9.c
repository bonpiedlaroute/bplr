#include <stdio.h>

int bitcount(unsigned int x)
{
    int b;
    for( b = 0; x != 0; x &= (x - 1), b++);

    return b;
}

int main(int argc, char *argv[])
{
    int v = 0;    
    v = bitcount(25943001);
    
    printf("Number of 1-bits:  %d\n",v);
    return 0;
}
