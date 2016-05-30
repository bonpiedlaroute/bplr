#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_TAB_STOP    4

void detab(int n)
{
    int c, i = 0;

    while( (c=getchar()) != EOF )
    {
        if( c == '\t')
        {
            for( i = 0; i < n; i++)            
            putchar(' ');
        }
        else
            putchar(c);


    }
}

void entab(int n)
{
	int c = 0, nbcurrentspace = 0, i;
	
	while( (c = getchar()) != EOF )
	{
		if( c == ' ')
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
    int n = DEFAULT_TAB_STOP;  

    if( argc > 2 )
    {
        printf("too many arguments\n");
        return -1;
    }

    if( --argc > 0 )
    {
        n = atoi(*(++argv));
    }

    entab(n);

    detab(n);

    return 0;
}
