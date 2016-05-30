#include <stdio.h>

#define MAX_SIZE    120

typedef enum
{
    IN = 0,
    OUT
} loop_state;


int main(int argc, char *argv[])
{
    char s[MAX_SIZE];
    int i = 0, c = 0, lim = MAX_SIZE;
    loop_state state = OUT;

    if( i < lim - 1 )
        state = IN;

    while( state != OUT )
    {
        c = getchar();

        if( c == '\n' )
            state = OUT;
        else
            if( c == EOF )
            state = OUT;
         
        if( state != OUT )
        s[i] = c;

        i++;
        
        if( i >= lim - 1)
        state = OUT;
    }

    return 0;
}
