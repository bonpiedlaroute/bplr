#include <stdio.h>
#include <string.h>


/* not compile, have to complete the function readlines, writelines, qsort
defined in the book
*/
int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);

    if( v1 < v2)
        return -1
    else if( v1 > v2)
        return 1;
    else
        return 0;
}

int reverse_numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);

    if( v1 > v2)
        return -1
    else if( v1 < v2)
        return 1;
    else
        return 0;
}

int reverse_strcmp(char *s, char *t)
{

    for( ; *s == *t; s++, t++)
    {
        if( *s == '\0' )
            return 0;
    }
    return *t-*s;
}

int fold_strcmp(char *s, char *t)
{
    for( ;toupper(*s) == toupper(*t); s++, t++)
    {
        if( *s =='\0' )
            return 0;
    }

    return toupper(*s) -toupper(*t) ;
}

int fold_reverse_strcmp(char *s, char *t)
{

    for( ; toupper(*s) == toupper(*t); s++, t++)
    {
        if( *s == '\0' )
            return 0;
    }
    
    return toupper(*t)-toupper(*s);
}

int main(int argc, char *argv[])
{
    int numeric = 0, reverse = 0, fold = 0;
    int (*comp)(char*, char*) cmp;

    while( --argc > 0 && (*++argv)[0] =='-' )
    {
        while( c = *++argv[0] )
        {
            switch(c)
            {
                case 'n':
                {
                    numeric = 1;
                    break;
                }
                case 'r':
                {
                    reverse = 1;
                    break;
                }
                case 'f':
                {
                    fold = 1;
                    break;
                }
                default:
                {
                    printf("error: illegal option %c\n", c);
                    argc = -2;
                    break;
                }
            }
        }
    }

    if( argc != 0 )
    {
        printf("Usage: exercise5-15 -r -n -f\n");
        return -1;
    }
    if( numeric && fold )
    {
        printf("Error: usage of -n option with -f is not allow\n");
        return -1;
    }

    if( numeric )
    {
        if( reverse )     
           cmp = reverse_numcmp;
        else
           cmp = numcmp;
    }
    else
    {
        if( reverse )
        {
            if( fold )
            cmp = fold_reverse_strcmp;
            else
            cmp = reverse_strcmp;
        }
        else
        {
            if( fold )
            cmp = fold_strcmp;
            else            
            cmp = strcmp;
        }
    }

    if( (nlines = readlines(lineptr, MAXLINES)) >= 0 )
    {
        qsort( (void **) lineptr, 0, nlines-1, (int (*) (void*, void*) ) cmp );
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("input too big to sort\n");
        return 1;
    }

}
