#include <stdio.h>


int main(int argc, char* argv[])
{
    int c = 0;


    while ( (c = getchar()) != EOF )
    {
        switch(c)
        {
            case '\t':
            {
                putchar('\\');
                putchar('t');
                break;
            }
            case '\b':
            {
                putchar('\\');
                putchar('b');
                break;
            }
            case '\\':
            {
                putchar('\\');
                putchar('\\');
                break;
            }
            default:
            {
                putchar(c);
                break;
            }
        }
    }
    return 0;
}
