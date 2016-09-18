#include <stdlib.h>
#include <iostream>
#include <unistd.h>

using namespace std;


int rand5()
{
   return (rand()%5) + 1 ;
}


int rand7()
{
   return rand5() + rand5()%3 ;
}


int main()
{
   srand(time(NULL));

   while(true)
   {
      cout << rand7() << "\n";
      sleep(1);
   }

   return 0;
}
