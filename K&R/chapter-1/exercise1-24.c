#include <stdio.h>

/* state machine */
#define IN_COMMENT  0

#define IN_CODE 1

#define POSSIBLE_COMMENT    2

#define POSSIBLE_UNCOMMENT  3

#define IN_SIMPLEQUOTE  4

#define IN_DOUBLEQUOTE  6

#define POSSIBLE_ENDOF_SIMPLEQUOTE   8

/* state machine transition */
#define INCODE_TO_POSSIBLECOMMENT   9
#define POSSIBLECOMMENT_TO_INCODE    10

#define INCODE_TO_INSIMPLEQUOTE 11
#define INSIMPLEQUOTE_TO_INCODE 12

#define INSIMPLEQUOTE_TO_ENDOFSIMPLEQUOTE   13
#define POSSIBLEENDOFQUOTE_TO_INSIMPLEQUOTE 14

#define INCODE_TO_INDOUBLEQUOTE 15
#define INDOUBLEQUOTE_TO_INCODE 16

#define POSSIBLECOMMENT_TO_INCOMMENT    17
#define INCOMMENT_TO_POSSIBLEUNCOMMENT  18

#define POSSIBLEUNCOMMENT_TO_INCOMMENT  19
#define POSSIBLEUNCOMMENT_TO_INCODE 20

#define POSSIBLECOMMENT_TO_INSIMPLEQUOTE 21

#define NO_TRANSITION   22


void rudimentary_check()
{
    int c = 0, par_cpt = 0, brackets_cpt = 0, braces_cpt = 0;
    int double_quote_cpt = 0, simple_quote_cpt = 0, state = IN_CODE, transition = NO_TRANSITION;

    while( (c = getchar()) != EOF)
    {
        transition = NO_TRANSITION;

        switch(c)
        {
            case '/':
            {
                if( state == IN_CODE )
                {
                    transition = INCODE_TO_POSSIBLECOMMENT;
                    state = POSSIBLE_COMMENT;
                }
                else
                {
                    if( state == POSSIBLE_UNCOMMENT )
                    {
                        transition = POSSIBLEUNCOMMENT_TO_INCODE;
                        state = IN_CODE;
                    }
                }
                break;
            }
            case '"':
            {
                if( state == IN_CODE )
                {
                    transition = INCODE_TO_INDOUBLEQUOTE;
                    state = IN_DOUBLEQUOTE;
                }
                else
                {
                    if( state == IN_DOUBLEQUOTE )
                    {
                        transition = INDOUBLEQUOTE_TO_INCODE;
                        state = IN_CODE;
                    }
                }
                break;
            }
            case '\'':
            {
                if( state == IN_CODE)
                {
                    transition = INCODE_TO_INSIMPLEQUOTE;
                    state = IN_SIMPLEQUOTE;
                }
                else
                {
                    if( state == IN_SIMPLEQUOTE )
                    {
                        transition = INSIMPLEQUOTE_TO_INCODE;
                        state = IN_CODE;
                    }
                    else
                    {
                        if( state == POSSIBLE_COMMENT )
                        {
                            transition = POSSIBLECOMMENT_TO_INSIMPLEQUOTE;
                            state = IN_SIMPLEQUOTE;
                        }
                    }
                }
                break;
            }
            case '*':
            {
                if( state == POSSIBLE_COMMENT)
                {
                    transition = POSSIBLECOMMENT_TO_INCOMMENT;
                    state = IN_COMMENT;
                }
                else
                {
                    if( state == IN_COMMENT )
                    {
                        transition = INCOMMENT_TO_POSSIBLEUNCOMMENT;
                        state = POSSIBLE_UNCOMMENT;
                    }
                }
                break;
            }
            case '\\':
            {
                if( state == IN_SIMPLEQUOTE)
                {
                    transition = INSIMPLEQUOTE_TO_ENDOFSIMPLEQUOTE;
                    state = POSSIBLE_ENDOF_SIMPLEQUOTE;
                }
                break;
            }
            default:
            {
                break;
            }

        }/* end of switch */
        
        if( transition == NO_TRANSITION )
        {
            if( state == POSSIBLE_COMMENT && c != '*' && c != '/' )
            {
                transition = POSSIBLECOMMENT_TO_INCODE;
                state = IN_CODE;
            }
            else
            {
                if( state == POSSIBLE_UNCOMMENT && c != '/' && c != '*' )
                {
                    transition = POSSIBLEUNCOMMENT_TO_INCOMMENT;
                    state = IN_COMMENT;
                }
                else
                {
                    if( state == POSSIBLE_ENDOF_SIMPLEQUOTE)
                    {
                        transition = POSSIBLEENDOFQUOTE_TO_INSIMPLEQUOTE;
                        state = IN_SIMPLEQUOTE;
                    }
                }
            }
        }

        if( state != IN_COMMENT )
        {
            switch(c)
            {
                case '(':
                {
                    par_cpt++;
                    break;
                }
                case ')':
                {
                    par_cpt--;
                    break;
                }
                case '[':
                {
                    brackets_cpt++;
                    break;
                }
                case ']':
                {
                    brackets_cpt--;
                    break;
                }
                case '{':
                {
                    braces_cpt++;
                    break;
                }
                case '}':
                {
                    braces_cpt--;
                    break;
                }
                case '"':
                {
                    if( state != IN_SIMPLEQUOTE )
                    {
                        if( double_quote_cpt == 0 ) 
                            double_quote_cpt++;
                        else
                            if( double_quote_cpt == 1 )
                                double_quote_cpt--;
                    }
                    break;
                }
                case '\'':
                {
                    if( state != POSSIBLE_ENDOF_SIMPLEQUOTE )
                    {                   
                       if( simple_quote_cpt == 0 ) 
                            simple_quote_cpt++;
                        else
                            if( simple_quote_cpt == 1 )
                                simple_quote_cpt--;
                    }
                    break;    
                }
                default:
                    break;
            }
        }
    }

    if( par_cpt != 0 )
        printf("Possible error in parentheses\n");
    else
        if( brackets_cpt != 0 )
        printf("Possible error in brackets \n");
        else
        if( braces_cpt != 0 )
        printf("Possible error in braces \n");
        else
        if( double_quote_cpt != 0 )
            printf("Possible error in double quote \n");
        else
        if( simple_quote_cpt != 0 )
            printf("Possible error in simple quote \n");
        else
            printf("Probably no rudimentary error in your program \n");
        
        

}

int main(int argc, char *argv[])
{
    rudimentary_check();
    return 0;
}
