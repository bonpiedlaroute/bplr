#include <stdio.h>

/* n <= 32 */
unsigned int rightrot(unsigned int x, unsigned int n)
{
    unsigned int y = 0, r = 0;

    y = (~( ~(unsigned int )0 << n ) & x ) ;

    y = y << (32 - n);

    y = (y |  ~(unsigned int )0 >> n );

    r = (y) & ( ~(~(unsigned int )0 >> n ) | (x >> n) );

    return r;
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

int main(int argc, char * argv[])
{
    unsigned int v = 0;
    
    printf("x:");
    print_bits(623650146);
    v = rightrot(623650146,6);
    printf("r:");
    print_bits(v);

    printf("x1:");
    print_bits(516458006);
    v = rightrot(516458006,9);
    printf("r1:");
    print_bits(v);
    
    return 0;
}
