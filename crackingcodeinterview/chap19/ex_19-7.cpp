#include <iostream>
#include <vector>
#include <utility>
#include <limits>


using namespace std;

vector<int> FindLargestSum(vector<int> input)
{
   int max =  std::numeric_limits<int>::min();
   int sum = 0;
   pair<int, int> tuple;

   for(int i = 0; i < input.size(); ++i)
   {
      sum += input[i];
      if( sum > max )
      {
         max = sum;
         tuple = pair<int,int>(i,i);
      }

      for(int j = i + 1; j < input.size(); ++j)
      {
         sum += input[j];

         if( sum > max )
         {
            max = sum;
            tuple = pair<int,int>(i,j);
         }
      }

      sum = 0;
   }

   vector<int> result;
   for(int k = tuple.first; k <= tuple.second; ++k)
   {
      result.push_back(input[k]);
   }

   return result;
}

int main()
{
   vector<int> input = {2,-8,3,-2,4, -10};

   vector<int> result = FindLargestSum(input);
   int sum = 0;
   cout << "\n";
   for( int val : result)
   {
      cout << val <<" ";
      sum += val;
   }
   cout << "\n" << sum << "\n";
   return 0;
}



