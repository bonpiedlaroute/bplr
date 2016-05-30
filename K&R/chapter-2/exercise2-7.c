#include <stdio.h>

unsigned int invert(unsigned int x, unsigned int p, unsigned int n)
{
    return x ^ ( ~(~0 << n) << p );
}

void print_bits(unsigned int v)
{
    unsigned int i = 0;

    for(i = 0x80000000; i > 0; i = i >> 1)
    {
        if( (v & i) == 0 )
        printf("0");
        else
        printf("1");
    }
    printf("\n");

}

int main(int argc, char *argv[])
{
    unsigned int v = 0;

    printf("x:");
    print_bits(40569862);
    
    v = invert( 40569862,16, 5);
    printf("r:");
    print_bits(v);

    return 0;
}
