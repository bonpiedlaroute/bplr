#include <utility>
#include <vector>
#include <unordered_map>


using namespace std;

vector<pair<int,int>> FindAllPair(vector<int> array)
{
   vector<pair<int,int>> result;
   
   unordered_map<int,int> c;
   int sum = 0;
   
   for(int i = 0;  i < array.size(); ++i)
   {
      c[array[i]] = i;
   }

   for(int i = 0; i < array.size(); ++i)
   {
      unordered_map<int,int>::iterator iter;

      if( (iter = c.find(sum - array[i] ) ) != c.end()) 
         result.push_back(pair<int,int>(i, iter->second));
   }

   return result;
}

int main()
{

   return 0;
}
