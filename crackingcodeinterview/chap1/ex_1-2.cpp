#include <iostream>
#include <string.h>

using namespace std;

void reverse_c_string(char* c_str, int length)
{
   int i = 0, j = length - 1;

   while( i < j )
   {
      char c = c_str[i];
      c_str[i] = c_str[j];
      c_str[j] = c;
      i++;
      j--;
   }

}

int main()
{
   char test1[] = "look at this wonderful apple !";
   char test2[] = "guess what, i need to go";

   cout << test1 << "\n";
   reverse_c_string(test1, strlen(test1));
   cout << " reverse: "<< test1 << "\n";

   cout << test2 << "\n";
   reverse_c_string(test2, strlen(test2));
   cout << " reverse: "<< test2 << "\n";

   return 0;
}
