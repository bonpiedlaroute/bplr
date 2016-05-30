#include <stdio.h>



void m_strcat(char s[], char t[])
{

    while( *s++ != '\0' ) ;

    while( ( *s++ = *t++) != '\0' );
}


int main(int argc, char * argv[])
{

    return 0;
}
