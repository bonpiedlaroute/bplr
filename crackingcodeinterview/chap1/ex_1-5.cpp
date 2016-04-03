#include <iostream>
#include <string>

using namespace std;

string ReplaceAllSpace(string& str)
{
   string result = "";
   int i = 0;

   for( char c: str )
   {
      if( c != ' ')
      {
         result += c;
      }
      else
      {
         result += '%';
         result += '2';
         result += '0';
      }
   
   }

   result+= '\0';
   
   return result;
}
int main()
{
   string test1="sorry, we have too many things to do today";
   
   cout << "Before :\n" << test1 << "\n";
   cout << "After  :\n" << ReplaceAllSpace(test1) << "\n";

   return 0;
}
