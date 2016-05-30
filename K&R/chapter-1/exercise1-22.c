#include <stdio.h>

#define MAXLINE 1000
#define MAXOUTPUTLINE   1020
#define NBCOLUMN    80
   
char inputline[MAXLINE];
char outputline[MAXOUTPUTLINE];

int m_getline()
{
    int c, i;

    for( i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c !='\n'; i++)
        inputline[i] = c;

    if( c == '\n')
    {
        inputline[i] = c;
        i++;
    }
    inputline[i] = '\0';
    return i;
}

void split_line(char input[], char output[])
{
    int i, j = 0, k = 0;

    for( i = 0; input[i] != '\0'; i++)
    {
        if( ( i!= 0 ) && ( (i % (NBCOLUMN - 1)) == 0 ) )
        {
            if( input[i] == ' ' || input[i] == '\t')
            {
                for( j = i; j >= 0 && (input[j] == ' ' || input[j] == '\t'); j-- ) ;
                
                if( j < 0 )
                    output[k++] = '\n';
                else
                {

                    k = k - (i - j) + 1;

                    output[k++] = '\n';
                    
                    for(j = j + 1 ; j <= i; j++)
                        output[k++] = input[j];
                }
            }
            else
            {
                if( input[i] == '\n')
                    output[k++] = input[i];
                else
                {
                    output[k++] = '\n';
                    output[k++] = input[i];
                }

            }
        }
        else
            output[k++] = input[i];
    }
    
    output[k] = input[i];
}

int main(int argc, char* argv[])
{
    int len = 0;
    
    while( (len = m_getline()) > 0 )
    {
        split_line(inputline, outputline);
        printf("%s",outputline);
    }

    return 0;
}

