#include <stdio.h>


int main(int argc, char* argv[])
{
    /* in unix operating systems used ctrl + d on shell to signal an EOF(enf of file) */
    printf("value of getchar() != EOF is %d \n", getchar() != EOF); 
    return 0;
}
