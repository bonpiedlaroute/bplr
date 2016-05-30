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
            state = OUT;
        else 
        if ( state == OUT )
        {
            state = IN;
            ++nw;
        }
    }
    printf("\nline words charaters\n");
    printf("%2d %5d %7d\n",nl, nw, nc);

    return 0;
}
/**
1) first test
./exercise1-11 < exercise1-11.c

2) second test
lines begin with space, tabs
lines with only new line character
lines end with space, tabs
lines with only space
lines with only tabs
inputs with only new line character

**/
