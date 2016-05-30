#include <stdio.h>

#define MAX_CHARACTERS 100

int m_getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i< lim - 1 && (c = getchar()) !=  EOF && c != '\n'; ++i)
        s[i] = c;

    if ( c == '\n' )
    {    
        s[i] = c;
        ++i;
    }
    
    s[i] = '\0';

    return i;
}

void reverse(char s[], int lastelement)
{
    int i = 0, j = 0;
    char c;

    for( i = 0, j = lastelement; i < j ; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int main(int argc, char* argv[])
{
    char s[MAX_CHARACTERS];
    int len = 0, lastelement_for_reverse = 0;

    while ( (len = m_getline(s, MAX_CHARACTERS)) > 0)
    {
        if( s[len - 1] == '\n' && len > 1)
        lastelement_for_reverse = len - 2;
        else
        lastelement_for_reverse = len - 1;

        reverse(s, lastelement_for_reverse);
        printf("%s",s);
    }

    return 0;
}
