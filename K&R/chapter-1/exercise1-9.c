#include <stdio.h>


int main(int argc, char* argv[])
{
    int c = 0,in_space = 0;


    while ( (c = getchar()) != EOF )
    {
        if( c != ' ' )
        {
            putchar(c);
            in_space = 0;
        }
        else
        {
            if ( in_space == 0 )
            putchar(c);

            in_space++;            
        }

    }
    return 0;
}
