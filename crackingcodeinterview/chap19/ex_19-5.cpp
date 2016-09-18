#include <string>


using namespace std;

void numberofhits(string solution, string guess, int& hits, int& pseudohits)
{
   hits = 0;
   pseudohits = 0;

   for(int i = 0; i <guess.length(); ++i)
   {
      if( solution[i] == guess[i] )
         hits++;
      else
      {
         if( solution.find(guess[i])  != string::npos )
         {
            pseudohits++;
         }
      }
   }
}

int main()
{
   return 0;
}
