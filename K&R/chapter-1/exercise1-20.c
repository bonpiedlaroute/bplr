#include <stdio.h>

void detab(int n)
{
    int c, i = 0;

    while( (c=getchar()) != EOF )
    {
        if( c == '\t')
        {
            for( i = 0; i < n; i++)            
            putchar(' ');
        }
        else
            putchar(c);


    }
}

int main(int argc, char *argv[])
{
    detab(4);

    return 0;
}
