#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

unordered_map<string,int> Frequency;

void  insertDictionaryWord(vector<string> WordDict )
{
   pair<unordered_map<string, int>::iterator, bool> ret;

   for(string word : WordDict)
   {
      ret = Frequency.insert(pair<string,int>(word, 1));

      if( ret.second == false )
         Frequency[word] += 1;
   }
}


int occurenceword(string word)
{
   unordered_map<string,int>::iterator iter;
   
   if( (iter = Frequency.find(word) ) != Frequency.end() )
      return iter->second;
   else
      return 0;
}


int main()
{

   return 0;
}
