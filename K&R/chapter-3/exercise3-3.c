#include <stdio.h>
#include <ctype.h>

int isletter(char c)
{
    if( ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') )
        return 1;
    else
        return 0;
}

/* we suppose that s2 is big enough */
void expand(char s1[], char s2[])
{
    int i = 0, j = 0, k = 0;
    while( s1[i] == '-') i++;
       
    s2[j++] = s1[i++];

    while( s1[i] != '\0' )
    {
        if( s1[i] != '-' )
        {        
            s2[j++] = s1[i];
        }
        else
            {
                while( s1[i] == '-' ) i++;
                
                if( s1[i] != '\0' )
                {
                    if( (isletter(s2[j - 1]) && isletter(s1[i])) || (isdigit(s2[j - 1]) && isdigit(s1[i])) )
                    {
                        for(k = s2[j-1] + 1 ; k <= s1[i] ; k++)
                            s2[j++] = k; 
                    }
                    else
                        s2[j++] = s1[i];

                }
            }

        i++;
    }
    s2[j] = '\0';
}

int main(int argc, char *argv[])
{
    char s1[]="-sdkjl msk -kljkljje-myiuyiu 4-9 ghjkjy-z kjlka----j,---";
    char s2[200];

    expand(s1, s2);

    printf("%s\n",s1);
    printf("%s\n",s2);

    return 0;
}
