#include "ex_7-10.h"
#include <iostream>

using namespace std;

int main()
{
   shared_ptr<int> p(new int(2));
   cout << " address of p :"<< p.operator->() <<"\n";
   {
      shared_ptr<int> copy = p;
      cout << " address of copy:" << copy.operator->() <<"\n";
   }
   shared_ptr<int> copy2(p);
   cout << " address of copy2:" << copy2.operator->() <<"\n";
   return 0;
}
