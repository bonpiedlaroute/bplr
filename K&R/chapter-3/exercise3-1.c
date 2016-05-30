#include <stdio.h>

int binsearch(int x, int v[], int n)
{
    int low = 0, high = 0, mid = 0;

    high = n - 1;
    
    while( low <= high && v[mid] != x )
    {
        mid = (low + high) / 2;

        if( x <= v[mid] )
            high = mid - 1;
        else
            low = mid + 1;
    }

    if( v[mid] == x )
        return mid;
    else
        return -1;
}

int main(int argc, char *argv[])
{
    int tab[] ={1,2,4,10,23, 24, 29, 31, 60, 63, 66, 67, 82};
    int r = -1;
    
    r = binsearch(67, tab, 13);
    if( r < 0 )
        printf("element was not found in the table\n");
    else
        printf("element was found at position %d\n", r);

    return 0;
}
