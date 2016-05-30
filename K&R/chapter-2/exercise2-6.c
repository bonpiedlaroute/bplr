#include <stdio.h>

unsigned int setbits( unsigned x, int p, int n, unsigned y)
{
    unsigned int x_m = 0, y_m = 0;
    
    y_m = ( ~(~0 << n ) & y ) << p  ;

    x_m = ~( ~(~0 << n ) << p ) & x;

    return x_m | y_m;
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
    print_bits(11550727);
    printf("y:");
    print_bits( 45101);
    v = setbits( 11550727,12 , 4 , 45101);
    printf("r:");
    print_bits(v);
    return 0;
}
