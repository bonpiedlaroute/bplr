#include <stdio.h>

#define IN 1 /* inside a word */

#define OUT 0 /* outside a word */

#define NB_CHARACTERS  26 /* number of characters */

/* count lines, words, and characters in input */
int main(int argc, char* argv[])
{
    int c = 0, i = 0, maxlen = 0;
    int freqofcharacters[NB_CHARACTERS];
    int j = 0;
    char v = 'a';

    /* we init the lenghtofword table */
    for(i = 0; i < NB_CHARACTERS; i++)
        freqofcharacters[i] = 0;

    while( (c = getchar()) != EOF )
    {
        if( 'a'<= c && c<='z' )
            freqofcharacters[c - 'a']++;
        else
        if( 'A' <= c && c<= 'Z' )
            freqofcharacters[c - 'A']++;
    }

    /*** we find the maximum word lenght ***/ 
    for(i = 0; i < NB_CHARACTERS; i++)
    {
        if( freqofcharacters[i] > maxlen )
            maxlen = freqofcharacters[i];
    }

    /*** we draw a histogram with vertical bar ***/
    printf("\nhistogram with vertical bar\n");

    /* we draw the vertical axis */
    for(i = maxlen; i >= 1; i--)
    {
        printf("%2d|",i);

        for(j = 0; j < NB_CHARACTERS ; j++)
        {
            if( freqofcharacters[j] >= i )            
            printf("   *");
            else
            printf("    ");
        }
        printf("\n");
    }
    printf("  0");
    /* we draw the horizontal axis */
    for(i = 0; i < NB_CHARACTERS; i++)
    {
        printf("---%c", ((int)v + i));
       
    }

    printf("\n");
    return 0;
}
