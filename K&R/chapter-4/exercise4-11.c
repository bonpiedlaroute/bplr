#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

char s[]="ajlkjalkjlkaj kjdlkjlkjlkjl";

int getop(char s[])
{
    int i, c;
    static int buf[BUFSIZE];
    static int bufp = 0;
    
    do
    {
        if( bufp > 0 )
            c = buf[--bufp];
        else
            c = getchar();

        s[0] = c;
    }while( c == ' ' || c =='\t' );

    s[1] = '\0';

    if( !isdigit(c) && c != '.' )
          return c;

    i = 0;
    
    if( isdigit(c))
    {
        do
        {        
            if( bufp > 0 )
                c = buf[--bufp];
            else
                c = getchar();

            s[++i] = c;
        } while( isdigit(c) ) ;
    }

    if( c == '.' )
    {
        do
        {        
            if( bufp > 0 )
                c = buf[--bufp];
            else
                c = getchar();

            s[++i] = c;
        } while( isdigit(c) ) ;
    }

    s[i] = '\0';

    if( c != EOF )
    {
        if( bufp >= BUFSIZE )
            printf("error: too many characters\n");
        else
            buf[bufp++] = c;
    }

    return NUMBER;
}

int main(int argc, char *argv[])
{



    return 0;
}
