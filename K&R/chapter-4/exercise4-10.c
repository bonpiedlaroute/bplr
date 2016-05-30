#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define MAXOP   100
#define NUMBER  '0'
#define VARIABLE  '1'
#define MAXVAL  100
#define MAXLINE 300

int sp = 0;
double val[MAXVAL];

int mp = 0:
char inputstring[MAXLINE];

int m_getline(char s[], int lim)
{
    int c, i;
    
    i = 0;
    while( --lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    
    if( c == '\n' )
        s[i++] = c;

    s[i] = '\0';

    return i;
}

void push(double f)
{
    if( sp < MAXVAL )
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n",f);
}

double pop(void)
{
    if( sp > 0 )
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}


int getop(char s[])
{
    int i, c;

    while( mp < MAXLINE && (s[0] = c = inputstring[mp++]) != EOF && ( c == ' ' || c == '\t' ) ) ;

    s[1] = '\0';

    if( !isdigit(c) && c != '.' && !isletterforvariable(c) )
        return c; /* not a number and not a variable */

    i = 0;

    if( isletterforvariable(c) )
    {
        if( mp < MAXLINE )
        c = inputstring[mp++];

        while( mp < MAXLINE && isletterforvariable(c) || c == '-' || isdigit(c) )
        {            
            if( ++i < MAXOP )            
                s[i] = c;

            c = inputstring[mp++];
        }

        if( ++i < MAXOP )            
        s[i] = '\0';

        if( mp < MAXLINE )
        mp--;
        else
        return EOF;

        return VARIABLE;
    }

    if( (isdigit(c) )
        while( mp < MAXLINE && isdigit( s[++i] = c = inputstring[mp++] ) ) ;

    s[i] = '\0';
    
    if( mp < MAXLINE )
        mp--;
        else
        return EOF;

    return NUMBER;
}

int main(int argc, char * agv[])
{
    int type = 0;
    doule op2 = 0.0;

    char s[MAXOP];
    
    while( m_getline(inputstring, MAXLINE) > 0 )
    {
        while( (type = getop(s, inputstring) ) != EOF )
        {
            switch(type)
            {
                case NUMBER:
                {
                    push(atof(s));
                    break;
                }
                case VARIABLE:
                {
                    
                    break;
                }
                case '+':
                {
                    push(pop() + pop());
                    break;
                }
                case '*':
                {
                    push(pop() * pop());
                    break;
                }
                case '-':
                {
                    op2 = pop();
                    push(pop() - op2);
                    break;
                }
                case '/':
                {
                    op2 = pop();
                    if( op2 != 0.0 )
                        push(pop() / op2);
                    else
                        printf("error: zero divisor\n");

                    break;            
                }
                case '%':
                {
                    op2 = pop();
                    if( op2 != 0.0 )
                        push(pop() % op2);
                    else
                        printf("error: zero divisor\n");

                    break;            
                }
                case '\n':
                {
                    printf("\t%.8g\n",pop());
                    break;
                }
                default:
                {
                    printf("error: unknown command %s\n", s);
                    break;
                }
            }
        }
    }

    return 0;
}
