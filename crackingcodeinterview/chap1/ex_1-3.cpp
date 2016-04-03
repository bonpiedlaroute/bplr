#include <iostream>
#include <string>

using namespace std;

void remove_duplicate(string& str)
{

   unsigned long long ascii_part1 = 0, ascii_part2 = 0;
   int j = 0;

   for(int i = 0; i < str.length(); i++)
   {
      if( str[i] > 64 )
      {
         if( (ascii_part2 & (unsigned long long) 1 << (str[i]%64) ) == 0 )
         {
            str[j] = str[i];
            j++;
            ascii_part2 |= (unsigned long long) 1 << (str[i]%64) ;
         }
         
      }
      else
      {
         if( (ascii_part1 & (unsigned long long) 1 << (str[i]%64) ) == 0 )
         {
            str[j] = str[i];
            j++;
            ascii_part1 |= (unsigned long long) 1 << (str[i]%64) ;
         }
      }

   }

   str[j] = '\0';
}


int main()
{
   string test1("house");
   string test2("beef");
   string test3("Wood");
   string test4("zoo");

   cout << "Before :" << test1 << "\n";
   remove_duplicate(test1);
   cout << "After :" << test1 << "\n";

   cout << "Before :" << test2 << "\n";
   remove_duplicate(test2);
   cout << "After :" << test2 << "\n";

   cout << "Before :" << test3 << "\n";
   remove_duplicate(test3);
   cout << "After :" << test3 << "\n";

   cout << "Before :" << test4 << "\n";
   remove_duplicate(test4);
   cout << "After :" << test4 << "\n";

   return 0;
}
