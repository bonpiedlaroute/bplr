#include <stdio.h>
#include <string.h>

void reverse(char s[])
{
    int c, i, j;

    for( i = 0, j = strlen(s) - 1; i < j ; i ++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[], unsigned width)
{
    int i, sign, r = 0;

    if( (sign = n) < 0 )
        n = -n; 

    i = 0;    
    do
    {
        s[i++] = n % 10 + '0';
    }while( (n /= 10) > 0 );

    if( sign < 0 )
        s[i++] = '-';

    for( ; i < width ; i++)
        s[i] = ' ';


    s[i] = '\0';

    reverse(s);
}
int main(int argc, char *argv[])
{
    char s[33];


    printf(" value 2589849\n");
    itoa(2589849, s, 32);
    printf("%s\n", s);

    return 0;
}
