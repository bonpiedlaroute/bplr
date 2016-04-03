#include <string>
#include <iostream>

using namespace std; 

bool IsAnagram(string str1, string str2)
{
   char tab1[256] = {0};
   char tab2[256] = {0};

   if( str1.length() != str2.length() )
      return false;

   for( char c : str1 )
   {
      tab1[c]++;
   }
   for( char c : str2 )
   {
      tab2[c]++;
   }

   for(int i = 0; i < 256; ++i )
   {
      if( tab1[i] != tab2[i] )
         return false;
   }

   return true;
}


int main()
{

   if( IsAnagram( "sea", "ase") )
   {
     cout << "sea is anagram of ase \n";
   }
   else
   {
     cout << "sea is not anagram of ase \n";
   }

   if( IsAnagram( "work", "ewor") )
   {
     cout << "work is anagram of ewor \n";
   }
   else
   {
     cout << "work is not anagram of ewor \n";
   }

   if( IsAnagram( "clothes", "theclos") )
   {
     cout << "clothes is anagram of theclos \n";
   }
   else
   {
     cout << "clothes is not anagram of theclos \n";
   }  
 

   return 0;
}
