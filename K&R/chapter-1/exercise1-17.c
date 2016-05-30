#include <stdio.h>

#define MAXLINE 1000
#define MAX_CHARACTERS  80



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


int main(int argc, char* argv[])
{
    int len;
    char line[MAXLINE];

    while( (len = m_getline(line, MAXLINE)) > 0)
    {
        if( len > MAX_CHARACTERS )
        {
  
            printf("nb characters %d:\t%s\n", len, line);
        }
    }
    
    return 0;
}
