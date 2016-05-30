#include <stdio.h>


int main(int argc, char * argv[])
{
    int nb_blanks= 0, nb_tabs = 0, nb_newlines = 0, c = 0;

    while ( (c = getchar()) != EOF )
    {
        switch(c)
        {
            case ' ':
            {
                nb_blanks++;
                break;
            }
            case '\t':
            {
                nb_tabs++;
                break;
            }
            case '\n':
            {
                nb_newlines++;
                break;
            }
        }
    }
    printf("\nNumber of blanks\tNumber of tabs\tNumber of newlines\n");
    printf("%9d\t%17d\t%9d\n",nb_blanks,nb_tabs,nb_newlines );
    return 0;
}
