

/* getword get next word or character from input */

int getword(char *word, int lim)
{
    int c;
    char *w = word;
    
    while( isspace(c = getch())) ;

    if( c != EOF )
        *w++ = c;

    if( !alpha(c) && c != '_'  && c != '#')
    {
        *w = '\0';
        return c;
    }

    for(; --lim > 0; w++)
    {
        if( !isalnum(*w = getch()) && c != '_' )
        {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    
    return word[0];
}
