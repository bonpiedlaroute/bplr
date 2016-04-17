#include <iostream>

struct Node
{
   int data;
   Node* left;
   Node* right;
};


bool IsEqual(Node* T1, Node* T2)
{
   if( T1 == nullptr && T2 == nullptr )
      return true;

   if( T1 == nullptr || T2 == nullptr )
      return false;

   if( T1->data != T2->data )
      return false;

   return IsEqual(T1->left,T2->left) && IsEqual(T1->right, T2->right) ;

}

bool SubTree(Node* T1, Node* T2)
{
   
   if( IsEqual(T1,T2) )
      return true;

   if( SubTree(T1->left, T2) )
      return true;

   if( SubTree(T2->right, T2) )
      return true;

   return false;

}

int main()
{

   return 0;
}
