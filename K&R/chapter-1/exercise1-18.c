#include <stdio.h>

#define MAX_CHARACTERS  100

int m_getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i< lim - 1 && (c = getchar()) !=  EOF && c != '\n'; ++i)
        s[i] = c;

    if ( c == '\n' )
    {    
        s[i] = c;
        ++i;
    }
    
    s[i] = '\0';

    return i;
}


/* lenght >= 0 */
void remove_blanks(char s[], int lenght)
{
    int i = 0, init_value = 0;
    
    if ( s[lenght - 1] == '\n')
    init_value = lenght - 2;
    else
    init_value = lenght - 1;
    
    for(i = init_value ; i >=0 && (s[i] == ' ' || s[i] == '\t') ; i--) ;

    if( i >=0 )
    {
        if( i < init_value )
        {

            if( s[lenght - 1] == '\n' )
            {
                s[i + 1] = '\n';
                s[i + 2] = '\0';
            }
            else
            {
                s[i + 1] = '\0';
            }
        }
        
    }
    else
        s[0] = '\0';

    
}

int main(int argc, char* argv[])
{
    int len = 0;
    char s[MAX_CHARACTERS];


    while( (len = m_getline(s, MAX_CHARACTERS)) > 0 )
    {
        remove_blanks(s, len);
        printf("%s",s);
    }

    return 0;
}
