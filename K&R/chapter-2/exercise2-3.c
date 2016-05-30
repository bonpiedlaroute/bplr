#include <stdio.h>
#include <ctype.h>

int convert_to_int(char c )
{
    int r = 0;

    switch(c)
    {
        case 'a':
        case 'A':
        {
            r = 10;
            break;
        }
        case 'b':
        case 'B':
        {
            r = 11;
            break;
        }
        case 'c':
        case 'C':
        {
            r = 12;
            break;
        }
        case 'd':
        case 'D':
        {
            r = 13;
            break;
        }
        case 'e':
        case 'E':
        {
            r = 14;
            break;
        }
        case 'f':
        case 'F':
        {
            r = 15;
            break;
        }
        default:
        break;
    }

    return r;
}

int ishexaletter(char c)
{
    return ( (c >='a' && c <= 'f') || ( c >= 'A' && c <= 'F') );
}

int htoi(char s[])
{
    int result = 0, i = 0, value = 0;

    if( s[i] == '0')
    {
        i++;
        if( s[i] == 'x' || s[i] == 'X' )
        i++;
    }

    while( isdigit(s[i]) || ishexaletter(s[i]) )
    {
        if( isdigit(s[i]) )
         value = s[i] - '0';
        else
            value = convert_to_int(s[i]);

        result = 16*result + value;
        
        i++;
    }

    return result;
}

int main(int argc, char *argv[])
{
    int i = 0, r = 0;    
    
    for( i = 1; i < argc ; i++)
    {
        
        r = htoi(argv[i]);
        
        printf("%s\t:%d\n",argv[i], r);
    }
    return 0;
}
