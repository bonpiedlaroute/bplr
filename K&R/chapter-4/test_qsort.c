#include <stdio.h>

/* assumption: i and j are in bound ! */
void swap(int v[], int i, int j)
{
    int temp = v[i];

    v[i] = v[j];
    v[j] = temp;
}

void qsort(int v[], int left, int right)
{
    int i, last;

    if( left >= right )
        return;

    swap(v, left, (left + right)/2);

    last = left;

    for( i = left + 1; i <= right; i++ )
    {
        if( v[i] < v[left] )
            swap(v, ++last, i);
    }
    
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right );

}

void m_qsort(int v[], int left, int right)
{
    int pivot = 0, i, j;
    

    if( left >= right )
        return;

    /* choice of the pivot */
    pivot = ( left + right ) / 2 ;

    swap(v, left, pivot);

    pivot = left;    
    
    for( i = left + 1;  i <= right ; i++ )
    {
        if( v[i] < v[pivot] )
        {
            for( j = i; j > pivot; j-- )            
            swap(v, j, j - 1);

            pivot = pivot + 1;
        }
    }

    m_qsort(v, left, pivot - 1);
    m_qsort(v, pivot + 1, right);
}

int main(int argc, char *argv[])
{
    int i;    
    int value[] ={9,2,1,5,10,13,7,34, 4, 102, 45, 80, 38, 50, 13, 49};

    for(i = 0; i < sizeof(value)/sizeof(int) ; i++)
    {
        printf("%d ",value[i]);
    }

    printf("\n");

    m_qsort(value,0, sizeof(value)/sizeof(int) - 1 );

    for(i = 0; i < sizeof(value)/sizeof(int) ; i++)
    {
        printf("%d ",value[i]);
    }

    printf("\n");
    return 0;
}
