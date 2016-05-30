#include <ctype.h>


int getch();
void ungecth(int);

int getfloat(float *pn)
{

    int c;
    float sign, power;

    while( isspace( c = getch() ) ) ;

    if( !isdigit(c) && c != EOF && c != '+' && c != '-' )
    {
        ungetch(c);
        return 0;
    }

    sign = ( c == '-' ) ? -1.0 : 1.0;

    if( c == '+' || c == '-' )
    {
        c = getch();
        
        if( !isdigit(c) )
        {
            ungetch(c);
            return 0;
        }
    }

    for(*pn = 0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (float) ( c - '0');


    if( c == '.' )
    {
        c = getch();
        
        for(power = 1.0; isdigit(c); c = getch())
        {
            *pn = 10.0 * *pn + (float) (c - '0');
            power *= 10.0;
        }

    }
    
    *pn = sign * *pn / power ;
    
    if( c != EOF )
        ungetch(c);

    return c;
}
