#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAXOP   100
#define NUMBER  '0'
#define VARIABLE  '1'
#define MAXVAL  100
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int sp = 0;
double val[MAXVAL];

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

void print_top_element(void)
{
    int i = sp - 1;
    if( i >= 0 )
        printf("%g\n",val[i]);
    else
        printf("no element in the stack\n");
}

void swap_two_top_element()
{
    double val1, val2;

    val1 = pop();
    val2 = pop();
    push(val1);
    push(val2);
}

void clear_stack()
{
    sp = 0;
}

int isletterforvariable(int c)
{
    int found = 0;

    if( ('a' <= c &&  c <= 'z') || ('A' <= c &&  c <= 'Z') ||
        c == '_' )
        found = 1;
    else
        found = 0;

    return found;
}

int getch()
{
    return (bufp > 0 ) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
    if( bufp >= BUFSIZE )
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void ungets(char s[])
{
    int i = 0;
    for(i = 0; s[i] != '\0'; i++)
    {
        ungetch(s[i]);
    }
}
int getop(char s[])
{
    int i, c;

    while( (s[0] = c = getch()) == ' ' || c == '\t') ;

    s[1] = '\0';

    if( !isdigit(c) && c != '.' && !isletterforvariable(c) )
        return c; /* not a number and not a variable */

    i = 0;

    if( isletterforvariable(c) )
    {
        c = getch();        
        while(isletterforvariable(c) || c == '-' || isdigit(c) )
        {            
            if( ++i < MAXOP )            
                s[i] = c;

            c = getch();
        }

        if( ++i < MAXOP )            
        s[i] = '\0';

        if( c !=EOF )
            ungetch(c);

        return VARIABLE;
    }

    if( isdigit(c) )
        while( isdigit( s[++i] = c = getch() ) ) ;

    s[i] = '\0';
    
    if( c != EOF )
        ungetch(c);

    return NUMBER;
}

int main(int argc, char * agv[])
{
    int type = 0;
    double op2 = 0.0;

    char s[MAXOP];

    s[0] = EOF;

    while( (type = getop(s) ) != EOF )
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
                    push((int)pop() % (int)op2);
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

    return 0;
}
