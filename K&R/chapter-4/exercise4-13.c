#include <stdio.h>


void reverse(char s[], int left, int right)
{
    int c = 0;

    if( left >= right )
        return;

    c = s[left];
    s[left] = s[right];
    s[right] = c;

    reverse(s, left -1, right -1);
}

int main(int argc, char *argv[])
{


    return 0;
}
