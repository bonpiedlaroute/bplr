#include <stdio.h>

int buf = -1;

int getch()
{
    int result;
    if (buf > 0 )
    {
        result = buf ;
        buf = -1;
    }
    else 
        result = getchar();

    return result;
}
void ungetch(int c)
{
    buf = c;
}

