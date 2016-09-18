#include <iostream>
#include <map>

using namespace std;

map<int, string> convert;

void init()
{
   convert[0] = "";
   convert[1] = "one";
   convert[2] = "two";
   convert[3] = "three";
   convert[10] = "ten";   

}

string phrase(int number)
{
   if( number <= 20 )
   {
      return convert[number];
   }
   else
   {
      if( number < 100 )
      {
         convert[number/10 * 10] + " " + phrase(number%10);
      }
      else
      {
         if( number >= 100 && number < 1000 )
         {
            convert[number/100] + " hundred" + " " + phrase(number%100);
         }
         else
         {
            if( number < 1000000 )
            {
               phrase(number/1000) + " thousand" + " " + phrase(number%1000);
            }
            else
            {
               phrase(number/1000000) + "million" + " " + phrase(number%1000000);
            }
         }
      }
   }

}

string transform2phrase(int number)
{
   if( number == 0 )
      return "zero";
 
   init();
  
   return phrase(number);
}

int main()
{
   return 0;
}
