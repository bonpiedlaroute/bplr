#include <stdio.h>
#include <string.h>

#define MAXLINES    5000    /* max #lines to be sorted */

#define MAXLEN  1000    /* max length of any input line */


char lineptr[MAXLINES][MAXLEN];



int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;

    char *p, line[MAXLEN];

    nlines = 0;

    while( (len = getline(line, MAXLEN) ) > 0 )
    {
        if( nlines >= maxlines )
            return -1;
        else
        {
            line[len - 1] = '\0';
            strcpy(lineptr[nlines], line);
            nlines++;
        }
    }

    return nlines;
}

int main(int argc, char *argv[])
{




    return 0;
}
