#include <iostream>


struct Node
{
   Node(int v) : data(v)
   {

   }
   int data;
   Node* left;
   Node* right;
};

Node* AddNode(int* array, int start, int end)
{
   if( start > end )
      return nullptr;

   int mid = (start + end)/2 ;

   Node* n = new Node(*(array+mid));

   n->left = AddNode(array, start, mid-1);
   n->right = AddNode(array, mid+1, end);
   
   return n;
}


int main()
{
   
   return 0;
}
