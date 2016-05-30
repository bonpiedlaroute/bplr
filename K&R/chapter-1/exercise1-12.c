#include <stdio.h>

#define IN 1 /* inside a word */

#define OUT 0 /* outside a word */

/* count lines, words, and characters in input */
int main(int argc, char* argv[])
{
    int c, nl, nw, nc, state;

    state = OUT;

    nl = nw = nc = 0;

    while( (c = getchar()) != EOF )
    {
        ++nc;
        if( c == '\n')
            ++nl;

        if( c == ' ' || c == '\n' || c == '\t')
        {
            if( state == IN)
                putchar('\n');

            state = OUT;
        }
        else
        {            
            if ( state == OUT )
            {                
                state = IN;
                ++nw;
            }
            putchar(c);
        }
    }
    printf("\nline words charaters\n");
    printf("%2d %5d %7d\n",nl, nw, nc);

    return 0;
}
