#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define DEFAULT_NBLINES 10

#define MAXLEN  1000

#define MAXNBLINES  300

static char *lineptr[MAXNBLINES];
static int start = 0;
static int end = 0;
static int begin = 1;

static char line[MAXLEN];

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

int tail(int n)
{
    int len = 0, i = 0;
    char *p = NULL;

    while( (len = m_getline(line, MAXLEN)) > 0 )
    {
        if( (p = (char *) malloc((len+1)*sizeof(char))) == NULL )
        {
            printf("no memory available\n");
            return -1;
        }
        else
        {
            strcpy(p, line);
            
            if(begin)
            {
                lineptr[end++] = p;
                begin = 0;
            }
            else
            {
                if( end >= n )
                    end = 0;
                if( start >= n )
                    start = 0;

                if( start == end )
                {
                    free(lineptr[start]);

                    lineptr[end++] = p;
                    start++;
            
                }
                else
                {
                    lineptr[end++] = p;
                }

            }
        }
    }

    printf("Last %d lines:\n", n);

    for(i = start; i != end - 1; i++)
    {
        if( i >=  n)
            i = 0;

        printf("%s", lineptr[i]);
    }

    printf("%s", lineptr[end - 1]);
    return 1;

}

int main(int argc, char *argv[])
{
    int n = 0;

    if( argc > 2 )
    {
        printf("error: too many arguments\n");
        return -1;
    }

    if( argc != 2)
        n =  DEFAULT_NBLINES;
    else
    {
        if( (*++argv)[0] != '-')
        {
            printf("error: unrecognized argument\n");
            return -1;
        }
        
        n = atoi(++argv[0]);
        if( n >= MAXNBLINES )
        {
            printf("error: too many lines\n");
            return -1;
        }
    }

    tail(n);
    return 0;
}
