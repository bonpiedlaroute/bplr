#include <stdio.h>

#define IN 1 /* inside a word */

#define OUT 0 /* outside a word */

#define MAX_CHARACTERS_IN_WORD  30 /* number maximal of characters in word */

/* count lines, words, and characters in input */
int main(int argc, char* argv[])
{
    int c = 0, state, nbc = 0, i = 0, j = 0 ;
    int lenghtofword[MAX_CHARACTERS_IN_WORD]; /* lenghtofword[1] is the 
    numbers of word with one character, lenghtofword[2] is the numbers of word with 
    two characters */
    int maxlen = 0, nbword = 0;

    /* we init the lenghtofword table */
    for(i = 0; i < MAX_CHARACTERS_IN_WORD; i++)
        lenghtofword[i] = 0;

    /*** we fill the lenghtofword table ***/
    state = OUT;

    while( (c = getchar()) != EOF )
    {
        if( c == ' ' || c == '\n' || c == '\t')
        {
            if( state == IN)
            {
                if( nbc < MAX_CHARACTERS_IN_WORD )
                {
                    lenghtofword[nbc]++;
                    nbc = 0;
                }
            }
            state = OUT;
        }
        else
        {            
            if ( state == OUT )
            {                
                state = IN;
            }
            nbc++;
        }
    }

    /*** we find the maximum word lenght ***/ 
    for(i = 0; i < MAX_CHARACTERS_IN_WORD; i++)
    {
        if( lenghtofword[i] > maxlen )
            maxlen = lenghtofword[i];
    }

    /*** we draw a histogram with horizontal bar ***/
    printf("\nhistogram with horizontal bar\n");

    printf("\t words frequencies \n");
    printf("  0");
    /* we draw the horizontal axis */
    for(i = 1; i <= maxlen; i++)
    {
        printf("--%2d", i);
    }

    printf("\n");
    /* we draw the vertical axis */
    for(i = 1; i < MAX_CHARACTERS_IN_WORD; i++)
    {
        printf("%2d|",i);

        nbword = lenghtofword[i];

        for(j = 1; j <= nbword ; j++)
        {
            printf("   *");
        }
        printf("\n");
    }

    /*** we draw a histogram with vertical bar ***/
    printf("\nhistogram with vertical bar\n");

    /* we draw the vertical axis */
    for(i = maxlen; i >= 1; i--)
    {
        printf("%2d|",i);

        for(j = 1; j <= MAX_CHARACTERS_IN_WORD ; j++)
        {
            if( lenghtofword[j] >= i )            
            printf("   *");
            else
            printf("    ");
        }
        printf("\n");
    }
    printf("  0");
    /* we draw the horizontal axis */
    for(i = 1; i <= MAX_CHARACTERS_IN_WORD; i++)
    {
        printf("--%2d", i);
    }

    printf("\n");
    printf("\t number of characters in each word\n");
    /* we draw the vertical axis */
   
    

    return 0;
}
