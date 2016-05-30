#include <stdio.h>

int main(int argc, char* argv[])
{
    printf("\c hello, world\n"); /* compiler warning \c sequence doesn't exist */

    return 0;
}
