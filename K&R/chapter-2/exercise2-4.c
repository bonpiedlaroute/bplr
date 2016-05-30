#include <stdio.h>

void squeeze(char s[], int c)
{
    int i, j;
    
    for( i = j = 0; s[i] != '\0'; i++)
    {
        if( s[i] != c )
            s[j++] = s[i];
    }

    s[j] = '\0';
}

void squeezeall( char s1[], char s2[])
{
    int i = 0;
    
    for( i = 0; s2[i] != '\0'; i++ )
    {
        squeeze(s1, (int)s2[i]);
    }

}

int main(int argc, char *argv[])
{
    char s1[] = " J'aime manger les plantains frits";
    char s2[] = " Je veux monter ma boite";
    char s3[] = " Tout le monde peut innover, si sa vie en dépend";

    printf("%s\n%s\n%s\n",s1, s2, s3);

    printf("\nafter deleting \"ez\"; \"fga\";\"irt\"\n\n");
    squeezeall(s1,"ez");
    squeezeall(s2,"fga");
    squeezeall(s3,"irt");

    printf("%s\n%s\n%s\n",s1, s2, s3);
    return 0;
}
