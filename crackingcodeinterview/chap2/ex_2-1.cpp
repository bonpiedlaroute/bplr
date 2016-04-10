#include <algorithm>
#include <list>
#include <unordered_map>
#include <utility>
#include <iostream>

using namespace std;


void remove_duplicate1(list<int>& mylist)
{
   mylist.sort();
   
   list<int>::iterator iter;
   list<int>::iterator iter_next;

   for(iter = mylist.begin(); iter != mylist.end() && (iter_next = std::next(iter,1)) != mylist.end(); )
   {
      if( *iter == *(iter_next))
         iter = mylist.erase(iter);
      else
         ++iter;
   }

}


void remove_duplicate2(list<int>& mylist)
{
   pair<unordered_map<int,int>::iterator, bool> ret;
   unordered_map<int,int> values;

   list<int>::iterator iter;

   for(iter = mylist.begin(); iter != mylist.end(); )
   {
      ret = values.insert(pair<int,int>(*iter, 1));
      if( ret.second == false )
         iter = mylist.erase(iter);
      else
         ++iter;
   }
}

int main()
{
   int v[] = {3, 15, 6, 5,9, 8,6,7,9};
   list<int> values(v, v + sizeof(v)/sizeof(v[0]));
   list<int> copy(values);


   for(int i : values )
   {
      cout << i << " ";
   }

   cout << "\n";

   remove_duplicate1(values);

   for(int i : values )
   {
      cout << i << " ";
   } 

   cout << "\n";

   for(int i : copy )
   {
      cout << i << " ";
   }

   cout << "\n";

   remove_duplicate2(copy);

   for(int i : copy )
   {
      cout << i << " ";
   } 

   cout << "\n";

   return 0;
}
