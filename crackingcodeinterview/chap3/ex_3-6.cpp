#include <iostream>
#include <stack>
#include <limits>


using namespace std;


void SortStack(stack<int>& S)
{
   stack<int> tmp;
   int level_s = 0, size_s = S.size(), min = std::numeric_limits<int>::max();
   bool found = false;

   while( level_s != size_s )
   {
      while( ! S.empty() && S.size() != level_s )
      {
         int val = S.top();
         S.pop();
         
         if( val < min )
            min = val;
         
          tmp.push(val);
      }

      S.push(min);
      level_s++;
      
      while( !tmp.empty())
      {
         if(min != tmp.top() || found )
         {
            S.push(tmp.top());
         }
         else
            found = true;

         tmp.pop();
      }

      found = false;
   }
}

int main()
{
   return 0;
}
