#include <stdio.h>
#include <string.h>

#define MAXLINE 1024

int m_getline(char s[], int lim)
{
    int c, i;
    
    i = 0;
    while( --lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    
    if( c == '\n' )
        s[i++] = c;

    s[i] = '\0';

    return i;
}

int strindex(char s[], char t[])
{
    int i, j, k;

    for(i = strlen(s) - 1; i >= 0 ; i--)
    {
        for(j = i,  k = strlen(t) -1; k >= 0 && s[j] == t[k]; j--, k--);
        
        if(  k < 0 && k != strlen(t) -1 )
            return i;
    }
    return -1;
}

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    int found = 0, index = 0;

    while( m_getline(line, MAXLINE) > 0 )
    {
        index = strindex(line, "out");
        index = index - strlen("out") + 1;
        if( index >= 0 )
        {
            printf("found at index %d\n", index);            
            printf("%s",line);
            found++;
        }
    }
    
    return found;
}
