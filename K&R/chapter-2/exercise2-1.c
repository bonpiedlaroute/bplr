#include <limits.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    
    printf("Max signed char : %d\n", SCHAR_MAX );
    printf("Min signed char : %d\n", SCHAR_MIN );

    printf("Max unsigned char : %d\n", UCHAR_MAX);

    printf("Max signed short : %d\n", SHRT_MIN );
    printf("Min signed short : %d\n", SHRT_MAX );

    printf("Max unsigned short : %d\n", USHRT_MAX);
    
    printf("Max signed int : %d\n", INT_MIN );
    printf("Min signed int : %d\n", INT_MAX );

    printf("Max unsigned int : %u\n", UINT_MAX);

    printf("Max signed long : %ld\n", LONG_MAX);
    printf("Min signed long : %ld\n", LONG_MIN);

    printf("Max unsigned long : %lu\n", ULONG_MAX);


    return 0;
}
