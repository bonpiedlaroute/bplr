#include <stdio.h>
#include <stdlib.h>


#define DEFAULT_TAB_STOP    4
#define DEFAULT_COLUMN_LIMIT    80

void detab(int n, int limit)
{
    int c, i = 0, nbcolumn = 0;

    while( (c=getchar()) != EOF )
    {
        if( c == '\n')
            nbcolumn = 0;
        else
            nbcolumn++;

        if( nbcolumn >= limit && c == '\t')
        {
            for( i = 0; i < n; i++)            
            putchar(' ');
        }
        else
            putchar(c);


    }
}

void entab(int n, int limit)
{
	int c = 0, nbcurrentspace = 0, i, nbcolumn = 0;
	
	while( (c = getchar()) != EOF )
	{
        if( c == '\n')
            nbcolumn = 0;
        else
            nbcolumn++;

		if( nbcolumn >= limit && c == ' ')
		{
			if( ++nbcurrentspace == n )
			{
				putchar('\t');
                nbcurrentspace = 0;
			}

		}
        else
        {
            if( nbcurrentspace > 0)
            {
                for( i = 0; i < nbcurrentspace; i++)
                    putchar(' ');

                nbcurrentspace = 0;
            }
            putchar(c);
        }
	}
}

int main(int argc, char *argv[])
{
    int tab_stop = DEFAULT_TAB_STOP, c, column_limit = DEFAULT_COLUMN_LIMIT;  

    if( argc > 3 )
    {
        printf("too many arguments\n");
        return -1;
    }

    while( --argc > 0  )
    {
        ++argv;
        c = (*argv)[0]; 
        switch(c)
        {
            case '-':
            {
                tab_stop = atoi(*(++argv));
                break;
            }
            case '+':
            {
                column_limit = atoi(*(++argv));
                break;
            }
            default:
            {
                printf("error: unrecognised argument\n");
                break;
            }

        }
    }

    entab(tab_stop, column_limit);

    detab(tab_stop, column_limit);

    return 0;
}
