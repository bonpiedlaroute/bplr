#include <iostream>

struct Node
{
   int data;
   Node* left;
   Node* right;
   Node* parent;
   bool flag = false; 
};

void markpathnode(Node* a)
{
   if(a == nullptr)
      return;

   a->flag = true;
   markpathnode(a->parent);
}

Node* findancestorwith(Node* b)
{
   if( b == nullptr )
      return nullptr;

   if(b->flag == true )
      return b;

   return findancestorwith(b->parent);
}

Node* findcommonancestor(Node* a, Node* b)
{
   markpathnode(a);

   return findancestorwith(b);
}


int main()
{

   return 0;
}
