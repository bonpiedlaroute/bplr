#include <stdio.h>

typedef enum
{
    SLASH = 0,
    NO_SLASH
} m_s;

/* we suppose that s is big enough to contain t and  \n \t sequence */
void escape(char s[], char t[])
{
    int i = 0, j = 0;
    for(i = 0; t[i] != '\0'; i++)
    {
        switch(t[i])
        {
            case '\t':
            {
                s[j++] = '\\';
                s[j++] = 't';
                break;
            }
            case '\n':
            {
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            }
            default:
            {
                s[j++] = t[i];
                break;
            }
        }
    }

    s[j] ='\0';
}

void reverse_escape(char s[], char t[])
{
    int i = 0, j = 0;
    m_s state = NO_SLASH;

    for(i = 0; s[i] != '\0'; i++)
    {
        switch(s[i])
        {
            case '\\':
            {
                if( state != SLASH )
                state = SLASH;
                else
                t[j++]= '\\';

                break;
            }
            case 't':
            {
                if( state == SLASH )
                {
                    t[j++] = '\t';
                    state = NO_SLASH;
                }
                else
                t[j++] = s[i];

                break;
            }
            case 'n':
            {
                if( state == SLASH )
                {
                    t[j++] = '\n';
                    state = NO_SLASH;
                }
                else
                t[j++] = s[i];

                break;
            }
            default:
            {
                if( state == SLASH )
                {
                    t[j++] = '\\';
                    state = NO_SLASH;
                }
                t[j++] = s[i];
                break;
            }
        }
    }

    t[j] ='\0';
}



int main(int argc, char *argv[])
{


    return 0;
}
