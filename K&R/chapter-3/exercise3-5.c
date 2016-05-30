#include <stdio.h>
#include <string.h>

void reverse(char s[])
{
    int c, i, j;

    for( i = 0, j = strlen(s) - 1; i < j ; i ++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int itoa(int n, char s[], unsigned b)
{
    int i, sign, r = 0;

    if( 2 <= b && b <= 16)
    {

        if( (sign = n) < 0 )
            n = -n; 
    
        i = 0;
    
        do
        {
            r = n % b;
            switch(r)
            {
                case 15:
                {
                    s[i++] = 'F' ;
                    break;
                }
                case 14:
                {
                    s[i++] = 'E';
                    break;
                }
                case 13:
                {
                    s[i++] = 'D';
                    break;
                }
                case 12:
                {
                    s[i++] = 'C';
                    break;
                }
                case 11:
                {
                    s[i++] = 'B';
                    break;
                }
                case 10:
                {
                    s[i++] = 'A';
                    break;
                }
                default:
                {
                    s[i++] = r + '0';
                    break;
                }
            }            
        }while( (n /= b) > 0 );
        
        if( b == 16 )
        {
            s[i++] = 'X';
            s[i++] = '0';
        }

        if( sign < 0 )
            s[i++] = '-';

        s[i] = '\0';

        reverse(s);
        return 1;
    }
    else
        return -1;
}
int main(int argc, char *argv[])
{
    char s[33];


    printf(" value -2589849\n");
    itoa(-2589849, s, 16);
    printf("%s\n", s);

    return 0;
}
