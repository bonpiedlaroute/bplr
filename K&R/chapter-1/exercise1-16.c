#include <stdio.h>
#define MAXLINE 1000



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

void copy(char to[], char from[])
{
    int i = 0;
    
    while( (to[i] = from[i]) != '\0')
        ++i;
}

int main(int argc, char* argv[])
{
    int len, max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while( (len = m_getline(line, MAXLINE)) > 0)
    {
        if( len > max )
        {
            max = len;
            copy(longest, line);
            printf("nb characters %d:\t%s\n", max, longest);
        }
    }
        if( max > 0 )
        {
            printf("the longest line is \n");
            printf("nb characters%d:\t%s", max, longest);
        }
    

    return 0;
}
