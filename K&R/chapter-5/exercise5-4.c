#include <stdio.h>
#include <string.h>

/* assume that s and t are not null!!! */
int strend(char *s, char *t)
{
    char *pt = t;

    while( *s != '\0' )
    {
        if( *s == *pt )
            pt++;
        else
            pt = t;

        s++;
    }

    if( *pt == '\0' )
        return 1;
    else
        return 0;
}

void m_strcat(char s[], char t[])
{

    while( *s != '\0' ) s++ ;

    while( ( *s = *t) != '\0' )
    {
        s++;
        t++;
    }
}

int main(int argc, char *argv[])
{
    char r[70];
    strcpy(r, "i have a ");
    char t[]="dream";
    char g[]="drea";
    char go[]="drem";

    char tu[] = "dream i have a";

    m_strcat(r,t);

    if( strend(r,t) )
    printf("%s is a the end of [%s]\n", t, r);
    else
    printf("%s is not a the end of [%s]\n", t, r);
    
    if( strend(r,g) )
    printf("%s is a the end of [%s]\n", g, r);
    else
    printf("%s is not a the end of [%s]\n", g, r);

    if( strend(r,go) )
    printf("%s is a the end of [%s]\n", go, r);
    else
    printf("%s is not a the end of [%s]\n", go, r);

    if( strend(tu,t) )
    printf("%s is a the end of [%s]\n", t, tu);
    else
    printf("%s is not a the end of [%s]\n", t, tu);

}
