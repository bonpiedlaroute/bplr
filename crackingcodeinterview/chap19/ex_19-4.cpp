#include <iostream>


int max(int a, int b)
{
   int c = a - b;
   int k ( c >> 31) & 0x1 ;
   return a - k * c;
}


