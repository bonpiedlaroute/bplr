#include <forward_list>


using namespace std;


int find_n_to_last_elt(int n, forward_list<int>& mylist)
{
   int size = 0, cnt = 0, i = 0;
   for( int value: mylist )
   {
      size++;
   }

   cnt = size - n;

   forward_list<int>::iterator it = mylist.begin();

   for(; it != mylist.end(); ++it)
   {
      if( i == (cnt-1) )
         return *it;
      else
         i++;
   }

   return 0;
}

int main()
{

   return 0;
}
