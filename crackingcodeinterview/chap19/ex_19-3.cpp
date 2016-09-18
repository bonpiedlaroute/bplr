#include <iostream>


int trailing_zero_fact(int n)
{
   int cnt = 0;
   
   for(int i = 5; n/i > 0; i *= 5 )
   {
      cnt += n/i;
   }

   return cnt;
}


