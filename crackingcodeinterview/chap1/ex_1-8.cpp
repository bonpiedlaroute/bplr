#include <string>


using namespace std;


void rotate_string(string s1, string s2)
{
   bool found_begin = false;
   int j = 0, k = 0;

   if( s1.length() != s2.length() )
      return false;

   for(int i = 0; i < s2.length(); ++i)
   {
      if( found_begin && s1[0] == s2[i] )
      {
         found_begin = true;
         k = i;
         j++;
      }
      else
      {
         if( found_begin )
         {
            if( s1[j] == s2[i] )
            {
               j++;
            }
            else
            {
               j  = 0;
               found_begin = false;
               k = 0;
            }
         }
      }
   }

   if( found_begin )
   {
      string tmp = s2.substr(0,k);
      if( IsSubstring(s1,s2) )
         return true;
      else
         return false;
   }
   else
      return false;
}
