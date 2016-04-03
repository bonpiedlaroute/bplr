#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


bool AllUnique1(string st)
{
   char tab[256] = {0};

   for( char c : st)
   {
      if( tab[c] == 0 )
         tab[c]++;
      else
         return false;
   }

   return true;

}


bool AllUnique2(string st)
{
   std::sort(st.begin(), st.end());

   for(int i=0; i < st.length() -1; ++i)
   {
      if( st[i] == st[i+1] )
         return false;
   }

   return true;
}  


int main()
{

 string test1("wood");
 string test2("beef");
 string test3("house");

 if( AllUnique1(test1) && AllUnique2(test1) )
 {
   cout << test1 << " has all unique characters \n";
 }
 else
 {
   cout << test1 << " has not all unique characters \n";
 }

 if( AllUnique1(test2) && AllUnique2(test2) )
 {
   cout << test2 << " has all unique characters \n";
 }
 else
 {
   cout << test2 << " has not all unique characters \n";
 }

 if( AllUnique1(test3) && AllUnique2(test3) )
 {
   cout << test3 << " has all unique characters \n";
 }
 else
 {
   cout << test3 << " has not all unique characters \n";
 }

 return 0;

}
