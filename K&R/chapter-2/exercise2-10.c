#include<stdio.h>

int lower(int c)
{
    int r = 0;
    r = ( c >= 'A' && c <= 'Z' ) ? c + 'a' - 'A': c ;

    return r;
}

int main(int argc, char *argv[])
{
    


    return 0;
}
