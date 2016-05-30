#include <stdio.h>

int any(char s1[], char s2[])
{
    int r = -1, i = 0, j = 0;
    int found = 0;
    
    for( i = 0; s1[i] != '\0' && !found ; i++)
    {
        for( j = 0; s2[j] != '\0' && !found ; j++)
        {
           if( s2[j] == s1[i] )
            {
                found = 1;
                r = i;
            }
        }
    }    

    return r;
}

int main(int argc, char *argv[])
{
    char s1[] = "J'aime manger les plantains frits";
    char s2[] = "Je veux monter ma boite";
    char s3[] = "Tout le monde peut innover, si sa vie en dépend";

    char s4[] = "any";
    char s5[] = "vie";
    char s6[] = "éwp";

    printf("found at index:%d\n", any(s1, s4));
    printf("found at index:%d\n", any(s2, s5));
    printf("found at index:%d\n", any(s3, s6));

    return 0;
}
