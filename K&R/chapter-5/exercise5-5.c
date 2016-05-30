#include <stdio.h>


void m_strncpy(char *s, char *t, int n)
{
    if( n == 0)
        return;

    while( n-- > 0 && (*s = *t) != '\0' )
    {
        s++;
        t++;
    }

    *s = '\0';
}

void m_strncat(char *s, char *t, int n)
{
    if( n == 0)
        return;

    while( *s != '\0' ) s++ ;

    while( n-- > 0 && ( *s = *t) != '\0' )
    {
        s++;
        t++;
    }
    
    *s = '\0';
}

int main(int argc, char *argv[])
{
    char r[70];
    m_strncpy(r, "i have a dream", 8);

    printf("%s\n",r);

    m_strncpy(r, "i have a dream", 0);

    printf("%s\n",r);

    m_strncat(r," dream", 6);

    printf("%s\n",r);

    return 0;
}
