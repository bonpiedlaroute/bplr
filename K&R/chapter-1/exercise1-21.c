#include <stdio.h>

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

int main(int argc, char* argv[])
{
    entab(4);

    return 0;
}
