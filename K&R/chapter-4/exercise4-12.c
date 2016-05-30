#include <stdio.h>

void itoa(int n, char s[])
{
    static int i;
    
    if( n < 0 )
    {
        s[0] = '-';
        n = -n;
        i = 1;
    }
    else
        i = 0;

    if( n / 10 )
        itoa( n / 10, s);

    s[i++] = n % 10 + '0' ;
}

int main(int argc, char * argv[])
{
    


    return 0;
}
