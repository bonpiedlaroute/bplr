#include <iostream>

struct Node
{
   int data;
   Node* left;
   Node* right;
   Node* parent;
};

bool findroute(Node* start, Node* end)
{
   if( start == nullptr || end == nullptr )
      return false;

   if( start->data == end->data )
      return true;

   if( findroute(start->left,end) )
      return true;

   if( findroute(start->right, end) )
      return true;

   if( findroute(start->parent, end) )
      return true;

   return false;
}

int main()
{

   return 0;
}
