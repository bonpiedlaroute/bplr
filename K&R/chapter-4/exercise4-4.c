#include <stdio.h>
#include <stdlib.h>


#define MAXOP   100
#define NUMBER  '0'
#define MAXVAL  100

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

int main(int argc, char * agv[])
{
    int type = 0;
    doule op2 = 0.0;

    char s[MAXOP];

    while( (type = getop(s) ) != EOF )
    {
        switch(type)
        {
            case NUMBER:
            {
                push(atof(s));
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

    return 0;
}
